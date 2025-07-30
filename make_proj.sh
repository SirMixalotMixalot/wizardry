#!/usr/bin/env bash
set -e
make clean
rm -f project.zip
zip -r project.zip . \
    -x "*/.*" ".*" "project.zip"
