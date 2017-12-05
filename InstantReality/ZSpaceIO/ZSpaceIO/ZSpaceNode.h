#ifndef __INSTANTIO_ZSpaceNODE_H
#define __INSTANTIO_ZSpaceNODE_H

#include "ZSpaceNodeDef.h"

#include <string>

#include <InstantIO/ThreadedNode.h>
#include <InstantIO/NodeType.h>
#include <InstantIO/Rotation.h>
#include <InstantIO/Vec3.h>

#include <vrpn_Tracker.h>
#include <vrpn_Button.h>

namespace InstantIO
{

template <class T> class OutSlot;


class ZSPACENODE_DLLMAPPING ZSpaceNode : public ThreadedNode
{
public:
    ZSpaceNode();
    virtual ~ZSpaceNode();

    // Create setter and getter methods for a field.
    INSTANTIO_SETTER_GETTER(float, RandMax, randMax_);

	INSTANTIO_SETTER_GETTER(std::string, ConnectionString, connectionString_);
  
    // Factory method to create an instance of ZSpaceNode.
    static Node *create();
  
    // Factory method to return the type of ZSpaceNode.
    virtual NodeType *type() const;

	static void VRPN_CALLBACK handle_button(void *userdata, const vrpn_BUTTONCB b);
    static void VRPN_CALLBACK handle_tracker(void *userdata,const vrpn_TRACKERCB t);

	vrpn_Tracker_Remote *headtracker_;
	vrpn_Tracker_Remote *handtracker_;
	vrpn_Button_Remote  *button_;
  
protected:
    // Gets called when the ZSpaceNode is enabled.
    virtual void initialize();
  
    // Gets called when the ZSpaceNode is disabled.
    virtual void shutdown();
  
    // thread method to send/receive data.
    virtual int processData ();
  
private:
	std::vector<float> headtrackerData;				//head tracker data
	std::vector<float> handtrackerData;				//hand tracker data
	std::vector<int> buttonData;				//stylus button data
    ZSpaceNode(const ZSpaceNode &);
    const ZSpaceNode &operator=(const ZSpaceNode &);

    // A "static" field of ZSpaceNode.
    float randMax_;
	
	std::string connectionString_;

    // Dynamic slots
    OutSlot<Vec3f>    *headposition_;
    OutSlot<Rotation> *headrotation_;
    OutSlot<Vec3f>    *handposition_;
    OutSlot<Rotation> *handrotation_;
	OutSlot<bool> *button_0;
	OutSlot<bool> *button_1;
	OutSlot<bool> *button_2;
  
    // Type and type attributes
    static NodeType type_;
    static const char *typeName_;
    static const char *shortDescription_;
    static const char *longDescription_;
    static const char *author_;
    static Field fields_[2];
};

} // namespace InstantIO


#endif // __INSTANTIO_ZSpaceNODE_H
