# $NetBSD: Makefile,v 1.1 2018/03/08 13:44:23 cheusov Exp $
#

DISTNAME=	nbase-7.0.0.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheusov/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/nbase
COMMENT=	NetBSD userlevel portable to other UNIX-like systems
LICENSE=	modified-bsd

NOT_FOR_PLATFORM=	SunOS-*-*

GITHUB_PROJECT=	nbase
BUILD_DEPENDS+=	mk-configure>=0.30.0:../../devel/mk-configure

USE_LANGUAGES=		c
USE_TOOLS+=		yacc lex

TEST_TARGET=		test

.include "../../devel/mk-configure/mk-c.mk"

MAKE_FLAGS+=	PREFIX=${PREFIX}/nbase \
		MANDIR=${PREFIX}/nbase/${PKGMANDIR} \
		LINKSPREFIX=${PREFIX}

.include "../../mk/curses.buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
