#ifndef ANDROID_BPMYSERVICE_H
#define ANDROID_BPMYSERVICE_H

#include <binder/Binder.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

#include "IMyService.h"


    /*   提供给客户端使用的接口
        （一般也可以定义在IMyService.h中）
     */
namespace android{

    // 继承BpInterface类，IMyService类，同时也间接继承BpRefBase
    class BpMyService: public BpInterface<IMyService>{

        public:
            //定义BpMyService 构造函数
            BpMyService(const sp<IBinder>& impl);

            //定义可以操作的客户端函数接口
            virtual void setValue(int32_t value);
            virtual int32_t getValue();

    };
};

#endif // ANDROID_BPMYSERVICE_H