#ifndef ANDROID_BNMYSERVICE_H
#define ANDROID_BNMYSERVICE_H

#include <binder/Binder.h>
#include <binder/Parcel.h>

#include "IMyService.h"

    /* 提供给服务端的接口，主要是服务端处理与binder通信的业务接口定义 
      （一般也可以定义在IMyService.h中）
    */
namespace android{

    //继承BnInterface类,IMyService类，同时也间接继承BBinder
    class BnMyService: public BnInterface<IMyService>{

        public:
            enum{
                SET_VALUE =1,
                GET_VALUE,
                MAX_VALUE
            };

            virtual status_t onTransact(uint32_t code, const Parcel& data, \
                    Parcel* reply, uint32_t flags = 0);
    };
};

#endif //ANDROID_BNMYSERVICE_H