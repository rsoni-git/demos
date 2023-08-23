#!/bin/bash
# @Func: Clean up the current directory

shopt -s nullglob

cd $(dirname $(readlink -f $0))

/bin/rm -f *.exe

