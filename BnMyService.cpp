#define LOG_TAG "BnMyService"

#include <utils/Log.h>
#include <binder/IInterface.h>
#include "BnMyService.h"


namespace android{

    /*
        void BnMyService:: setValue(uint32_t value){
            ALOGD("setValue is %d",value);
            myValue =value;
        }

        int32_t BnMyService:: getValue(){
            return myValue;
        }
    */


    /* 
        服务端处理函数
        BBinder的子类，需重写onTransact函数，用来解析客户端发来的消息
    */
    status_t BnMyService::onTransact(uint32_t code, const Parcel& data, \
                    Parcel* reply, uint32_t flags){
       
       // 解析客户端传过来的code值
        switch (code) {
            case SET_VALUE: {
                //解析客户端发来的data 数据
                int32_t nums =data.readInt32();
                setValue(nums);
                break;
            }
            case GET_VALUE: {
                int32_t result = getValue();
                // 将result写入reply，返回给客户端
                reply->writeInt32(result);
                break;
            }
        }
        return NO_ERROR;
    }
};