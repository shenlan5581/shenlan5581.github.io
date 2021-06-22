CMAKE_MINIMUM_REQUIRED(VERSION 2.6) #版本号
PROJECT(HELLO) #项目名称
#ADD_SUBDIRECTORY(src)# 添加源文件子目录  用于拆分模块子项目

include_directories(include)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #设置输出
 
#aux_source_directory(src SRC_LIST) #设置源文件目录到变量
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) #设置库输出位置
set (LIB_LIST ${PROJECT_SOURCE_DIR}/src/func.c) #设置某个源文件到 变量
add_library(func_static ${LIB_LIST})#添加库
set_target_properties(func_static PROPERTIES OUTPUT_NAME "Func") #输出名称


###使用库方式  
find_library(libs Func ${${PROJECT_SOURCE_DIR}/lib}) #搜索库到变量
target_link_libraries(main ${libs})  #链接库

#add_executable(main ${SRC_LIST})


