TARGET	:= webui
OBJS	:= webui.o request.o response.o ls.o mime.o cgi.o

mimefile := "/etc/mime.types"
CFLAGS   = -march=core2 -O3 -pipe -fomit-frame-pointer
CFLAGS	+= -DMIMEFILE=\"$(mimefile)\"
CFLAGS	+= -D_GNU_SOURCE
CFLAGS	+= -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS	+= -DUSE_THREADS=1 -D_REENTRANT
LDLIBS	+= -lpthread

all: $(TARGET)

$(TARGET): $(OBJS)

clean:
	rm -f *.o $(TARGET)
