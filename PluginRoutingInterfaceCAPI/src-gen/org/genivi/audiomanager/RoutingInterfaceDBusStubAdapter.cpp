/*
* This file was generated by the CommonAPI Generators.
*
 *  Copyright (c) 2012 BMW
 *
 *  \author Aleksandar Donchev, aleksander.donchev@partner.bmw.de BMW 2013
 *
 *  \copyright
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction,
 *  including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 *  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *  For further information see http://www.genivi.org/.
*/
#include "RoutingInterfaceDBusStubAdapter.h"
#include <org/genivi/audiomanager/RoutingInterface.h>

namespace org {
namespace genivi {
namespace audiomanager {

std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> createRoutingInterfaceDBusStubAdapter(
                   const std::string& commonApiAddress,
                   const std::string& interfaceName,
                   const std::string& busName,
                   const std::string& objectPath,
                   const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyConnection,
                   const std::shared_ptr<CommonAPI::StubBase>& stubBase) {
    return std::make_shared<RoutingInterfaceDBusStubAdapter>(commonApiAddress, interfaceName, busName, objectPath, dbusProxyConnection, stubBase);
}

__attribute__((constructor)) void registerRoutingInterfaceDBusStubAdapter(void) {
    CommonAPI::DBus::DBusFactory::registerAdapterFactoryMethod(RoutingInterface::getInterfaceId(),
                                                               &createRoutingInterfaceDBusStubAdapter);
}

RoutingInterfaceDBusStubAdapter::RoutingInterfaceDBusStubAdapter(
        const std::string& commonApiAddress,
        const std::string& dbusInterfaceName,
        const std::string& dbusBusName,
        const std::string& dbusObjectPath,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusConnection,
        const std::shared_ptr<CommonAPI::StubBase>& stub):
        RoutingInterfaceDBusStubAdapterHelper(commonApiAddress, dbusInterfaceName, dbusBusName, dbusObjectPath, dbusConnection, std::dynamic_pointer_cast<RoutingInterfaceStub>(stub)) {
}

const char* RoutingInterfaceDBusStubAdapter::getMethodsDBusIntrospectionXmlData() const {
    return
        "<signal name=\"setRoutingReady\">\n"
        "</signal>\n"
        "<signal name=\"setRoutingRundown\">\n"
        "</signal>\n"
        "<method name=\"ackConnect\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"connectionID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackDisconnect\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"connectionID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSetSinkVolume\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"volume\" type=\"n\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSetSourceVolume\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"volume\" type=\"n\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSetSourceState\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSetSinkSoundProperties\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSetSinkSoundProperty\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSetSourceSoundProperties\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSetSourceSoundProperty\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSourceVolumeTick\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"source\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"volume\" type=\"n\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSinkVolumeTick\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"sink\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"volume\" type=\"n\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackCrossFading\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"hotSink\" type=\"i\" direction=\"in\" />\n"
            "<arg name=\"returnError\" type=\"i\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"peekDomain\">\n"
            "<arg name=\"name\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"domainID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"registerDomain\">\n"
            "<arg name=\"domainData\" type=\"(qsssbbi)\" direction=\"in\" />\n"
            "<arg name=\"returnBusname\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"returnPath\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"returnInterface\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"domainID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"deregisterDomain\">\n"
            "<arg name=\"domainID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"returnError\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"registerGateway\">\n"
            "<arg name=\"gatewayData\" type=\"(qsqqqqqaiaiab)\" direction=\"in\" />\n"
            "<arg name=\"gatewayID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"deregisterGateway\">\n"
            "<arg name=\"gatewayID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"returnError\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"peekSink\">\n"
            "<arg name=\"name\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"sinkID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"registerSink\">\n"
            "<arg name=\"sinkData\" type=\"(qsqqnb(ii)ina(in)aia(in)a(iin)a(iin))\" direction=\"in\" />\n"
            "<arg name=\"sinkID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"deregisterSink\">\n"
            "<arg name=\"sinkID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"returnError\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"peekSource\">\n"
            "<arg name=\"name\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"sourceID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"registerSource\">\n"
            "<arg name=\"sourceData\" type=\"(qqsqinb(ii)ia(in)aia(in)a(iin)a(iin))\" direction=\"in\" />\n"
            "<arg name=\"sourceID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"deregisterSource\">\n"
            "<arg name=\"sourceID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"returnError\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"registerCrossfader\">\n"
            "<arg name=\"crossfaderData\" type=\"(qsqqqi)\" direction=\"in\" />\n"
            "<arg name=\"crossfaderID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"deregisterCrossfader\">\n"
            "<arg name=\"crossfaderID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"returnError\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"peekSourceClassID\">\n"
            "<arg name=\"name\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"sourceClassID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"peekSinkClassID\">\n"
            "<arg name=\"name\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"sinkClassID\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"error\" type=\"i\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"hookInterruptStatusChange\">\n"
            "<arg name=\"sourceID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"interruptState\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"hookDomainRegistrationComplete\">\n"
            "<arg name=\"domainID\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"hookSinkAvailablityStatusChange\">\n"
            "<arg name=\"sinkID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"availability\" type=\"(ii)\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"hookSourceAvailablityStatusChange\">\n"
            "<arg name=\"sourceID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"availability\" type=\"(ii)\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"hookDomainStateChange\">\n"
            "<arg name=\"domainID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"domainState\" type=\"i\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"hookTimingInformationChanged\">\n"
            "<arg name=\"connectionID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"delay\" type=\"n\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"sendChangedData\">\n"
            "<arg name=\"earlyData_volumes\" type=\"a(i(yv)(yv))\" direction=\"in\" />\n"
            "<arg name=\"earlyData_soundproperties\" type=\"a(i(yv)(yv))\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"confirmRoutingReady\">\n"
            "<arg name=\"domainID\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"confirmRoutingRundown\">\n"
            "<arg name=\"domainID\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"updateGateway\">\n"
            "<arg name=\"gatewayID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"listSourceFormats\" type=\"ai\" direction=\"in\" />\n"
            "<arg name=\"listSinkFormats\" type=\"ai\" direction=\"in\" />\n"
            "<arg name=\"convertionMatrix\" type=\"ab\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"updateSink\">\n"
            "<arg name=\"sinkID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"sinkClassID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"listSoundProperties\" type=\"a(in)\" direction=\"in\" />\n"
            "<arg name=\"listConnectionFormats\" type=\"ai\" direction=\"in\" />\n"
            "<arg name=\"listMainSoundProperties\" type=\"a(in)\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"updateSource\">\n"
            "<arg name=\"sourceID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"sourceClassID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"listSoundProperties\" type=\"a(in)\" direction=\"in\" />\n"
            "<arg name=\"listConnectionFormats\" type=\"ai\" direction=\"in\" />\n"
            "<arg name=\"listMainSoundProperties\" type=\"a(in)\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSetVolumes\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"listVolumes\" type=\"a(i(yv)niq)\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSinkNotificationConfiguration\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"ackSourceNotificationConfiguration\">\n"
            "<arg name=\"handle\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"error\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"hookSinkNotificationDataChange\">\n"
            "<arg name=\"sinkID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"payload\" type=\"(nn)\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"hookSourceNotificationDataChange\">\n"
            "<arg name=\"sourceID\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"payload\" type=\"(nn)\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"getRoutingReadyState\">\n"
            "<arg name=\"readyState\" type=\"b\" direction=\"out\" />\n"
        "</method>\n"
    ;
}



static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, am_gen::am_connectionID_t, uint16_t>,
    std::tuple<>
    > ackConnectStubDispatcher(&RoutingInterfaceStub::ackConnect, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, am_gen::am_connectionID_t, uint16_t>,
    std::tuple<>
    > ackDisconnectStubDispatcher(&RoutingInterfaceStub::ackDisconnect, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, am_gen::am_volume_t, uint16_t>,
    std::tuple<>
    > ackSetSinkVolumeStubDispatcher(&RoutingInterfaceStub::ackSetSinkVolume, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, am_gen::am_volume_t, uint16_t>,
    std::tuple<>
    > ackSetSourceVolumeStubDispatcher(&RoutingInterfaceStub::ackSetSourceVolume, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, uint16_t>,
    std::tuple<>
    > ackSetSourceStateStubDispatcher(&RoutingInterfaceStub::ackSetSourceState, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, uint16_t>,
    std::tuple<>
    > ackSetSinkSoundPropertiesStubDispatcher(&RoutingInterfaceStub::ackSetSinkSoundProperties, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, uint16_t>,
    std::tuple<>
    > ackSetSinkSoundPropertyStubDispatcher(&RoutingInterfaceStub::ackSetSinkSoundProperty, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, uint16_t>,
    std::tuple<>
    > ackSetSourceSoundPropertiesStubDispatcher(&RoutingInterfaceStub::ackSetSourceSoundProperties, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, uint16_t>,
    std::tuple<>
    > ackSetSourceSoundPropertyStubDispatcher(&RoutingInterfaceStub::ackSetSourceSoundProperty, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, am_gen::am_sourceID_t, am_gen::am_volume_t>,
    std::tuple<>
    > ackSourceVolumeTickStubDispatcher(&RoutingInterfaceStub::ackSourceVolumeTick, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, am_gen::am_sinkID_t, am_gen::am_volume_t>,
    std::tuple<>
    > ackSinkVolumeTickStubDispatcher(&RoutingInterfaceStub::ackSinkVolumeTick, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, am_gen::am_HotSink_e, am_gen::am_Error_e>,
    std::tuple<>
    > ackCrossFadingStubDispatcher(&RoutingInterfaceStub::ackCrossFading, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<std::string>,
    std::tuple<am_gen::am_domainID_t, am_gen::am_Error_e>
    > peekDomainStubDispatcher(&RoutingInterfaceStub::peekDomain, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_Domain_s, std::string, std::string, std::string>,
    std::tuple<am_gen::am_domainID_t, am_gen::am_Error_e>
    > registerDomainStubDispatcher(&RoutingInterfaceStub::registerDomain, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_domainID_t>,
    std::tuple<am_gen::am_Error_e>
    > deregisterDomainStubDispatcher(&RoutingInterfaceStub::deregisterDomain, "i");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_Gateway_s>,
    std::tuple<am_gen::am_gatewayID_t, am_gen::am_Error_e>
    > registerGatewayStubDispatcher(&RoutingInterfaceStub::registerGateway, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_gatewayID_t>,
    std::tuple<am_gen::am_Error_e>
    > deregisterGatewayStubDispatcher(&RoutingInterfaceStub::deregisterGateway, "i");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<std::string>,
    std::tuple<am_gen::am_sinkID_t, am_gen::am_Error_e>
    > peekSinkStubDispatcher(&RoutingInterfaceStub::peekSink, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::sinkData_s>,
    std::tuple<am_gen::am_sinkID_t, am_gen::am_Error_e>
    > registerSinkStubDispatcher(&RoutingInterfaceStub::registerSink, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_sinkID_t>,
    std::tuple<am_gen::am_Error_e>
    > deregisterSinkStubDispatcher(&RoutingInterfaceStub::deregisterSink, "i");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<std::string>,
    std::tuple<am_gen::am_sourceID_t, am_gen::am_Error_e>
    > peekSourceStubDispatcher(&RoutingInterfaceStub::peekSource, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::sourceData_s>,
    std::tuple<am_gen::am_sourceID_t, am_gen::am_Error_e>
    > registerSourceStubDispatcher(&RoutingInterfaceStub::registerSource, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_sourceID_t>,
    std::tuple<am_gen::am_Error_e>
    > deregisterSourceStubDispatcher(&RoutingInterfaceStub::deregisterSource, "i");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::crossfaderData_s>,
    std::tuple<am_gen::am_crossfaderID_t, am_gen::am_Error_e>
    > registerCrossfaderStubDispatcher(&RoutingInterfaceStub::registerCrossfader, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_crossfaderID_t>,
    std::tuple<am_gen::am_Error_e>
    > deregisterCrossfaderStubDispatcher(&RoutingInterfaceStub::deregisterCrossfader, "i");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<std::string>,
    std::tuple<am_gen::am_sourceClass_t, am_gen::am_Error_e>
    > peekSourceClassIDStubDispatcher(&RoutingInterfaceStub::peekSourceClassID, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<std::string>,
    std::tuple<am_gen::am_sinkClass_t, am_gen::am_Error_e>
    > peekSinkClassIDStubDispatcher(&RoutingInterfaceStub::peekSinkClassID, "qi");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_sourceID_t, uint16_t>,
    std::tuple<>
    > hookInterruptStatusChangeStubDispatcher(&RoutingInterfaceStub::hookInterruptStatusChange, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_domainID_t>,
    std::tuple<>
    > hookDomainRegistrationCompleteStubDispatcher(&RoutingInterfaceStub::hookDomainRegistrationComplete, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_sinkID_t, am_gen::am_Availability_s>,
    std::tuple<>
    > hookSinkAvailablityStatusChangeStubDispatcher(&RoutingInterfaceStub::hookSinkAvailablityStatusChange, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_sourceID_t, am_gen::am_Availability_s>,
    std::tuple<>
    > hookSourceAvailablityStatusChangeStubDispatcher(&RoutingInterfaceStub::hookSourceAvailablityStatusChange, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_domainID_t, am_gen::am_DomainState_e>,
    std::tuple<>
    > hookDomainStateChangeStubDispatcher(&RoutingInterfaceStub::hookDomainStateChange, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_connectionID_t, int16_t>,
    std::tuple<>
    > hookTimingInformationChangedStubDispatcher(&RoutingInterfaceStub::hookTimingInformationChanged, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_EarlyData_l, am_gen::am_EarlyData_l>,
    std::tuple<>
    > sendChangedDataStubDispatcher(&RoutingInterfaceStub::sendChangedData, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_domainID_t>,
    std::tuple<>
    > confirmRoutingReadyStubDispatcher(&RoutingInterfaceStub::confirmRoutingReady, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_domainID_t>,
    std::tuple<>
    > confirmRoutingRundownStubDispatcher(&RoutingInterfaceStub::confirmRoutingRundown, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_gatewayID_t, am_gen::am_ConnectionFormat_L, am_gen::am_ConnectionFormat_L, am_gen::bool_L>,
    std::tuple<>
    > updateGatewayStubDispatcher(&RoutingInterfaceStub::updateGateway, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_sinkID_t, am_gen::am_sinkClass_t, am_gen::am_SoundProperty_L, am_gen::am_ConnectionFormat_L, am_gen::am_MainSoundProperty_L>,
    std::tuple<>
    > updateSinkStubDispatcher(&RoutingInterfaceStub::updateSink, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_sourceID_t, am_gen::am_sourceClass_t, am_gen::am_SoundProperty_L, am_gen::am_ConnectionFormat_L, am_gen::am_MainSoundProperty_L>,
    std::tuple<>
    > updateSourceStubDispatcher(&RoutingInterfaceStub::updateSource, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, am_gen::am_Volumes_l, uint16_t>,
    std::tuple<>
    > ackSetVolumesStubDispatcher(&RoutingInterfaceStub::ackSetVolumes, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, uint16_t>,
    std::tuple<>
    > ackSinkNotificationConfigurationStubDispatcher(&RoutingInterfaceStub::ackSinkNotificationConfiguration, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<uint16_t, uint16_t>,
    std::tuple<>
    > ackSourceNotificationConfigurationStubDispatcher(&RoutingInterfaceStub::ackSourceNotificationConfiguration, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_sinkID_t, am_gen::notificationPayload_s>,
    std::tuple<>
    > hookSinkNotificationDataChangeStubDispatcher(&RoutingInterfaceStub::hookSinkNotificationDataChange, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<am_gen::am_sourceID_t, am_gen::notificationPayload_s>,
    std::tuple<>
    > hookSourceNotificationDataChangeStubDispatcher(&RoutingInterfaceStub::hookSourceNotificationDataChange, "");
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RoutingInterfaceStub,
    std::tuple<>,
    std::tuple<bool>
    > getRoutingReadyStateStubDispatcher(&RoutingInterfaceStub::getRoutingReadyState, "b");


void RoutingInterfaceDBusStubAdapter::fireSetRoutingReadyEvent() {
    CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<>>
            ::sendSignal(
                *this,
                "setRoutingReady",
                ""
        );
}
void RoutingInterfaceDBusStubAdapter::fireSetRoutingRundownEvent() {
    CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<>>
            ::sendSignal(
                *this,
                "setRoutingRundown",
                ""
        );
}

} // namespace audiomanager
} // namespace genivi
} // namespace org

template<>
const org::genivi::audiomanager::RoutingInterfaceDBusStubAdapterHelper::StubDispatcherTable org::genivi::audiomanager::RoutingInterfaceDBusStubAdapterHelper::stubDispatcherTable_ = {
    { { "ackConnect", "qqq" }, &org::genivi::audiomanager::ackConnectStubDispatcher },
    { { "ackDisconnect", "qqq" }, &org::genivi::audiomanager::ackDisconnectStubDispatcher },
    { { "ackSetSinkVolume", "qnq" }, &org::genivi::audiomanager::ackSetSinkVolumeStubDispatcher },
    { { "ackSetSourceVolume", "qnq" }, &org::genivi::audiomanager::ackSetSourceVolumeStubDispatcher },
    { { "ackSetSourceState", "qq" }, &org::genivi::audiomanager::ackSetSourceStateStubDispatcher },
    { { "ackSetSinkSoundProperties", "qq" }, &org::genivi::audiomanager::ackSetSinkSoundPropertiesStubDispatcher },
    { { "ackSetSinkSoundProperty", "qq" }, &org::genivi::audiomanager::ackSetSinkSoundPropertyStubDispatcher },
    { { "ackSetSourceSoundProperties", "qq" }, &org::genivi::audiomanager::ackSetSourceSoundPropertiesStubDispatcher },
    { { "ackSetSourceSoundProperty", "qq" }, &org::genivi::audiomanager::ackSetSourceSoundPropertyStubDispatcher },
    { { "ackSourceVolumeTick", "qqn" }, &org::genivi::audiomanager::ackSourceVolumeTickStubDispatcher },
    { { "ackSinkVolumeTick", "qqn" }, &org::genivi::audiomanager::ackSinkVolumeTickStubDispatcher },
    { { "ackCrossFading", "qii" }, &org::genivi::audiomanager::ackCrossFadingStubDispatcher },
    { { "peekDomain", "s" }, &org::genivi::audiomanager::peekDomainStubDispatcher },
    { { "registerDomain", "(qsssbbi)sss" }, &org::genivi::audiomanager::registerDomainStubDispatcher },
    { { "deregisterDomain", "q" }, &org::genivi::audiomanager::deregisterDomainStubDispatcher },
    { { "registerGateway", "(qsqqqqqaiaiab)" }, &org::genivi::audiomanager::registerGatewayStubDispatcher },
    { { "deregisterGateway", "q" }, &org::genivi::audiomanager::deregisterGatewayStubDispatcher },
    { { "peekSink", "s" }, &org::genivi::audiomanager::peekSinkStubDispatcher },
    { { "registerSink", "(qsqqnb(ii)ina(in)aia(in)a(iin)a(iin))" }, &org::genivi::audiomanager::registerSinkStubDispatcher },
    { { "deregisterSink", "q" }, &org::genivi::audiomanager::deregisterSinkStubDispatcher },
    { { "peekSource", "s" }, &org::genivi::audiomanager::peekSourceStubDispatcher },
    { { "registerSource", "(qqsqinb(ii)ia(in)aia(in)a(iin)a(iin))" }, &org::genivi::audiomanager::registerSourceStubDispatcher },
    { { "deregisterSource", "q" }, &org::genivi::audiomanager::deregisterSourceStubDispatcher },
    { { "registerCrossfader", "(qsqqqi)" }, &org::genivi::audiomanager::registerCrossfaderStubDispatcher },
    { { "deregisterCrossfader", "q" }, &org::genivi::audiomanager::deregisterCrossfaderStubDispatcher },
    { { "peekSourceClassID", "s" }, &org::genivi::audiomanager::peekSourceClassIDStubDispatcher },
    { { "peekSinkClassID", "s" }, &org::genivi::audiomanager::peekSinkClassIDStubDispatcher },
    { { "hookInterruptStatusChange", "qq" }, &org::genivi::audiomanager::hookInterruptStatusChangeStubDispatcher },
    { { "hookDomainRegistrationComplete", "q" }, &org::genivi::audiomanager::hookDomainRegistrationCompleteStubDispatcher },
    { { "hookSinkAvailablityStatusChange", "q(ii)" }, &org::genivi::audiomanager::hookSinkAvailablityStatusChangeStubDispatcher },
    { { "hookSourceAvailablityStatusChange", "q(ii)" }, &org::genivi::audiomanager::hookSourceAvailablityStatusChangeStubDispatcher },
    { { "hookDomainStateChange", "qi" }, &org::genivi::audiomanager::hookDomainStateChangeStubDispatcher },
    { { "hookTimingInformationChanged", "qn" }, &org::genivi::audiomanager::hookTimingInformationChangedStubDispatcher },
    { { "sendChangedData", "a(i(yv)(yv))a(i(yv)(yv))" }, &org::genivi::audiomanager::sendChangedDataStubDispatcher },
    { { "confirmRoutingReady", "q" }, &org::genivi::audiomanager::confirmRoutingReadyStubDispatcher },
    { { "confirmRoutingRundown", "q" }, &org::genivi::audiomanager::confirmRoutingRundownStubDispatcher },
    { { "updateGateway", "qaiaiab" }, &org::genivi::audiomanager::updateGatewayStubDispatcher },
    { { "updateSink", "qqa(in)aia(in)" }, &org::genivi::audiomanager::updateSinkStubDispatcher },
    { { "updateSource", "qqa(in)aia(in)" }, &org::genivi::audiomanager::updateSourceStubDispatcher },
    { { "ackSetVolumes", "qa(i(yv)niq)q" }, &org::genivi::audiomanager::ackSetVolumesStubDispatcher },
    { { "ackSinkNotificationConfiguration", "qq" }, &org::genivi::audiomanager::ackSinkNotificationConfigurationStubDispatcher },
    { { "ackSourceNotificationConfiguration", "qq" }, &org::genivi::audiomanager::ackSourceNotificationConfigurationStubDispatcher },
    { { "hookSinkNotificationDataChange", "q(nn)" }, &org::genivi::audiomanager::hookSinkNotificationDataChangeStubDispatcher },
    { { "hookSourceNotificationDataChange", "q(nn)" }, &org::genivi::audiomanager::hookSourceNotificationDataChangeStubDispatcher },
    { { "getRoutingReadyState", "" }, &org::genivi::audiomanager::getRoutingReadyStateStubDispatcher }
};