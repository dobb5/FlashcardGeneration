cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Enable the generation of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the source files for the project and include directory
add_executable(vocabentrytest
    src/VocabularyEntry.cpp
    test/VocabularyEntryTest.cpp
)

# Add include directory to vocabentrytest target
target_include_directories(vocabentrytest PRIVATE include)

# If you have additional dependencies, link them here
# target_link_libraries(vocabentrytest other_libraries)

# If you want to add more tests:
# add_executable(test_project
#     test/AnkiManagerTest.cpp
#     test/CLIManagerTest.cpp
#     test/MediaCorpusManagerTest.cpp
#     test/VocabularyEntryTest.cpp
#     test/VocabularyManagerTest.cpp
# )
# target_link_libraries(test_project other_libraries)

