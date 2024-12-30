#!/bin/bash

# Add the submodule
git submodule add https://github.com/sblantipodi/platformio_version_increment.git platformio_version_increment

# Initialize the submodule
git submodule init

# Update the submodule
git submodule update --init --recursive