#
# Appends the new_bit to the original.
# If the original is not set, it will be set to the new_bit.
#

macro(append ORIGINAL)
    if (${ORIGINAL})
        set(${ORIGINAL} ${${ORIGINAL}} ${ARGN})
    else(${ORIGINAL})
        set(${ORIGINAL} ${ARGN})
    endif(${ORIGINAL})
endmacro(append ORIGINAL)

macro (absolutize)
    foreach(PATH_VAR ${ARGN})
        get_filename_component(${PATH_VAR} ${${PATH_VAR}} ABSOLUTE)
    endforeach(PATH_VAR)
endmacro(absolutize)

function (SLICE2CPP_INTERNAL BASE_DIR HEADERS_DIR SOURCES_DIR FILENAME)
    # parameter parsing
    absolutize(FILENAME BASE_DIR SOURCES_DIR HEADERS_DIR)
    file(RELATIVE_PATH subname ${BASE_DIR} ${FILENAME})
    get_filename_component(src ${subname} NAME)
    get_filename_component(subpath ${subname} PATH)
    string( REGEX REPLACE "\\.ice$" ".h" outname_h "${src}" )
    string( REGEX REPLACE "\\.ice$" ".cpp" outname_cpp "${src}" )
    set(out_h ${HEADERS_DIR}/${subpath}/${outname_h})
    set(out_cpp ${SOURCES_DIR}/${outname_cpp})

    # build command
    if (${SOURCES_DIR} STREQUAL ${HEADERS_DIR})
        add_custom_command(
            OUTPUT ${out_cpp} ${out_h}
            MAIN_DEPENDENCY ${src_path}
            COMMAND "slice2cpp"
            ARGS --output-dir ${SOURCES_DIR} --include-dir ${subpath}
                 -I${BASE_DIR} ${SLICE2CPP_FLAGS} ${FILENAME})
    else (${SOURCES_DIR} STREQUAL ${HEADERS_DIR})
        add_custom_command(
            OUTPUT ${out_cpp} ${out_h}
            MAIN_DEPENDENCY ${src_path}
            COMMAND "slice2cpp"
            ARGS --output-dir ${SOURCES_DIR} --include-dir ${subpath}
                 -I${BASE_DIR} ${SLICE2CPP_FLAGS} ${FILENAME}
            COMMAND ${CMAKE_COMMAND}
            ARGS    -E copy ${SOURCES_DIR}/${outname_h} ${out_h}
            COMMAND ${CMAKE_COMMAND}
            ARGS    -E remove ${SOURCES_DIR}/${outname_h})
    endif (${SOURCES_DIR} STREQUAL ${HEADERS_DIR})

    # register everything
    set_source_files_properties(${out_h} PROPERTIES GENERATED true)
    set_source_files_properties(${out_cpp} PROPERTIES GENERATED true)
    set(SLICE2CPP_INT_HEADER ${out_h} PARENT_SCOPE)
    set(SLICE2CPP_INT_SOURCE ${out_cpp} PARENT_SCOPE)
endfunction (SLICE2CPP_INTERNAL)

function (add_object_dependency ARGS)
    foreach(OBJ ${ARGS})
        get_source_file_property(prop ${OBJ} OBJECT_DEPENDS)
        append(prop ${ARGN})
        set_source_files_properties(${OBJ} PROPERTIES OBJECT_DEPENDS "${prop}")
    endforeach(OBJ)
endfunction (add_object_dependency)

macro (SLICE2CPP_EX BASE_DIR HEADERS_DIR SOURCES_DIR SOURCES_VAR HEADERS_VAR)
    foreach(FILENAME ${ARGN})
        SLICE2CPP_INTERNAL(${BASE_DIR} ${HEADERS_DIR} ${SOURCES_DIR} ${FILENAME})
        append(${HEADERS_VAR} ${SLICE2CPP_INT_HEADER})
        append(${SOURCES_VAR} ${SLICE2CPP_INT_SOURCE})
        add_object_dependency(${${SOURCES_VAR}} ${SLICE2CPP_INT_HEADER})
    endforeach(FILENAME)
endmacro (SLICE2CPP_EX)

macro (SLICE2CPP SOURCES_VAR HEADERS_VAR)
    SLICE2CPP_EX(${SLICE_DIR} ${SLICE_HEADER_DIR} ${CMAKE_CURRENT_BINARY_DIR}
                 ${SOURCES_VAR} ${HEADERS_VAR} ${ARGN})
endmacro (SLICE2CPP)

