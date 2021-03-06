# $FreeBSD: head/comms/libimobiledevice/Makefile 389224 2015-06-11 15:07:48Z avilla $

PORTNAME=	libimobiledevice
PORTVERSION=	1.2.0
PORTREVISION?=	0
CATEGORIES?=	comms
MASTER_SITES=	http://www.${PORTNAME}.org/downloads/

MAINTAINER?=	avilla@FreeBSD.org
COMMENT?=	Library to communicate with Apple iOS devices

LICENSE?=	LGPL21

SLAVE_PORT?=	no

USES+=		cpe libtool pathfix pkgconfig tar:bzip2
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=openssl_CFLAGS="-I${OPENSSLINC}" \
		openssl_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.if ${SLAVE_PORT} == no

LIB_DEPENDS=	libplist.so:${PORTSDIR}/devel/libplist \
		libusbmuxd.so:${PORTSDIR}/comms/libusbmuxd

USE_GNOME=	glib20
CONFIGURE_ARGS+=--without-cython
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's, *@ssl_requires@,,' \
		${WRKSRC}/src/${PORTNAME}*.pc.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.endif # ${SLAVE_PORT} == no

.include <bsd.port.mk>
