#ifndef __SAI_H__
#define __SAI_H__

/**
 *
 * @file    SAI.h
 * @brief   C-Wrapper for the SAI
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
 *
 */

/**
 *
 * \if SAI_DOC
 *
 *    \mainpage Scene access interface
 *
 *      Implementation of the X3D "Scene access interface" (SAI)
 *
 *      @author   Timm.Drevensek@igd.fraunhofer.de
 *      @see      SAI::Base
 *      @see      http://www.web3d.org/x3d/specifications/ISO-IEC-19775-2-X3D-SceneAccessInterface
 *
 * \endif
 *
 */

#include "SAI_c.h"
#include "SAI_base.h"

/**
 * @namespace   SAI
 * @brief       Wrapper Namespace for to use with a binary compatible SAI interface
 */
namespace SAI {

  class SAIFieldValue: public Base::SAIFieldValue
  {
  public:
    SAIFieldValue(Base::SAIFieldValue *field_value)                               : field_value((SAI_SAIFieldValue)field_value) {}

    operator SAIString ()                                                         { return get(); }
    void operator = (SAIString value)                                             { set(value); }

    virtual SAIString get()                                                       { return (SAIString) SAI_SAIFieldValue_get(field_value); }
    virtual void set(SAIString value)                                             { SAI_SAIFieldValue_set(field_value, value); }

  protected:
    SAI_SAIFieldValue field_value;
  };

/*
  template <>
  SAIFieldValue<float> : public SAIFieldValue
  {
  public:
    operator const float ();
    void operator = (const float &)                                               { return (float) SAI_SAIFieldValue_float(); }
  };
*/

  class SAIBrowserRef: public Base::SAIBrowserRef
  {
  public:
    SAIBrowserRef()                                                               : browser_(0) {}

    SAIBrowserRef(Base::SAIBrowserRef *browser)                                   : browser_((SAI_SAIBrowserRef)browser) {}
    SAIBrowserRef(SAI_SAIBrowserRef browser)                                      : browser_(browser) {}
    void operator = (Base::SAIBrowserRef *browser)                                { if(browser_) dispose(); browser_ = (SAI_SAIBrowserRef)browser; }
    void operator = (SAI_SAIBrowserRef browser)                                   { if(browser_) dispose(); browser_ = browser; }

    virtual ~SAIBrowserRef()                                                      { dispose(); }

    virtual SAIBrowserName getName()                                              { return (SAIBrowserName) SAI_SAIBrowserRef_getName(browser_); }
    virtual SAIBrowserVersion getVersion()                                        { return (SAIBrowserVersion) SAI_SAIBrowserRef_getVersion(browser_); }
    virtual SAINavSpeed getCurrentSpeed()                                         { return (SAINavSpeed) SAI_SAIBrowserRef_getCurrentSpeed(browser_); }
    virtual SAIFrameRate getCurrentFrameRate()                                    { return (SAIFrameRate) SAI_SAIBrowserRef_getCurrentFrameRate(browser_); }
    // virtual SAIProfileDeclarations getSupportedProfiles();
    // virtual SAIProfileDeclaration getProfile(const SAIString &);
    // virtual SAIComponentDeclarations getSupportedComponents();
    // virtual SAIComponentDeclaration getComponent();
    virtual Base::SAIExecutionContext *getExecutionContext()                      { return (Base::SAIExecutionContext*) SAI_SAIBrowserRef_getExecutionContext(browser_); }
    // virtual SAIScene createScene();
    // virtual void replaceWorld();
    // virtual SAIScene importDocument();
    virtual Base::SAIScene *loadURL(SAIURL url)                                   { return (Base::SAIScene*) SAI_SAIBrowserRef_loadURL(browser_, url); }
    virtual void setDescription(SAIString description)                            { SAI_SAIBrowserRef_setDescription(browser_, description); }
    // virtual SAIScene createX3DFromString(const SAIString &);
    // virtual SAIScene createX3DFromStream(const SAIStream &);
    // virtual Base::SAIScene *createX3DFromURL(SAIURL url)                          { return (Base::SAIScene*) SAI_SAIBrowserRef_createX3DFromURL(browser, url); }
    // virtual void updateControl();
    // virtual registerBrowserInterest();
    // virtual getRenderingProperties();
    // virtual getBrowserProperties();
    // virtual changeViewpoint();
    virtual void print(SAIString string)                                          { SAI_SAIBrowserRef_print(browser_, string); }
    virtual void dispose()                                                        { SAI_SAIBrowserRef_dispose(browser_); }

  private:
    SAI_SAIBrowserRef browser_;
  };

  class SAIExecutionContext: public Base::SAIExecutionContext
  {
  public:
    SAIExecutionContext()                                                         : context_(0) {}

    SAIExecutionContext(Base::SAIExecutionContext *context)                       : context_((SAI_SAIExecutionContext)context) {}
    SAIExecutionContext(SAI_SAIExecutionContext context)                          : context_(context) {}
    void operator = (Base::SAIExecutionContext *context)                          { if(context_) dispose(); context_ = (SAI_SAIExecutionContext)context; }
    void operator = (SAI_SAIExecutionContext context)                             { if(context_) dispose(); context_ = context; }

