#!/usr/bin/env bash

if (( "$#" < 1 )); then
  echo "Usage: analyze_project <project_dir>\n"
  exit 1
fi

path_to_project="$1"
current_clang_path=$CLANG_DEBUG_PATH

rm -rf build.json build.json.lock && \
CodeChecker log \
  -o build.json \
  -b "cd $path_to_project && make clean && make" && \
rm -rf .xtu .xtu-out && \
xtu-build.py -b build.json -j 4 \
  --clang-path $current_clang_path && \
xtu-analyze.py -b build.json -j 4 -v\
  --clang-path $current_clang_path \
  --analyze-cc-path $ANALYZE_CC_PATH

