# $NetBSD: Makefile,v 1.9 2017/09/03 08:36:49 wiz Exp $
#

DISTNAME=	moodbar-0.1.2
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://pwsp.net/~qbob/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://amarok.kde.org/wiki/Moodbar
COMMENT=	Tool to show the "mood" of a track
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../math/fftwf/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
