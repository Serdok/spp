# Import GoogleTest targets
set(INSTALL_GTEST OFF CACHE BOOL "")
add_subdirectory(googletest)

# Tests setup
add_subdirectory(src)