#include <jni.h>
#include <string>
void crash() {
    volatile int *a = (int *) (NULL);
    *a = 1;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_test_jnitest2_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    crash();
    return env->NewStringUTF(hello.c_str());
}


