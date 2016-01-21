#include "com_example_learnjni_NdkUtils.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <android/log.h>

#define TAG ("NdkUtils-jni")
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

int number = 0;

/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    setNumber
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_example_learnjni_NdkUtils_setNumber
  (JNIEnv *env, jclass thiz, jint i)
{
	number = i;
}

/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    getNumber
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_learnjni_NdkUtils_getNumber
  (JNIEnv *env, jclass thiz)
{
	return number;
}

//演示如何返回字符串给java层
/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    getStringFromJni
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_learnjni_NdkUtils_getStringFromJni
  (JNIEnv *env, jclass thiz)
{
	return env->NewStringUTF("Hello World from jni");
}

//演示将java层传过来的字符串做一些转换，再返回给java
/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    convertToUpper
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_learnjni_NdkUtils_convertToUpper
  (JNIEnv *env, jclass thiz, jstring jString)
{
	const char *str = env->GetStringUTFChars(jString, NULL);
	char cap[128];
	strcpy(cap, str);

	env->ReleaseStringChars(jString, (jchar *)str);//char和jchar一样
	int i = 0;
	size_t len = strlen(cap);
	for(i = 0; i < len; i++)
	{
		*(cap+i) = toupper(*(cap+i));
	}

	return env->NewStringUTF(cap);

}

//演示java传一个int数组给jni
/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    totalIntArray
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_com_example_learnjni_NdkUtils_totalIntArray
  (JNIEnv *env, jclass thiz, jintArray intArray)
{
	int len = env->GetArrayLength(intArray);//获取数组对象元素个数
	jint *numbers = env->GetIntArrayElements(intArray, NULL);//获取数组中所有元素
	int total = 0;
	int i = 0;

	for(i = 0; i < len; i++)
	{
		total += *(numbers + i);
	}
	return total;
}


//演示java传int数组过来，jni处理一个，再返回一个int数组
/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    IntArrayAdd10
 * Signature: ([I)[I
 */
JNIEXPORT jintArray JNICALL Java_com_example_learnjni_NdkUtils_IntArrayAdd10
  (JNIEnv *env, jclass thiz, jintArray intArray)
{

	int len = env->GetArrayLength(intArray);//获取数组对象元素个数
	jint *numbers = env->GetIntArrayElements(intArray, NULL);//获取数组中所有元素

	jintArray add10IntArray;
	add10IntArray = env->NewIntArray(len);//生成jintArray

	int i = 0;
	for(i = 1; i <= len; i++)
	{
		jint add10 = *(numbers + i - 1) + 10;
		env->SetIntArrayRegion(add10IntArray, i - 1, 1, &add10);
	}
	return add10IntArray;
}

//演示如何回传一个string数组
/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    returnStringArray
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_example_learnjni_NdkUtils_returnStringArray
  (JNIEnv *env, jclass thiz)
{
	int i;
	char *sa[] = {"Hello", "world", "jni", "很", "好玩"};
	jclass stringClass = env->FindClass("java/lang/String");
	jobjectArray returnObjectArray = env->NewObjectArray(5, stringClass, 0);//生成要返回的string数组

	jstring jstr;
	for(i = 0; i < 5; i++)
	{
		jstr = env->NewStringUTF(*(sa + i));
		env->SetObjectArrayElement(returnObjectArray, i, jstr);//设置string数组每一项
	}
	return returnObjectArray;
}

//演示java传对象过来，jni获取其值,并返回
/*
 * Class:     com_example_learnjni_NdkUtils
 * Method:    getUserName
 * Signature: (Lcom/example/learnjni/User;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_learnjni_NdkUtils_getUserName
  (JNIEnv *env, jclass thiz, jobject object)
{
	jclass userClass = env->GetObjectClass(object);
	jfieldID nameField = env->GetFieldID(userClass, "name", "Ljava/lang/String;");//获取name fieldID
	jstring name = (jstring)env->GetObjectField(object, nameField);
	return name;
}
