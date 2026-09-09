#!/bin/bash

# File name: client.sh

WAV_OUT="out.wav"
TXT_OUT="out.txt"

function record {
  echo "Recording..."
  ffmpeg -y -f pulse -i default -ac 1 -ar 16000 "$WAV_OUT"
  echo "✅ Recording complete."
}

function transcribe {
  echo "Transcribing..."
  curl -X POST "http://127.0.0.1:8000/transcribe" | jq -r .text >> "$TXT_OUT"
  echo "✅ Transcribing complete."
}

# 

record
transcribe
