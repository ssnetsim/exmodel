cmake_minimum_required(VERSION 3.10)
project(exmodel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# zlib
find_library(ZLIB_A NAMES zlib.a PATHS ${CMAKE_INSTALL_RPATH})
if(ZLIB_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "zlib.a not found")
endif()
string(REPLACE lib/zlib.a include/ ZLIB_INC ${ZLIB_A})
if(NOT EXISTS ${ZLIB_INC})
  message(FATAL_ERROR "zlib include dir doesn't exist")
endif()

# jsoncpp
find_library(JSONCPP_A NAMES jsoncpp.a PATHS ${CMAKE_INSTALL_RPATH})
if(JSONCPP_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "jsoncpp.a not found")
endif()
string(REPLACE lib/jsoncpp.a include/ JSONCPP_INC ${JSONCPP_A})
if(NOT EXISTS ${JSONCPP_INC})
  message(FATAL_ERROR "jsoncpp include dir doesn't exist")
endif()

# libprim
find_library(LIBPRIM_A NAMES libprim.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBPRIM_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "libprim.a not found")
endif()
string(REPLACE lib/libprim.a include/ LIBPRIM_INC ${LIBPRIM_A})
if(NOT EXISTS ${LIBPRIM_INC})
  message(FATAL_ERROR "libprim include dir doesn't exist")
endif()

# libcolhash
find_library(LIBCOLHASH_A NAMES libcolhash.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBCOLHASH_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "libcolhash.a not found")
endif()
string(REPLACE lib/libcolhash.a include/ LIBCOLHASH_INC ${LIBCOLHASH_A})
if(NOT EXISTS ${LIBCOLHASH_INC})
  message(FATAL_ERROR "libcolhash include dir doesn't exist")
endif()

# libfactory
find_library(LIBFACTORY_A NAMES libfactory.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBFACTORY_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "libfactory.a not found")
endif()
string(REPLACE lib/libfactory.a include/ LIBFACTORY_INC ${LIBFACTORY_A})
if(NOT EXISTS ${LIBFACTORY_INC})
  message(FATAL_ERROR "libfactory include dir doesn't exist")
endif()

# librnd
find_library(LIBRND_A NAMES librnd.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBRND_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "librnd.a not found")
endif()
string(REPLACE lib/librnd.a include/ LIBRND_INC ${LIBRND_A})
if(NOT EXISTS ${LIBRND_INC})
  message(FATAL_ERROR "librnd include dir doesn't exist")
endif()

# libmut
find_library(LIBMUT_A NAMES libmut.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBMUT_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "libmut.a not found")
endif()
string(REPLACE lib/libmut.a include/ LIBMUT_INC ${LIBMUT_A})
if(NOT EXISTS ${LIBMUT_INC})
  message(FATAL_ERROR "libmut include dir doesn't exist")
endif()

# libbits
find_library(LIBBITS_A NAMES libbits.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBBITS_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "libbits.a not found")
endif()
string(REPLACE lib/libbits.a include/ LIBBITS_INC ${LIBBITS_A})
if(NOT EXISTS ${LIBBITS_INC})
  message(FATAL_ERROR "libbits include dir doesn't exist")
endif()

# libstrop
find_library(LIBSTROP_A NAMES libstrop.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBSTROP_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "libstrop.a not found")
endif()
string(REPLACE lib/libstrop.a include/ LIBSTROP_INC ${LIBSTROP_A})
if(NOT EXISTS ${LIBSTROP_INC})
  message(FATAL_ERROR "libstrop include dir doesn't exist")
endif()

# libfio
find_library(LIBFIO_A NAMES libfio.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBFIO_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "libfio.a not found")
endif()
string(REPLACE lib/libfio.a include/ LIBFIO_INC ${LIBFIO_A})
if(NOT EXISTS ${LIBFIO_INC})
  message(FATAL_ERROR "libfio include dir doesn't exist")
endif()

# libsettings
find_library(LIBSETTINGS_A NAMES libsettings.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBSETTINGS_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "libsettings.a not found")
endif()
string(REPLACE lib/libsettings.a include/ LIBSETTINGS_INC ${LIBSETTINGS_A})
if(NOT EXISTS ${LIBSETTINGS_INC})
  message(FATAL_ERROR "libsettings include dir doesn't exist")
endif()

# supersim
find_library(SUPERSIM_A NAMES supersim.a PATHS ${CMAKE_INSTALL_RPATH})
if(SUPERSIM_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "supersim.a not found")
endif()
string(REPLACE lib/supersim.a include/ SUPERSIM_INC ${SUPERSIM_A})
if(NOT EXISTS ${SUPERSIM_INC})
  message(FATAL_ERROR "supersim include dir doesn't exist")
endif()

add_library(
  exmodel
  STATIC
  ${PROJECT_SOURCE_DIR}/src/traffic/continuous/WeirdCTP.cc
  ${PROJECT_SOURCE_DIR}/src/traffic/continuous/WeirdCTP.h
  )

set_target_properties(
  exmodel
  PROPERTIES
  LINKER_LANGUAGE
  CXX
  )

target_include_directories(
  exmodel
  PUBLIC
  ${PROJECT_SOURCE_DIR}/src
  ${ZLIB_INC}
  ${JSONCPP_INC}
  ${LIBPRIM_INC}
  ${LIBCOLHASH_INC}
  ${LIBFACTORY_INC}
  ${LIBRND_INC}
  ${LIBMUT_INC}
  ${LIBBITS_INC}
  ${LIBSTROP_INC}
  ${LIBFIO_INC}
  ${LIBSETTINGS_INC}
  ${SUPERSIM_INC}
  )

target_link_libraries(
  exmodel
  ${ZLIB_A}
  ${JSONCPP_A}
  ${LIBPRIM_A}
  ${LIBCOLHASH_A}
  ${LIBFACTORY_A}
  ${LIBRND_A}
  ${LIBMUT_A}
  ${LIBBITS_A}
  ${LIBSTROP_A}
  ${LIBFIO_A}
  ${LIBSETTINGS_A}
  ${SUPERSIM_A}
  )

include(GNUInstallDirs)

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/traffic/continuous/WeirdCTP.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/exmodel/
  )

install(
  TARGETS
  exmodel
  )

