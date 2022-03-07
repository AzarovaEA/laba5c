cmake_minimum_required(VERSION 3.20)
project(laba5c C)

set(CMAKE_C_STANDARD 11)

# определение точки входа. Будет запущен файл main.c.
# указывается произвольная метка, в данном случае - project
add_executable(laba5c main.c)

# создаём библиотеку
add_library(str libs/string_.h libs/string_.c
        libs/tasks/task1.h
        libs/tasks/task2.h
        libs/tasks/task3.h
#        libs/tasks/task4.h
#        libs/tasks/task5.h
#        libs/tasks/task6.h
#        libs/tasks/task7.h
#        libs/tasks/task8.h
        )

# описываем, что для запуска project потребуется сборка tasks
target_link_libraries(laba5c str)