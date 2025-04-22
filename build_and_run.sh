#!/bin/bash
echo "🧹 Cleaning..."
rm -rf build

echo "⚙️  Configuring..."
cmake -S . -B build -DCMAKE_PREFIX_PATH="/Users/faryafarhang/Qt/6.6.3/macos/lib/cmake"

echo "🛠 Building..."
cmake --build build

echo "🚀 Running..."
./build/MyApp
