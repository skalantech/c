cmake_minimum_required(VERSION 3.8)

add_executable(unix_datagram_calc_server
  main.c
)

target_link_libraries(unix_datagram_calc_server
  srvcore
)
