function (DBUSXX_XML2CPP_INTERNAL PARAM TARGET_FILENAME FILENAME)
    add_custom_command(
        OUTPUT ${TARGET_FILENAME}
        MAIN_DEPENDENCY ${src_path}
        COMMAND "dbusxx-xml2cpp"
        ARGS ${FILENAME} ${PARAM}=${TARGET_FILENAME})

    set_source_files_properties(${TARGET_FILENAME} PROPERTIES GENERATED true)
endfunction (DBUSXX_XML2CPP_INTERNAL)

function (DBUSXX_XML2CPP_ADAPTOR TARGET_FILENAME FILENAME)
    DBUSXX_XML2CPP_INTERNAL("--adaptor" ${TARGET_FILENAME} ${FILENAME})
endfunction (DBUSXX_XML2CPP_ADAPTOR)

function (DBUSXX_XML2CPP_PROXY TARGET_FILENAME FILENAME)
    DBUSXX_XML2CPP_INTERNAL("--proxy" ${TARGET_FILENAME} ${FILENAME})
endfunction (DBUSXX_XML2CPP_PROXY)
