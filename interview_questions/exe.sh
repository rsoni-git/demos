#!/bin/bash
# @Func: Compile and execute

set -eu

_C_FILE=${1:-}

[[ -z ${_C_FILE:-} ]] && echo 'Need a C file to continue' && exit 1

gcc $_C_FILE -o "${_C_FILE%.*}.exe" && ./"${_C_FILE%.*}.exe"

