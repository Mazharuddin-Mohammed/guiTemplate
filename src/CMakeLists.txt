cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(guiTemplate_Core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Hack for buggy CMake's FindwxWidgets Script
if(DEFINED ENV_WX_CONFIG)
    set(WX_CONFIG ${ENV_WX_CONFIG})
endif()

set(wxWidgets_USE_STATIC 1)

find_package(wxWidgets REQUIRED)

se(SRCS MainApp.cpp MainFrame.cpp)

include(${wxWidgets_USE_FILE})

if(Apple)

    # Create bundle on Apple Compiles
    add_executable(guiTemplate MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the apple app bundle - needed for MacOS Retina display
    set_target_properties(guiTemplate PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)

else()

    # WIN32 is needed for WindowsOS in order for it to look for WinMain 
    # instead of the main function. This is ignored on all other operating systems,
    # so it works on all platforms
    add_executable(guiTemplate WIN32 ${SRCS} guiTemplate.exe.manifest)

endif()

target_link_libraries(guiTemplate PRIVATE ${wxWidgets_LIBRARIES})
