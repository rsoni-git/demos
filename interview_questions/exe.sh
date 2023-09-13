#!/bin/bash
# @Func: Compile and execute

set -eu

_FILE=${1:-}

[[ -z ${_FILE:-} ]] && echo 'Need a C file to continue' && exit 1

# Remove the code file name from command line param list
shift;

if [[ ${_FILE##*.} == 'cc' ]]; then
  # _FILE is a c++ file
  g++ -std=c++17 -O2 -g $_FILE -o "${_FILE%.*}.exe" && ./"${_FILE%.*}.exe" $*

else
  # _FILE is a c file
  gcc -std=c17 -O2 -g $_FILE -o "${_FILE%.*}.exe" && ./"${_FILE%.*}.exe" $*
fi

