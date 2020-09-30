

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)    
endif()


target_include_directories(Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
    )