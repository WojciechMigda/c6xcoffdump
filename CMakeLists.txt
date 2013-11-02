project( "C6x COFF dump" )

cmake_minimum_required( VERSION 2.8.3 )

set( CMAKE_ECLIPSE_VERSION 3.7 )
set( _ECLIPSE_VERSION 3.7 )

#add_definitions( -O2 -ggdb -std=c++0x )
add_definitions( -O2 -std=c++0x -ggdb -D__GXX_EXPERIMENTAL_CXX0X__ )

################################################################################

set( CXXTEST_USE_PYTHON YES CACHE INTERNAL "" )
find_program(CXXTEST_PYTHON_TESTGEN_EXECUTABLE cxxtestgen
    PATHS ${CXXTEST_INCLUDE_DIR}
)
find_package( CxxTest )

set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake-modules )

################################################################################

include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/api
)

################################################################################

set( src_list
    src/main.cpp
)

set( lib_name coff )

################################################################################

add_library( ${lib_name} ${src_list} )
set_target_properties( ${lib_name} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib
)

add_executable( main src/main.cpp )

target_link_libraries(
    main
    ${lib_name}
)


################################################################################

if( CXXTEST_FOUND )
    include_directories( ${CXXTEST_INCLUDE_DIR} )
    enable_testing()

    find_package( GMock )
    find_package( GTest )

    function( my_test_add name test_src_dir )
        cxxtest_add_test( ${name} ${name}.cpp ${test_src_dir}/${name}.hpp )
        target_link_libraries( ${name}
            ${lib_name}
            ${GMOCK_BOTH_LIBRARIES}
            ${GTEST_BOTH_LIBRARIES}
            pthread
        )
    endfunction( my_test_add )

#    my_test_add( test_timeline    ${CMAKE_CURRENT_LIST_DIR}/tests )

endif( CXXTEST_FOUND )
