# $NetBSD: Makefile,v 1.64 2018/05/04 05:43:42 adam Exp $

DISTNAME=	libgpg-error-1.31
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgpg-error/
MASTER_SITES+=	ftp://ftp.ring.gr.jp/pub/net/gnupg/libgpg-error/
MASTER_SITES+=	ftp://mirror.switch.ch/mirror/gnupg/libgpg-error/
MASTER_SITES+=	ftp://ftp.freenet.de/pub/ftp.gnupg.org/gcrypt/libgpg-error/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Definitions of common error values for all GnuPG components
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		LC_ALL="C"
MAKE_JOBS_SAFE=		no
INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.else
CONFIGURE_ENV+=		CC_FOR_BUILD=${CC:Q}\ ${CFLAGS:M*:Q}
.endif

.if !empty(MACHINE_PLATFORM:MSunOS-5.10-*)
LIBS+=	-lrt
.endif

TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
