# $NetBSD: Makefile,v 1.39 2018/04/16 14:34:25 wiz Exp $

PKGREVISION= 8
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.4.0
DISTNAME=	mousepad-${VERSION}
PKGNAME=	xfce4-mousepad-${VERSION}
CATEGORIES=	editors
MASTER_SITES=	http://archive.xfce.org/src/apps/mousepad/0.4/

HOMEPAGE=	http://users.xfce.org/~benny/xfce/apps.html
COMMENT=	Xfce text editor

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
