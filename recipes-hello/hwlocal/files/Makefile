# App make file template
# TODO: fill the following definitions
#     CROSS_COMPILER = cross compiler path in host computer
#     SYSROOT = SDK path in host computer
#     SRC = source file(s)
#     OUT = output file name
#include $(GFXLIB)/tools/gmake_scripts/library_ugfx.mk
libdir=/usr/lib
includedir=/usr/include
#CROSS_COMPILER="/opt/fsl-imx-fb/4.9.11-1.0.0/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc"
SYSROOT="/home/karlvenegas/Y/imx-yocto/build/tmp/work/armv8a-poky-linux/helloworld/1.0-r0/recipe-sysroot"
SRC=helloworld.c
						
OUT=helloworld

all: $(SRC)
	. $(SYSROOT)
	${CC} $(Cflags) --sysroot=$(SYSROOT) $(SRC) -o $(OUT)
clean: rm $(OUT)
