@echo off
set project_path=C:\Users\dell\Desktop\learnjni
set classes_path=%project_path%\bin\classes
set jni_path=%project_path%\jni
set ndk_filename=com.example.learnjni.NdkUtils

::切换到工程目录
chdir /d %project_path%

::1.生成.h文件
chdir /d %classes_path%
javah -jni -d %jni_path% %ndk_filename%


pause