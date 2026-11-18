#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
mkdir -p out

echo '=== Stage 0: tools ==='
g++ --version | head -n 1
cmake --version | head -n 1
git --version

echo '=== Stage 1: one cpp ==='
g++ -std=c++17 stages/stage1.cpp -o out/app_stage1
./out/app_stage1

echo '=== Stage 2: separated modules ==='
g++ -std=c++17 main.cpp src/arraylib.cpp -Iinclude -o out/app_stage2
./out/app_stage2

echo '=== Stage 3: static library ==='
g++ -std=c++17 -Iinclude -c src/arraylib.cpp -o out/arraylib.o
ar rcs out/libarraylib.a out/arraylib.o
g++ -std=c++17 main.cpp -Iinclude out/libarraylib.a -o out/app_static
./out/app_static
nm out/libarraylib.a | grep 'arr_sum' | head -n 1

echo '=== Stage 4: shared library ==='
g++ -std=c++17 -fPIC -Iinclude -c src/arraylib.cpp -o out/arraylib_pic.o
g++ -shared -o out/libarraylib.so out/arraylib_pic.o
g++ -std=c++17 main.cpp -Iinclude -Lout -larraylib -Wl,-rpath,'$ORIGIN' -o out/app_shared
LD_LIBRARY_PATH=out ./out/app_shared
ldd out/app_shared | grep libarraylib

echo '=== Stages 5-6: CMake and tests ==='
cmake -S . -B build
cmake --build build -j 2
ctest --test-dir build --output-on-failure
./build/variant_07
ldd build/app | grep libarraylib

echo '=== All stage checks complete ==='
