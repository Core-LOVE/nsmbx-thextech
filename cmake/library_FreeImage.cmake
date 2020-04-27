# FreeImage is an image management library

add_library(PGE_FreeImage INTERFACE)

option(USE_SHARED_FREEIMAGE "Use shared build of FreeImage" OFF)

if(USE_SHARED_FREEIMAGE)
    set(libFreeImage_Libs "${DEPENDENCIES_INSTALL_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}FreeImageLite${PGE_LIBS_DEBUG_SUFFIX}${CMAKE_SHARED_LIBRARY_SUFFIX}")
    set(USE_STATIC_FREEIMAGE OFF)
else()
    if(WIN32)
        set(FI_STATIC_SUFFIX "-static")
    else()
        set(FI_STATIC_SUFFIX "")
    endif()
    set(libFreeImage_Libs "${DEPENDENCIES_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}FreeImageLite${FI_STATIC_SUFFIX}${PGE_LIBS_DEBUG_SUFFIX}${CMAKE_STATIC_LIBRARY_SUFFIX}")
    set(USE_STATIC_FREEIMAGE ON)
endif()

ExternalProject_Add(
    FreeImage_Local
    PREFIX ${CMAKE_BINARY_DIR}/external/FreeImage
    GIT_REPOSITORY https://github.com/WohlSoft/libFreeImage.git
    UPDATE_COMMAND ""
    CMAKE_ARGS
        "-DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_INSTALL_DIR}"
        "-DFREEIMAGE_SHARED=${USE_SHARED_FREEIMAGE}"
        "-DFREEIMAGE_STATIC=${USE_STATIC_FREEIMAGE}"
        "-DDEPENDENCIES_INSTALL_DIR=${DEPENDENCIES_INSTALL_DIR}"
        #"-DCMAKE_PROJECT_FreeImage_INCLUDE=${CMAKE_SOURCE_DIR}/_common/build_env.cmake"
        "-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}"
        "-DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_INSTALL_DIR}"
        "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
        "-DCMAKE_POSITION_INDEPENDENT_CODE=ON"
        "-DFREEIMAGE_USE_SYSTEM_LIBPNG=OFF"
        "-DFREEIMAGE_USE_SYSTEM_LIBJPEG=OFF"
        #"-DFREEIMAGE_PNG_INCLUDE=${PNG_INCLUDE_DIRS}"
        #"-DFREEIMAGE_ZLIB_INCLUDE=${ZLIB_INCLUDE_DIRS}"
        #"-DFREEIMAGE_PNG_LIB=${libPNG_A_Lib}"
        #"-DFREEIMAGE_ZLIB_LIB=${libZLib_A_Lib}"
        $<$<BOOL:APPLE>:-DCMAKE_OSX_DEPLOYMENT_TARGET=${CMAKE_OSX_DEPLOYMENT_TARGET}>
        ${ANDROID_CMAKE_FLAGS}
    BUILD_BYPRODUCTS
        "${libFreeImage_Libs}"
)

target_link_libraries(PGE_FreeImage INTERFACE
    "${libFreeImage_Libs}"
)

if(USE_SHARED_FREEIMAGE AND NOT WIN32)
    install(FILES ${libFreeImage_Libs} DESTINATION ${PGE_INSTALL_DIRECTORY})
endif()
