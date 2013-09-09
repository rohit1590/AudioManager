/*
* This file was generated by the CommonAPI Generators.
*
 * Copyright (C) 2013, BMW AG
 *
 * \author Christian Linke, christian.linke@bmw.de BMW 2012,2013
*/
#ifndef ORG_GENIVI_AM_Routing_Control_Observer_DBUS_PROXY_H_
#define ORG_GENIVI_AM_Routing_Control_Observer_DBUS_PROXY_H_

#include <org/genivi/am/RoutingControlObserverProxyBase.h>

#define COMMONAPI_INTERNAL_COMPILATION

#include <CommonAPI/DBus/DBusFactory.h>
#include <CommonAPI/DBus/DBusProxy.h>
#include <CommonAPI/DBus/DBusAttribute.h>

#undef COMMONAPI_INTERNAL_COMPILATION

#include <string>

namespace org {
namespace genivi {
namespace am {

class RoutingControlObserverDBusProxy: virtual public RoutingControlObserverProxyBase, virtual public CommonAPI::DBus::DBusProxy {
 public:
    RoutingControlObserverDBusProxy(
                    const std::string& commonApiAddress,
                    const std::string& interfaceName,
                    const std::string& busName,
                    const std::string& objectPath,
                    const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyconnection);

    virtual ~RoutingControlObserverDBusProxy() { }

    virtual RoutingReadyAttribute& getRoutingReadyAttribute();