    virtual ~SAIExecutionContext()                                                { dispose(); }

    // virtual SAIString getSpecificationVersion();
    // virtual SAIEncoding getEncoding();
    // virtual SAIProfileDeclaration getProfile();
    // virtual SAIComponentDeclarations getComponents();
    // virtual SAIURL getWorldURL();
    virtual Base::SAINode *getNode(SAIString node_name)                           { return (Base::SAINode*) SAI_SAIExecutionContext_getNode(context_, node_name); }
    virtual Base::SAINode *createNode(SAIString type_name)                        { return (Base::SAINode*) SAI_SAIExecutionContext_createNode(context_, type_name); }
    // virtual createProto();
    // virtual namedNodeHandling();
    // virtual getProtoDeclaration();
    // virtual protoDeclarationHandling();
    // virtual getExternProtoDeclaration();
    // virtual externprotoDeclarationHandling();
    virtual Base::SAINodes *getRootNodes()                                        { return (Base::SAINodes*) SAI_SAIExecutionContext_getRootNodes(context_); }
    // virtual SAIRoutes getRoutes();
    // virtual dynamicRouteHandling();
    virtual void dispose()                                                        { SAI_SAIExecutionContext_dispose(context_); }

  private:
    SAI_SAIExecutionContext context_;
  };

  class SAIScene: public Base::SAIScene
  {
  public:
    SAIScene()                                                                    : scene_(0) {}

    SAIScene(Base::SAIScene *scene)                                               : scene_((SAI_SAIScene)scene) {}
    SAIScene(SAI_SAIScene scene)                                                  : scene_(scene) {}
    void operator = (Base::SAIScene *scene)                                       { if(scene_) dispose(); scene_ = (SAI_SAIScene)scene; }
    void operator = (SAI_SAIScene scene)                                          { if(scene_) dispose(); scene_ = scene; }

    virtual ~SAIScene()                                                           { dispose(); }

    // virtual SAIString getMetaData();
    // virtual void setMetaData(const SAIString &);
    // virtual void namedNodeHandling();
    // virtual void rootNodeHandling();

    // virtual SAIString getSpecificationVersion();
    // virtual SAIEncoding getEncoding();
    // virtual SAIProfileDeclaration getProfile();
    // virtual SAIComponentDeclarations getComponents();
    // virtual SAIURL getWorldURL();
    virtual Base::SAINode *getNode(SAIString node_name)                           { return (Base::SAINode*) SAI_SAIExecutionContext_getNode(context_, node_name); }
    virtual Base::SAINode *createNode(SAIString type_name)                        { return (Base::SAINode*) SAI_SAIExecutionContext_createNode(context_, type_name); }
    // virtual createProto();
    // virtual namedNodeHandling();
    // virtual getProtoDeclaration();
    // virtual protoDeclarationHandling();
    // virtual getExternProtoDeclaration();
    // virtual externprotoDeclarationHandling();
    // virtual getRootNodes();
    // virtual SAIRoutes getRoutes();
    // virtual dynamicRouteHandling();
    virtual void dispose()                                                        { SAI_SAIExecutionContext_dispose(context_); }

  private:
    union
    {
      SAI_SAIScene scene_;
      SAI_SAIExecutionContext context_;
    };
  };

  class SAINode: public Base::SAINode
  {
  public:
    SAINode()                                                                     : node_(0) {}

    SAINode(Base::SAINode *node)                                                  : node_((SAI_SAINode)node) {}
    SAINode(SAI_SAINode node)                                                     : node_(node) {}
    void operator = (Base::SAINode *node)                                         { if(node_) dispose(); node_ = (SAI_SAINode)node; }
    void operator = (SAI_SAINode node)                                            { if(node_) dispose(); node_ = node; }

    virtual ~SAINode()                                                            { if(node_) dispose(); }

    virtual SAIString getTypeName()                                               { return SAI_SAINode_getTypeName(node_); }
    virtual SAINodeType getType()                                                 { return SAI_SAINode_getType(node_); }
    virtual Base::SAIField *getField(SAIString field_name)                        { return (Base::SAIField*) SAI_SAINode_getField(node_, field_name); }
    virtual Base::SAIFields *getFieldDefinitions()                                { return (Base::SAIFields*) SAI_SAINode_getFieldDefinitions(node_); }
    virtual void dispose()                                                        { SAI_SAINode_dispose(node_); }

  private:
    SAI_SAINode node_;
  };

  class SAINodes: public Base::SAINodes
  {
  public:
    SAINodes(Base::SAINodes *nodes)                                               : nodes_((SAI_SAINodes)nodes) {}
    virtual ~SAINodes()                                                           { dispose(); }

    virtual Base::SAINode *get(SAIIndex index)                                    { return (Base::SAINode*) SAI_SAINodes_get(nodes_, index); }
    virtual SAIIndex size()                                                       { return SAI_SAINodes_size(nodes_); }
    virtual void dispose()                                                        { SAI_SAINodes_dispose(nodes_); }

