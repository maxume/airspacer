add_executable(${PROJECT_NAME} main_airspacer.cpp)

target_link_libraries( ${PROJECT_NAME} airspacerlib ${Eigen3_LIBS} ${Boost_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_INCLUDE_CURRENT_DIR})

install (TARGETS ${PROJECT_NAME} DESTINATION bin)
