/* File: Example.i */
%module Example
%{
#include <stdlib.h>
#include <stdio.h>
#include "log.h"
#define TAG "hehe"

void testJniLog()
{
	LOGD(TAG, "call testJniLog");
	LOGI(TAG, "call testJniLog");
	LOGW(TAG, "call testJniLog");
	LOGE(TAG, "call testJniLog");
	LOGF(TAG, "call testJniLog");
}
 
%}

extern void testJniLog();
 
 