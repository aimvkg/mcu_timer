#!/bin/bash

# Check if the project name argument is provided
if [ $# -ne 1 ]; then
    echo "Project: $0 <project_name>"
    exit 1
fi

# Capture the project name argument
project_name="$1"

# Check if the project name is not empty
if [ -z "$project_name" ]; then
    echo "Project name cannot be empty."
    exit 1
fi

# Run cmake with the specified project name
cmake -S ./ -B ./ -G "CodeLite - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -D CMAKE_PROJECT_NAME="$project_name";

# Move workspace files in the workspace directory
mv ./$project_name.project ../../
mv ./$project_name.workspace ../../

