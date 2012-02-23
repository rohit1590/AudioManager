/**
 * Copyright (C) 2012, BMW AG
 *
 * GeniviAudioMananger AudioManagerDaemon
 *
 * \file CAmTelnetMenuHelper.cpp
 *
 * \date 24-Jan-2012
 * \author Frank Herchet (frank.fh.herchet@bmw.de)
 *
 * \section License
 * GNU Lesser General Public License, version 2.1, with special exception (GENIVI clause)
 * Copyright (C) 2012, BMW AG Frank Herchet  frank.fh.herchet@bmw.de
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License, version 2.1, as published by the Free Software Foundation.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License, version 2.1, for more details.
 * You should have received a copy of the GNU Lesser General Public License, version 2.1, along with this program; if not, see <http://www.gnu.org/licenses/lgpl-2.1.html>.
 * Note that the copyright holders assume that the GNU Lesser General Public License, version 2.1, may also be applicable to programs even in cases in which the program is not a library in the technical sense.
 * Linking AudioManager statically or dynamically with other modules is making a combined work based on AudioManager. You may license such other modules under the GNU Lesser General Public License, version 2.1. If you do not want to license your linked modules under the GNU Lesser General Public License, version 2.1, you may use the program under the following exception.
 * As a special exception, the copyright holders of AudioManager give you permission to combine AudioManager with software programs or libraries that are released under any license unless such a combination is not permitted by the license of such a software program or library. You may copy and distribute such a system following the terms of the GNU Lesser General Public License, version 2.1, including this special exception, for AudioManager and the licenses of the other code concerned.
 * Note that people who make modified versions of AudioManager are not obligated to grant this special exception for their modified versions; it is their choice whether to do so. The GNU Lesser General Public License, version 2.1, gives permission to release a modified version without this exception; this exception also makes it possible to release a modified version which carries forward this exception.
 *
 */

#include "CAmTelnetMenuHelper.h"
#include "TelnetServer.h"
#include "DatabaseHandler.h"
#include "ControlSender.h"
#include "CommandSender.h"
#include "RoutingSender.h"
#include "RoutingReceiver.h"
#include "CommandReceiver.h"
#include "ControlReceiver.h"
#include "Router.h"
#include "config.h"
#include "DLTWrapper.h"
#include <cassert>

static const std::string COLOR_WELCOME("\033[1;33m\033[44m");
static const std::string COLOR_HEAD("\033[1m\033[42m");
static const std::string COLOR_DEFAULT("\033[0m");


using namespace am;

CAmTelnetMenuHelper* CAmTelnetMenuHelper::instance = NULL;

/****************************************************************************/
CAmTelnetMenuHelper::CAmTelnetMenuHelper(SocketHandler *iSocketHandler, CommandSender *iCommandSender, CommandReceiver *iCommandReceiver, RoutingSender *iRoutingSender, RoutingReceiver *iRoutingReceiver, ControlSender *iControlSender, ControlReceiver *iControlReceiver, DatabaseHandler *iDatabasehandler, Router *iRouter, TelnetServer *iTelnetServer)
/****************************************************************************/
:mpTelenetServer(iTelnetServer), mpSocketHandler(iSocketHandler), mpCommandSender(iCommandSender), mpCommandReceiver(iCommandReceiver), mpRoutingSender(iRoutingSender), mpRoutingReceiver(iRoutingReceiver), mpControlSender(iControlSender), mpControlReceiver(iControlReceiver), mpDatabasehandler(iDatabasehandler), mpRouter(iRouter)
{
    instance = this;
    createCommandMaps();
}

/****************************************************************************/
CAmTelnetMenuHelper::~CAmTelnetMenuHelper()
/****************************************************************************/
{
}

