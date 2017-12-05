#ifndef __SAI_SCRIPT_H__
#define __SAI_SCRIPT_H__

/**
 *
 * @file    SAI_script.h
 * @brief   C++ Wrapper for user-implemented Script Nodes
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
 * @see     http://www.web3d.org/x3d/specifications/ISO-IEC-19775-2-X3D-SceneAccessInterface/Part02/servRef.html#ServicesByScriptContent
 * @see     SAI::Base::SAIScript
 *
 */

#include "SAI_base.h"

#if defined(_WIN32)
#  define SAI_SCRIPT_DLLMAPPING __declspec(dllexport)
#else
#  define SAI_SCRIPT_DLLMAPPING
#endif

/**
 * @brief Pointer to the Instance of the Script implementation
 */
extern SAI::Base::SAIScript *script;

#ifdef __cplusplus
extern "C" {
#endif

SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_setBrowser(SAI_SAIBrowserRef);
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_setFields(SAI_SAINode, SAI_SAIFields);
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_initialize();
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_prepareEvents();
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_eventsProcessed(SAI_SAIBrowserRef);
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_shutdown();

#ifdef __cplusplus
}
#endif

SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_setBrowser(SAI_SAIBrowserRef browser)
{
  script->setBrowser((SAI::Base::SAIBrowserRef*)browser);
}
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_setFields(SAI_SAINode node, SAI_SAIFields fields)
{
  script->setFields((SAI::Base::SAINode*)node, (SAI::Base::SAIFields*)fields);
}
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_initialize()
{
  script->initialize();
}
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_prepareEvents()
{
  script->prepareEvents();
}
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_eventsProcessed(SAI_SAIBrowserRef browser)
{
  script->eventsProcessed((SAI::Base::SAIBrowserRef*)browser);
}
SAI_SCRIPT_DLLMAPPING void SAI_SAIScript_shutdown()
{
  script->shutdown();
}

#endif
