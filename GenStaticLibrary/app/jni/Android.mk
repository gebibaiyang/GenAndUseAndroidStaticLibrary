LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    := mystaticLibrary
LOCAL_SRC_FILES := MathLib.cpp
LOCAL_INCLUDES  := ./

include $(BUILD_STATIC_LIBRARY)
