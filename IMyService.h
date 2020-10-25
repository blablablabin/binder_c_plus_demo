#ifndef ANDROID_IMYSERVICE_H
#define ANDROID_IMYSERVICE_H

#include <binder/Binder.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

        /* 接口定义文件 */
namespace android {
    
    // 继承IInterface类，同时也间接继承了RefBase
    class IMyService: public IInterface {

        public:
        // 宏定义描述符变量descriptor，asInterface()和getInterfaceDescriptor()函数
        DECLARE_META_INTERFACE(MyService);

        // 声明纯虚函数，需子类实现
        virtual void setValue(int32_t value) =0;
        virtual int32_t getValue() =0;

        int32_t myValue =0;
    };
};

#endif //ANDROID_IMYSERVICE_H