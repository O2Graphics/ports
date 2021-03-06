$OpenBSD: patch-src_ssl_sock_c,v 1.6 2017/02/01 15:49:34 naddy Exp $
--- src/ssl_sock.c.orig	2017-04-04 09:21:44 UTC
+++ src/ssl_sock.c
@@ -2810,7 +2810,7 @@ int ssl_sock_handshake(struct connection
 				if (!errno && conn->flags & CO_FL_WAIT_L4_CONN)
 					conn->flags &= ~CO_FL_WAIT_L4_CONN;
 				if (!conn->err_code) {
-					if (!((SSL *)conn->xprt_ctx)->packet_length) {
+					if (SSL_state((SSL *)conn->xprt_ctx) == SSL_ST_BEFORE) {
 						if (!errno) {
 							if (conn->xprt_st & SSL_SOCK_RECV_HEARTBEAT)
 								conn->err_code = CO_ER_SSL_HANDSHAKE_HB;
@@ -2877,7 +2877,7 @@ int ssl_sock_handshake(struct connection
 			if (!errno && conn->flags & CO_FL_WAIT_L4_CONN)
 				conn->flags &= ~CO_FL_WAIT_L4_CONN;
 
-			if (!((SSL *)conn->xprt_ctx)->packet_length) {
+			if (SSL_state((SSL *)conn->xprt_ctx) == SSL_ST_BEFORE) {
 				if (!errno) {
 					if (conn->xprt_st & SSL_SOCK_RECV_HEARTBEAT)
 						conn->err_code = CO_ER_SSL_HANDSHAKE_HB;
