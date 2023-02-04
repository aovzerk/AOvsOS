#!/bin/bash

./COMPILE_C.SH
fasm BOOT/BOOT.S
fasm FILE_SYSTEM/FILE_SYSTEM.S
fasm KERNEL/KERNEL.S
fasm AOVs_OS_IMAGE/AOVs_OS_IMAGE.S AOVs_OS.IMG

#rm ./**/*.BIN
rm ./**/*.Bin
#qemu-system-x86_64 -gdb tcp:localhost:9000 -S -drive file=AOVs_OS.IMG,index=0,format=raw
qemu-system-x86_64 -drive file=AOVs_OS.IMG,index=0,format=raw