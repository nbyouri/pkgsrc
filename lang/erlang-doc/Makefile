# $NetBSD: Makefile,v 1.12 2015/04/28 14:34:20 fhajny Exp $

DISTNAME=		otp_doc_html_${DIST_VERSION_MAJOR}.${DIST_VERSION_MINOR}
PKGNAME=		${DISTNAME:S/otp_doc_html_/erlang-doc-/}
CATEGORIES=		lang
MASTER_SITES=		http://www.erlang.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.erlang.org/
COMMENT=		Documentation for Erlang, a concurrent functional programming language

DIST_SUBDIR=		erlang

# needs erlang installed for its directory structure
DEPENDS+=		erlang-${PKGVERSION_NOREV}{,nb*}:../../lang/erlang

NO_CONFIGURE=		yes
NO_BUILD=		yes

USE_TOOLS+=		pax

# these files are already installed by ../../lang/erlang:
DUPLICATE_FILES=	lib/cosEvent-${VERSION.cosEvent}/info
DUPLICATE_FILES+=	lib/cosEventDomain-${VERSION.cosEventDomain}/info
DUPLICATE_FILES+=	lib/mnesia_session-${VERSION.mnesia_session}/info

INSTALLATION_DIRS=	lib/erlang

do-install:
	cd ${WRKDIR} && pax ${DUPLICATE_FILES:=-s,%,,} -rw doc erts-${VERSION.erts} lib ${DESTDIR}${PREFIX}/lib/erlang/

.include "../../lang/erlang/Makefile.versions"

.include "../../mk/bsd.pkg.mk"
