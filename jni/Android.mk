LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := learnjni
LOCAL_SRC_FILES := 

# for logging
LOCAL_LDLIBS +=-llog

MY_SWIG_PACKAGE := com.example.learnjni
MY_SWIG_INTERFACES := Example.i
MY_SWIG_TYPE := c
include $(LOCAL_PATH)/my_swig_generate.mk

include $(BUILD_SHARED_LIBRARY)
