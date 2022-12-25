# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Freewheelin-mobile_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Freewheelin-mobile_autogen.dir/ParseCache.txt"
  "Freewheelin-mobile_autogen"
  )
endif()
