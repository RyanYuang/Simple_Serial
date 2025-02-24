# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Simple_Seriall_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Simple_Seriall_autogen.dir/ParseCache.txt"
  "Simple_Seriall_autogen"
  )
endif()
