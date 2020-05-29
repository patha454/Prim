# Define the prim_app target.
ADD_EXECUTABLE(prim_app)

# Add the prim_app sources
ADD_SUBDIRECTORY(src)

# Link the prim_app driver against the Prim library.
TARGET_LINK_LIBRARIES(prim_app prim)

# Just name the Prim driver 'prim`. The library should be named something like `libprim` by default.
SET_TARGET_PROPERTIES(prim_app PROPERTIES OUTPUT_NAME "prim")
