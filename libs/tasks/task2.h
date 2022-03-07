#ifndef LABA5C_TASK2_H
#define LABA5C_TASK2_H

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

#include "../string_.h"

/* Сокращает количество пробелов между
словами данного предложения до одного */
void removeExtraSpaces(char *s) {
    char *begin = s;
    char *copyOfTheString = begin;
    int isSpace = 0;
    while (*begin != '\0') {
        if (*begin != ' ' || isSpace) {
            *copyOfTheString = *begin;
            if (*begin == ' ')
                isSpace = 0;
            else
                isSpace = 1;
            copyOfTheString++;
        }
        begin++;
    }

    if (!isSpace)
        copyOfTheString--;
    *copyOfTheString = '\0';
}

void test_removeExtraSpaces_thereAreBothRepetitiveAndNonRepetitive() {
    char s[] = "a551  556";
    removeExtraSpaces(s);

    ASSERT_STRING("a551 556", s);
}

void test_removeExtraSpaces_aFewSpacesAtTheEnd() {
    char s[] = "df85   ";
    removeExtraSpaces(s);

    ASSERT_STRING("df85", s);
}

void test_removeExtraSpaces_aFewSpacesAtTheBeginning() {
    char s[] = "   d$fj5b";
    removeExtraSpaces(s);

    ASSERT_STRING("d$fj5b", s);
}

void test_removeExtraSpaces_noSpaces() {
    char s[] = "33gj5mj78d";
    removeExtraSpaces(s);

    ASSERT_STRING("33gj5mj78d", s);
}

void test_removeExtraSpaces_onlySpaces() {
    char s[] = "     ";
    removeExtraSpaces(s);

    ASSERT_STRING("     ", s);
}

void test_2() {
    test_removeExtraSpaces_thereAreBothRepetitiveAndNonRepetitive();
    test_removeExtraSpaces_aFewSpacesAtTheEnd();
    test_removeExtraSpaces_aFewSpacesAtTheBeginning();
    test_removeExtraSpaces_noSpaces();
    test_removeExtraSpaces_onlySpaces();
}

#endif
