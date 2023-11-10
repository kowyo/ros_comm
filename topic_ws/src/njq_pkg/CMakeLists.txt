cmake_minimum_required(VERSION 3.0.2)
project(njq_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_message_files(
  DIRECTORY msg
  FILES
  PersonNongjinqi.msg
  GroupNongjinqi.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs  # 添加std_msgs作为依赖项
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(person_publisher src/person_publisher.cpp)
target_link_libraries(person_publisher ${catkin_LIBRARIES})
add_dependencies(person_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(group_publisher src/group_publisher.cpp)
target_link_libraries(group_publisher ${catkin_LIBRARIES})
add_dependencies(group_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(subscriber_1 src/subscriber_1.cpp)
target_link_libraries(subscriber_1 ${catkin_LIBRARIES})
add_dependencies(subscriber_1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(subscriber_2 src/subscriber_2.cpp)
target_link_libraries(subscriber_2 ${catkin_LIBRARIES})
add_dependencies(subscriber_2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
