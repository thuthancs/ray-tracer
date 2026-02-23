#!/usr/bin/env bash
# Convert all PPM files from ppm_images/ to PNG in png_images/.

set -e
INPUT_DIR="${1:-ppm_images}"
OUTPUT_DIR="${2:-png_images}"

if [[ ! -d "$INPUT_DIR" ]]; then
  echo "Usage: $0 [input_dir] [output_dir]" >&2
  echo "Defaults: ppm_images -> png_images" >&2
  echo "Error: input directory '$INPUT_DIR' not found." >&2
  exit 1
fi

mkdir -p "$OUTPUT_DIR"

if command -v convert &>/dev/null; then
  CONVERT='convert'
elif command -v magick &>/dev/null; then
  CONVERT='magick'
elif command -v ffmpeg &>/dev/null; then
  CONVERT='ffmpeg'
else
  echo "Error: need ImageMagick (convert/magick) or ffmpeg to convert PPM to PNG." >&2
  echo "Install with: brew install imagemagick   OR   brew install ffmpeg" >&2
  exit 1
fi

count=0
for f in "$INPUT_DIR"/*.ppm; do
  [[ -f "$f" ]] || continue
  base=$(basename "$f" .ppm)
  out="$OUTPUT_DIR/${base}.png"
  if [[ "$CONVERT" == ffmpeg ]]; then
    ffmpeg -y -i "$f" "$out" 2>/dev/null
  else
    "$CONVERT" "$f" "$out"
  fi
  echo "$f -> $out"
  ((count++)) || true
done

if [[ $count -eq 0 ]]; then
  echo "No .ppm files found in $INPUT_DIR"
else
  echo "Converted $count file(s) to $OUTPUT_DIR/"
fi
