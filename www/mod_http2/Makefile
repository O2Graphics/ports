# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_http2
PORTVERSION=	1.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	HTTP/2 module for Apache httpd (EXPERIMENTAL)

LICENSE=	APACHE20

BUILD_DEPENDS=	nghttp2>=1.2:${PORTSDIR}/www/nghttp2
LIB_DEPENDS=	libnghttp2.so:${PORTSDIR}/www/nghttp2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	no
GH_ACCOUNT=	icing
GH_PROJECT=	mod_h2

USES=		autoreconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-silent-rules CONFIG_SHELL=/bin/sh \
		--program-prefix=ext-
CONFIGURE_ENV+=	CONFIG_SHELL=/bin/sh

USE_APACHE=	24+
MODULENAME=	mod_http2

CFLAGS+=	-I${LOCALBASE}/include

#WARNING=	"This is an experimental port! Requires a patched apache24"

post-build:


post-install:
#	${MV} -f ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/d_http2.so.0.0.0 \
#		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${PORTNAME}.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so.0.0.0
#	${MV} ${STAGEDIR}${PREFIX}/share/doc/mod_http2 \
#		${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
