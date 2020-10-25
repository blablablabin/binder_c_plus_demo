#define LOG_TAG "ServerTset"
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "MyServices.h"

using namespace android;

int main( int argc, char **argv)
{

    //open,mmap
    sp<ProcessState> proc(ProcessState::self());
    //get SM
    sp<IServiceManager> sm = defaultServiceManager();
    sm->addService(String16("MyServiceDemo"), new MyServices());
    
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}