  private:
    SAI_SAINodes nodes_;
  };

  class SAIField: public Base::SAIField
  {
  public:
    SAIField()                                                                    : field_(0) {}

    SAIField(Base::SAIField *field)                                               : field_((SAI_SAIField)field) {}
    SAIField(SAI_SAIField field)                                                  : field_(field) {}
    void operator = (Base::SAIField *field)                                       { if(field_) dispose(); field_ = (SAI_SAIField)field; }
    void operator = (SAI_SAIField field)                                          { if(field_) dispose(); field_ = field; }

    virtual ~SAIField()                                                           { if(field_) dispose(); }

    virtual SAIFieldAccess getAccessType()                                        { return (SAIFieldAccess) SAI_SAIField_getAccessType(field_); }
    virtual SAIFieldType getType()                                                { return (SAIFieldType) SAI_SAIField_getType(field_); }
    virtual SAIFieldName getName()                                                { return (SAIFieldName) SAI_SAIField_getName(field_); }
    virtual Base::SAIFieldValue *getValue()                                       { return (Base::SAIFieldValue*) SAI_SAIField_getValue(field_); }
    virtual void setValue(Base::SAIFieldValue *value)                             { SAI_SAIField_setValue(field_, (SAI_SAIFieldValue)value); }
    virtual void registerFieldInterest(SAIRegisterFieldInterestAction action, SAIRequester request)    
                                                                                  { SAI_SAIField_registerFieldInterest(field_, (SAI_SAIAction)action, (SAI_SAIRequester)request); }
    virtual void dispose()                                                        { SAI_SAIField_dispose(field_); }

  private:
    SAI_SAIField field_;
  };

  class SAIFields: public Base::SAIFields
  {
  public:
    SAIFields()                                                                   : fields_(0) {}
    SAIFields(Base::SAIFields *fields)                                            : fields_((SAI_SAIFields)fields) {}
    void operator = (Base::SAIFields *fields)                                     { if(fields_) dispose(); fields_ = (SAI_SAIFields)fields; }
    virtual ~SAIFields()                                                          { if(fields_) dispose(); }

    virtual Base::SAIField *get(SAIIndex index)                                   { return (Base::SAIField*) SAI_SAIFields_get(fields_, index); }
    virtual SAIIndex size()                                                       { return SAI_SAIFields_size(fields_); }
    virtual void dispose()                                                        { SAI_SAIFields_dispose(fields_); }

  private:
    SAI_SAIFields fields_;
  };

  class SAIRoute: public Base::SAIRoute
  {
    SAIRoute()                                                                   : route_(0) {}

    SAIRoute(Base::SAIRoute *route)                                               : route_((SAI_SAIRoute)route) {}
    SAIRoute(SAI_SAIRoute route)                                                  : route_(route) {}
    void operator = (Base::SAIRoute *route)                                       { if(route_) dispose(); route_ = (SAI_SAIRoute)route; }
    void operator = (SAI_SAIRoute route)                                          { if(route_) dispose(); route_ = route; }

    virtual ~SAIRoute()                                                           { if(route_) dispose(); }

    virtual SAINode *getSourceNode()                                              { return (SAINode*) SAI_SAIRoute_getSourceNode(route_); }
    virtual SAIField *getSourceField()                                            { return (SAIField*) SAI_SAIRoute_getSourceField(route_); }
    virtual SAINode *getDestinationNode()                                         { return (SAINode*) SAI_SAIRoute_getDestinationNode(route_); }
    virtual SAIField *getDestinationField()                                       { return (SAIField*) SAI_SAIRoute_getDestinationField(route_); }
    virtual void dispose()                                                        { SAI_SAIRoute_dispose(route_); }

  private:
    SAI_SAIRoute route_;
  };

  class SAIRoutes: public Base::SAIRoutes
  {
  public:
    SAIRoutes(Base::SAIRoutes *routes)                                            : routes_((SAI_SAIRoutes)routes) {}
    virtual ~SAIRoutes()                                                          { dispose(); }

    virtual Base::SAIRoute *get(SAIIndex index)                                   { return (Base::SAIRoute*) SAI_SAIRoutes_get(routes_, index); }
    virtual SAIIndex size()                                                       { return SAI_SAIRoutes_size(routes_); }
    virtual void dispose()                                                        { SAI_SAIRoutes_dispose(routes_); }

  private:
    SAI_SAIRoutes routes_;
  };

  class SAIPrototype: public Base::SAIPrototype
  {
  public:
    // virtual isExternproto
    // virtual createInstance
    // virtual getFieldDefinitions
    // virtual checkLoadState
    // virtual requestImmediateLoad
  };

  class SAIConfiguration: public Base::SAIConfiguration
  {
  public:
    // virtual getComponentName
    // virtual getComponentLevel
    // virtual getProfileName
    // virtual getProfileComponents
    // virtual getProvderName
  };

  class SAIMatrix: public Base::SAIMatrix
  {
  public:
    // virtual set
    // virtual get
    // virtual inverse
    // virtual transpose
    // virtual multiply
    // virtual multiplyWithVector
  };

}

#endif
