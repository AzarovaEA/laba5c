#ifndef LABA5C_STRING__H
#define LABA5C_STRING__H

#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

#define MAX_STRING_SIZE 100
char stringBuffer[MAX_STRING_SIZE + 1];

#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

/* Возвращает количество символов в строке начиная с begin
(не считая ноль-символ) */
size_t strlen_(const char *begin);

/* Возвращает указатель на первый элемент с кодом ch,
расположенным на ленте памяти между адресами begin и end не
включая end. Если символ не найден, возвращает значение end */
char *find(char *begin, char *end, int ch);

/* Возвращает указатель на первый символ, отличный от пробельных,
расположенный на ленте памяти, начиная с begin и заканчивая
ноль-символом. Если символ не найден, возвращает адрес
первого ноль-символа */
char *findNonSpace(char *begin);

/* Возвращает указатель на первый пробельный символ, расположенный
на ленте памяти начиная с адреса begin или на первый ноль-символ */
char *findSpace(char *begin);

/* Возвращает указатель на первый справа символ, отличный от пробельных,
расположенный на ленте памяти, начиная с rbegin (последний символ строки,
за которым следует ноль-символ) и заканчивая rend (адрес символа перед
 началом строки). Если символ не найден, возвращается адрес rend */
char *findNonSpaceReverse(char *rbegin, const char *rend);

/* Возвращает указатель на первый пробельный символ справа,
расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
Если символ не найден, возвращается адрес rend */
char *findSpaceReverse(char *rbegin, const char *rend);

/* Функция возвращает отрицательное значение, если lhs располагается до
rhs в лексикографическом порядке, значение 0, если lhs и rhs равны,
иначе – положительное значение */
int strcmp(const char *lhs, const char *rhs);

/* Записывает по адресу beginDestination фрагмент памяти, начиная
с адреса beginSource до endSource. Возвращает указатель на следующий
свободный фрагмент памяти в destination */
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

/*  Записывает по адресу beginDestination элементы из фрагмента памяти
начиная с beginSource заканчивая endSource, удовлетворяющие функции-
предикату f. Функция возвращает указатель на следующий свободный для
записи фрагмент в памяти */
char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

/* Записывает по адресу beginDestination элементы из фрагмента памяти
начиная с rbeginSource заканчивая rendSource, удовлетворяющие
функции-предикату f. Функция возвращает значение beginDestination
по окончанию работы функции */
char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

#endif
