set (NAVIT_DIR ~/navit)

find_path(NAVIT_INCLUDE_DIR
    navit.h
    PATHS ${NAVIT_DIR}
    PATH_SUFFIXES include
)

find_path(NAVIT_LIB_DIR
    libnavit_core.so
    PATHS ${NAVIT_DIR}
    PATH_SUFFIXES lib
)

if (NAVIT_LIB_DIR)
    set(NAVIT_FOUND TRUE)
endif()

if (NAVIT_FOUND)
    if (NOT navit_FIND_QUIETLY)
        message(STATUS "Found navit:")
        message(STATUS " - Includes: ${NAVIT_INCLUDE_DIR}")
        message(STATUS " - Libraries: ${NAVIT_LIB_DIR}")
    endif()
    add_library(navit INTERFACE)
    set_target_properties(navit PROPERTIES INTERFACE_LINK_DIRECTORIES ${NAVIT_LIB_DIR})
    target_link_libraries(navit INTERFACE libnavit_core.so )
else()
    if (navit_FIND_REQUIRED)
               message(FATAL_ERROR "Could not find navit")
    endif()
endif()

mark_as_advanced(NAVIT_INCLUDE_DIRS NAVIT_LIBRARIES)
