#ifndef __URLSTREAMHANDLER_H
#define __URLSTREAMHANDLER_H


// ========================================================================= //
//                                                                           //
// Filename: URLStreamHandler.h                                              //
//                                                                           //
//                                                                           //
// Author: Fraunhofer Institut fuer Graphische Datenverarbeitung (IGD)       //
//         Department Virtual and Augmented Reality                          //
//         Fraunhoferstrasse 5                                               //
//         64283 Darmstadt, Germany                                          //
//                                                                           //
// Rights: Copyright (c) 2009 by Fraunhofer IGD.                             //
//         All rights reserved.                                              //
//         Fraunhofer IGD provides this product without warranty of any kind //
//         and shall not be liable for any damages caused by the use         //
//         of this product.                                                  //
//                                                                           //
// ========================================================================= //


/**
 * @file
 * A brief file description.
 * A more elaborated file description.
 */

#if defined(_WIN32)
#  ifdef Hermes_EXPORTS
#    define IR_DLLMAPPING __declspec(dllexport)
#  else
#    define IR_DLLMAPPING __declspec(dllimport)
#  endif
#else
#  define IR_DLLMAPPING
#endif


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Error codes returned by some functions.
 */
typedef enum
{
	IR_SUCCESS = 0,
	IR_INVALID_URL = 1,
	IR_UNKNOWN_HOST = 2,
	IR_CONNECTION_FAILED = 3,
	IR_HANDSHAKE_FAILED = 4,
	IR_FILE_DOES_NOT_EXIST = 5,
	IR_NO_ACCESS_RIGHTS = 6
}
IR_ErrorCode;

/** Forward declaration. */
typedef struct IR_URLStreamHandler_ IR_URLStreamHandler;

/**
 * URL structure. Keeps the different parts parsed by the
 * URLStreamHandler. A typical URL has the following components:
 * <protocol>://<userInfo>@<host>:<port><path>?<query>#<ref>
 */
typedef struct
{
	/** The "protocol" part of the URL, e.g. http or ftp */
	const char *protocol;

	/** The "userInfo" part of the URL. */
	const char *userInfo;

	/** The "host" part of the URL. */
	const char *host;

	/** The "port" part of the URL. */
	int port;

	/** The "path" part of the URL. */
	const char *path;

	/** The "query" part of the URL. */
	const char *query;

	/** The "ref" part of the URL. */
	const char *ref;

	/** The handler that is able to cope with this URL. */
	IR_URLStreamHandler *handler;
}
IR_URL;

/** Forward declaration. */
typedef struct IR_URLConnection_ IR_URLConnection;

/**
 * Starts the connection to a URL resource.
 * @param connection The connection object.
 * @return An error code.
 */
typedef int IR_URLConnection_connect(IR_URLConnection *connection);

/**
 * Returns the size (in bytes) of a resource.
 * @param connection The connection object.
 * @return The size (in bytes) or -1 when the size is unknown.
 */
typedef long IR_URLConnection_getContentLength(IR_URLConnection *connection);

/**
 * Returns the mime type of a resource.
 * @param connection The connection object.
 * @return The mime type of the resource of 0 if the mime type is
 * unknown. The caller has to free() this string.
 */
typedef char *IR_URLConnection_getContentType(IR_URLConnection *connection);

/**
 * Reads data.
 * @param connection The connection object.
 * @param buf The buffer the read data gets written to.
 * @param nbyte The size of the buffer in bytes.
 * @return The number of bytes actually read.
 */
typedef unsigned long IR_URLConnection_read(IR_URLConnection *connection, void *buf, unsigned long nbyte);

/**
 * Closes a connection to a URL resource.
 * @param connection The connection object.
 */
typedef void IR_URLConnection_close(IR_URLConnection *close);

typedef struct IR_URLConnection_
{
	/** The size of this structure, in bytes */
	unsigned long size;

	/** Pointer to the connect method */
	IR_URLConnection_connect *connect;

	/** Pointer to the getContentLength method */
	IR_URLConnection_getContentLength *getContentLength;

	/** Pointer to the getContentType method */
	IR_URLConnection_getContentType *getContentType;

	/** Pointer to the read method */
	IR_URLConnection_read *read;

	/** Pointer to the close method */
	IR_URLConnection_close *close;
}
IR_URLConnection;

/**
 * Returns the default port number.
 * @return The default port number, or -1 if the is no default
 * port number.
 */
typedef int IR_URLStreamHandler_getDefaultPort();

/**
 * Parses a given URL.
 * @param url The base URL used to resolve relative URLs.
 * @param spec The URL string.
 * @return An error code.
 */
typedef IR_ErrorCode IR_URLStreamHandler_parseURL(IR_URL *url, const char *spec, int start, int limit);

/**
 * Transforms an URL structure into a string.
 * @param url The URL structure.
 * @return A string representation of the URL structure. The caller has to free()
 * that string.
 */
typedef char *IR_URLStreamHandler_toExternalForm(const IR_URL *url);

/**
 * Initiate a connection with the URL. For the given URL structure, returns
 * a URLConnection object that can be used to access the contents of the URL.
 * @param url The URL.
 * @return The URLConnection object that can be used to access the contents
 * of the URL. The caller is responsible to free() this object.
 */
typedef IR_URLConnection *IR_URLStreamHandler_openConnection(const IR_URL *url);

/**
 * URLStreamHandler structure.
 */
typedef struct IR_URLStreamHandler_
{
	/** The size of this structure, in bytes */
	unsigned long size;

	/** Pointer to the getDefaultPort method */
	IR_URLStreamHandler_getDefaultPort *getDefaultPort;

	/** Pointer to the parseURL method */
	IR_URLStreamHandler_parseURL *parseURL;

	/** Pointer to the toExternalForm method */
	IR_URLStreamHandler_toExternalForm *toExternalForm;

	/** Pointer to the openConnection method */
	IR_URLStreamHandler_openConnection *openConnection;
}
IR_URLStreamHandler;

/**
 * Register a handler for a protocol.
 * @param protocol The protocol.
 * @param handler The handler that is able to handle the protocol.
 */
IR_DLLMAPPING void IR_URLStreamHandlerFactory_registerHandler(const char *protocol, IR_URLStreamHandler *handler);

/**
 * Unregister a handler for a protocol.
 * @param protocol The protocol.
 * @param handler The handler that is able to handle the protocol.
 */
IR_DLLMAPPING void IR_URLStreamHandlerFactory_unregisterHandler(const char *protocol, IR_URLStreamHandler *handler);


#ifdef __cplusplus
}
#endif


#endif // __URLSTREAMHANDLER_H
