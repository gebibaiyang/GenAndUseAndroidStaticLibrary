# GenAndUseAndroidStaticLibrary
通过android studio 和ndk生成Android 平台的静态库，以及使用静态库demo

#环境说明
Android studio version 3.1.4
OS MacOS 10.13.6
生成静态库 NDK version r17
使用静态库 NDK version r18
其实操作系统，Android studio，以及NDK 均对demo运行无影响，大家可以自行设置

GenStaticLibrary  生成Android平台静态库demo
1. 创建普通android 工程即可（不要勾选include c++ support）
2. 添加工程下jni目录及其中的示例文件
3. 切换至jni 目录环境，运行ndk-build 命令
4. 在obj目录中查看生成的静态库 mystaticLibrary.a 文件

备注：
1)相关设置都在Android.mk 和 Application.mk 中完成
2)如果命令运行成功，则会生成各个平台下的mystaticLibrary.a 文件

UseStaticLibrary  Android平台使用静态库demo
1. 创建android 工程（勾选include c++ support）
2. 在main 目录下添加jniLibs 目录，存放相关平台下的mystaticLibrary.a 文件
3. 在cpp 目录下添加include 目录，存放相关的 *.h 文件
4. 修改工程目录下的CMakeLists文件，添加
   1）设定查找头文件目录： include_directories(${CMAKE_CURRENT_LIST_DIR}/src/main/cpp/include)  
   2）设定添加静态文件相关属性：
     add_library(mystaticLibrary STATIC IMPORTED)
     set_target_properties(mystaticLibrary
     PROPERTIES IMPORTED_LOCATION
     ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libmystaticLibrary.a)
   3）设置需要连接的静态文件
     target_link_libraries( # Specifies the target library.
            native-lib

            mystaticLibrary
            # Links the target library to the log library
            # included in the NDK.
            ${log-lib} )
5. 编辑app目录下的build.gradle 文件
   在defaultConfig下面添加目标平台
   ndk {
        // Specifies the ABI configurations of your native
        // libraries Gradle should build and package with your APK.
        abiFilters 'armeabi-v7a'
    }
6. 在测试文件native-lib.cpp中使用静态库中的方法
7. 运行apk，查看效果

备注：在app/build/intermediates/cmake/debug/obj/armeabi-v7a中可以查看生成的so文件