/****************************************************************************/
void CAmTelnetMenuHelper::createCommandMaps()
/****************************************************************************/
{
    // ROOT commands

    mRootCommands.clear();

    mRootCommands.insert(std::make_pair("help", sCommandPrototypeInfo("show all possible commands", &CAmTelnetMenuHelper::helpCommand)));
    mRootCommands.insert(std::make_pair("list", sCommandPrototypeInfo("Go into 'list'-submenu", &CAmTelnetMenuHelper::rootListCommand)));
    mRootCommands.insert(std::make_pair("info", sCommandPrototypeInfo("Go into 'info'-submenu", &CAmTelnetMenuHelper::rootInfoCommand)));
    mRootCommands.insert(std::make_pair("set", sCommandPrototypeInfo("Go into 'set'-submenu", &CAmTelnetMenuHelper::rootSetCommand)));
    mRootCommands.insert(std::make_pair("get", sCommandPrototypeInfo("Go into 'get'-submenu", &CAmTelnetMenuHelper::rootGetCommand)));
    mRootCommands.insert(std::make_pair("exit", sCommandPrototypeInfo("quit telnet session", &CAmTelnetMenuHelper::exitCommand)));

    // List commands
    mListCommands.insert(std::make_pair("help", sCommandPrototypeInfo(std::string("show all possible commands"), &CAmTelnetMenuHelper::helpCommand)));
    mListCommands.insert(std::make_pair("conn", sCommandPrototypeInfo("list all connections", &CAmTelnetMenuHelper::listConnectionsCommand)));
    mListCommands.insert(std::make_pair("sources", sCommandPrototypeInfo("list all available sources", &CAmTelnetMenuHelper::listSourcesCommand)));
    mListCommands.insert(std::make_pair("sinks", sCommandPrototypeInfo("list all available sinks", &CAmTelnetMenuHelper::listSinksCommands)));
    mListCommands.insert(std::make_pair("crfaders", sCommandPrototypeInfo("list all crossfaders", &CAmTelnetMenuHelper::listCrossfaders)));
    mListCommands.insert(std::make_pair("domains", sCommandPrototypeInfo("list all domains", &CAmTelnetMenuHelper::listDomainsCommand)));
    mListCommands.insert(std::make_pair("gws", sCommandPrototypeInfo("list all gateways", &CAmTelnetMenuHelper::listGatewaysCommand)));
    mListCommands.insert(std::make_pair("mainconn", sCommandPrototypeInfo("list all main connections", &CAmTelnetMenuHelper::listMainConnectionsCommand)));
    mListCommands.insert(std::make_pair("mainsinks", sCommandPrototypeInfo("list all main sinks", &CAmTelnetMenuHelper::listMainSinksCommand)));
    mListCommands.insert(std::make_pair("mainsources", sCommandPrototypeInfo("list all main sources", &CAmTelnetMenuHelper::listMainSourcesCommand)));
    mListCommands.insert(std::make_pair("..", sCommandPrototypeInfo("one step back in menu tree (back to root folder)", &CAmTelnetMenuHelper::oneStepBackCommand)));
    mListCommands.insert(std::make_pair("exit", sCommandPrototypeInfo("close telnet session", &CAmTelnetMenuHelper::exitCommand)));

    // Set commands
    mSetCommands.insert(std::make_pair("help", sCommandPrototypeInfo(std::string("show all possible commands"), &CAmTelnetMenuHelper::helpCommand)));
    mSetCommands.insert(std::make_pair("..", sCommandPrototypeInfo("one step back in menu tree (back to root folder)", &CAmTelnetMenuHelper::oneStepBackCommand)));
    mSetCommands.insert(std::make_pair("exit", sCommandPrototypeInfo("close telnet session", &CAmTelnetMenuHelper::exitCommand)));
    mSetCommands.insert(std::make_pair("conn", sCommandPrototypeInfo("use 'conn sourceId sinkId' to connect a source and a sink", &CAmTelnetMenuHelper::setConnection)));
    mSetCommands.insert(std::make_pair("routing", sCommandPrototypeInfo("use 'routing sourceId sinkId' to get all\n\t  possible routes between a sourceID and a sinkID", &CAmTelnetMenuHelper::setRoutingCommand)));
    mSetCommands.insert(std::make_pair("disc", sCommandPrototypeInfo("use 'disc connectionID' to disconnect \n\t  this connection", &CAmTelnetMenuHelper::setDisconnectConnId)));

    // Get commands
    mGetCommands.insert(std::make_pair("help", sCommandPrototypeInfo(std::string("show all possible commands"), &CAmTelnetMenuHelper::helpCommand)));
    mGetCommands.insert(std::make_pair("routing", sCommandPrototypeInfo("show current routing", &CAmTelnetMenuHelper::getRoutingCommand)));
    mGetCommands.insert(std::make_pair("sendv", sCommandPrototypeInfo("show senderversion", &CAmTelnetMenuHelper::getSenderversionCommand)));
    mGetCommands.insert(std::make_pair("recv", sCommandPrototypeInfo("show receiverversion ", &CAmTelnetMenuHelper::getReceiverversionCommand)));
    mGetCommands.insert(std::make_pair("..", sCommandPrototypeInfo("one step back in menu tree (back to root folder)", &CAmTelnetMenuHelper::oneStepBackCommand)));
    mGetCommands.insert(std::make_pair("exit", sCommandPrototypeInfo("close telnet session", &CAmTelnetMenuHelper::exitCommand)));

    // Info comands
    mInfoCommands.insert(std::make_pair("help", sCommandPrototypeInfo(std::string("show all possible commands"), &CAmTelnetMenuHelper::helpCommand)));
    mInfoCommands.insert(std::make_pair("sysprop", sCommandPrototypeInfo("show all systemproperties", &CAmTelnetMenuHelper::infoSystempropertiesCommand)));
    mInfoCommands.insert(std::make_pair("..", sCommandPrototypeInfo("one step back in menu tree (back to root folder)", &CAmTelnetMenuHelper::oneStepBackCommand)));
    mInfoCommands.insert(std::make_pair("exit", sCommandPrototypeInfo("close telnet session", &CAmTelnetMenuHelper::exitCommand)));
}

