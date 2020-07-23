#!/bin/bash
# shell script fuer monte carlo integration

make e_fkt
echo "Build finished"
date >> output
./e_fkt.o >> output
echo "Written to output"
cat output
