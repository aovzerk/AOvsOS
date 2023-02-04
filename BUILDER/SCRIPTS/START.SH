#!/bin/bash

#qemu-system-x86_64 -gdb tcp:localhost:9000 -S -drive file=AOVs_OS.IMG,index=0,format=raw
qemu-system-x86_64 -drive file=AOVs_OS.IMG,index=0,format=raw