/****************************************************************************/
void CAmTelnetMenuHelper::newSocketConnection(int filedescriptor)
/****************************************************************************/
{
    EMainState state = eRootState;
    std::map<int, EMainState>::iterator it;
    std::stringstream welcome;

    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        // socket connection already exists, delete entry and go back to root state
        mCurrentMainStateMap.erase(it);
    }

    it = mCurrentMainStateMap.begin();

    // insert new socket connection
    mCurrentMainStateMap.insert(it, std::make_pair<int, EMainState>(filedescriptor, state));

    // Send welcome message
    welcome << COLOR_WELCOME << "Welcome to GENIVI AudioManager " << DAEMONVERSION << COLOR_DEFAULT << "\n>";
    send(filedescriptor, welcome.str().c_str(), welcome.str().size(), 0);
    logInfo("[TN] New connection: ",filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::socketConnectionsClosed(int filedescriptor)
/****************************************************************************/
{
    std::map<int, EMainState>::iterator it;

    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        mCurrentMainStateMap.erase(it);
    }
    else
    {
        logError("[TN] socketConnectionsClosed, fd not found, ",filedescriptor);
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::enterCmdQueue(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    std::map<int, EMainState>::iterator it;
    std::string cmd;
    tCommandMap::iterator cmditer;

    // find current filedescriptor to get the current state of the telnet session
    it = mCurrentMainStateMap.find(filedescriptor);
    while (!CmdQueue.empty())
    {
        cmd = CmdQueue.front();

        // Now remove the first command, it's stored in 'cmd'
        CmdQueue.pop();
        // telnet session found. depending on the current state, different commands are available
        switch (it->second)
        {
        case eRootState:
            cmditer = mRootCommands.find(cmd);
            if (mRootCommands.end() != cmditer)
                cmditer->second.CommandPrototype(CmdQueue, filedescriptor);
            else
                sendError(filedescriptor, "Command not found\n");
            break;
        case eListState:
            cmditer = mListCommands.find(cmd);
            if (mListCommands.end() != cmditer)
                cmditer->second.CommandPrototype(CmdQueue, filedescriptor);
            else
                sendError(filedescriptor, "Command not found\n");
            break;
        case eInfoState:
            cmditer = mInfoCommands.find(cmd);
            if (mInfoCommands.end() != cmditer)
                cmditer->second.CommandPrototype(CmdQueue, filedescriptor);
            else
                sendError(filedescriptor, "Command not found\n");
            break;
        case eGetState:
            cmditer = mGetCommands.find(cmd);
            if (mGetCommands.end() != cmditer)
                cmditer->second.CommandPrototype(CmdQueue, filedescriptor);
            else
                sendError(filedescriptor, "Command not found\n");
            break;
        case eSetState:
            cmditer = mSetCommands.find(cmd);
            if (mSetCommands.end() != cmditer)
                cmditer->second.CommandPrototype(CmdQueue, filedescriptor);
            else
                sendError(filedescriptor, "Command not found\n");
            break;
        default:
            break;
        }
    }

    sendCurrentCmdPrompt(filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::sendError(int & filedescriptor, std::string error_string)
/****************************************************************************/
{
    send(filedescriptor, error_string.c_str(), error_string.size(), 0);
}

/****************************************************************************/
void CAmTelnetMenuHelper::sendTelnetLine(int & filedescriptor, std::stringstream &line)
/****************************************************************************/
{
    send(filedescriptor, line.str().c_str(), line.str().size(), 0);
}

/****************************************************************************/
void CAmTelnetMenuHelper::sendCurrentCmdPrompt(int & filedescriptor)
/****************************************************************************/
{
    std::map<int, EMainState>::iterator it;
    std::stringstream outputstream;
    outputstream << std::endl;

    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        switch (it->second)
        {
        case eRootState:
            outputstream << "\\>";
            break;
        case eListState:
            outputstream << "\\List>";
            break;
        case eGetState:
            outputstream << "\\Get>";
            break;
        case eSetState:
            outputstream << "\\Set>";
            break;
        case eInfoState:
            outputstream << "\\Info>";
            break;
        default:
            break;
        }

        send(filedescriptor, outputstream.str().c_str(), outputstream.str().size(), 0);

    }
    else
    {
        logInfo("[TN] sendCurrentCmdPrompt, fd not found: ",filedescriptor);
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::exitCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->exitCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::oneStepBackCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::map<int, EMainState>::iterator it;
    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        switch (it->second)
        {
        case eRootState:
            it->second = eRootState;
            break;
        case eListState:
            it->second = eRootState;
            ;
            break;
        case eGetState:
            it->second = eRootState;
            ;
            break;
        case eSetState:
            it->second = eRootState;
            ;
            break;
        case eInfoState:
            it->second = eRootState;
            ;
            break;
        default:
            it->second = eRootState;
            break;
        }

        logInfo("[TN] oneStepBackCommandExec, state: ",it->second);
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::oneStepBackCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->oneStepBackCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::exitCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::map<int, EMainState>::iterator it;
    std::stringstream line;
    std::stringstream output;

    // Sending a last message to the client
    output << "bye!" << COLOR_DEFAULT << std::endl;
    sendTelnetLine(filedescriptor, output);

    tCommandMap::iterator iter;
    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        if (NULL != mpTelenetServer)
        {
            logInfo("[TN] exitCommandExec, removing fd ",filedescriptor);
            mpTelenetServer->disconnectClient(filedescriptor);
            mCurrentMainStateMap.erase(it);
        }
        else
        {
            logError("[TN] exitCommandExec, mpTelenetServer == NULL, fd ",filedescriptor);
        }
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::helpCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->helpCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::helpCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::map<int, EMainState>::iterator it;
    std::stringstream line;
    tCommandMap::iterator cmdIter;
    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        line << COLOR_HEAD << "###################################################" << COLOR_DEFAULT << std::endl;
        line << COLOR_HEAD << "###### The following commands are supported: ######" << COLOR_DEFAULT << std::endl;
        line << COLOR_HEAD << "###################################################" << COLOR_DEFAULT << std::endl << std::endl;
        switch (it->second)
        {
        case eRootState:

            cmdIter = mRootCommands.begin();
            while (cmdIter != mRootCommands.end())
            {
                line << cmdIter->first << "\t\t- " << cmdIter->second.info << std::endl;
                cmdIter++;
            }
            break;
        case eListState:
            cmdIter = mListCommands.begin();
            while (cmdIter != mListCommands.end())
            {
                line << cmdIter->first << "\t\t- " << cmdIter->second.info << std::endl;
                cmdIter++;
            }
            break;
        case eGetState:
            cmdIter = mGetCommands.begin();
            while (cmdIter != mGetCommands.end())
            {
                line << cmdIter->first << "\t\t- " << cmdIter->second.info << std::endl;
                cmdIter++;
            }
            break;
        case eSetState:
            cmdIter = mSetCommands.begin();
            while (cmdIter != mSetCommands.end())
            {
                line << cmdIter->first << "\t\t- " << cmdIter->second.info << std::endl;
                cmdIter++;
            }
            break;
        case eInfoState:
            cmdIter = mInfoCommands.begin();
            while (cmdIter != mInfoCommands.end())
            {
                line << cmdIter->first << "\t\t- " << cmdIter->second.info << std::endl;
                cmdIter++;
            }
            break;
        default:
            break;
        }
        sendTelnetLine(filedescriptor, line);
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::rootGetCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->rootGetCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::rootGetCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::map<int, EMainState>::iterator it;
    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        it->second = eGetState;
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::rootSetCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->rootSetCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::rootSetCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::map<int, EMainState>::iterator it;
    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        it->second = eSetState;
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::rootListCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->rootListCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::rootListCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::map<int, EMainState>::iterator it;
    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        it->second = eListState;
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::rootInfoCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->rootInfoCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::rootInfoCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::map<int, EMainState>::iterator it;
    it = mCurrentMainStateMap.find(filedescriptor);
    if (it != mCurrentMainStateMap.end())
    {
        it->second = eInfoState;
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::listConnectionsCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listConnectionsCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listConnectionsCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;

    std::vector<am_Connection_s> listConnections;
    if(E_OK == mpDatabasehandler->getListConnections(listConnections))
    {
        std::stringstream output;
        output << "\tConnections: " << listConnections.size() << std::endl;
        for (std::vector<am_Connection_s>::iterator iter(listConnections.begin()); iter < listConnections.end(); iter++)
        {
            output << "\tID: " << iter->connectionID
                   << "\tSrcID: " << iter->sourceID
                   << "\tSinkID: " << iter->sinkID
                   << "\tFormat: " << iter->connectionFormat
                   << "\tdelay: " << iter->delay << std::endl;
        }
        sendTelnetLine(filedescriptor, output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListConnections");
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::listSourcesCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listSourcesCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listSourcesCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;

    std::vector<am_Source_s> listSources;
    if(E_OK == mpDatabasehandler->getListSources(listSources))
    {
        std::stringstream output;
        output << "\tSources: " << listSources.size() << std::endl;
        for (std::vector<am_Source_s>::iterator iter(listSources.begin()); iter < listSources.end(); iter++)
        {
            output << "\tID: " << iter->sourceID
                   << "\tName: " << iter->name
                   << "\tDomainID: " << iter->domainID
                   << "\tState: " << iter->sourceState
                   << "\tVolume: " << iter->volume << std::endl;
        }
        sendTelnetLine(filedescriptor, output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListSources");
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::listSinksCommands(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listSinksCommandsExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listSinksCommandsExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;

    std::vector<am_Sink_s> listSinks;
    if(E_OK == mpDatabasehandler->getListSinks(listSinks))
    {
        std::stringstream output;
        output << "\tSinks: " << listSinks.size() << std::endl;
        for (std::vector<am_Sink_s>::iterator iter(listSinks.begin()); iter < listSinks.end(); iter++)
        {
            output << "\tID: " << iter->sinkID
                   << "\tDomainID: " << iter->domainID
                   << "\tName: " << iter->name
                   << "\tAvailable: " << iter->available.availability
                   << "\tVolume: " << iter->volume << std::endl;
        }

        sendTelnetLine(filedescriptor, output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListSinks");
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::listCrossfaders(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listCrossfadersExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listCrossfadersExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;

    std::vector<am_Crossfader_s> listCrossfaders;
    if(E_OK == mpDatabasehandler->getListCrossfaders(listCrossfaders))
    {
        std::stringstream output;
        output << "\tCrossfaders: " << listCrossfaders.size() << std::endl;
        for (std::vector<am_Crossfader_s>::iterator iter(listCrossfaders.begin()); iter < listCrossfaders.end(); iter++)
        {
            output << "\tID: " << iter->crossfaderID
                   << "\tName: " << iter->name
                   << "\tSourceID: " << iter->sourceID << std::endl;
        }

        sendTelnetLine(filedescriptor, output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListCrossfaders");
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::listDomainsCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listDomainsCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listDomainsCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;

    std::vector<am_Domain_s> listDomains;
    if(E_OK == mpDatabasehandler->getListDomains(listDomains))
    {
        std::stringstream output;
        output << "\tDomains: " << listDomains.size() << std::endl;
        for (std::vector<am_Domain_s>::iterator iter(listDomains.begin()); iter < listDomains.end(); iter++)
        {
            output << "\tID: " << iter->domainID
                   << "\tName: " << iter->name
                   << "\tBusname: " << iter->busname
                   << "\tNodename: " << iter->nodename
                   << "\tState: " << static_cast<int>(iter->state) << std::endl;
        }

        sendTelnetLine(filedescriptor, output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListDomains");
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::listGatewaysCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listGatewaysCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listGatewaysCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;

    std::vector<am_Gateway_s> listGateways;
    if(E_OK == mpDatabasehandler->getListGateways(listGateways))
    {
        std::stringstream output;
        output << "\tGateways: " << listGateways.size();

        for( std::vector<am_Gateway_s>::iterator iter(listGateways.begin()); iter < listGateways.end(); iter++)
        {
            output << "\tID: " << iter->gatewayID
                   << "\tName: " << iter->name
                   << "\tSourceID: " << iter->sourceID
                   << "\tSinkID: " << iter->sinkID << std::endl;
        }
        sendTelnetLine(filedescriptor, output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListGateways");
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::getRoutingCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->getRoutingCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::getRoutingCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    (void) filedescriptor;
    //TODO: fill with function
}

/****************************************************************************/
void CAmTelnetMenuHelper::getSenderversionCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->getSenderversionCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::getSenderversionCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;

    std::stringstream output;
    output << "\tSender versions:" << std::endl << "\tCtrl: " << mpControlSender->getInterfaceVersion() << " | " << "Cmd: " << mpCommandSender->getInterfaceVersion() << " | " << "Routing: " << mpRoutingSender->getInterfaceVersion() << std::endl;

    sendTelnetLine(filedescriptor, output);
}

/****************************************************************************/
void CAmTelnetMenuHelper::getReceiverversionCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->getReceiverversionCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::getReceiverversionCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;

    std::stringstream output;
    output << "\tReceiver versions:" << std::endl << "\tCtrl: " << mpControlReceiver->getInterfaceVersion() << " | " << "Cmd: " << mpCommandReceiver->getInterfaceVersion() << " | " << "Routing: " << mpRoutingReceiver->getInterfaceVersion() << std::endl;

    sendTelnetLine(filedescriptor, output);

}

/****************************************************************************/
void CAmTelnetMenuHelper::infoSystempropertiesCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->infoSystempropertiesCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::infoSystempropertiesCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::vector<am_SystemProperty_s> listSystemProperties;

    if(E_OK == mpDatabasehandler->getListSystemProperties(listSystemProperties))
    {
        std::stringstream output;
        output << "\tSystemproperties: " << listSystemProperties.size() << std::endl;

        std::vector<am_SystemProperty_s>::iterator it;
        for (it = listSystemProperties.begin(); it < listSystemProperties.end(); it++)
        {
            output << "\tType: " << it->type << " Value: " << it->value << std::endl;
        }

        sendTelnetLine(filedescriptor, output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListSystemProperties");
    }


}

/****************************************************************************/
void CAmTelnetMenuHelper::setRoutingCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->setRoutingCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::setRoutingCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    if (CmdQueue.size() >= 2)
    {
        bool error = false;

        std::istringstream istream_sourceID(CmdQueue.front());
        CmdQueue.pop();
        std::istringstream istream_sinkID(CmdQueue.front());
        CmdQueue.pop();

        am_sourceID_t sourceID = 0;
        if (!(istream_sourceID >> sourceID))
            error = true;

        am_sinkID_t sinkID = 0;
        if (!(istream_sinkID >> sinkID))
            error = true;

        if (error)
        {
            sendError(filedescriptor, "Error parsing sourcID and sinkID");
            return;
        }

        std::vector<am_Route_s> routingList;
        if (E_OK == mpRouter->getRoute(true, sourceID, sinkID, routingList))
        {
            std::stringstream output;

            std::vector<am_Route_s>::iterator rlIter = routingList.begin();
            for (int rlCnt = 1; rlIter < routingList.end(); rlIter++)
            {
                output << "#" << rlCnt << " ";

                std::vector<am_RoutingElement_s>::iterator reIter = rlIter->route.begin();
                for (; reIter < rlIter->route.end(); reIter++)
                {
                    reIter->connectionFormat;
                    reIter->domainID;
                    output << ">(" << reIter->sourceID << ")->--[D:" << reIter->domainID << "][F:" << reIter->connectionFormat << "]-->-(" << reIter->sinkID << ")" << std::endl;
                }

                rlCnt++;
            }

            sendTelnetLine(filedescriptor, output);
        }
        else
        {
            sendError(filedescriptor, "Error getting route");
        }

    }
    else
    {
        if(!CmdQueue.empty())
           CmdQueue.pop();

        sendError(filedescriptor,"Not enough arguments to set routing. Please enter sourceID and sinkID after command");
    }

}

/****************************************************************************/
void CAmTelnetMenuHelper::setConnection(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->setConnectionExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::setConnectionExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    bool error = false;
    am_Error_e rError = E_OK;

    if (CmdQueue.size() >= 2)
    {
        std::istringstream istream_sourceID(CmdQueue.front());
        CmdQueue.pop();

        std::istringstream istream_sinkID(CmdQueue.front());
        CmdQueue.pop();

        am_sourceID_t sourceID = 0;
        if (!(istream_sourceID >> sourceID))
            error = true;

        am_sinkID_t sinkID = 0;
        if (!(istream_sinkID >> sinkID))
            error = true;

        if (error)
        {
            sendError(filedescriptor, "Error parsing sinkID and/or sourceID");
            return;
        }

        // Try to set up connection
        am_mainConnectionID_t connID = 0;
        rError = mpCommandReceiver->connect(sourceID, sinkID, connID);

        if (E_OK == rError)
        {
            std::stringstream output;
            output << "ConnID: " << connID << "\tSrc: " << sourceID << " ---> Sink: " << sinkID << std::endl;
            sendTelnetLine(filedescriptor, output);
        }
        else
        {
            sendError(filedescriptor, "Error connecting sourceID and sinkID");
        }

    }
    else
    {
        // remove 1 element if list is not empty
        if(!CmdQueue.empty())
           CmdQueue.pop();

        sendError(filedescriptor, "Not enough arguments to set routing. Please enter sourceID and sinkID after command");
        return;
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::setDisconnectConnId(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->setDisconnectConnIdExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::setDisconnectConnIdExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    am_mainConnectionID_t connID = 0;

    bool error = false;
    am_Error_e rError = E_OK;

    if (CmdQueue.size() >= 1)
    {
        std::istringstream istream_connID(CmdQueue.front());
        CmdQueue.pop();

        if (!(istream_connID >> connID))
            error = true;

        if (error)
        {
            sendError(filedescriptor, "Error parsing connID");
            return;
        }

        // Try to disconnect connection id
        rError = mpCommandReceiver->disconnect(connID);

        if (E_OK == rError)
        {
            std::stringstream output;
            output << "ConnID " << connID << " closed successfully! " << std::endl;
            sendTelnetLine(filedescriptor, output);
        }
        else
        {
            sendError(filedescriptor, "Error disconnecting connectionID");
        }
    }
    else
    {
        sendError(filedescriptor, "Not enough arguments to disconnect a Main Connection, please enter 'connectionID' after command");
        return;
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::setSourceSoundProperties(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->setConnectionExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::setSourceSoundPropertiesExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    if (CmdQueue.size() >= 3)
    {
        bool error = false;

        std::istringstream istream_sourceID(CmdQueue.front());
        CmdQueue.pop();

        std::istringstream istream_type(CmdQueue.front());
        CmdQueue.pop();

        std::istringstream istream_value(CmdQueue.front());
        CmdQueue.pop();

        unsigned int tmpType = 0;
        if (!(istream_type >> tmpType))
            error = true;

        am_MainSoundProperty_s soundProperty;
        if (tmpType < MSP_MAX)
            soundProperty.type = static_cast<am_MainSoundPropertyType_e>(tmpType);
        else
            error = true;

        if (!(istream_value >> soundProperty.value))
            error = true;

        am_sinkID_t sourceID = 0;
        if (!(istream_sourceID >> sourceID))
            error = true;

        if (error)
        {
            sendError(filedescriptor, "Error parsing MainSinkSoundProperty 'type', 'value' or 'sourceID'");
            return;
        }

        if (E_OK == mpCommandReceiver->setMainSourceSoundProperty(soundProperty, sourceID))
        {
            std::stringstream output;
            output << "MainSourceSoundProperty set: " << soundProperty.type << "->" << soundProperty.value << std::endl;
            sendTelnetLine(filedescriptor, output);
        }
        else
        {
            sendError(filedescriptor, "Error setMainSourceSoundProperty");
        }
    }
    else
    {
        sendError(filedescriptor, "Not enough arguments to set MainSourceSoundProperty, please enter 'sourceID', 'type' and 'value' after command");
        return;
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::setSinkSoundProperties(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->setConnectionExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::setSinkSoundPropertiesExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    unsigned int tmpType = 0;
    bool error = false;

    if (CmdQueue.size() >= 3)
    {
        std::istringstream istream_sinkID(CmdQueue.front());
        CmdQueue.pop();

        std::istringstream istream_type(CmdQueue.front());
        CmdQueue.pop();

        std::istringstream istream_value(CmdQueue.front());
        CmdQueue.pop();

        if (!(istream_type >> tmpType))
            error = true;

        am_MainSoundProperty_s soundProperty;
        if (tmpType < MSP_MAX)
            soundProperty.type = static_cast<am_MainSoundPropertyType_e>(tmpType);
        else
            error = true;

        if (!(istream_value >> soundProperty.value))
            error = true;

        am_sinkID_t sinkID = 0;
        if (!(istream_sinkID >> sinkID))
            error = true;

        if (error)
        {
            sendError(filedescriptor, "Error parsing MainSinkSoundProperty 'type', 'value' or 'sinkID'");
            return;
        }

        if (E_OK == mpCommandReceiver->setMainSinkSoundProperty(soundProperty, sinkID))
        {
            std::stringstream output;
            output << "MainSinkSoundProperty set: " << soundProperty.type << "->" << soundProperty.value << std::endl;
            sendTelnetLine(filedescriptor, output);
        }
        else
        {
            sendError(filedescriptor, "Error setMainSinkSoundProperty");
        }
    }
    else
    {
        sendError(filedescriptor, "Not enough arguments to set MainSinkSoundProperty, please enter 'sinkID', 'type' and 'value' after command");
        return;
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::listPluginsCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listPluginsCommandExec(CmdQueue, filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listPluginsCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::vector<std::string> PlugInNames;
    std::vector<std::string>::iterator iter;
    std::stringstream output;


    if(E_OK == mpCommandSender->getListPlugins(PlugInNames))
    {
        output << "\tCommandSender Plugins loaded: " << PlugInNames.size() << std::endl;

        for (iter = PlugInNames.begin(); iter < PlugInNames.end(); iter++)
        {
            output << iter->c_str() << std::endl;
        }
    }
    else
    {
        sendError(filedescriptor,"ERROR: mCommandSender->getListPlugins");
    }


    if(E_OK == mpRoutingSender->getListPlugins(PlugInNames))
    {
        output << std::endl << "\tRoutingSender Plugins loaded: " << PlugInNames.size() << std::endl;

        for (iter = PlugInNames.begin(); iter < PlugInNames.end(); iter++)
        {
            output << iter->c_str() << std::endl;
        }
    }
    else
    {
        sendError(filedescriptor,"ERROR: mRoutingSender->getListPlugins");
    }

    sendTelnetLine(filedescriptor, output);
}


/****************************************************************************/
void CAmTelnetMenuHelper::listMainSourcesCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listMainSourcesCommandExec(CmdQueue,filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listMainSourcesCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::vector<am_SourceType_s> listMainSources;

    if(E_OK == mpDatabasehandler->getListMainSources(listMainSources))
    {
        std::stringstream output;
        output << std::endl << "\tMainSources:  " << listMainSources.size() << std::endl;

        std::vector<am_SourceType_s>::iterator iter;
        for (iter = listMainSources.begin(); iter < listMainSources.end(); iter++)
        {
            output << "\t" << iter->name << "\tID: " << iter->sourceID
                           << "\tClassID: " << iter->sourceClassID
                           << "\tavailability: " << static_cast<int>(iter->availability.availability)
                           << "\tavailabilityReason: " << static_cast<int>(iter->availability.availabilityReason) << std::endl;
        }
        sendTelnetLine(filedescriptor,output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListMainSources");
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::listMainSinksCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listMainSinksCommandExec(CmdQueue,filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listMainSinksCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::vector<am_SinkType_s> listMainSinks;

    if(E_OK == mpDatabasehandler->getListMainSinks(listMainSinks))
    {
        std::stringstream output;
        output << std::endl << "\tMainSinks: " << listMainSinks.size() << std::endl;

        std::vector<am_SinkType_s>::iterator iter;
        for (   iter = listMainSinks.begin(); iter < listMainSinks.end(); iter++)
        {
            output << "\t" << iter->name << "\tID: " << iter->sinkID
                           << "\tClassID: " << iter->sinkClassID
                           << "\tavailability: " << static_cast<int>(iter->availability.availability)
                           << "\tavailabilityReason: " << static_cast<int>(iter->availability.availabilityReason)
                           << "\tMuteState: " << iter->muteState
                           << "\tVolume: " << iter->volume << std::endl;
        }
        sendTelnetLine(filedescriptor,output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListMainSinks");
    }
}

/****************************************************************************/
void CAmTelnetMenuHelper::listMainConnectionsCommand(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    instance->listMainConnectionsCommandExec(CmdQueue,filedescriptor);
}

/****************************************************************************/
void CAmTelnetMenuHelper::listMainConnectionsCommandExec(std::queue<std::string> & CmdQueue, int & filedescriptor)
/****************************************************************************/
{
    (void) CmdQueue;
    std::vector<am_MainConnection_s> listMainConnections;

    if(E_OK == mpDatabasehandler->getListMainConnections(listMainConnections))
    {
        std::stringstream output;
        output << std::endl << "\tMainConnections: " << listMainConnections.size() << std::endl;

        std::vector<am_MainConnection_s>::iterator iter;
        for (iter = listMainConnections.begin(); iter < listMainConnections.end(); iter++)
        {
            output << "\tID: " << iter->mainConnectionID
                   << "\tState: " << iter->connectionState
                   << "\tDelay: " << iter->delay
                   << "\tsourceID: " << iter->sourceID
                   << "\tsinkID: " << iter->sinkID << std::endl;

            output << "ConnectionIDs: ";
            std::vector<am_connectionID_t>::iterator list_connIDs_iter = iter->listConnectionID.begin();
            for(;list_connIDs_iter < iter->listConnectionID.end();list_connIDs_iter++)
            {
                output << *list_connIDs_iter << " ";
            }

            output << std::endl;
        }
        sendTelnetLine(filedescriptor,output);
    }
    else
    {
        sendError(filedescriptor,"ERROR: mDatabasehandler->getListMainSinks");
    }
}






