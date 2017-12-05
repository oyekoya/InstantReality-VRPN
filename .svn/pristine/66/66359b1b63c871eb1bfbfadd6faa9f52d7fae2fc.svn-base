#ifndef __SAI_C_H
#define __SAI_C_H

/**
 *
 * @file    SAI_c.h
 * @brief   Library mapping of the C-Wrapper
 *
 * @date    2010
 * @author  Fraunhofer Institut fuer Graphische Datenverarbeitung (IGD)     \n
 *          Department Virtual and Augmented Reality                        \n
 *          Fraunhoferstrasse 5                                             \n
 *          64283 Darmstadt, Germany
 *
 * Copyright (c) 2010 by Fraunhofer IGD.                                    \n
 * All rights reserved                                                      \n
 * Fraunhofer IGD provides this product without warranty of any kind and    \n
 * shall not be liable for any damages caused by the use of this product.
 *
 */

#if defined(_WIN32)
#  ifdef SAI_EXPORTS
#    define SAI_DLLMAPPING        __declspec(dllexport)
#  else
#    define SAI_DLLMAPPING        __declspec(dllimport)
#  endif
#else
#  define SAI_DLLMAPPING
#endif

#include "SAI_base.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct __SAI_SAIBrowserRef *SAI_SAIBrowserRef;
typedef struct __SAI_SAIExecutionContext *SAI_SAIExecutionContext;
typedef struct __SAI_SAIScene *SAI_SAIScene;

typedef struct __SAI_SAINodes *SAI_SAINodes;
typedef struct __SAI_SAINode *SAI_SAINode;

typedef struct __SAI_SAIFields *SAI_SAIFields;
typedef struct __SAI_SAIField *SAI_SAIField;

typedef struct __SAI_SAIRoutes *SAI_SAIRoutes;
typedef struct __SAI_SAIRoute *SAI_SAIRoute;

typedef struct __SAI_SAIScript *SAI_SAIScript;

typedef struct __SAI_SAIFieldValue *SAI_SAIFieldValue;

typedef int SAI_SAIFieldType;
typedef int SAI_SAIFieldAccess;

typedef void (*SAI_SAIRequester)(SAI_SAINode, SAI_SAIField);
typedef int SAI_SAIAction;

typedef const char * SAI_SAIString;

typedef SAI_SAIString SAI_SAIURL;
typedef SAI_SAIString SAI_SAINodeType;
typedef SAI_SAIString SAI_SAIFieldName;
typedef SAI_SAIString SAIBrowserName;
typedef SAI_SAIString SAIBrowserVersion;

typedef float SAINavSpeed;
typedef float SAIFrameRate;

//////////////////////////////////////////////////////////////////////////

SAI_DLLMAPPING SAIBrowserName SAI_SAIBrowserRef_getName(SAI_SAIBrowserRef);
SAI_DLLMAPPING SAIBrowserVersion SAI_SAIBrowserRef_getVersion(SAI_SAIBrowserRef);
SAI_DLLMAPPING SAINavSpeed SAI_SAIBrowserRef_getCurrentSpeed(SAI_SAIBrowserRef);
SAI_DLLMAPPING SAIFrameRate SAI_SAIBrowserRef_getCurrentFrameRate(SAI_SAIBrowserRef);
SAI_DLLMAPPING SAI_SAIExecutionContext SAI_SAIBrowserRef_getExecutionContext(SAI_SAIBrowserRef);
SAI_DLLMAPPING SAI_SAIScene SAI_SAIBrowserRef_loadURL(SAI_SAIBrowserRef, SAI_SAIURL);
SAI_DLLMAPPING void SAI_SAIBrowserRef_setDescription(SAI_SAIBrowserRef, SAI_SAIString);
SAI_DLLMAPPING void SAI_SAIBrowserRef_print(SAI_SAIBrowserRef, SAI_SAIString);
SAI_DLLMAPPING SAI_SAIScene SAI_SAIBrowserRef_createX3DFromURL(SAI_SAIBrowserRef, SAI_SAIURL);
SAI_DLLMAPPING void SAI_SAIBrowserRef_dispose(SAI_SAIBrowserRef);

//////////////////////////////////////////////////////////////////////////

