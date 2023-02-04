
main: file "../../../BOOT/BOOT.Bin"
times(512-2-($-main)) db 0
db 055h,0AAh
