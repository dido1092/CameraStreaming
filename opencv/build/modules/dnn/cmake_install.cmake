# Install script for directory: C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/build/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x64/vc17/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/build/lib/Debug/opencv_dnn4110d.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x64/vc17/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/build/lib/Release/opencv_dnn4110.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libs" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x64/vc17/bin" TYPE SHARED_LIBRARY OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/build/bin/Debug/opencv_dnn4110d.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x64/vc17/bin" TYPE SHARED_LIBRARY OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/build/bin/Release/opencv_dnn4110.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "pdb")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x64/vc17/bin" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/build/bin/Debug/opencv_dnn4110d.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x64/vc17/bin" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/build/bin/Release/opencv_dnn4110.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/all_layers.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/dict.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/dnn.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/dnn.inl.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/layer.details.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/layer.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/shape_utils.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn/utils" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/utils/debug_utils.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn/utils" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/utils/inference_engine.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/dnn" TYPE FILE OPTIONAL FILES "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/sources/modules/dnn/include/opencv2/dnn/version.hpp")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/Lemon/source/repos/OpenCVStream/CameraStream_WinForms_GUI/opencv/build/modules/dnn/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
