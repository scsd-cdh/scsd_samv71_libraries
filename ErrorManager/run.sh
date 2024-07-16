#!/bin/bash

# Build the src
cmake -S src -B src/build
cd src/build
make
cd ../..

# Build the test
cmake -S test -B test/build
cd test/build
make
cd ../..

# Run the test
test/build/testerrormanager