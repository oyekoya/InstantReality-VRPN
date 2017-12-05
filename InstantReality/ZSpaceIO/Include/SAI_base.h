#ifndef __SAI_BASE_H__
#define __SAI_BASE_H__

/**
 *
 * @file    SAI_base.h
 * @brief   Pure virtual base of the SAI interfaces
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
#    define SAI_DLLMAPPING __declspec(dllexport)
#  else
#    define SAI_DLLMAPPING __declspec(dllimport)
#  endif
#else
#  define SAI_DLLMAPPING
#endif

namespace SAI {

  class SAIFieldValue;
  class SAIBrowser;
  class SAIExecutionContext;
  class SAIScene;
  class SAINodes;
  class SAINode;
  class SAIField;
  class SAIFields;
  class SAIRoute;

  /**
   * @brief   Definition for a Callback function
   */
  typedef void (*SAIRequester)(SAINode*, SAIField*);

  typedef const char * SAIString;

  typedef SAIString SAIURL;
  typedef SAIString SAIFieldName;
  typedef SAIString SAINodeType;
  typedef SAIString SAIBrowserName;
  typedef SAIString SAIBrowserVersion;

  typedef float SAINavSpeed;
  typedef float SAIFrameRate;

  typedef unsigned int SAIIndex;

  /**
   * @brief Enumeration of field access types. This enumeration defines the constants returned by "Field::getAccessType".
   * @see   getAccessType
   */
  typedef enum
  {
    initializeOnly  = 1,
    inputOnly       = 2,
    outputOnly      = 3,
    inputOutput     = 4,
  }
  SAIFieldAccess;

  /**
   * @brief Enumeration of field data types. This enumeration defines the constants returned by "Field::getType".
   * @see getType
   */
  typedef enum
  {
    SAI_SFBOOL      = 1,
    SAI_MFBOOL      = 2,
    SAI_SFINT32     = 3,
    SAI_MFINT32     = 4,
    SAI_SFFLOAT     = 5,
    SAI_MFFLOAT     = 6,
    SAI_SFDOUBLE    = 7,
    SAI_MFDOUBLE    = 8,
    SAI_SFTIME      = 9,
    SAI_MFTIME      = 10,

    SAI_SFNODE      = 11,
    SAI_MFNODE      = 12,
    SAI_SFVEC2F     = 13,
    SAI_MFVEC2F     = 14,
    SAI_SFVEC3F     = 15,
    SAI_MFVEC3F     = 16,
    SAI_SFVEC3D     = 17,
    SAI_MFVEC3D     = 18,
    SAI_SFROTATION  = 19,
    SAI_MFROTATION  = 20,

    SAI_SFCOLOR     = 21,
    SAI_MFCOLOR     = 22,
    SAI_SFCOLORRGBA = 23,
    SAI_MFCOLORRGBA = 24,
    SAI_SFIMAGE     = 25,
    SAI_MFIMAGE     = 26,
    SAI_SFSTRING    = 27,
    SAI_MFSTRING    = 28,
    SAI_SFVEC2D     = 29,
    SAI_MFVEC2D     = 30,

    SAI_SFVEC4D     = 31,
    SAI_MFVEC4D     = 32,
    SAI_SFVEC4F     = 33,
    SAI_MFVEC4F     = 34,
    SAI_SFMATRIX3D  = 35,
    SAI_MFMATRIX3D  = 36,
    SAI_SFMATRIX3F  = 37,
    SAI_MFMATRIX3F  = 38,
    SAI_SFMATRIX4D  = 39,
    SAI_MFMATRIX4D  = 40,

    SAI_SFMATRIX4F  = 41,
    SAI_MFMATRIX4F  = 42
  }
  SAIFieldType;

  /**
   * @brief Enumeration of encoding types. This enumeration defines the constants returned by "SAI_ExecutionContext_getEncoding".
   * @see SAI_ExecutionContext_getEncoding
   */
  typedef enum
  {
    NO_SCENE          = 0,
    SCRIPTED_ENCODING = 1,
    ASCII_ENCODING    = 2,
    VRML_ENCODING     = 3,
    XML_ENCODING      = 4,
    BINARY_ENCODING   = 5,
    BIFS_ENCODING     = 6,
    LAST_STD_ENCODING = 127
  }
  SAIEncoding;

  /**
   * @namespace   SAI::Base
   * @brief       Base Classes of the SAI
   */
  namespace Base {

    class SAIFieldValue;
    class SAIBrowser;
    class SAIExecutionContext;
    class SAIScene;
    class SAINodes;
    class SAINode;
    class SAIField;
    class SAIFields;
    class SAIRoute;

    /** 
     * @brief SAIFieldValue represents the value to be set or to be returned of an SAIFieldType.
     *
     * SAIFieldValue (5.2.16)
     *
     * @see getValue
     * @see setValue
     */
    class SAIFieldValue
    {
    public:
      /**
       * @brief   Gets the value in form of a string
       * @return  SAIString   The value
       */
      virtual SAIString get() = 0;

      /**
       * @brief  sets the value by a string
       * @param  SAIString   The value
       */
      virtual void set(SAIString) = 0;
    };

    /**
     * @brief Helper for accessing a vector of values
     */
    template <typename type>
    class SAIVector
    {
    public:
      /**
       * @brief   Returns the reference to a indexed Value
       * @param   SAIIndex    The Index of the wanted value 
       * @return  type        The reference to the value
       */
      virtual type *get(SAIIndex) = 0;

      /**
       * @brief   Returns the size of the vector
       * @return  SAIIndex    The number of holden values
       */
      virtual SAIIndex size() = 0;

      /**
       * @brief   Deletes the vector
       */
      virtual void dispose() = 0;

      /**
       * @brief   Wrapper for get methode
       * @param   SAIIndex    The Index of the wanted value 
       * @return  type        The reference to the value
       */
      inline type *operator [] (SAIIndex index) { return get(index); }
    };

    /**
     * @brief   The following services can be requested from a browser.
     *
     * Browser services (6.3)
     */
    class SAIBrowserRef
    {
    public:
      /**
       * @brief   The getName service returns the name of the browser.
       * @return  The Browser Name
       */
      virtual SAIBrowserName getName() = 0;

      /**
       * @brief   The getVersion service returns the current version of the browser application.
       * @return  The Browser Version
       */
      virtual SAIBrowserVersion getVersion() = 0;

      /**
       * @brief   The getCurrentSpeed service returns the navigation speed of the current world.
       *
       * The current speed is the average navigation speed for the currently
       * bound NavigationInfo node in meters per second in the coordinate
       * system of the currently bound viewpoint.
       *
       * @return   The Navigation Speed (m/s)
       */
      virtual SAINavSpeed getCurrentSpeed() = 0;

      /**
       * @brief The getCurrentFrameRate service returns the current frame display rate of the browser.
       * @return    The frame rate (f/s)
       */
      virtual SAIFrameRate getCurrentFrameRate() = 0;

      // virtual SAIProfileDeclarations getSupportedProfiles() = 0;
      // virtual SAIProfileDeclaration getProfile(const SAIString &) = 0;
      // virtual SAIComponentDeclarations getSupportedComponents() = 0;
      // virtual SAIComponentDeclaration getComponent() = 0;

      /**
       * @brief   The getExecutionContext service returns the current execution context.
       *
       * If used in an internal interaction, this service returns
       * the execution context in which the containing node exists.
       * When used in an external interaction, this service returns the
       * current top-level scene.
       * The execution context is the base form of a scene, but only
       * provides access to the local nodes, PROTOs and routes.
       * Depending on the place in the scene graph, the returned type may
       * be an instance of SAIScene allowing the user to use the greater
       * capabilities.
       *
       * @return    The current ExecutionContext
       * @see       SAIExecutionContext
       */
      virtual SAIExecutionContext *getExecutionContext() = 0;

      // virtual SAIScene createScene() = 0;
      // virtual void replaceWorld() = 0;
      // virtual SAIScene importDocument() = 0;

      /**
       * @brief   The loadURL service inserts the content identified by the URL
       *
       * TODO
       *
       * @return    The generated SAIScene
       * @see       SAIExecutionContext, SAIScene
       */
      virtual SAIScene *loadURL(SAIURL) = 0;

      /**
       * @brief   The browser description title set to the new description.
       *
       * This will be the title in a window title bar.
       *
       * @param   SAIString   Title of the window
       */
      virtual void setDescription(SAIString) = 0;

      // virtual SAIScene createX3DFromString(const SAIString &) = 0;
      // virtual SAIScene createX3DFromStream(const SAIStream &) = 0;
      // virtual SAIScene *createX3DFromURL(SAIURL) = 0;
      // virtual void updateControl() = 0;
      // virtual registerBrowserInterest() = 0;
      // virtual getRenderingProperties() = 0;
      // virtual getBrowserProperties() = 0;
      // virtual changeViewpoint() = 0;

      /**
       * @brief   The print service prints a message to the browser's console.
       *
       * User code may call this service at any time, without restriction,
       * unless the browser reference has been disposed of.
       *
       * @param   SAIString   Text to print to the console
       */
      virtual void print(SAIString) = 0;

      /**
       * @brief  Deletes the object
       *
       * The dispose service indicates that the client is about to exit
       * this session and the browser is free to dispose of any resources
       * that this client may have consumed.
       */
      virtual void dispose() = 0;
    };

    /**
     * @brief Execution context services
     */
    class SAIExecutionContext
    {
    public:
      // virtual SAIString getSpecificationVersion() = 0;
      // virtual SAIEncoding getEncoding() = 0;
      // virtual SAIProfileDeclaration getProfile() = 0;
      // virtual SAIComponentDeclarations getComponents() = 0;
      // virtual SAIURL getWorldURL() = 0;

      /**
       * @brief   The getNode service searches for a node based on specified criteria and returns an identifier for the node.
       *
       * The SAIString is to identify the name of the node that has been
       * marked with one of the naming statements DEF, IMPORT or EXPORT in
       * the currently loaded X3D scene or previously added with an
       * namedNodeHandling request.
       *
       * @param   SAIString           Name of the Node to find
       * @return  SAINode             Pointer to the found Node
       */
      virtual SAINode *getNode(SAIString) = 0;

      /**
       * @brief   The createNode service creates a new default instance of the node.
       *
       * SAIString value containing the name of an X3D node type.
       * The availability of the node is defined by the containing
       * scene's profile and component declarations. The name shall only
       * refer to a built-in node and shall not be used to create
       * instances of PROTOs or EXTERNPROTOs.
       *
       * @param   SAIString     Type name of the node to create
       * @return  SAINode       Pointer to the created Node
       */
      virtual SAINode *createNode(SAIString) = 0;

      // virtual createProto() = 0;
      // virtual namedNodeHandling() = 0;
      // virtual getProtoDeclaration() = 0;
      // virtual protoDeclarationHandling() = 0;
      // virtual getExternProtoDeclaration() = 0;
      // virtual externprotoDeclarationHandling() = 0;

      /**
       * @brief   The getRootNodes service returns a listing of the current root nodes of the execution context.
       * @return  SAINodes   List of root nodes
       */
      virtual SAINodes *getRootNodes() = 0;

      // virtual SAIRoutes getRoutes() = 0;
      // virtual dynamicRouteHandling() = 0;

      /**
       * @brief  Deletes the object
       *
       * The dispose service specifies that the client has no further
       * interest in the resource represented by this execution context.
       * The browser may now take whatever action is necessary to reclaim
       * any resources consumed by this execution context, now or at any
       * time in the future.
       */
      virtual void dispose() = 0;
    };

    /**
     * @brief   A scene is an extension of the execution context services with additional services provided.
     *
     * Scene services (6.5)
     */
    class SAIScene : virtual public SAIExecutionContext
    {
    public:
      // virtual SAIString getMetaData() = 0;
      // virtual void setMetaData(const SAIString &) = 0;
      // virtual void namedNodeHandling() = 0;
      // virtual void rootNodeHandling() = 0;
    };

    /**
     * @brief   The following services can be requested of an individual node.
     *
     * Each service requires an identifier for that node.
     * Node services (6.6)
     */
    class SAINode
    {
    public:
      /**
       * @brief   The getTypeName service returns the name of the type of the referenced node.
       * 
       * If the node represents a PROTO node instance,
       * the type name returned is the name of the PROTO declaration.
       *
       * @return  SAIString   The typename of the node
       */
      virtual SAIString getTypeName() = 0;

      /**
       * @brief   The getType service returns the type indicator for the referenced node.
       *
       * The type indicator is either the type defined
       * for the basic node types in the X3D specification, or the PROTO
       * type name if it is a prototyped node.
       * 
       * @return  SAIString   The typename of the node
       */
      virtual SAINodeType getType() = 0;

      /**
       * @brief   The getField service returns a field identifier so that operations can be performed on the node properties.
       * @param   SAIString   Name of the field to search for
       * @return  SAIField    Pointer to the searched field
       */
      virtual SAIField *getField(SAIString) = 0;

      /**
       * @brief   The getFieldDefinitions service returns a list of all the fields of the referenced node.
       * @return  SAIFields    A list containing all fields of the node
       */
      virtual SAIFields *getFieldDefinitions() = 0;

      /**
       * @brief  Deletes the object
       *
       * The dispose node service indicates that the client has no further
       * interest in the resource represented by this node.
       * The browser may take whatever action is necessary to reclaim any
       * resources consumed by this node, now or at any time in the future.
       * Disposing of a node does not remove the node from the scene graph
       * but rather removes any local information per client to it.
       * The underlying X3D node representation is only disposed if no
       * other applications or scene graph structures contain references
       * to this node.
       */
      virtual void dispose() = 0;
    };

    /**
     * @brief   Container, holding multiple Nodes
     */
    class SAINodes : public SAIVector<SAINode>
    {
    };

    /**
     * @brief   The following are services that can be requested of individual fields of a node.
     *
     * Field services (6.7)
     * If the node from which a field was retrieved has
     * been disposed, field services are still permitted to operate
     * providing that the field reference has been obtained before
     * disposing of the node.
     */
    class SAIField
    {
    public:
      enum SAIRegisterFieldInterestAction
      {
        AddInterest,
        RemoveInterest
      };

      /**
       * @brief   The getAccessType service returns the access type for the specified field of the referenced node.
       * @return  SAIFieldAccess    The type to access the field
       */
      virtual SAIFieldAccess getAccessType() = 0;

      /**
       * @brief   The getType field service returns the type for the specified field of the referenced node.
       * @return  SAIFieldType    The value type of this field
       */
      virtual SAIFieldType getType() = 0;

      /**
       * @brief   If supported by the implementation, the getName field service returns the name of the field as it was requested from the node.
       * @return  SAIFieldName    The name of the field inside the node
       */
      virtual SAIFieldName getName() = 0;

      /**
       * @brief   The getValue field service returns the value represented by the specified field as it exists in the world.
       *
       * This represents the current value of the field at the time of
       * the request. The value of the field may be a node if the field
       * represents an MFNode or SFNode.
       *
       * @return  SAIFieldValue   The current value of the field
       */
      virtual SAIFieldValue *getValue() = 0;

      /**
       * @brief   The setValue field service sets the value of the specified field.
       *
       * The value of the field may be an SAINode value if the field
       * represents an MFNode or SFNode. It is permitted to send a null
       * to a node or field in order to clear the value from that field.
       *
       * @param   SAIFieldValue   The new value to set
       */
      virtual void setValue(SAIFieldValue *) = 0;

      /**
       * @brief   The registerFieldInterest service nominates the requester as the receiver of all SAIFieldEvents.
       * @param   SAIRegisterFieldInterestAction    Register/Remove interest
       * @param   SAIRequester                      Callback Function
       */
      virtual void registerFieldInterest(SAIRegisterFieldInterestAction, SAIRequester) = 0;

      /**
       * @brief  Deletes the object
       *
       * The dispose field service indicates that the client has no further
       * interest in the resource represented by this field.
       * The browser may take whatever action is necessary to reclaim any
       * resources consumed by this field, now or at any time in the future.
       */
      virtual void dispose() = 0;
    };

    /**
     * @brief   Container, holding multiple Fields
     */
    class SAIFields : public SAIVector<SAIField>
    {
    };

    /**
     * @brief   Routes between Fields or Nodes
     *
     * Route services (6.8)
     */
    class SAIRoute
    {
    public:
      /**
       * @brief   The getSourceNode service returns the source node of the specified route.
       * @return    The source Node
       * @see       SAINode
       */
      virtual SAINode *getSourceNode() = 0;

      /**
       * @brief   The getSourceField service returns a reference to the source field of the specified route.
       * @return    The source Field
       * @see       SAIField
       */
      virtual SAIField *getSourceField() = 0;

      /**
       * @brief The getDestinationNode service returns the destination node of the specified route.
       * @return    The destination Node
       * @see       SAINode
       */
      virtual SAINode *getDestinationNode() = 0;

      /**
       * @brief   The getDestinationField service returns a reference to the destination field of the specified route.
       * @return    The destination Field
       * @see       SAIField
       */
      virtual SAIField *getDestinationField() = 0;

      /**
       * @brief  Deletes the object
       *
       * The dispose route service indicates that the client has no further
       * interest in the resource represented by this route. Disposing of
       * a route does not remove the route from the scene graph.
       */
      virtual void dispose() = 0;
    };

    /**
     * @brief   Container, holding multiple Routes
     */
    class SAIRoutes : public SAIVector<SAIRoute>
    {
    };

    /**
     * @brief   Not Implemented
     *
     * Prototype services (6.9)
     */
    class SAIPrototype
    {
    public:
      // virtual isExternproto
      // virtual createInstance
      // virtual getFieldDefinitions
      // virtual checkLoadState
      // virtual requestImmediateLoad
    };

    /**
     * @brief The services specified here allow an application to identify the configuration of the current world.
     *
     * Configuration services (6.10)
     */
    class SAIConfiguration
    {
    public:
      // virtual getComponentName
      // virtual getComponentLevel
      // virtual getProfileName
      // virtual getProfileComponents
      // virtual getProvderName
    };

    /**
     * @brief   When an author provides the executable content of a script, certain conventions shall be satisfied.
     *
     * Services provided by script content (6.11)
     *
     * Script content shall be required to run identically regardless of
     * language used to author the content. All services are defined at
     * the user's discretion.
     *
     * @see   SAI::SAIScript
     */
    class SAIScript
    {
    public:
      /**
       * @brief   The setBrowser service passes to the script implementation code the the SAIBrowserRef value to be used.
       * @param   SAIBrowserRef   Pointer to the BrowserRef
       */
      virtual void setBrowser(SAIBrowserRef*) = 0;

      /**
       * @brief   The setFields script service passes in the list of fields declared in this script node instance.
       *
       * It also passes in the external view
       * of the containing script node so that the user may add and remove
       * routes to the script directly.
       * The SAIField instances represent all of the fields of a script,
       * including the pre-defined fields.
       *
       * @param   SAINode     External view to the Script (this pointer)
       * @param   SAIFields   List of fields in this script node instance
       */
      virtual void setFields(SAINode*, SAIFields*) = 0;

      /**
       * @brief   The initialize script service provides notification to the script
       *
       * All basic initialization has been completed and that the
       * user code is active in the scene graph. At this point,
       * the user code may access script field values and change its state.
       */
      virtual void initialize() = 0;

      /**
       * @brief   Provides notification that the browser is about to start the event cascade processing.
       */
      virtual void prepareEvents() = 0;

      /**
       * @brief   Provides notification that the current event cascade processing has finished.
       *
       * The containing node is now allowed to make updates to the scene graph.
       *
       * @param   SAIBrowserRef   Pointer to the BrowserRef
       * @see     SAIBrowserRef
       */
      virtual void eventsProcessed(SAIBrowserRef*) = 0;

      /**
       * @brief  Deletes the object
       *
       * The shutdown service provides notification that the user code
       * has been disposed of by the containing node.
       * This may be due to the complete shutdown of the browser,
       * the loaded world changing or the containing node changing
       * the user code to another implementation.
       * After this service request has been completed,
       * user code will no longer be functional or executed.
       */
      virtual void shutdown() = 0;
    };

    /**
     * @brief   Matrix objects represent the standard mathematic matrix capabilities using double precision numbers and column-major order.
     *
     * Matrix services (6.12)
     */
    class SAIMatrix
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
}

#endif
