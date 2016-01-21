/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_learnjni_NdkUtils */

#ifndef _Included_com_example_learnjni_NdkUtils
#define _Included_com_example_learnjni_NdkUtils
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    setNumber
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_example_learnjni_NdkUtils_setNumber
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    getNumber
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_learnjni_NdkUtils_getNumber
  (JNIEnv *, jclass);

/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    getStringFromJni
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_learnjni_NdkUtils_getStringFromJni
  (JNIEnv *, jclass);

/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    convertToUpper
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_learnjni_NdkUtils_convertToUpper
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    totalIntArray
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_com_example_learnjni_NdkUtils_totalIntArray
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    IntArrayAdd10
 * Signature: ([I)[I
 */
JNIEXPORT jintArray JNICALL Java_com_example_learnjni_NdkUtils_IntArrayAdd10
  (JNIEnv *, jclass, jintArray);

#ifdef __cplusplus
}
#endif
#endif