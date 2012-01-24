/**
* Copyright (C) 2011, BMW AG
*
* GeniviAudioMananger
*
* \file  
*
* \date 20-Oct-2011 3:42:04 PM
* \author Christian Mueller (christian.ei.mueller@bmw.de)
*
* \section License
* GNU Lesser General Public License, version 2.1, with special exception (GENIVI clause)
* Copyright (C) 2011, BMW AG Christian M?ller  Christian.ei.mueller@bmw.de
*
* This program is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License, version 2.1, as published by the Free Software Foundation.
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License, version 2.1, for more details.
* You should have received a copy of the GNU Lesser General Public License, version 2.1, along with this program; if not, see <http://www.gnu.org/licenses/lgpl-2.1.html>.
* Note that the copyright holders assume that the GNU Lesser General Public License, version 2.1, may also be applicable to programs even in cases in which the program is not a library in the technical sense.
* Linking AudioManager statically or dynamically with other modules is making a combined work based on AudioManager. You may license such other modules under the GNU Lesser General Public License, version 2.1. If you do not want to license your linked modules under the GNU Lesser General Public License, version 2.1, you may use the program under the following exception.
* As a special exception, the copyright holders of AudioManager give you permission to combine AudioManager with software programs or libraries that are released under any license unless such a combination is not permitted by the license of such a software program or library. You may copy and distribute such a system following the terms of the GNU Lesser General Public License, version 2.1, including this special exception, for AudioManager and the licenses of the other code concerned.
* Note that people who make modified versions of AudioManager are not obligated to grant this special exception for their modified versions; it is their choice whether to do so. The GNU Lesser General Public License, version 2.1, gives permission to release a modified version without this exception; this exception also makes it possible to release a modified version which carries forward this exception.
*
* THIS CODE HAS BEEN GENERATED BY ENTERPRISE ARCHITECT GENIVI MODEL. PLEASE CHANGE ONLY IN ENTERPRISE ARCHITECT AND GENERATE AGAIN
*/
#if !defined(EA_434BDFE9_DDA7_4273_AF1E_77AE60CB055D__INCLUDED_)
#define EA_434BDFE9_DDA7_4273_AF1E_77AE60CB055D__INCLUDED_

#include <vector>
#include <string>
#include "../audiomanagertypes.h"
namespace am {
class DBusWrapper;
class SocketHandler;
}


#define CommandReceiveVersion 1
namespace am {
	/**
	 * The interface towards the Controlling Instance (e.g HMI). It handles the communication towards the HMI and other system components who need to interact with the audiomanagement.
	 * @author christian
	 * @version 1.0
	 * @created 19-Jan-2012 4:32:00 PM
	 */
	class CommandReceiveInterface
	{

