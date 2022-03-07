#ifndef LABA5C_TASK4_H
#define LABA5C_TASK4_H

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

#include "../string_.h"

// Заменяет каждую цифру вв строке s соответствующим ей числом пробелов
void replacesADigitWithAnEqualNumberOfSpaces(char *s) {
    char *copyString = s;
    char *endBuffer = copy(copyString, getEndOfString(copyString), stringBuffer);
    char *begin = stringBuffer;

    while (*begin != *endBuffer) {
        if (isdigit(*begin)) {
            char digit = *begin - '0';
            while (digit > 0) {
                *copyString++ = ' ';
                digit--;
            }
        } else
            *copyString++ = *begin;
        begin++;
    }
    *copyString = '\0';
}

void test_replacesADigitWithAnEqualNumberOfSpaces_digit3and0and1() {
    char s[MAX_STRING_SIZE] = "a3b0c1";
    replacesADigitWithAnEqualNumberOfSpaces(s);
    ASSERT_STRING("a   bc ", s);
}

void test_replacesADigitWithAnEqualNumberOfSpaces_noNumbers() {
    char s[MAX_STRING_SIZE] = "abdhbg";
    replacesADigitWithAnEqualNumberOfSpaces(s);
    ASSERT_STRING("abdhbg", s);
}

void test_replacesADigitWithAnEqualNumberOfSpaces_onlyDigits() {
    char s[MAX_STRING_SIZE] = "2301";
    replacesADigitWithAnEqualNumberOfSpaces(s);
    ASSERT_STRING("      ", s);
}

void test_replacesADigitWithAnEqualNumberOfSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    replacesADigitWithAnEqualNumberOfSpaces(s);
    ASSERT_STRING("", s);
}

void test_4() {
    test_replacesADigitWithAnEqualNumberOfSpaces_digit3and0and1();
    test_replacesADigitWithAnEqualNumberOfSpaces_noNumbers();
    test_replacesADigitWithAnEqualNumberOfSpaces_onlyDigits();
    test_replacesADigitWithAnEqualNumberOfSpaces_emptyString();
}

#endif
