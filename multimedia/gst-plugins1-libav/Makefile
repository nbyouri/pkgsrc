# $NetBSD: Makefile,v 1.41 2018/04/17 22:10:04 wiz Exp $

DISTNAME=	gst-libav-1.14.0
PKGNAME=	${DISTNAME:S/gst/gst-plugins1/}
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-libav/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/src/gst-libav/
COMMENT=	GStreamer libav/ffmpeg plugin
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-system-libav
PKGSRC_MAKE_ENV+=	PERL=${PERL5:Q}

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.14.0
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
# the upstream developers only want to support building against
# the included ffmpeg version, since the ffmpeg API/ABI is unstable
# and there are no releases
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
