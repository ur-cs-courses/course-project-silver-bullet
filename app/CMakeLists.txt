add_executable(say_hello
  say_hello.cpp
)

target_link_libraries(say_hello
  PRIVATE
    libhello
)

target_compile_features(say_hello PRIVATE cxx_std_20)
