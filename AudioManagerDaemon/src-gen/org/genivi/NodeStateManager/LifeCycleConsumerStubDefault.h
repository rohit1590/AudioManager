/*
* This file was generated by the CommonAPI Generators.
*
 * Copyright (C) 2013, BMW AG
 *
 * \author Christian Linke, christian.linke@bmw.de BMW 2012,2013
*/
#ifndef ORG_GENIVI_NODESTATEMANAGER_Life_Cycle_Consumer_STUB_DEFAULT_H_
#define ORG_GENIVI_NODESTATEMANAGER_Life_Cycle_Consumer_STUB_DEFAULT_H_

#include <org/genivi/NodeStateManager/LifeCycleConsumerStub.h>

namespace org {
namespace genivi {
namespace NodeStateManager {

/**
 * Provides a default implementation for LifeCycleConsumerStubRemoteEvent and
 * LifeCycleConsumerStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 * 
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class LifeCycleConsumerStubDefault : public LifeCycleConsumerStub {
 public:
    LifeCycleConsumerStubDefault();

    LifeCycleConsumerStubRemoteEvent* initStubAdapter(const std::shared_ptr<LifeCycleConsumerStubAdapter>& stubAdapter);


    virtual void LifecycleRequest(uint32_t Request, uint32_t RequestId, int32_t& ErrorCode);

    

 protected:
    
 private:
    class RemoteEventHandler: public LifeCycleConsumerStubRemoteEvent {
     public:
        RemoteEventHandler(LifeCycleConsumerStubDefault* defaultStub);


     private:
        LifeCycleConsumerStubDefault* defaultStub_;
    };

    RemoteEventHandler remoteEventHandler_;
    std::shared_ptr<LifeCycleConsumerStubAdapter> stubAdapter_;

};

} // namespace NodeStateManager
} // namespace genivi
} // namespace org

#endif // ORG_GENIVI_NODESTATEMANAGER_Life_Cycle_Consumer_STUB_DEFAULT_H_
