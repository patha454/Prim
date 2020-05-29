# Add Prim sources
ADD_LIBRARY(prim)

# Add Prim sources
ADD_SUBDIRECTORY(src)

TARGET_INCLUDE_DIRECTORIES(prim PUBLIC include)
