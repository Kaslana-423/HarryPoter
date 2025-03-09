# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HarryPoter_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HarryPoter_autogen.dir\\ParseCache.txt"
  "HarryPoter_autogen"
  )
endif()
