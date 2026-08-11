#!/bin/bash
set -e
cd "$(dirname "$0")"

echo "Membangun proyek Ada..."
gprbuild -P belajar.gpr

echo "Build selesai. File eksekusi ada di ./bin/belajar"
