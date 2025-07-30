#!/usr/bin/env bash
set -e
zip -r project.zip . \
    -x "*/.*" ".*" "project.zip"
