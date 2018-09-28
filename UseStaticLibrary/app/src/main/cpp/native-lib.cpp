#include <jni.h>
#include <string>
#include "MathLib.h"

extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_yangdaokuan_usestaticlibrary_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    char resultBuff[10];
    sprintf(resultBuff, "%d", MathLib::add(10000,2345));
    hello+= resultBuff;
    return env->NewStringUTF(hello.c_str());
}
