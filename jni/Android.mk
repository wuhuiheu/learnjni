LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := learnjni
LOCAL_SRC_FILES := com_example_learnjni_NdkUtils.cpp

# for logging
LOCAL_LDLIBS +=-llog

include $(BUILD_SHARED_LIBRARY)
