/*
* This file was generated by the CommonAPI Generators.
*
 * Copyright (C) 2013, BMW AG
 *
 * \author Christian Linke, christian.linke@bmw.de BMW 2012,2013
*/
#ifndef ORG_GENIVI_AM_Routing_Control_STUB_H_
#define ORG_GENIVI_AM_Routing_Control_STUB_H_



#include <org/genivi/am.h>

#include "RoutingControl.h"

#define COMMONAPI_INTERNAL_COMPILATION

#include <CommonAPI/InputStream.h>
#include <CommonAPI/OutputStream.h>
#include <CommonAPI/SerializableStruct.h>
#include <cstdint>
#include <vector>

#include <CommonAPI/Stub.h>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace org {
namespace genivi {
namespace am {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service RoutingControl. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class RoutingControlStubAdapter: virtual public CommonAPI::StubAdapter, public RoutingControl {
 public:

};


/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for RoutingControl.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class RoutingControlStubRemoteEvent {
 public:
    virtual ~RoutingControlStubRemoteEvent() { }

};


/**
 * Defines the interface that must be implemented by any class that should provide
 * the service RoutingControl to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class RoutingControlStub : public CommonAPI::Stub<RoutingControlStubAdapter , RoutingControlStubRemoteEvent> {
 public:
    virtual ~RoutingControlStub() { }


    /// This is the method that will be called on remote calls on the method asyncAbort.
    virtual void asyncAbort(am_Handle_s handle) = 0;
    /// This is the method that will be called on remote calls on the method asyncConnect.
    virtual void asyncConnect(am_Handle_s handle, am_connectionID_t connectionID, am_sourceID_t sourceID, am_sinkID_t sinkID, am_ConnectionFormat_pe connectionFormat) = 0;
    /// This is the method that will be called on remote calls on the method asyncDisconnect.
    virtual void asyncDisconnect(am_Handle_s handle, am_connectionID_t connectionID) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetSinkVolume.
    virtual void asyncSetSinkVolume(am_Handle_s handle, am_sinkID_t sinkID, am_volume_t volume, am_RampType_pe ramp, am_time_t time) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetSourceVolume.
    virtual void asyncSetSourceVolume(am_Handle_s handle, am_sourceID_t sourceID, am_volume_t volume, am_RampType_pe ramp, am_time_t time) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetSourceState.
    virtual void asyncSetSourceState(am_Handle_s handle, am_sourceID_t sourceID, am_SourceState_e state) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetSinkSoundProperties.
    virtual void asyncSetSinkSoundProperties(am_Handle_s handle, am_sinkID_t sinkID, am_SoundProperty_L listSoundProperties) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetSinkSoundProperty.
    virtual void asyncSetSinkSoundProperty(am_Handle_s handle, am_sinkID_t sinkID, am_SoundProperty_s soundProperty) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetSourceSoundProperties.
    virtual void asyncSetSourceSoundProperties(am_Handle_s handle, am_sourceID_t sourceID, am_SoundProperty_L listSoundProperties) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetSourceSoundProperty.
    virtual void asyncSetSourceSoundProperty(am_Handle_s handle, am_sourceID_t sourceID, am_SoundProperty_s soundProperty) = 0;
    /// This is the method that will be called on remote calls on the method asyncCrossFade.
    virtual void asyncCrossFade(am_Handle_s handle, am_crossfaderID_t crossfaderID, am_HotSink_e hotSink, am_RampType_pe rampType, am_time_t time) = 0;
    /// This is the method that will be called on remote calls on the method setDomainState.
    virtual void setDomainState(am_domainID_t domainID, am_DomainState_e domainState, am_Error_e& error) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetVolumes.
    virtual void asyncSetVolumes(am_Handle_s handle, am_Volumes_L volumes) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetSinkNotificationConfiguration.
    virtual void asyncSetSinkNotificationConfiguration(am_Handle_s handle, am_sinkID_t sinkID, am_NotificationConfiguration_s notificationConfiguration) = 0;
    /// This is the method that will be called on remote calls on the method asyncSetSourceNotificationConfiguration.
    virtual void asyncSetSourceNotificationConfiguration(am_Handle_s handle, am_sourceID_t sourceID, am_NotificationConfiguration_s notificationConfiguration) = 0;
    
};

} // namespace am
} // namespace genivi
} // namespace org

#endif // ORG_GENIVI_AM_Routing_Control_STUB_H_
