# $FreeBSD: head/Mk/Uses/sqlite.mk 405716 2016-01-10 16:15:29Z bapt $
#
# Provide support for SQLite
# Feature:	sqlite
# Usage:	USES=	sqlite[:version]
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_SQLITE_MK)
_INCLUDE_USES_SQLITE_MK=	yes

.if !empty(sqlite_ARGS)
SQLITE_VER=	${sqlite_ARGS}
.endif
SQLITE_VER?=	3

.if ${SQLITE_VER} == 3
LIB_DEPENDS+=	libsqlite3.so:${PORTSDIR}/databases/sqlite${SQLITE_VER}
.elif ${SQLITE_VER} == 2
LIB_DEPENDS+=	libsqlite.so:${PORTSDIR}/databases/sqlite${SQLITE_VER}
.else
IGNORE=		cannot install: unknown SQLite version: ${SQLITE_VER}
.endif

.endif
