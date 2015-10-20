# $FreeBSD: head/Mk/Uses/gettext-runtime.mk 399326 2015-10-15 07:36:38Z bapt $
#
# Handle dependency on the gettext-runtime (libintl) port
#
# Feature:	gettext-runtime
# Usage:	USES=gettext-runtime or USES=gettext-runtime:ARGS
# Valid ARGS:	lib (default), build, run
#
# MAINTAINER:	portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_GETTEXT_RUNTIME_MK)
_INCLUDE_USES_GETTEXT_RUNTIME_MK=	yes

.if empty(gettext-runtime_ARGS)
gettext-runtime_ARGS=	lib
.endif

.if ${gettext-runtime_ARGS:Mlib}
LIB_DEPENDS+=	libintl.so:${PORTSDIR}/devel/gettext-runtime
.endif
.if ${gettext-runtime_ARGS:Mbuild}
BUILD_DEPENDS+=	gettext:${PORTSDIR}/devel/gettext-runtime
.endif
.if ${gettext-runtime_ARGS:Mrun}
RUN_DEPENDS+=	gettext:${PORTSDIR}/devel/gettext-runtime
.endif

.endif
