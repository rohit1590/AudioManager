/*
* This file was generated by the CommonAPI Generators.
*
 * Copyright (C) 2013, BMW AG
 *
 * \author Christian Linke, christian.linke@bmw.de BMW 2012,2013
*/
#ifndef ORG_GENIVI_AM_Routing_Control_Observer_STUB_DEFAULT_H_
#define ORG_GENIVI_AM_Routing_Control_Observer_STUB_DEFAULT_H_

#include <org/genivi/am/RoutingControlObserverStub.h>

namespace org {
namespace genivi {
namespace am {

/**
 * Provides a default implementation for RoutingControlObserverStubRemoteEvent and
 * RoutingControlObserverStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 * 
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class RoutingControlObserverStubDefault : public RoutingControlObserverStub {
 public:
    RoutingControlObserverStubDefault();

    RoutingControlObserverStubRemoteEvent* initStubAdapter(const std::shared_ptr<RoutingControlObserverStubAdapter>& stubAdapter);

    virtual const am_RoutingReady_e& getRoutingReadyAttribute();
    virtual void setRoutingReadyAttribute(am_RoutingReady_e value);


    virtual void ackConnect(am_Handle_s handle, am_connectionID_t connectionID, am_Error_e error);

    virtual void ackDisconnect(am_Handle_s handle, am_connectionID_t connectionID, am_Error_e error);

    virtual void ackSetSinkVolumeChange(am_Handle_s handle, am_volume_t volume, am_Error_e error);

    virtual void ackSetSourceVolumeChange(am_Handle_s handle, am_volume_t volume, am_Error_e error);

    virtual void ackSetSourceState(am_Handle_s handle, am_Error_e error);

    virtual void ackSetSinkSoundProperties(am_Handle_s handle, am_Error_e error);

    virtual void ackSetSinkSoundProperty(am_Handle_s handle, am_Error_e error);

    virtual void ackSetSourceSoundProperties(am_Handle_s handle, am_Error_e error);

    virtual void ackSetSourceSoundProperty(am_Handle_s handle, am_Error_e error);

    virtual void ackCrossFading(am_Handle_s handle, am_HotSink_e hotSink, am_Error_e error);

    virtual void ackSourceVolumeTick(am_Handle_s handle, am_sourceID_t sourceID, am_volume_t volume);

    virtual void ackSinkVolumeTick(am_Handle_s handle, am_sinkID_t sinkID, am_volume_t volume);

    virtual void peekDomain(std::string name, am_domainID_t& domainID, am_Error_e& error);

    virtual void registerDomain(am_Domain_s domainData, std::string returnInterface, std::string returnPath, std::string returnBusname, am_domainID_t& domainID, am_Error_e& error);

    virtual void deregisterDomain(am_domainID_t domainID, am_Error_e& error);

    virtual void registerGateway(am_Gateway_s gatewayData, am_gatewayID_t& gatewayID, am_Error_e& error);

    virtual void deregisterGateway(am_gatewayID_t gatewayID, am_Error_e& error);

    virtual void peekSink(std::string name, am_sinkID_t& sinkID, am_Error_e& error);

    virtual void registerSink(am_Sink_s sinkData, am_sinkID_t& sinkID, am_Error_e& error);

    virtual void deregisterSink(am_sinkID_t sinkID, am_Error_e& error);

    virtual void peekSource(std::string name, am_sourceID_t& sourceID, am_Error_e& error);

    virtual void registerSource(am_Source_s sourceData, am_sourceID_t& sourceID, am_Error_e& error);

    virtual void deregisterSource(am_sourceID_t sourceID, am_Error_e& error);

    virtual void registerCrossfader(am_Crossfader_s crossfaderData, am_crossfaderID_t& crossfaderID, am_Error_e& error);

    virtual void deregisterCrossfader(am_crossfaderID_t crossfaderID, am_Error_e& error);

    virtual void peekSourceClassID(std::string name, am_sourceClass_t& sourceClassID, am_Error_e& error);

    virtual void peekSinkClassID(std::string name, am_sinkClass_t& sinkClassID, am_Error_e& error);

    virtual void hookInterruptStatusChange(am_sourceID_t sourceID, am_InterruptState_e interruptState);

    virtual void hookDomainRegistrationComplete(am_domainID_t domainID);

    virtual void hookSinkAvailablityStatusChange(am_sinkID_t sinkID, am_Availability_s availability);

    virtual void hookSourceAvailablityStatusChange(am_sourceID_t sourceID, am_Availability_s availability);

    virtual void hookDomainStateChange(am_domainID_t domainID, am_DomainState_e domainState);

    virtual void hookTimingInformationChanged(am_connectionID_t connectionID, am_timeSync_t delay);

    virtual void sendChangedData(am_EarlyData_L earlyData);

    virtual void updateGateway(am_gatewayID_t gatewayID, am_ConnectionFormat_L listSourceFormats, am_ConnectionFormat_L listSinkFormats, am_Convertion_L convertionMatrix, am_Error_e& error);

    virtual void updateSink(am_sinkID_t sinkID, am_sinkClass_t sinkClassID, am_SoundProperty_L listSoundProperties, am_ConnectionFormat_L listConnectionFormats, am_MainSoundProperty_L listMainSoundProperties, am_Error_e& error);

    virtual void updateSource(am_sourceID_t sourceID, am_sourceClass_t sourceClassID, am_SoundProperty_L listSoundProperties, am_ConnectionFormat_L listConnectionFormats, am_MainSoundProperty_L listMainSoundProperties, am_Error_e& error);

    virtual void ackSetVolumes(am_Handle_s handle, am_Volumes_L listvolumes, am_Error_e error);

    virtual void ackSinkNotificationConfiguration(am_Handle_s handle, am_Error_e error);

    virtual void ackSourceNotificationConfiguration(am_Handle_s handle, am_Error_e error);

    virtual void hookSinkNotificationDataChange(am_sinkID_t sinkID, am_NotificationPayload_s payload);

    virtual void hookSourceNotificationDataChange(am_sourceID_t sourceID, am_NotificationPayload_s payload);

    virtual void confirmRoutingRundown(std::string domainName);

    

 protected:
    virtual void onRemoteRoutingReadyAttributeChanged();
    virtual bool trySetRoutingReadyAttribute(am_RoutingReady_e value);
    virtual bool validateRoutingReadyAttributeRequestedValue(const am_RoutingReady_e& value);

    
 private:
    class RemoteEventHandler: public RoutingControlObserverStubRemoteEvent {
     public:
        RemoteEventHandler(RoutingControlObserverStubDefault* defaultStub);

        virtual bool onRemoteSetRoutingReadyAttribute(am_RoutingReady_e value);
        virtual void onRemoteRoutingReadyAttributeChanged();


     private:
        RoutingControlObserverStubDefault* defaultStub_;
    };

    RemoteEventHandler remoteEventHandler_;
    std::shared_ptr<RoutingControlObserverStubAdapter> stubAdapter_;

    am_RoutingReady_e routingReadyAttributeValue_;
};

} // namespace am
} // namespace genivi
} // namespace org

#endif // ORG_GENIVI_AM_Routing_Control_Observer_STUB_DEFAULT_H_
