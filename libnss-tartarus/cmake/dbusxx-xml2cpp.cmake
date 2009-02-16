function (DBUSXX_XML2CPP_INTERNAL PARAM TARGET TARGET_FILENAME XML_FILENAME)
    set(xml_src ${CMAKE_CURRENT_SOURCE_DIR}/${XML_FILENAME})
    set(header_dst ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_FILENAME})
    add_custom_command(
        OUTPUT ${header_dst}
        DEPENDS ${xml_src}
        COMMAND "dbusxx-xml2cpp"
        ARGS ${xml_src} ${PARAM}=${header_dst})

    set_source_files_properties(${header_dst} PROPERTIES GENERATED true)
    set(${TARGET} ${header_dst} PARENT_SCOPE)
endfunction (DBUSXX_XML2CPP_INTERNAL)

macro (DBUSXX_XML2CPP_ADAPTOR TARGET TARGET_FILENAME XML_FILENAME)
    DBUSXX_XML2CPP_INTERNAL("--adaptor" ${TARGET} ${TARGET_FILENAME} ${XML_FILENAME})
endmacro (DBUSXX_XML2CPP_ADAPTOR)

macro (DBUSXX_XML2CPP_PROXY TARGET TARGET_FILENAME XML_FILENAME)
    DBUSXX_XML2CPP_INTERNAL("--proxy" ${TARGET} ${TARGET_FILENAME} ${XML_FILENAME})
endmacro (DBUSXX_XML2CPP_PROXY)