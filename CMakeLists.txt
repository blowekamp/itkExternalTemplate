project(ModuleTemplate)
cmake_minimum_required(VERSION 2.8.9)

include(CheckIncludeFileCXX)
check_include_file_cxx("random" _have_random)
if(NOT _have_random)
  message(FATAL_ERROR "This module requires the C++11 \"random\" header.")
endif()

set(ModuleTemplate_LIBRARIES ModuleTemplate)

if(NOT ITK_SOURCE_DIR)
  find_package(ITK REQUIRED)
  list(APPEND CMAKE_MODULE_PATH ${ITK_CMAKE_DIR})
  include(ITKModuleExternal)
else()
  itk_module_impl()
endif()
