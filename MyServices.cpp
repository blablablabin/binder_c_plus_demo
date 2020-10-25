#define LOG_TAG "MyService"
#include <utils/Log.h>
#include <binder/IInterface.h>
#include "MyServices.h"
#include "IMyService.h"

namespace android {

    MyServices::MyServices() {
        ALOGD("MyServices() ...");
    }

    MyServices::~MyServices() {

    }

    void MyServices::setValue(int32_t value) {
        ALOGD("setValue: %d", value);
        myValue = value;
    }

    int32_t MyServices::getValue() {
        return myValue;
    }
};