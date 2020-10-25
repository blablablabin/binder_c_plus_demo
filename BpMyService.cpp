#define LOG_TAG "BpMyService"
#include <utils/Log.h>
#include <binder/IInterface.h>
#include "BpMyService.h"

    /*（一般也可以定义在IMyService.cpp中实现）*/
namespace android{

    //BpMyService 构造函数初始化，在IMyService.cpp里会实例化new BpMyService对象
    BpMyService::BpMyService(const sp<IBinder>& impl) 
        
        /* 
           BpInterface是一个模板类，传入什么继承什么;这里会把IBinder impl对象
           赋给BpRefBase类中的BpRefBase变量保存，最终会调用到BpRefBase的构造函数，
           将BpRefBase又赋给 mRemote
        */
        : BpInterface<IMyService>(impl){

    }

    //接收处理客户端set操作
    void BpMyService::setValue(int32_t value) {
        Parcel data, reply;
        data.writeInterfaceToken(String16("IMyService"));
        data.writeInt32(value);
        //传递给BnMyservice::onTransact进行处理
        remote()->transact(1, data, &reply);
    }

    //接收处理客户端get操作
    int32_t BpMyService::getValue() {
        Parcel data, reply;
        data.writeInterfaceToken(String16("IMyService"));
        //传递给BnMyservice::onTransact进行处理
        remote()->transact(2, data, &reply);
        return reply.readInt32();
    }
};