SAI_DLLMAPPING SAI_SAINode SAI_SAIExecutionContext_getNode(SAI_SAIExecutionContext, SAI_SAIString);
SAI_DLLMAPPING SAI_SAINode SAI_SAIExecutionContext_createNode(SAI_SAIExecutionContext, SAI_SAIString);
SAI_DLLMAPPING SAI_SAINodes SAI_SAIExecutionContext_getRootNodes(SAI_SAIExecutionContext);
SAI_DLLMAPPING void SAI_SAIExecutionContext_dispose(SAI_SAIExecutionContext);

//////////////////////////////////////////////////////////////////////////

SAI_DLLMAPPING SAI_SAINode SAI_SAINodes_get(SAI_SAINodes, unsigned);
SAI_DLLMAPPING unsigned SAI_SAINodes_size(SAI_SAINodes);
SAI_DLLMAPPING void SAI_SAINodes_dispose(SAI_SAINodes);

//////////////////////////////////////////////////////////////////////////

SAI_DLLMAPPING SAI_SAIString SAI_SAINode_getTypeName(SAI_SAINode);
SAI_DLLMAPPING SAI_SAINodeType SAI_SAINode_getType(SAI_SAINode);
SAI_DLLMAPPING SAI_SAIField SAI_SAINode_getField(SAI_SAINode, SAI_SAIString);
SAI_DLLMAPPING SAI_SAIFields SAI_SAINode_getFieldDefinitions(SAI_SAINode);
SAI_DLLMAPPING void SAI_SAINode_dispose(SAI_SAINode);

//////////////////////////////////////////////////////////////////////////

SAI_DLLMAPPING SAI_SAIField SAI_SAIFields_get(SAI_SAIFields, unsigned);
SAI_DLLMAPPING unsigned SAI_SAIFields_size(SAI_SAIFields);
SAI_DLLMAPPING void SAI_SAIFields_dispose(SAI_SAIFields);

//////////////////////////////////////////////////////////////////////////

SAI_DLLMAPPING SAI_SAIFieldAccess SAI_SAIField_getAccessType(SAI_SAIField);
SAI_DLLMAPPING SAI_SAIFieldType SAI_SAIField_getType(SAI_SAIField);
SAI_DLLMAPPING SAI_SAIFieldName SAI_SAIField_getName(SAI_SAIField);
SAI_DLLMAPPING SAI_SAIFieldValue SAI_SAIField_getValue(SAI_SAIField);
SAI_DLLMAPPING void SAI_SAIField_setValue(SAI_SAIField, SAI_SAIFieldValue);
SAI_DLLMAPPING void SAI_SAIField_registerFieldInterest(SAI_SAIField, SAI_SAIAction, SAI_SAIRequester);
SAI_DLLMAPPING void SAI_SAIField_dispose(SAI_SAIField);

//////////////////////////////////////////////////////////////////////////

SAI_DLLMAPPING void SAI_SAIFieldValue_set(SAI_SAIFieldValue, SAI_SAIString);
SAI_DLLMAPPING SAI_SAIString SAI_SAIFieldValue_get(SAI_SAIFieldValue);

//////////////////////////////////////////////////////////////////////////

SAI_DLLMAPPING SAI_SAIRoute SAI_SAIRoutes_get(SAI_SAIRoutes, unsigned);
SAI_DLLMAPPING unsigned SAI_SAIRoutes_size(SAI_SAIRoutes);
SAI_DLLMAPPING void SAI_SAIRoutes_dispose(SAI_SAIRoutes);

//////////////////////////////////////////////////////////////////////////

SAI_DLLMAPPING SAI_SAINode SAI_SAIRoute_getSourceNode(SAI_SAIRoute);
SAI_DLLMAPPING SAI_SAIField SAI_SAIRoute_getSourceField(SAI_SAIRoute);
SAI_DLLMAPPING SAI_SAINode SAI_SAIRoute_getDestinationNode(SAI_SAIRoute);
SAI_DLLMAPPING SAI_SAIField SAI_SAIRoute_getDestinationField(SAI_SAIRoute);
SAI_DLLMAPPING void SAI_SAIRoute_dispose(SAI_SAIRoute);

//////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif
