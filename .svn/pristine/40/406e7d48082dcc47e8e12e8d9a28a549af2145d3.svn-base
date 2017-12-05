#ifndef SCAPI_H
#define SCAPI_H

#include <SAI/SAI.h>

/**
 * @file SCAPI.h
 * SCAPI: The simple C API for interacting with the Avalon scene-graph via C
 */

#ifdef __cplusplus
extern "C" 
{
#endif

# if defined(COMPILE_WITH_DLL) && defined(WIN32)
#  if defined(AVALONVIEWPASSIVE_DLL)
#   define AVALON_PASSIVE_DLLMAPPING __declspec(dllexport)
#  else
#   define AVALON_PASSIVE_DLLMAPPING __declspec(dllimport)
#  endif
# else
#   define AVALON_PASSIVE_DLLMAPPING
# endif

#define SCAPI_VERSION_MAJOR 0           //!< The major version of the SCAPI
#define SCAPI_VERSION_MINOR 3           //!< The minor version of the SCAPI

/**
 * Definition of a callback function
 *
 * @param  data            Data passed from the calling function
 * @param  size            Size of the data
 * @param  clientData      Pointer to client data
 */
typedef void (*Callback)( const char *data, 
                          int  size,
                          void  *clientData);

/**
 * Creates the rendering context from a file or url
 *
 * @param  url       To the file to load
 * @retval ID        Unique context ID
 * @retval 0         On error
*/
unsigned AVALON_PASSIVE_DLLMAPPING 
av_sys_createContext ( const char *url );

/**
 * Destroy a single Context
 *
 * @param ID     Unique context ID
 */
void AVALON_PASSIVE_DLLMAPPING 
av_sys_destroyContext    ( unsigned contextID );

/**
 * Reload the scene of an existing context
 *
 * @param  contextID   Unique context ID
 * @param  url         The URL to the file to load
 * @retval ID          Of the context
 * @retval 0           On error
 */
unsigned AVALON_PASSIVE_DLLMAPPING 
av_sys_loadContext   ( unsigned contextID,
                       const char *url );

/**
 * Gets the SAI BrowserInterface
 *
 * @param  contextID          Unique context ID
 * @retval SAI_SAIBrowserRef  Reference to the SAI Browser
 * @retval 0                  On error
 */
SAI_SAIBrowserRef AVALON_PASSIVE_DLLMAPPING
av_sys_getBrowser(unsigned contextID);

/**
 * Sets the value of a field
 *
 * @param  contextID     Unique context ID
 * @param  nodeName      Name of the node
 * @param  field         Name of the field
 * @param  value         Pointer to the value to set
 * @retval 1             On success
 * @retval 0             On error
 */
unsigned AVALON_PASSIVE_DLLMAPPING 
av_sys_setValue      ( unsigned contextID, 
                       const char *nodeName,
                       const char *field,
                       const char *value );
                       
/**
 * The mode for setting a value
 *
 * @see av_sys_addValue
 */
enum AddParam {
  CLEAR_AP,   /*!< Overwrites the value */
  ADD_AP      /*!< Adds the value */
};

/**
 * Sets or adds the value of a field
 *
 * @see AddParam
 *
 * @param  contextID     Unique context ID
 * @param  nodeName      Name of the node
 * @param  field         Name of the field
 * @param  addParam      Overwrite or add the value
 * @param  value         Pointer to the source value to set
 * @retval 1             On success
 * @retval 0             On error
 */
unsigned AVALON_PASSIVE_DLLMAPPING 
av_sys_addValue      ( unsigned contextID, 
                       const char *nodeName,
                       const char *field,
                       enum AddParam addParam,
                       const char *value );

/**
 * Returns the value of a field
 *
 * @param  contextID     Unique Context ID
 * @param  nodeName      Name of the node
 * @param  field         Name of the field
 * @return               The value as a string
 */
const char AVALON_PASSIVE_DLLMAPPING 
*av_sys_getValue      ( unsigned contextID, 
                       const char *nodeName,
                       const char *field);

/**
 * Adds a listener to a field
 *
 * @param  contextID     Unique Context ID
 * @param  nodeName      Name of the node
 * @param  field         Name of the field
 * @param  cb            Callback function to call on events
 * @param  clientData    Client data passed to the callback function
 * @retval ID            Unique identifier of the listener
 * @retval 0             On error
 */
unsigned AVALON_PASSIVE_DLLMAPPING 
av_sys_addListener   ( unsigned contextID, 
                       const char *nodeName,
                       const char *field,
                       Callback cb, 
                       void *clientData );

/**
 * Removes an existing listener
 *
 * @param  listenerID    Unique Context ID
 * @retval 0             On error
 */
unsigned AVALON_PASSIVE_DLLMAPPING 
av_sys_removeListener ( unsigned listenerID );

/**
 * Runs a frame
 *
 * @param  contextID     Unique Context ID
 * @return               The frame time if desiredFrameRate > 0
 * @retval -1            On error (no Context)
 */
double AVALON_PASSIVE_DLLMAPPING 
av_sys_runFrame   ( unsigned contextID );

/**
 * Resizes the rendering window
 *
 * @param  contextID     Unique Context ID
 * @param  x             Horizontal resolution
 * @param  y             Vertical resolution
 */
void AVALON_PASSIVE_DLLMAPPING 
av_win_resize       ( unsigned constextID, 
                      int x, int y);

/**
 * Send mouse move events to the context
 *
 * @param  contextID     Unique Context ID
 * @param  x             Horizontal resolution
 * @param  y             Vertical resolution
 */
void AVALON_PASSIVE_DLLMAPPING 
av_win_mouseMove    ( unsigned contextID, 
                      int x, int y);

/**
 * Send mouse press events to the context
 *
 * @see av_win_mouseRelease
 * @param  contextID     Unique Context ID
 * @param  buttonStat    The ID to the button pressed
 * @param  x             Horizontal resolution
 * @param  y             Vertical resolution
 */
void AVALON_PASSIVE_DLLMAPPING 
av_win_mousePress   ( unsigned contextID, 
                      int buttonStat, int x, int y);

/**
 * Send mouse release events to the context
 *
 * @see av_win_mousePress
 * @param  contextID     Unique Context ID
 * @param  buttonStat    The ID to the button released
 * @param  x             Horizontal resolution
 * @param  y             Vertical resolution
 */
void AVALON_PASSIVE_DLLMAPPING 
av_win_mouseRelease ( unsigned contextID,
                      int buttonStat, int x, int y);

/**
 * Send keyboard press events to the context
 *
 * @see av_win_keyRelease
 * @param  contextID     Unique Context ID
 * @param  keyCode       Pressed Key
 */
void AVALON_PASSIVE_DLLMAPPING 
av_win_keyPress     ( unsigned contextID,
                      unsigned keyCode );

/**
 * Send keyboard release events to the context
 *
 * @see av_win_keyPress
 * @param  contextID     Unique Context ID
 * @param  keyCode       Released Key
 */
void AVALON_PASSIVE_DLLMAPPING 
av_win_keyRelease   ( unsigned contextID,
                      unsigned keyCode );

/**
 * Adds a callback for logging
 *
 * @param  cb            Callback function to call on logging events
 * @param  clientData    Client data passed to the callback function
 */
void AVALON_PASSIVE_DLLMAPPING 
av_sys_initLog    ( Callback  cb, 
                    void *clientData);

/**
 * Removes the logging callback
 */
void AVALON_PASSIVE_DLLMAPPING 
av_sys_destroyLog    ();


#ifdef __cplusplus
} // extern "C"
#endif

#endif // SCAPI_H
