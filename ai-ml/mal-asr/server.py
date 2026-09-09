import os
import tempfile
import numpy as np

if not hasattr(np, "sctypes"):
    np.sctypes = {
        "int": [np.int8, np.int16, np.int32, np.int64],
        "uint": [np.uint8, np.uint16, np.uint32, np.uint64],
        "float": [np.float16, np.float32, np.float64],
        "complex": [np.complex64, np.complex128],
        "others": [bool, object, bytes, str],
    }

###

from contextlib import asynccontextmanager
from fastapi import FastAPI, File, UploadFile, HTTPException
import torch
import nemo.collections.asr as nemo_asr

AUDIO_FILE_PATH = "out.wav"
MODEL_PATH = "/path/to/indicconformer_stt_ml_hybrid_rnnt_large.nemo"
asr_model = None

# Lifespan context manager: loads model once on server start
@asynccontextmanager
async def lifespan(app: FastAPI):
    global asr_model
    print("Loading IndicConformer model into memory...")
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    # Load model and configure for fast CTC decoding
    asr_model = nemo_asr.models.EncDecCTCModelBPE.restore_from(restore_path=MODEL_PATH)
    asr_model.change_decoding_strategy(decoder_type="ctc")
    asr_model.eval()
    asr_model.freeze()
    asr_model = asr_model.to(device)

    print(f"✅ Model successfully loaded on {device}!")
    yield
    print("Shutting down STT server...")

app = FastAPI(title="Malayalam STT Fast API Server", lifespan=lifespan)

@app.post("/transcribe")
async def transcribe_audio():
    transcriptions = asr_model.transcribe([AUDIO_FILE_PATH], batch_size=1, language_id="ml")
    text = transcriptions[0] if transcriptions else ""
    if isinstance(text, list) and len(text) > 0:
        text = text[0]

    return {"text": text}

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)
