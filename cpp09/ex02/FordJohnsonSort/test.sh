#!/bin/bash

# FordJohnsonSort 실행 파일이 없으면 컴파일
if [ ! -f FordJohnsonSort ]; then
    c++ Group.cpp FordJohnsonSort.cpp main.cpp -o FordJohnsonSort
fi
echo "FordJohnsonSort O.K"

# 인자가 없으면 기본값 사용
arg1=${1:-9997}
arg2=${2:-1}
arg3=${3:-20000}

# 테스트
echo "./FordJohnsonSort \$(jot -r $arg1 $arg2 $arg3 | tr '\n' ' ')"
./FordJohnsonSort $(jot -r $arg1 $arg2 $arg3 | tr '\n' ' ')