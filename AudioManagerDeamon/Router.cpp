/**
 * Copyright (C) 2011, BMW AG
 *
 * AudioManangerDeamon
 *
 * \file Router.cpp
 *
 * \date 20.05.2011
 * \author Christian Müller (christian.ei.mueller@bmw.de)
 *
 * \section License
 * GNU Lesser General Public License, version 2.1, with special exception (GENIVI clause)
 * Copyright (C) 2011, BMW AG – Christian Müller  Christian.ei.mueller@bmw.de
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License, version 2.1, as published by the Free Software Foundation.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License, version 2.1, for more details.
 * You should have received a copy of the GNU Lesser General Public License, version 2.1, along with this program; if not, see <http://www.gnu.org/licenses/lgpl-2.1.html>.
 * Note that the copyright holders assume that the GNU Lesser General Public License, version 2.1, may also be applicable to programs even in cases in which the program is not a library in the technical sense.
 * Linking AudioManager statically or dynamically with other modules is making a combined work based on AudioManager. You may license such other modules under the GNU Lesser General Public License, version 2.1. If you do not want to license your linked modules under the GNU Lesser General Public License, version 2.1, you may use the program under the following exception.
 * As a special exception, the copyright holders of AudioManager give you permission to combine AudioManager with software programs or libraries that are released under any license unless such a combination is not permitted by the license of such a software program or library. You may copy and distribute such a system following the terms of the GNU Lesser General Public License, version 2.1, including this special exception, for AudioManager and the licenses of the other code concerned.
 * Note that people who make modified versions of AudioManager are not obligated to grant this special exception for their modified versions; it is their choice whether to do so. The GNU Lesser General Public License, version 2.1, gives permission to release a modified version without this exception; this exception also makes it possible to release a modified version which carries forward this exception.
 *
 *
 */

#include <qstring.h>
#include <QMutableListIterator>
#include <iostream>
#include <stdio.h>

#include "DataBaseHandler.h"
#include "Router.h"

Router::Router() {
}

Router::~Router() {
}

void Router::registerDatabasehandler(DataBaseHandler* db_handler) {
	m_dbHandler = db_handler;
}

bool Router::get_Route_from_Source_ID_to_Sink_ID(const bool onlyfree,
		const source_t Source_ID, const sink_t Sink_ID,
		QList<genRoute_t>* ReturnList) {

	domain_t Source_Domain = m_dbHandler->get_Domain_ID_from_Source_ID(
			Source_ID); //first find out in which domains the source and sink are
	domain_t Sink_Domain = m_dbHandler->get_Domain_ID_from_Sink_ID(Sink_ID);

	if (Source_Domain == -1 || Sink_Domain == -1) {
		return false;
	} //if source or sink does not exists, exit here

	RoutingTree routingtree(Source_Domain); //Build up a Tree from the Source_Domain to every other domain.
	QList<RoutingTreeItem*> flattree; //This list is the flat tree
	QList<RoutingTreeItem*> matchtree; //This List holds all TreeItems which have the right Domain Sink IDs
	QList<gateway_t> gwids; //holds all gateway ids of the route
	genRoutingElement_t element;
	QList<genRoutingElement_t> actualRoutingElement;//intermediate list of current routing pairs
	genRoute_t actualRoute; //holds the actual Route
	source_t ReturnSource = 0;
	sink_t ReturnSink = 0;
	source_t LastSource = 0;
	domain_t ReturnDomain = 0;

	//TODO: kind of unclean. The separation between database and router could be better.
	m_dbHandler->get_Domain_ID_Tree(onlyfree, &routingtree, &flattree); //Build up the tree out of the database as

	//we go through the returned flattree and look for our sink, after that flattree holds only treeItems that match
	foreach (RoutingTreeItem* rTree,flattree)
		{
			if (rTree->returnDomainID() == Sink_Domain) {
				matchtree.append(rTree);
			}
		}

	//No we need to trace back the routes for each entry in matchtree
	foreach (RoutingTreeItem* match, matchtree)
		{
			//getting the route for the actual item
			actualRoute.len = routingtree.getRoute(match, &gwids); //This gives only the Gateway IDs we need more

			//go throught the gatewayids and get more information
			for (int i = 0; i < gwids.length(); i++) {
				m_dbHandler->get_Gateway_Source_Sink_Domain_ID_from_ID(
						gwids.value(i), &ReturnSource, &ReturnSink,
						&ReturnDomain);
				//first routing pair is source to ReturnSink of course;
				if (i == 0) {
					element.source = Source_ID;
					element.sink = ReturnSink;
					element.Domain_ID = Source_Domain;
				} else {
					element.source = LastSource;
					element.sink = ReturnSink;
					element.Domain_ID = ReturnDomain;
				}
				actualRoutingElement.append(element);
				LastSource = ReturnSource;
			}
			element.source = LastSource;
			element.sink = Sink_ID;
			element.Domain_ID = Sink_Domain;
			actualRoutingElement.append(element);

			actualRoute.Source_ID = Source_ID;
			actualRoute.Sink_ID = Sink_ID;
			actualRoute.route = actualRoutingElement;
			ReturnList->append(actualRoute);
		}

	return true;
	//TODO: return actual status !
}

