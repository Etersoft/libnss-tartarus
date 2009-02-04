file(GLOB sources "*.cpp")
add_library(tartarus-rpc SHARED ${sources})
target_link_libraries(tartarus-rpc json_spirit boost_system pthread)
