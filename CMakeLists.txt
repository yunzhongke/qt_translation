cmake_minimum_required(VERSION 3.0)

###  参考：https://codingman.space/coding/2017/07/14/qt-translation-support-in-cmake.html

project(translation)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON) #< 自动运行moc，只针对Qt项目
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/yunzhongke/work/Qt5.6.2/5.6/gcc_64/lib/cmake/Qt5Widgets/Qt5WidgetsConfig.cmake")

find_package(Qt5Widgets)
if(Qt5Widgets_FOUND)
    message(STATUS ${Qt5Widgets_LIBRARIES})
    message(STATUS ${Qt5Widgets_VERSION_STRING})
    message(STATUS ${CMAKE_CURRENT_LIST_DIR})
    message(STATUS ${Qt5Widgets_INCLUDE_DIRS})

    # 设置导入Qt5的库是Release版本的
    set_target_properties(${Qt5Widgets_LIBRARIES} PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
endif()

find_package(Qt5LinguistTools)

 set(TRANS
     lang_en.ts
     lang_zh.ts
 )
qt5_create_translation(qm_files ${TRANS} mainwindow.ui mainwindow.cpp main.cpp)
set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM TRUE) #避免每次执行CMake时都会删除“.ts”文件
add_executable(${PROJECT_NAME} ${qm_files} mainwindow.cpp main.cpp
    )

target_link_libraries(${PROJECT_NAME} ${Qt5LinguistTools_LIBRARIES} ${Qt5Widgets_LIBRARIES})
