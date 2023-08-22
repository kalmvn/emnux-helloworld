SUMMARY = "Test image"

IMAGE_INSTALL = "packagegroup-core-boot ${CORE_IMAGE_EXTRA_INSTALL}"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image
inherit extrausers

# IMAGE_OVERHEAD_FACTOR ?= "1.0"
# IMAGE_ROOTFS_SIZE ?= "204800"

IMAGE_ROOTFS_SIZE ?= "8192"
IMAGE_ROOTFS_EXTRA_SPACE:append = "${@bb.utils.contains("DISTRO_FEATURES", "systemd", " + 4096", "", d)}"

# Change root password
PASSWD = "$6$C.gmlR5MBAJy$enwRHcWkMclMr..xBLLDh6V4UMWhBaI8TGLOl.6nx.8uA7bmwNUJVYmDU/otGG/4lAUrTHGmMsjYpN74JsMr1/"
EXTRA_USERS_PARAMS = "\
	usermod -p '${PASSWD}' root; \
	useradd -p '' kalog \
 	"
