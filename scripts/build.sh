#!/bin/bash

# Build script for LeetCode solutions
# Usage: ./scripts/build.sh [category] [problem_number]

set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="$ROOT_DIR/build"

# Create build directory if it doesn't exist
mkdir -p "$BUILD_DIR"

# Function to build a single file
build_file() {
    local file="$1"
    local output_name="$(basename "$file" .cpp)"
    local output_path="$BUILD_DIR/$output_name"
    
    echo "Building $file..."
    g++ -std=c++17 -O2 -Wall -Wextra "$file" -o "$output_path"
    echo "Built: $output_path"
}

# Function to build all files in a directory
build_directory() {
    local dir="$1"
    echo "Building all files in $dir..."
    
    find "$dir" -name "*.cpp" -type f | while read -r file; do
        build_file "$file"
    done
}

# Main logic
if [ $# -eq 0 ]; then
    # Build all files
    echo "Building all solutions..."
    find "$ROOT_DIR/problems" "$ROOT_DIR/collections" -name "*.cpp" -type f | while read -r file; do
        build_file "$file"
    done
elif [ $# -eq 1 ]; then
    # Build specific category
    category="$1"
    if [ -d "$ROOT_DIR/problems/$category" ]; then
        build_directory "$ROOT_DIR/problems/$category"
    elif [ -d "$ROOT_DIR/collections/$category" ]; then
        build_directory "$ROOT_DIR/collections/$category"
    else
        echo "Category '$category' not found"
        exit 1
    fi
elif [ $# -eq 2 ]; then
    # Build specific problem
    category="$1"
    problem="$2"
    
    # Search for the problem file
    file_found=""
    for dir in "problems/$category" "collections/$category"; do
        if [ -d "$ROOT_DIR/$dir" ]; then
            file_pattern="$ROOT_DIR/$dir/*$problem*.cpp"
            for file in $file_pattern; do
                if [ -f "$file" ]; then
                    file_found="$file"
                    break
                fi
            done
        fi
    done
    
    if [ -n "$file_found" ]; then
        build_file "$file_found"
    else
        echo "Problem '$problem' not found in category '$category'"
        exit 1
    fi
else
    echo "Usage: $0 [category] [problem_number]"
    echo "Examples:"
    echo "  $0                    # Build all"
    echo "  $0 hash-table         # Build category"
    echo "  $0 hash-table 0001    # Build specific problem"
    exit 1
fi

echo "Build completed successfully!"
