/****************************************************************************
 Copyright (c) 2012      Wenbin Wang
 
 http://geeksavetheworld.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "ChartboostXJni.h"
#include "ChartboostX.h"

using namespace cocos2d;

extern "C"
{
    void vCallToJNI(const char* classname, const char* function, const char* location)
    {
        JniMethodInfo methodInfo;
        
        if (! JniHelper::getStaticMethodInfo(methodInfo, classname, function, "(Ljava/lang/String;)V"))
        {
            return;
        }
        jstring stringArg = methodInfo.env->NewStringUTF(location);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, stringArg);
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        methodInfo.env->DeleteLocalRef(stringArg);
    }
   
    bool bCallToJNI(const char* classname, const char* function, const char* location)
    {
        JniMethodInfo methodInfo;
        bool hasAd = false;
        
        if (JniHelper::getStaticMethodInfo(methodInfo, classname, function, "(Ljava/lang/String;)V"))
        {
            jstring stringArg = methodInfo.env->NewStringUTF(location);
            hasAd = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, stringArg);
            
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
            methodInfo.env->DeleteLocalRef(stringArg);
        }

        return hasAd;
    }
    
/////////////////////////////////////////////////////////////////////////////

    jboolean Java_com_wonderwombat_ChartboostX_ChartboostXBridge_bCallFromJNI(JNIEnv*  env, jobject thiz, jstring function, jstring location)
    {
        if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
            return delegate->bCallBack(JniHelper::jstring2string(function).c_str(), JniHelper::jstring2string(location).c_str());
        }
        
        return true;
    }

    void Java_com_wonderwombat_ChartboostX_ChartboostXBridge_vCallFromJNI(JNIEnv*  env, jobject thiz, jstring function, jstring location)
    {
        if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
            delegate->vCallBack(JniHelper::jstring2string(function).c_str(), JniHelper::jstring2string(location).c_str());
        }
    }

}
