# add_executable( say_hello
#   say_hello.cpp
# )
add_executable(add_room
  roomMain.cpp
)

# target_link_libraries(say_hello
#   PRIVATE
#     libhello
# )
# target_link_libraries(add_room
#   PRIVATE
#     libhello
# )

# target_compile_features(say_hello PRIVATE cxx_std_20)
target_compile_features(add_room PRIVATE cxx_std_20)
