# $NetBSD: Makefile,v 1.4 2018/02/18 16:25:45 jmcneill Exp $

UBOOT_VERSION=		2018.01
UBOOT_TARGET=		pinebook
UBOOT_CONFIG=		pinebook_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

# Use anarsoul's fork of mainline U-Boot with Pinebook support patched in
MASTER_SITES=		${MASTER_SITE_GITHUB:=anarsoul/}
GITHUB_PROJECT=		u-boot-pine64
GITHUB_TAG=		98b74f94efc0bfa40ff78785f99a8f0a1fb0110a
DISTNAME=		u-boot-${UBOOT_TARGET}-${UBOOT_VERSION}
EXTRACT_SUFX=		.tar.gz

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50iw1p1/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50iw1p1/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"

# Override U-Boot defaults
DISTINFO_FILE=		${.CURDIR}/distinfo
PATCHDIR=		${.CURDIR}/patches
