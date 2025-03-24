cmake_minimum_required(VERSION 3.5)

project(Simple_Seriall LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt6 COMPONENTS
        Widgets
        SerialPort
        Core5Compat
        Charts
        REQUIRED)

if(ANDROID)
  add_library(Simple_Seriall SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(Simple_Seriall
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
          Serial.h
          Serial.cpp
          Thread.cpp
          Thread.h
          Drage_Widget.cpp
          Drage_Widget.h
  )
endif()

target_link_libraries(Simple_Seriall PRIVATE
        Qt6::Widgets
        Qt6::SerialPort
        Qt6::Core5Compat
        Qt6::Charts
)