	public:
		/**
		 * connects a source to sink
		 * @return E_OK on success, E_NOT_POSSIBLE on failure, E_ALREADY_EXISTS if the connection does already exists
		 * 
		 * @param sourceID
		 * @param sinkID
		 * @param mainConnectionID
		 */
		virtual am_Error_e connect(const am_sourceID_t sourceID, const am_sinkID_t sinkID, am_mainConnectionID_t& mainConnectionID) =0;
		/**
		 * disconnects a mainConnection
		 * @return E_OK on successes, E_NON_EXISTENT if the connection does not exist, E_NOT_POSSIBLE on error.
		 * 
		 * @param mainConnectionID
		 */
		virtual am_Error_e disconnect(const am_mainConnectionID_t mainConnectionID) =0;
		/**
		 * sets the volume for a sink
		 * @return E_OK on success, E_UNKOWN on error, E_OUT_OF_RANGE in case the value is out of range
		 * 
		 * @param sinkID    the sink
		 * @param volume    the volume
		 */
		virtual am_Error_e setVolume(const am_sinkID_t sinkID, const am_mainVolume_t volume) =0;
		/**
		 * This function is used to increment or decrement the current volume for a sink.
		 * @return E_OK on success, E_UNKNOWN on error and E_OUT_OF_RANGE if the value is not in the given volume range.
		 * 
		 * @param sinkID
		 * @param volumeStep    indicated the number of steps that should be incremented or decremented. Positive values here inkrement, negative values decrement
		 */
		virtual am_Error_e volumeStep(const am_sinkID_t sinkID, const int16_t volumeStep) =0;
		/**
		 * sets the mute state of a sink
		 * @return E_OK on success, E_UNKNOWN on error. If the mute state is already the desired one, the Daemon will return E_OK.
		 * 
		 * @param sinkID
		 * @param muteState
		 */
		virtual am_Error_e setSinkMuteState(const am_sinkID_t sinkID, const am_MuteState_e muteState) =0;
		/**
		 * This method is used to set sound properties, e.g. Equalizer Values. Since the capabilities of the system can differ, the exact key value pairs can be extended in each product
		 * @return E_OK on success, E_OUT_OF_RANGE if value exceeds range, E_UNKNOWN in case of an error
		 * 
		 * @param soundProperty
		 * @param sinkID
		 */
		virtual am_Error_e setMainSinkSoundProperty(const am_MainSoundProperty_s& soundProperty, const am_sinkID_t sinkID) =0;
		/**
		 * This method is used to set sound properties, e.g. Equalizer Values. Since the capabilities of the system can differ, the exact key value pairs can be extended in each product
		 * @return E_OK on success, E_OUT_OF_RANGE if value exceeds range, E_UNKNOWN in case of an error
		 * 
		 * @param soundProperty
		 * @param sourceID
		 */
		virtual am_Error_e setMainSourceSoundProperty(const am_MainSoundProperty_s& soundProperty, const am_sourceID_t sourceID) =0;
		/**
		 * is used to set a specific system property.
		 * @return E_OK on success, E_OUT_OF_RANGE if value exceeds range, E_UNKNOWN in case of an error
		 * 
		 * @param property    the property that shall be set
		 */
		virtual am_Error_e setSystemProperty(const am_SystemProperty_s& property) =0;
		/**
		 * returns the actual list of MainConnections
		 * @return E_OK on success, E_DATABASE_ERROR on error 
		 * 
		 * @param listConnections    returns a list of all connections
		 */
		virtual am_Error_e getListMainConnections(std::vector<am_MainConnectionType_s>& listConnections) const =0;
		/**
		 * returns the actual list of Sinks
		 * @return E_OK on success, E_DATABASE_ERROR on error 
		 * 
		 * @param listMainSinks    the list of the sinks
		 */
		virtual am_Error_e getListMainSinks(std::vector<am_SinkType_s>& listMainSinks) const =0;
		/**
		 * returns the actual list of Sources
		 * @return E_OK on success, E_DATABASE_ERROR on error 
		 * 
		 * @param listMainSources    the list of sources
		 */
		virtual am_Error_e getListMainSources(std::vector<am_SourceType_s>& listMainSources) const =0;
		/**
		 * This is used to retrieve all source sound properties related to a source. Returns a vector of the sound properties and values as pair
		 * @return E_OK on success, E_DATABASE_ERROR on error 
		 * 
		 * @param sinkID
		 * @param listSoundProperties
		 */
		virtual am_Error_e getListMainSinkSoundProperties(const am_sinkID_t sinkID, std::vector<am_MainSoundProperty_s>& listSoundProperties) const =0;
		/**
		 * This is used to retrieve all source sound properties related to a source.
		 * @return E_OK on success, E_DATABASE_ERROR on error 
		 * 
		 * @param sourceID
		 * @param listSourceProperties
		 */
		virtual am_Error_e getListMainSourceSoundProperties(const am_sourceID_t sourceID, std::vector<am_MainSoundProperty_s>& listSourceProperties) const =0;
		/**
		 * This is used to retrieve SourceClass Information of all source classes 
		 * @return E_OK on success, E_DATABASE_ERROR on error 
		 * 
		 * @param listSourceClasses
		 */
		virtual am_Error_e getListSourceClasses(std::vector<am_SourceClass_s>& listSourceClasses) const =0;
		/**
		 * This is used to retrieve SinkClass Information of all sink classes 
		 * @return E_OK on success, E_DATABASE_ERROR on error 
		 * 
		 * @param listSinkClasses
		 */
		virtual am_Error_e getListSinkClasses(std::vector<am_SinkClass_s>& listSinkClasses) const =0;
		/**
		 * Retrieves a complete list of all systemProperties.
		 * @return E_OK on success, E_DATABASE_ERROR on error 
		 * 
		 * @param listSystemProperties
		 */
		virtual am_Error_e getListSystemProperties(std::vector<am_SystemProperty_s>& listSystemProperties) const =0;
		/**
		 * returns the delay in ms that the audiopath for the given mainConnection has
		 * @return E_OK on success, E_NOT_POSSIBLE if timing information is not yet retrieved, E_DATABASE_ERROR on read error on the database
		 * 
		 * @param mainConnectionID
		 * @param delay
		 */
		virtual am_Error_e getTimingInformation(const am_mainConnectionID_t mainConnectionID, am_timeSync_t& delay) const =0;
		/**
		 * this function is used to retrieve a pointer to the dBusConnectionWrapper
		 * @return E_OK if pointer is valid, E_UKNOWN if AudioManager was compiled without DBus Support
		 * 
		 * @param dbusConnectionWrapper    This is a wrapper class that is needed to keep dbus inclusions away from the interface. The DBusWrapperClass will return the pointer to the DbusConnection call (getDBusConnection)
		 */
		virtual am_Error_e getDBusConnectionWrapper(DBusWrapper*& dbusConnectionWrapper) const =0;
		/**
		 * This function returns the pointer to the socketHandler. This can be used to integrate socket-based activites like communication with the mainloop of the AudioManager.
		 * returns E_OK if pointer is valid, E_UNKNOWN in case AudioManager was compiled without socketHandler support,
		 * 
		 * @param socketHandler
		 */
		virtual am_Error_e getSocketHandler(SocketHandler*& socketHandler) const =0;
		/**
		 * This function returns the version of the interface.
		 */
		virtual uint16_t getInterfaceVersion() const =0;

	};
}
#endif // !defined(EA_434BDFE9_DDA7_4273_AF1E_77AE60CB055D__INCLUDED_)
