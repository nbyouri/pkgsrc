# $NetBSD: Makefile,v 1.5 2017/08/16 21:22:11 wiz Exp $
#

DISTNAME=	innotop-1.9.1
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://innotop.googlecode.com/files/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/innotop/innotop
COMMENT=	MySQL and InnoDB monitor program
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Term-ReadKey>=2.10:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=	p5-DBD-mysql>=1.0:../../databases/p5-DBD-mysql

PERL5_PACKLIST=	auto/innotop/.packlist
REPLACE_PERL=	innotop
NO_BUILD=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
