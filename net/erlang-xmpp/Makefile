# $NetBSD: Makefile,v 1.13 2018/03/24 16:39:41 fhajny Exp $

DISTNAME=	xmpp-1.1.20
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/xmpp/
COMMENT=	XMPP parsing and serialization library on top of Fast XML
LICENSE=	apache-2.0

DEPENDS+=	erlang-fast_xml>=1.1.29:../../textproc/erlang-fast_xml
DEPENDS+=	erlang-stringprep>=1.0.11:../../textproc/erlang-stringprep
DEPENDS+=	erlang-p1_utils>=1.0.11:../../misc/erlang-p1_utils

GITHUB_PROJECT=	xmpp

BUILD_TARGET=	src

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	rebar.config
SUBST_MESSAGE.path=	Fixing include path
SUBST_VARS.path=	LOCALBASE

# Leave a non-versioned symlink in place for net/erlang-esip to find
post-install:
	${LN} -sf ${DISTNAME} ${DESTDIR}${PREFIX}/lib/erlang/lib/xmpp

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
