from dataclasses import dataclass

import cv2
import mediapipe as mp
import numpy as np

MODEL_PATH = "/media/famubu/f9b396f5-5f46-465a-a1ee-5b008f58d5f9/data/Soft/ai-models/hand_landmarker.task"

@dataclass
class Status:
    canvas: np.ndarray
    prev_x: int
    prev_y: int
    timestamp: int
    width: int
    height: int


def check_camera() -> (cv2.VideoCapture, Status):
    #/dev/video0 ??
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        raise RuntimeError("Could not open camera")

    success, frame = cap.read()

    if not success:
        cap.release()
        raise RuntimeError("Could not read from camera")

    canvas = np.zeros_like(frame)
    
    status = Status(
        canvas=np.zeros_like(frame),
        prev_x=0,
        prev_y=0,
        timestamp=0,
        width=frame.shape[1],
        height=frame.shape[0]
    )

    return cap, status

def get_model(model_path: str):
    BaseOptions = mp.tasks.BaseOptions
    HandLandmarker = mp.tasks.vision.HandLandmarker
    HandLandmarkerOptions = mp.tasks.vision.HandLandmarkerOptions
    VisionRunningMode = mp.tasks.vision.RunningMode

    options = HandLandmarkerOptions(
        base_options=BaseOptions(model_asset_path=model_path),
        running_mode=VisionRunningMode.VIDEO,
        num_hands=1,
        min_hand_detection_confidence=0.7,
        min_hand_presence_confidence=0.7,
        min_tracking_confidence=0.7,
    )

    return HandLandmarker.create_from_options(options)

def read_frame(cap, status: Status):
    success, frame = cap.read()

    if not success:
        raise RuntimeError("Could not read from camera")

    # Mirror camera
    frame = cv2.flip(frame, 1)

    status.height, status.width, _ = frame.shape

    # OpenCV gives BGR.
    # MediaPipe expects an RGB image.
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb)

    # VIDEO mode requires a timestamp for every frame
    status.timestamp += 1
    result = landmarker.detect_for_video(mp_image, status.timestamp)

    return frame, result, status

def detect_hand(result, status):
    if result.hand_landmarks:
        hand_landmarks = result.hand_landmarks[0]

        # MediaPipe landmark 8 = index fingertip
        # MediaPipe landmark 6 = index finger PIP
        index_tip = hand_landmarks[8]
        index_pip = hand_landmarks[6]
        middle_tip = hand_landmarks[12]

        x = int(index_tip.x * status.width)
        y = int(index_tip.y * status.height)

        # Index finger pointing upward
        #finger_up = index_tip.y < index_pip.y
        finger_up = index_tip.y < index_pip.y and middle_tip.y > index_pip.y

        if finger_up:
            # Green fingertip = drawing
            cv2.circle(frame, (x, y), 10, (0, 255, 0), -1)

            # Initialize drawing position
            if status.prev_x == 0 and status.prev_y == 0:
                status.prev_x, status.prev_y = x, y

            # Draw onto persistent canvas
            cv2.line(status.canvas, (status.prev_x, status.prev_y), (x, y), (255, 0, 255), 6)

            status.prev_x, status.prev_y = x, y

        else:
            # Red fingertip = not drawing
            cv2.circle(frame, (x, y), 10, (0, 0, 255), -1)

            # Reset previous point
            status.prev_x, status.prev_y = 0, 0

    else:
        # No hand → stop drawing
        status.prev_x, status.prev_y = 0, 0

    # Display
    combined = cv2.add(frame, status.canvas)
    #
    # Window title: Air Pencil
    cv2.imshow("Air Pencil", combined)

    return status

def process_input(status: Status) -> (bool, Status):
    key = cv2.waitKey(1) & 0xFF

    # Q → quit
    if key == ord("q"):
        return (True, status)

    # C → clear canvas
    if key == ord("c"):
        status.canvas = np.zeros_like(frame)
    return (False, status)


if __name__ == "__main__":
    cap, status = check_camera()
    with get_model(MODEL_PATH) as landmarker:
        while True:
            frame, result, status = read_frame(cap, status)
            status = detect_hand(result, status)
            is_finish, status = process_input(status)
            if is_finish:
                break

    # Cleanup
    cap.release()
    cv2.destroyAllWindows()
