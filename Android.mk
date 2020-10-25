LOCAL_PATH:= $(call my-dir)


# /* ------server------- */
include $(CLEAR_VARS)

LOCAL_C_INCLUDES +=frameworks/native/include/binder \
					external/libcxx/include \

LOCAL_SRC_FILES += \
	IMyService.cpp \
	ServerTest.cpp \
	MyServices.cpp \
	BpMyService.cpp \
	BnMyService.cpp \

LOCAL_SHARED_LIBRARIES += \
	libbinder \
	libcutils \
	libutils \
	liblog \
	libc++ \

LOCAL_CFLAGS := -Wno-unused-parameter -Wunused-variable -Wunused-label -std=c++11

LOCAL_MODULE := myserverdemo
LOCAL_MODULE_TAGS := optional
#LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_EXECUTABLE)


# /* ------client------- */
include $(CLEAR_VARS)
LOCAL_C_INCLUDES +=frameworks/native/include/binder \
					external/libcxx/include \

LOCAL_SRC_FILES := \
			ClientTest.cpp \
			IMyService.cpp \
			BpMyService.cpp \

LOCAL_SHARED_LIBRARIES += \
	libbinder \
	libcutils \
	libutils \
	liblog \
	libc++ \

LOCAL_CFLAGS := -Wno-unused-parameter -Wunused-variable -Wunused-label -std=c++11

LOCAL_MODULE := myclientdemo
LOCAL_MODULE_TAGS := optional
#LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_EXECUTABLE)