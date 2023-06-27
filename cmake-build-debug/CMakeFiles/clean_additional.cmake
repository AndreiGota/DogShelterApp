# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DogShelterApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DogShelterApp_autogen.dir\\ParseCache.txt"
  "DogShelterApp_autogen"
  )
endif()
