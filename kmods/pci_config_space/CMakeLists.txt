project(kmod_pci_config_space LANGUAGES C)
cmake_minimum_required(VERSION 3.17)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

execute_process(
  COMMAND uname -r
  OUTPUT_VARIABLE _TARGET_KERNEL_RELEASE
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(_KMOD_KO ${CMAKE_PROJECT_NAME}.ko)
set(_KMOD_BUILD_DIR /lib/modules/${_TARGET_KERNEL_RELEASE}/build)

set(_SRCS_KMOD
  kmod_pci_config_space.c
)

file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild "obj-m := ${CMAKE_PROJECT_NAME}.o")
file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild "\nccflags-y += -Wno-unused-label")

add_custom_target(${CMAKE_PROJECT_NAME} ALL DEPENDS ${_KMOD_KO})

add_custom_command(OUTPUT ${_KMOD_KO}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMAND ${CMAKE_MAKE_PROGRAM} ${_SRCS_KMOD} -C ${_KMOD_BUILD_DIR} M=${CMAKE_CURRENT_BINARY_DIR} modules
)