    virtual void ackConnect(const am_Handle_s& handle, const am_connectionID_t& connectionID, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackConnectAsync(const am_Handle_s& handle, const am_connectionID_t& connectionID, const am_Error_e& error, AckConnectAsyncCallback callback);

    virtual void ackDisconnect(const am_Handle_s& handle, const am_connectionID_t& connectionID, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackDisconnectAsync(const am_Handle_s& handle, const am_connectionID_t& connectionID, const am_Error_e& error, AckDisconnectAsyncCallback callback);

    virtual void ackSetSinkVolumeChange(const am_Handle_s& handle, const am_volume_t& volume, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSetSinkVolumeChangeAsync(const am_Handle_s& handle, const am_volume_t& volume, const am_Error_e& error, AckSetSinkVolumeChangeAsyncCallback callback);

    virtual void ackSetSourceVolumeChange(const am_Handle_s& handle, const am_volume_t& volume, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSetSourceVolumeChangeAsync(const am_Handle_s& handle, const am_volume_t& volume, const am_Error_e& error, AckSetSourceVolumeChangeAsyncCallback callback);

    virtual void ackSetSourceState(const am_Handle_s& handle, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSetSourceStateAsync(const am_Handle_s& handle, const am_Error_e& error, AckSetSourceStateAsyncCallback callback);

    virtual void ackSetSinkSoundProperties(const am_Handle_s& handle, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSetSinkSoundPropertiesAsync(const am_Handle_s& handle, const am_Error_e& error, AckSetSinkSoundPropertiesAsyncCallback callback);

    virtual void ackSetSinkSoundProperty(const am_Handle_s& handle, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSetSinkSoundPropertyAsync(const am_Handle_s& handle, const am_Error_e& error, AckSetSinkSoundPropertyAsyncCallback callback);

    virtual void ackSetSourceSoundProperties(const am_Handle_s& handle, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSetSourceSoundPropertiesAsync(const am_Handle_s& handle, const am_Error_e& error, AckSetSourceSoundPropertiesAsyncCallback callback);

    virtual void ackSetSourceSoundProperty(const am_Handle_s& handle, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSetSourceSoundPropertyAsync(const am_Handle_s& handle, const am_Error_e& error, AckSetSourceSoundPropertyAsyncCallback callback);

    virtual void ackCrossFading(const am_Handle_s& handle, const am_HotSink_e& hotSink, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackCrossFadingAsync(const am_Handle_s& handle, const am_HotSink_e& hotSink, const am_Error_e& error, AckCrossFadingAsyncCallback callback);

    virtual void ackSourceVolumeTick(const am_Handle_s& handle, const am_sourceID_t& sourceID, const am_volume_t& volume, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSourceVolumeTickAsync(const am_Handle_s& handle, const am_sourceID_t& sourceID, const am_volume_t& volume, AckSourceVolumeTickAsyncCallback callback);

    virtual void ackSinkVolumeTick(const am_Handle_s& handle, const am_sinkID_t& sinkID, const am_volume_t& volume, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSinkVolumeTickAsync(const am_Handle_s& handle, const am_sinkID_t& sinkID, const am_volume_t& volume, AckSinkVolumeTickAsyncCallback callback);

    virtual void peekDomain(const std::string& name, CommonAPI::CallStatus& callStatus, am_domainID_t& domainID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> peekDomainAsync(const std::string& name, PeekDomainAsyncCallback callback);

    virtual void registerDomain(const am_Domain_s& domainData, const std::string& returnInterface, const std::string& returnPath, const std::string& returnBusname, CommonAPI::CallStatus& callStatus, am_domainID_t& domainID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> registerDomainAsync(const am_Domain_s& domainData, const std::string& returnInterface, const std::string& returnPath, const std::string& returnBusname, RegisterDomainAsyncCallback callback);

    virtual void deregisterDomain(const am_domainID_t& domainID, CommonAPI::CallStatus& callStatus, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> deregisterDomainAsync(const am_domainID_t& domainID, DeregisterDomainAsyncCallback callback);

    virtual void registerGateway(const am_Gateway_s& gatewayData, CommonAPI::CallStatus& callStatus, am_gatewayID_t& gatewayID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> registerGatewayAsync(const am_Gateway_s& gatewayData, RegisterGatewayAsyncCallback callback);

    virtual void deregisterGateway(const am_gatewayID_t& gatewayID, CommonAPI::CallStatus& callStatus, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> deregisterGatewayAsync(const am_gatewayID_t& gatewayID, DeregisterGatewayAsyncCallback callback);

    virtual void peekSink(const std::string& name, CommonAPI::CallStatus& callStatus, am_sinkID_t& sinkID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> peekSinkAsync(const std::string& name, PeekSinkAsyncCallback callback);

    virtual void registerSink(const am_Sink_s& sinkData, CommonAPI::CallStatus& callStatus, am_sinkID_t& sinkID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> registerSinkAsync(const am_Sink_s& sinkData, RegisterSinkAsyncCallback callback);

    virtual void deregisterSink(const am_sinkID_t& sinkID, CommonAPI::CallStatus& callStatus, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> deregisterSinkAsync(const am_sinkID_t& sinkID, DeregisterSinkAsyncCallback callback);

    virtual void peekSource(const std::string& name, CommonAPI::CallStatus& callStatus, am_sourceID_t& sourceID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> peekSourceAsync(const std::string& name, PeekSourceAsyncCallback callback);

    virtual void registerSource(const am_Source_s& sourceData, CommonAPI::CallStatus& callStatus, am_sourceID_t& sourceID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> registerSourceAsync(const am_Source_s& sourceData, RegisterSourceAsyncCallback callback);

    virtual void deregisterSource(const am_sourceID_t& sourceID, CommonAPI::CallStatus& callStatus, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> deregisterSourceAsync(const am_sourceID_t& sourceID, DeregisterSourceAsyncCallback callback);

    virtual void registerCrossfader(const am_Crossfader_s& crossfaderData, CommonAPI::CallStatus& callStatus, am_crossfaderID_t& crossfaderID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> registerCrossfaderAsync(const am_Crossfader_s& crossfaderData, RegisterCrossfaderAsyncCallback callback);

    virtual void deregisterCrossfader(const am_crossfaderID_t& crossfaderID, CommonAPI::CallStatus& callStatus, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> deregisterCrossfaderAsync(const am_crossfaderID_t& crossfaderID, DeregisterCrossfaderAsyncCallback callback);

    virtual void peekSourceClassID(const std::string& name, CommonAPI::CallStatus& callStatus, am_sourceClass_t& sourceClassID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> peekSourceClassIDAsync(const std::string& name, PeekSourceClassIDAsyncCallback callback);

    virtual void peekSinkClassID(const std::string& name, CommonAPI::CallStatus& callStatus, am_sinkClass_t& sinkClassID, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> peekSinkClassIDAsync(const std::string& name, PeekSinkClassIDAsyncCallback callback);

    virtual void hookInterruptStatusChange(const am_sourceID_t& sourceID, const am_InterruptState_e& interruptState, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> hookInterruptStatusChangeAsync(const am_sourceID_t& sourceID, const am_InterruptState_e& interruptState, HookInterruptStatusChangeAsyncCallback callback);

    virtual void hookDomainRegistrationComplete(const am_domainID_t& domainID, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> hookDomainRegistrationCompleteAsync(const am_domainID_t& domainID, HookDomainRegistrationCompleteAsyncCallback callback);

    virtual void hookSinkAvailablityStatusChange(const am_sinkID_t& sinkID, const am_Availability_s& availability, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> hookSinkAvailablityStatusChangeAsync(const am_sinkID_t& sinkID, const am_Availability_s& availability, HookSinkAvailablityStatusChangeAsyncCallback callback);

    virtual void hookSourceAvailablityStatusChange(const am_sourceID_t& sourceID, const am_Availability_s& availability, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> hookSourceAvailablityStatusChangeAsync(const am_sourceID_t& sourceID, const am_Availability_s& availability, HookSourceAvailablityStatusChangeAsyncCallback callback);

    virtual void hookDomainStateChange(const am_domainID_t& domainID, const am_DomainState_e& domainState, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> hookDomainStateChangeAsync(const am_domainID_t& domainID, const am_DomainState_e& domainState, HookDomainStateChangeAsyncCallback callback);

    virtual void hookTimingInformationChanged(const am_connectionID_t& connectionID, const am_timeSync_t& delay, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> hookTimingInformationChangedAsync(const am_connectionID_t& connectionID, const am_timeSync_t& delay, HookTimingInformationChangedAsyncCallback callback);

    virtual void sendChangedData(const am_EarlyData_L& earlyData, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> sendChangedDataAsync(const am_EarlyData_L& earlyData, SendChangedDataAsyncCallback callback);

    virtual void updateGateway(const am_gatewayID_t& gatewayID, const am_ConnectionFormat_L& listSourceFormats, const am_ConnectionFormat_L& listSinkFormats, const am_Convertion_L& convertionMatrix, CommonAPI::CallStatus& callStatus, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> updateGatewayAsync(const am_gatewayID_t& gatewayID, const am_ConnectionFormat_L& listSourceFormats, const am_ConnectionFormat_L& listSinkFormats, const am_Convertion_L& convertionMatrix, UpdateGatewayAsyncCallback callback);

    virtual void updateSink(const am_sinkID_t& sinkID, const am_sinkClass_t& sinkClassID, const am_SoundProperty_L& listSoundProperties, const am_ConnectionFormat_L& listConnectionFormats, const am_MainSoundProperty_L& listMainSoundProperties, CommonAPI::CallStatus& callStatus, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> updateSinkAsync(const am_sinkID_t& sinkID, const am_sinkClass_t& sinkClassID, const am_SoundProperty_L& listSoundProperties, const am_ConnectionFormat_L& listConnectionFormats, const am_MainSoundProperty_L& listMainSoundProperties, UpdateSinkAsyncCallback callback);

    virtual void updateSource(const am_sourceID_t& sourceID, const am_sourceClass_t& sourceClassID, const am_SoundProperty_L& listSoundProperties, const am_ConnectionFormat_L& listConnectionFormats, const am_MainSoundProperty_L& listMainSoundProperties, CommonAPI::CallStatus& callStatus, am_Error_e& error);
    virtual std::future<CommonAPI::CallStatus> updateSourceAsync(const am_sourceID_t& sourceID, const am_sourceClass_t& sourceClassID, const am_SoundProperty_L& listSoundProperties, const am_ConnectionFormat_L& listConnectionFormats, const am_MainSoundProperty_L& listMainSoundProperties, UpdateSourceAsyncCallback callback);

    virtual void ackSetVolumes(const am_Handle_s& handle, const am_Volumes_L& listvolumes, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSetVolumesAsync(const am_Handle_s& handle, const am_Volumes_L& listvolumes, const am_Error_e& error, AckSetVolumesAsyncCallback callback);

    virtual void ackSinkNotificationConfiguration(const am_Handle_s& handle, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSinkNotificationConfigurationAsync(const am_Handle_s& handle, const am_Error_e& error, AckSinkNotificationConfigurationAsyncCallback callback);

    virtual void ackSourceNotificationConfiguration(const am_Handle_s& handle, const am_Error_e& error, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> ackSourceNotificationConfigurationAsync(const am_Handle_s& handle, const am_Error_e& error, AckSourceNotificationConfigurationAsyncCallback callback);

    virtual void hookSinkNotificationDataChange(const am_sinkID_t& sinkID, const am_NotificationPayload_s& payload, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> hookSinkNotificationDataChangeAsync(const am_sinkID_t& sinkID, const am_NotificationPayload_s& payload, HookSinkNotificationDataChangeAsyncCallback callback);

    virtual void hookSourceNotificationDataChange(const am_sourceID_t& sourceID, const am_NotificationPayload_s& payload, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> hookSourceNotificationDataChangeAsync(const am_sourceID_t& sourceID, const am_NotificationPayload_s& payload, HookSourceNotificationDataChangeAsyncCallback callback);

    virtual void confirmRoutingRundown(const std::string& domainName, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> confirmRoutingRundownAsync(const std::string& domainName, ConfirmRoutingRundownAsyncCallback callback);
    
    virtual void getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const;

 private:
    CommonAPI::DBus::DBusObservableAttribute<CommonAPI::DBus::DBusAttribute<RoutingReadyAttribute>> routingReady_;

};

} // namespace am
} // namespace genivi
} // namespace org

#endif // ORG_GENIVI_AM_Routing_Control_Observer_DBUS_PROXY_H_