RoutingTreeItem::RoutingTreeItem(const domain_t Domain_Id,
		const gateway_t Gateway_Id, RoutingTreeItem *parent) {
	parentItem = parent;
	m_domainID = Domain_Id;
	m_gatewayID = Gateway_Id;
}

RoutingTreeItem::RoutingTreeItem() {

}

RoutingTreeItem::~RoutingTreeItem() {
	qDeleteAll(childItems);
}

void RoutingTreeItem::appendChild(RoutingTreeItem *item) {
	childItems.append(item);
}

RoutingTreeItem *RoutingTreeItem::return_Parent() {
	return parentItem;
}

domain_t RoutingTreeItem::returnDomainID() {
	return m_domainID;
}

gateway_t RoutingTreeItem::returnGatewayID() {
	return m_gatewayID;
}

RoutingTree::RoutingTree(const domain_t Root_ID) :
	m_rootItem(RoutingTreeItem(Root_ID)) {
}

RoutingTree::~RoutingTree() {
}

RoutingTreeItem* RoutingTree::insertItem(const domain_t Domain_ID,
		const gateway_t Gateway_ID, RoutingTreeItem *parentItem) {
	RoutingTreeItem *newTree = new RoutingTreeItem(Domain_ID, Gateway_ID,
			parentItem);
	parentItem->appendChild(newTree);
	m_allChildList.append(newTree);
	return newTree;
}

int RoutingTree::getRoute(RoutingTreeItem* Targetitem, QList<gateway_t>* route) {
	int hopps = 0;
	RoutingTreeItem *parentItem = Targetitem;
	while (parentItem != &m_rootItem) {
		route->prepend(parentItem->returnGatewayID());
		hopps++;
		parentItem = parentItem->return_Parent();
	}
	return hopps;
}

int RoutingTree::returnRootDomainID() {
	return m_rootItem.returnDomainID();
}

RoutingTreeItem* RoutingTree::returnRootItem() {
	return &m_rootItem;
}

void Bushandler::load_Bus_plugins() {
	RoutingSendInterface *b = NULL;
	char BusName[40];
	Bus newBus;
	foreach (QObject *plugin, QPluginLoader::staticInstances())
		{
			strcpy(BusName, "");
			RoutingInterfaceFactory* busInterfaceFactory = qobject_cast<
					RoutingInterfaceFactory *> (plugin);
			if (busInterfaceFactory) {
				b = busInterfaceFactory->returnInstance();
				b->return_BusName(BusName);
				newBus.Name = QString(BusName);
				newBus.sendInterface = b;
				Busses.append(newBus);
				QObject::connect((const QObject*) this,
						SIGNAL (signal_system_ready(void)), (const QObject*) b,
						SLOT(slot_system_ready(void)));
				DLT_LOG(AudioManager,DLT_LOG_INFO, DLT_STRING("Bushandler:Found new bus interface"), DLT_STRING(newBus.Name.toAscii()));
			}
		}
}

void Bushandler::StartupInterfaces() {
	foreach (Bus bus, Busses)
		{
			bus.sendInterface->startup_interface(m_receiver);
			DLT_LOG(AudioManager,DLT_LOG_INFO, DLT_STRING("Bushandler:Started Interface"), DLT_STRING(bus.Name.toAscii()));
		}
	emit signal_system_ready();
}

void Bushandler::registerReceiver(RoutingReceiver * receiver) {
	m_receiver = receiver;
}

RoutingSendInterface* Bushandler::getInterfaceforBus(QString bus) {
	foreach (Bus b, Busses)
		{
			if (b.Name.compare(bus) == 0) {
				return b.sendInterface;
			}
		}
	return NULL;
}

