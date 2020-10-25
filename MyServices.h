#ifndef ANDROID_MYSERVICE_H
#define ANDROID_MYSERVICE_H



#include <binder/Binder.h>
#include <binder/Parcel.h>
#include "BnMyService.h"

namespace android {
        //继承BnMyService
        class MyServices: public BnMyService {
        public:
                MyServices();
                ~MyServices();
                virtual void setValue(int32_t value);
                virtual int32_t getValue();
        //private:
        int32_t myVlue = 0;
        };
}
#endif //ANDROID_MYSERVICE_H