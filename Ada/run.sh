#!/bin/bash
set -e
cd "$(dirname "$0")"

if [ ! -x ./bin/belajar ]; then
  echo "File eksekusi tidak ditemukan. Jalankan ./build.sh terlebih dahulu."
  exit 1
fi

./bin/belajar
