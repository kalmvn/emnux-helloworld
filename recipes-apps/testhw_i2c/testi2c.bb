DESCRIPTION = "Sample I2C API"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

#files/src
SRC_URI="file://src" 

# This is where to keep downloaded source files (tmp/work/..)
S="${WORKDIR}/src"

# Cross-compile source code
do_compile(){
	${CC} ${CFLAGS} ${LDFLAGS} -o testi2c testi2c.c
}

# Create /usr/bin in rootfs and copy program to it, gives access to run it as app
do_install(){
	install -d ${D}${bindir}
	install -m 0755 testi2c ${D}${bindir}
}

FILES:${PN} = "/usr/*"