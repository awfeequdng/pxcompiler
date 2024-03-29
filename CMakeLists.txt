CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
add_subdirectory(third_party/gtest)
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

add_library(pxcompiler
  ${PXCOMPILER_SRCS}
)
target_link_libraries(pxcompiler
  PUBLIC
  utf8proc
  fmt::fmt
)

add_llvm_executable(pxc
  main.cc
  ir_test.cc
  llvmtest.cc
  pxc_main.cc
)

llvm_update_compile_flags(pxc)

target_link_libraries(pxc
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
target_link_libraries(pxcompiler
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
    MLIRFuncToLLVM
)

target_link_libraries(pxc
  PRIVATE
  # utf8proc
  # fmt::fmt
  pxcompiler
)

SET(PX_TEST_PARALLELISM 1)
SET(UNITTEST_OUTPUT_ON_FAILURE ON)
# //////////////////////////////////// test ///////////////////////////////////
# unittest invoke ctest on tests which are labeled "unittest".
# Unit tests are executed in parallel because we only care about correctness, not performance.
# This means that two different unit tests could be executing at the same time.
# In practice, figuring out the number to -j seems annoying and there doesn't appear to be a penalty for having too
# many tests queued up, so we'll use the magic number ${PX_TEST_PARALLELISM}.
# Footgun: Running tests in parallel causes wonderful breakages on OSX/clang. Not on Ubuntu/clang though.
# Footgun: labels passed to -L are regex. Give them very unique names.
add_custom_target(unittest
        # ctest
        # --resource-spec-file ${BUILD_SUPPORT_DATA_DIR}/ctest_resource_specs.json    # For controlling conflicting tests.
        ${UNITTEST_OUTPUT_ON_FAILURE}       # Whether to print output when a test fails.
        -j ${PX_TEST_PARALLELISM}       # Maximum number of parallel jobs.
        -L unittest                         # Run all tests that have a label like unittests. See footgun warning above.
        --no-compress-output                # Output verbosely so that it can be logged.
        -T Test                             # Run tests and log it to Testing/*/Test.xml.
        --timeout 3000                      # 3000 second timeout per test.
        USES_TERMINAL)

function(add_px_test
        TEST_NAME                   # The name of this test.
        TEST_SOURCES                # The CPP files for this test.
        TEST_LABEL                  # The label of this test. Will be added as a dependency of this label.
        SHOULD_EXCLUDE_FROM_ALL     # EXCLUDE_ALL if we should exclude from default ALL target, NO_EXCLUDE otherwise.
        SHOULD_UNITY_BUILD          # UNITY if we should unity build, NO_UNITY otherwise.
        )
    set(TEST_OUTPUT_DIR "${CMAKE_BINARY_DIR}/test")             # Output directory for tests.

    if (${SHOULD_EXCLUDE_FROM_ALL} STREQUAL "EXCLUDE_ALL")
        set(EXCLUDE_OPTION "EXCLUDE_FROM_ALL")
    elseif (${SHOULD_EXCLUDE_FROM_ALL} STREQUAL "NO_EXCLUDE")
        set(EXCLUDE_OPTION "")
    else ()
        message(FATAL_ERROR "Invalid option for SHOULD_EXCLUDE_FROM_ALL.")
    endif ()

    if (${SHOULD_UNITY_BUILD} STREQUAL "UNITY")
        set(UNITY_OPTION "ON")
    elseif (${SHOULD_UNITY_BUILD} STREQUAL "NO_UNITY")
        set(UNITY_OPTION "OFF")
    else ()
        message(FATAL_ERROR "Invalid option for SHOULD_UNITY_BUILD.")
    endif ()

    add_executable(${TEST_NAME} ${EXCLUDE_OPTION} ${TEST_SOURCES})

    target_compile_options(${TEST_NAME} PRIVATE "-Werror" "-Wall" "-fvisibility=hidden")
    target_link_libraries(${TEST_NAME} PRIVATE gmock_main)
    target_link_libraries(${TEST_NAME} PRIVATE gtest)
    target_link_libraries(${TEST_NAME} PRIVATE pxcompiler)
    # if (${PXCOMPILER_ENABLE_SHARED})
    #     target_link_libraries(${TEST_NAME} PRIVATE pxcompiler)
    # else ()
    #     target_link_libraries(${TEST_NAME} PRIVATE pxcompiler)
    # endif ()

    set_target_properties(${TEST_NAME} PROPERTIES
            CXX_EXTENSIONS OFF                                  # Disable compiler-specific extensions.
            ENABLE_EXPORTS ON                                   # Export for tpl.
            RUNTIME_OUTPUT_DIRECTORY "${TEST_OUTPUT_DIR}"       # Output the test binaries to this folder.
            UNITY_BUILD "${UNITY_OPTION}"                       # Possibly choose to use unity builds.
            )
    # Include the testing directories.
    target_include_directories(${TEST_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/test/include/)
    # Include the src directories.
    # target_include_directories(${TEST_NAME} PUBLIC ${PXCOMPILER_INCLUDE_DIRECTORIES})
    # TODO(WAN): The "modern" gtest_discover_test has a ton of files. Favoring legacy add_test for now...
    # add_test(${TEST_NAME} ${BUILD_SUPPORT_DIR}/run-test.sh ${CMAKE_BINARY_DIR} test ${TEST_OUTPUT_DIR}/${TEST_NAME})
    # Label each test with TEST_LABEL so that ctest can run all the tests under the TEST_LABEL label later.
    # set_tests_properties(${TEST_NAME} PROPERTIES
    #         LABELS "${TEST_LABEL};${TEST_NAME}"                 # Label the test.
    #         ENVIRONMENT "PYTHONPATH=${PROJECT_SOURCE_DIR}"      # Set the PYTHONPATH to project root for self-driving.
    #         )
    # Add TEST_NAME as a dependency to TEST_LABEL. Note that TEST_LABEL must be a valid target!
    add_dependencies(${TEST_LABEL} ${TEST_NAME})
endfunction()


file(GLOB_RECURSE PX_TEST_SOURCES
        "test/common/*.cc"
        "test/parser/*.cc"
        "test/llvm/*.cc"
        )

option (MAKE_TESTS
        "whether make test" OFF)

if (${MAKE_TESTS})
    foreach (PX_TEST_CC ${PX_TEST_SOURCES})
        file(RELATIVE_PATH PX_TEST_CC_REL "${PROJECT_SOURCE_DIR}/test" ${PX_TEST_CC})
        get_filename_component(PX_TEST_DIR ${PX_TEST_CC_REL} DIRECTORY)
        get_filename_component(PX_TEST ${PX_TEST_CC} NAME_WE)

        if (NOT ${PX_BUILD_TESTS})
            set(EXCLUDE_OR_NOT "EXCLUDE_ALL")
        elseif (${PX_USE_JUMBOTESTS})
            set(EXCLUDE_OR_NOT "EXCLUDE_ALL")
        else ()
            set(EXCLUDE_OR_NOT "NO_EXCLUDE")
        endif ()

        add_px_test(${PX_TEST} ${PX_TEST_CC} unittest ${EXCLUDE_OR_NOT} NO_UNITY)
    endforeach ()
endif() # MAKE_TESTS

# add generated grammar to demo binary target
#add_dependencies(llvmtest)
