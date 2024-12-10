if(BUILD_TESTING)
  add_executable(test_aes test_aes.cpp)
  target_link_libraries(test_aes PRIVATE GTest::gtest_main)

  include(GoogleTest)
  gtest_discover_tests(test_aes)
endif()
