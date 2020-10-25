#define LOG_TAG "MyService"

#include <stdint.h>
#include <sys/types.h>

#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "IMyService.h"
#include "BpMyService.h"

namespace android{

    //初始化描述符变量descriptor，并实现getInterfaceDescriptor (),asInterface()函数
    //asInterface()函数会new BpMyService(BpBinder)
    IMPLEMENT_META_INTERFACE(MyService, "android.test.IMyService")
};