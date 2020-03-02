CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

PROJECT(meguminit VERSION 1.0)

add_executable(meguminit main.cc)
install(TARGETS meguminit DESTINATION /bin/)
install(FILES meg.txt DESTINATION /etc/)
