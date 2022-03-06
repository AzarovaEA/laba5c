#ifndef LABA5C_TASK1_H
#define LABA5C_TASK1_H

#include "../string_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;

    return begin;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_removesMultipleWhitespaceCharacters() {
    char s[] = "a b  1 ";
    removeNonLetters(s);
    ASSERT_STRING("ab1", s);
}

void test_removeNonLetters_noSpacesNothingWillChange() {
    char s[] = "ab1 ";
    removeNonLetters(s);
    ASSERT_STRING("ab1", s);
}

void test_removeNonLetters_noCharactersOtherThanWhitespace() {
    char s[] = "ab1 ";
    removeNonLetters(s);
    ASSERT_STRING("ab1", s);
}

void test_1() {
    test_removeNonLetters_removesMultipleWhitespaceCharacters();
    test_removeNonLetters_noSpacesNothingWillChange();
    test_removeNonLetters_noCharactersOtherThanWhitespace();
}

#endif
