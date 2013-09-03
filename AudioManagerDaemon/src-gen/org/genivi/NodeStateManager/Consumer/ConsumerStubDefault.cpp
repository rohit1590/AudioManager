/*
* This file was generated by the CommonAPI Generators.
*
 * Copyright (C) 2012, BMW AG
 *
 * This file is part of GENIVI Project AudioManager.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *
 * \author Aleksandar Donchev, aleksander.donchev@partner.bmw.de BMW 2013
 *
 * For further information see http://www.genivi.org/.
*/
#include <org/genivi/NodeStateManager/Consumer/ConsumerStubDefault.h>

namespace org {
namespace genivi {
namespace NodeStateManager {
namespace Consumer {

ConsumerStubDefault::ConsumerStubDefault():
        remoteEventHandler_(this) {
}

ConsumerStubRemoteEvent* ConsumerStubDefault::initStubAdapter(const std::shared_ptr<ConsumerStubAdapter>& stubAdapter) {
    stubAdapter_ = stubAdapter;
    return &remoteEventHandler_;
}

const int32_t& ConsumerStubDefault::getRestartReasonAttribute() {
    return restartReasonAttributeValue_;
}

void ConsumerStubDefault::setRestartReasonAttribute(int32_t value) {
    const bool valueChanged = trySetRestartReasonAttribute(std::move(value));
    if (valueChanged)
        stubAdapter_->fireRestartReasonAttributeChanged(restartReasonAttributeValue_);
}

void ConsumerStubDefault::onRemoteRestartReasonAttributeChanged() {
    // No operation in default
}

bool ConsumerStubDefault::trySetRestartReasonAttribute(int32_t value) {
    if (!validateRestartReasonAttributeRequestedValue(value))
        return false;

    const bool valueChanged = (restartReasonAttributeValue_ != value);
    restartReasonAttributeValue_ = std::move(value);
    return valueChanged;
}

bool ConsumerStubDefault::validateRestartReasonAttributeRequestedValue(const int32_t& value) {
    return true;
}

bool ConsumerStubDefault::RemoteEventHandler::onRemoteSetRestartReasonAttribute(int32_t value) {
    return defaultStub_->trySetRestartReasonAttribute(std::move(value));
}

void ConsumerStubDefault::RemoteEventHandler::onRemoteRestartReasonAttributeChanged() {
    defaultStub_->onRemoteRestartReasonAttributeChanged();
}

const int32_t& ConsumerStubDefault::getShutdownReasonAttribute() {
    return shutdownReasonAttributeValue_;
}

void ConsumerStubDefault::setShutdownReasonAttribute(int32_t value) {
    const bool valueChanged = trySetShutdownReasonAttribute(std::move(value));
    if (valueChanged)
        stubAdapter_->fireShutdownReasonAttributeChanged(shutdownReasonAttributeValue_);
}

void ConsumerStubDefault::onRemoteShutdownReasonAttributeChanged() {
    // No operation in default
}

bool ConsumerStubDefault::trySetShutdownReasonAttribute(int32_t value) {
    if (!validateShutdownReasonAttributeRequestedValue(value))
        return false;

    const bool valueChanged = (shutdownReasonAttributeValue_ != value);
    shutdownReasonAttributeValue_ = std::move(value);
    return valueChanged;
}

bool ConsumerStubDefault::validateShutdownReasonAttributeRequestedValue(const int32_t& value) {
    return true;
}

bool ConsumerStubDefault::RemoteEventHandler::onRemoteSetShutdownReasonAttribute(int32_t value) {
    return defaultStub_->trySetShutdownReasonAttribute(std::move(value));
}

void ConsumerStubDefault::RemoteEventHandler::onRemoteShutdownReasonAttributeChanged() {
    defaultStub_->onRemoteShutdownReasonAttributeChanged();
}

const int32_t& ConsumerStubDefault::getWakeUpReasonAttribute() {
    return wakeUpReasonAttributeValue_;
}

void ConsumerStubDefault::setWakeUpReasonAttribute(int32_t value) {
    const bool valueChanged = trySetWakeUpReasonAttribute(std::move(value));
    if (valueChanged)
        stubAdapter_->fireWakeUpReasonAttributeChanged(wakeUpReasonAttributeValue_);
}

void ConsumerStubDefault::onRemoteWakeUpReasonAttributeChanged() {
    // No operation in default
}

bool ConsumerStubDefault::trySetWakeUpReasonAttribute(int32_t value) {
    if (!validateWakeUpReasonAttributeRequestedValue(value))
        return false;

    const bool valueChanged = (wakeUpReasonAttributeValue_ != value);
    wakeUpReasonAttributeValue_ = std::move(value);
    return valueChanged;
}

bool ConsumerStubDefault::validateWakeUpReasonAttributeRequestedValue(const int32_t& value) {
    return true;
}

bool ConsumerStubDefault::RemoteEventHandler::onRemoteSetWakeUpReasonAttribute(int32_t value) {
    return defaultStub_->trySetWakeUpReasonAttribute(std::move(value));
}

void ConsumerStubDefault::RemoteEventHandler::onRemoteWakeUpReasonAttributeChanged() {
    defaultStub_->onRemoteWakeUpReasonAttributeChanged();
}

const int32_t& ConsumerStubDefault::getBootModeAttribute() {
    return bootModeAttributeValue_;
}

void ConsumerStubDefault::setBootModeAttribute(int32_t value) {
    const bool valueChanged = trySetBootModeAttribute(std::move(value));
    if (valueChanged)
        stubAdapter_->fireBootModeAttributeChanged(bootModeAttributeValue_);
}

void ConsumerStubDefault::onRemoteBootModeAttributeChanged() {
    // No operation in default
}

bool ConsumerStubDefault::trySetBootModeAttribute(int32_t value) {
    if (!validateBootModeAttributeRequestedValue(value))
        return false;

    const bool valueChanged = (bootModeAttributeValue_ != value);
    bootModeAttributeValue_ = std::move(value);
    return valueChanged;
}

bool ConsumerStubDefault::validateBootModeAttributeRequestedValue(const int32_t& value) {
    return true;
}

bool ConsumerStubDefault::RemoteEventHandler::onRemoteSetBootModeAttribute(int32_t value) {
    return defaultStub_->trySetBootModeAttribute(std::move(value));
}

void ConsumerStubDefault::RemoteEventHandler::onRemoteBootModeAttributeChanged() {
    defaultStub_->onRemoteBootModeAttributeChanged();
}


void ConsumerStubDefault::GetNodeState(int32_t& NodeStateId, int32_t& ErrorCode) {
    // No operation in default
}

void ConsumerStubDefault::SetSessionState(std::string SessionName, std::string SessionOwner, int32_t SeatID, int32_t SessionState, int32_t& ErrorCode) {
    // No operation in default
}

void ConsumerStubDefault::GetSessionState(std::string SessionName, int32_t SeatID, int32_t& SessionState, int32_t& ErrorCode) {
    // No operation in default
}

void ConsumerStubDefault::GetApplicationMode(int32_t& ApplicationModeId, int32_t& ErrorCode) {
    // No operation in default
}

void ConsumerStubDefault::RegisterShutdownClient(std::string BusName, std::string ObjName, uint32_t ShutdownMode, uint32_t TimeoutMs, int32_t& ErrorCode) {
    // No operation in default
}

void ConsumerStubDefault::UnRegisterShutdownClient(std::string BusName, std::string ObjName, uint32_t ShutdownMode, int32_t& ErrorCode) {
    // No operation in default
}

void ConsumerStubDefault::RegisterSession(std::string SessionName, std::string SessionOwner, int32_t SeatID, int32_t SessionState, int32_t& ErrorCode) {
    // No operation in default
}

void ConsumerStubDefault::UnRegisterSession(std::string SessionName, std::string SessionOwner, int32_t SeatID, int32_t& ErrorCode) {
    // No operation in default
}

void ConsumerStubDefault::GetAppHealthCount(uint32_t& Count) {
    // No operation in default
}

void ConsumerStubDefault::GetInterfaceVersion(uint32_t& Version) {
    // No operation in default
}

void ConsumerStubDefault::LifecycleRequestComplete(uint32_t RequestId, int32_t Status, int32_t& ErrorCode) {
    // No operation in default
}


void ConsumerStubDefault::fireNodeStateEvent(const int32_t& NodeState) {
    stubAdapter_->fireNodeStateEvent(NodeState);
}
void ConsumerStubDefault::fireNodeApplicationModeEvent(const int32_t& ApplicationModeId) {
    stubAdapter_->fireNodeApplicationModeEvent(ApplicationModeId);
}
void ConsumerStubDefault::fireSessionStateChangedEvent(const std::string& SessionStateName, const int32_t& SeatID, const int32_t& SessionState) {
    stubAdapter_->fireSessionStateChangedEvent(SessionStateName, SeatID, SessionState);
}

ConsumerStubDefault::RemoteEventHandler::RemoteEventHandler(ConsumerStubDefault* defaultStub):
        defaultStub_(defaultStub) {
}

} // namespace Consumer
} // namespace NodeStateManager
} // namespace genivi
} // namespace org