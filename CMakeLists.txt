cmake_minimum_required(VERSION 3.20)
project(laba5c C)

set(CMAKE_C_STANDARD 11)

# определение точки входа. Будет запущен файл main . c .
# указывается произвольная метка, в данном случае - project
add_executable(laba5c main.c)

# создаём библиотеку
add_library(str libs/string_.h libs/string_.c
        libs/tasks/task1.h
        # libs/tasks/task2.h
        # string / tasks / reverseWords . h
        # string / tasks / replaceDigitsBySpaces . h
        # ...
        # < файл с решением задачи >
        # ...
        # string / tasks / hasPairOfWordsWithEqualLetterSet . h
        # string / tasks / printWordsNonEqualLastWord . h
        )

# описываем, что для запуска project потребуется сборка tasks
target_link_libraries(laba5c str)