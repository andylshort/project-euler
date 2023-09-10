add_executable(problem-3 main.cpp)

message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")

target_include_directories(
    problem-3 PUBLIC ${PROJECT_SOURCE_DIR})
