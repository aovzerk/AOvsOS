files:
point = 1

kernel:
size = 10
db 0,0,size,point,"kernel"
point = point + size
times(16-($-kernel)) db 0

times(1024-($-files)) db 0