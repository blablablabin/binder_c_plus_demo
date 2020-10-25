#define LOG_TAG "ClientTest"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <string>
#include "IMyService.h"

using namespace android;

int main(int argc,char **argv){

    // 获取ServiceMnager代理
    sp<IServiceManager> sm = defaultServiceManager();
    // 获取要通讯的目标service
    //获取服务的代理，binder是BpBinder(handle)对象，MyServiceProxy实际是BpMyService
    sp<IBinder> binder = sm->getService(String16("MyServiceDemo"));
    //interface_cast会调用到asInterface()函数,最终返回Bp代理对象
    sp<IMyService> MyServiceProxy =interface_cast<IMyService>(binder);

    if (argv[1] == std::string("set")) {
        int32_t value = atoi(argv[2]);
        ALOGD("client setValue %d", value);
        MyServiceProxy->setValue(value);
    } else if (argv[1] == std::string("get")) {
        int32_t getValue =0;
        getValue =MyServiceProxy->getValue();
        ALOGD("client getValue %d ",getValue);
    }

    return 0;
}

