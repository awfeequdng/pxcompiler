CMAKE_MINIMUM_REQUIRED(VERSION 3.5)


if (POLICY CMP0068)
	cmake_policy(SET CMP0068 NEW)
	set(CMAKE_BUILD_WITH_INSTALL_NAME_DIR ON)
endif ()

if(POLICY CMP0075)
	cmake_policy(SET CMP0075 NEW)
endif()

if (POLICY CMP0077)
	cmake_policy(SET CMP0077 NEW)
endif ()

project(llvmtest)

include(FetchContent)                   # FetchContent_ functions.
# find_package(PkgConfig REQUIRED)        # pkg_search_module function.

function(add_pxcompiler_dep NAME GIT_URL GIT_TAG)
    string(TOLOWER "${NAME}" NAME_LOWER)    # The automatically created variables are lowercase. Footgun!
    FetchContent_Declare(${NAME})           # Declare the resource to be fetched.
    if (NOT ${NAME}_POPULATED)
        # The long form of FetchContent_Populate is used since pxtidb requires control of the source folder name.
        # This is to enable includes like #include "NAME/their_files.h".
        FetchContent_Populate(${NAME}
                # QUIET                                                   # Don't print verbose output while populating.
                SOURCE_DIR ${CMAKE_BINARY_DIR}/_deps/src/${NAME}        # Source files go here.
                BINARY_DIR ${CMAKE_BINARY_DIR}/_deps/build/${NAME}      # Build files go here.
                SUBBUILD_DIR ${CMAKE_BINARY_DIR}/_deps/sub/${NAME}      # Sub-build files go here.
                GIT_REPOSITORY ${GIT_URL}                               # Download from GIT_URL.
                GIT_TAG ${GIT_TAG}                                      # Checkout the specific GIT_TAG version.
                )

        # set(MESSAGE_QUIET ON)                                                           # Silence third party includes.
        add_subdirectory(${${NAME_LOWER}_SOURCE_DIR} ${${NAME_LOWER}_BINARY_DIR})       # Include the dependency.
        unset(MESSAGE_QUIET)                                                            # Undo silence.
    endif ()

    # Get the date of the last git commit for the GIT_TAG branch.
    execute_process(COMMAND git log -1 --format=%cd --date=short                        # Get the last commit's date.
            WORKING_DIRECTORY ${${NAME_LOWER}_SOURCE_DIR}                               # From the specified git dir.
            OUTPUT_VARIABLE GIT_LAST_COMMIT)                                            # Save to GIT_LAST_COMMIT.
    string(STRIP "${GIT_LAST_COMMIT}" GIT_LAST_COMMIT)                                  # Remove any trailing newlines.

    message(STATUS "[FOUND] ${NAME} (${GIT_URL} ${GIT_TAG} ${GIT_LAST_COMMIT})")        # Print a success message.
endfunction()

function(add_pxcompiler_dep_singlefile NAME FILE_URL)
    string(TOLOWER "${NAME}" NAME_LOWER)    # For consistency with add_pxtidb_dep above, also use lowercase.
    get_filename_component(FILE_NAME ${FILE_URL} NAME)                                  # Get the filename.
    set(DOWNLOAD_FOLDER ${CMAKE_BINARY_DIR}/_deps/src/${NAME})                          # Set download folder.
    if (EXISTS ${DOWNLOAD_FOLDER}/${FILE_NAME})                                         # Only download if required.
        message(STATUS "[FOUND] ${NAME} (already in ${DOWNLOAD_FOLDER}, skipping download)")
    else ()
        file(DOWNLOAD ${FILE_URL} ${DOWNLOAD_FOLDER}/${FILE_NAME})                      # Download the file.
        message(STATUS "[FOUND] ${NAME} (${FILE_URL})")                                 # Print a success message.
    endif ()
    set(${NAME_LOWER}_SOURCE_DIR ${DOWNLOAD_FOLDER} PARENT_SCOPE)                       # Set SOURCE_DIR in parent.
endfunction()

add_pxcompiler_dep(utf8proc https://github.com/JuliaStrings/utf8proc.git v2.6.1)
# add_pxcompiler_dep(fmt https://github.com/fmtlib/fmt.git 9.0.0)
# add_pxcompiler_dep(gtest https://github.com/google/googletest.git release-1.10.0)

add_subdirectory(third_party/fmt)
# find_package(fmt)

# set(CMAKE_BUILD_TYPE Debug)


SET (CMAKE_CXX_STANDARD 17)
set(LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING 0)

# include generated files in project environment
include_directories(
  ${PROJECT_SOURCE_DIR}
)

set(MLIR_DIR /home/pxcai/opt/llvm/lib/cmake/mlir)
link_directories(/usr/local/lib)
find_package(MLIR REQUIRED CONFIG)
message(STATUS "Using MLIRConfig.cmake in: ${MLIR_DIR}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/bin)
set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/lib)
set(MLIR_BINARY_DIR ${CMAKE_BINARY_DIR})

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(TableGen)
include(AddLLVM)
include(AddMLIR)
include(HandleLLVMOptions)

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
link_directories(${LLVM_BUILD_LIBRARY_DIR})

include_directories(${MLIR_INCLUDE_DIRS})

include_directories(include/)
include_directories(src/include/)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(LLVM_COMPONENTS Support)

set(LIBS
    MLIROptLib
    MLIRExecutionEngine
    # MLIRAffine
    LLVMLinker
)

# Get the list of all pxtidb sources.
file(GLOB_RECURSE
        PXCOMPILER_SRCS                  # Store the list of files into the variable ${PXTIDB_SRCS}.
        CONFIGURE_DEPENDS               # See above. Ask CMake to regenerate the build system if these files change.
        ${PROJECT_SOURCE_DIR}/src/*.cc
        ${PROJECT_SOURCE_DIR}/src/include/*.h
        )

add_llvm_executable(llvmtest
  main.cc
  ir_test.cc
  llvmtest.cc
  ${PXCOMPILER_SRCS}
)

llvm_update_compile_flags(llvmtest)

target_link_libraries(llvmtest
  PRIVATE
	${LIBS}
    MLIRAnalysis
    MLIRCallInterfaces
    MLIRIR
    MLIRParser
    MLIRPass
    MLIRSideEffectInterfaces
    MLIRTransforms
    MLIRDialect
    LLVMX86AsmParser
    # MLIRFunc
    MLIRFuncToLLVM
)

target_link_libraries(llvmtest
  PRIVATE
  utf8proc
  fmt::fmt
)

# add generated grammar to demo binary target
#add_dependencies(llvmtest)
