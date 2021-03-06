# $FreeBSD: head/deskutils/growl-for-linux/Makefile 379891 2015-02-25 10:03:34Z nivit $

PORTNAME=	growl-for-linux
PORTVERSION=	0.8.1
PORTREVISION=	0
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Notification system compatible with Growl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	desktop-file-install:${PORTSDIR}/devel/desktop-file-utils
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

AUTOMAKE_ARGS=	-a -c -f

CONFIGURE_ARGS=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

GH_ACCOUNT=	mattn
GH_COMMIT=	f81dea9
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

LIBNOTIFY_DESC=		Use notify-osd for libnotify display plugin
LIBNOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
LIBNOTIFY_RUN_DEPENDS=	notify-osd>=0.9.29_3:${PORTSDIR}/deskutils/notify-osd

OPTIONS_DEFAULT=LIBNOTIFY
OPTIONS_DEFINE=	LIBNOTIFY

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,^${PREFIX}/,,}

USES=		compiler:nestedfct libtool pkgconfig
USE_AUTOTOOLS=	aclocal autoconf automake libtoolize
USE_GITHUB=	yes
USE_GNOME=	gtk20
USE_OPENSSL=	yes
USE_SQLITE=	3

post-patch:
	@${REINPLACE_CMD} '/^gol_LDADD =/s/$$/ -lgmodule-2.0/' \
		${WRKSRC}/Makefile.am

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libgolplug.a

.include <bsd.port.mk>
