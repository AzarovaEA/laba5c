#ifndef LABA5C_TASK3_H
#define LABA5C_TASK3_H

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

#include "../string_.h"

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);
    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf(stringBuffer, endStringBuffer,word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitAtTheBeginningLettersAtTheEnd(char *s){
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

void test_digitAtTheBeginningLettersAtTheEnd_everythingIsInTheRightOrderInTheWords() {
    char s[MAX_STRING_SIZE] = "890uht 45dr 567uiog";
    digitAtTheBeginningLettersAtTheEnd(s);
    ASSERT_STRING("890uht 45dr 567uiog", s);
}

void test_digitAtTheBeginningLettersAtTheEnd_lettersAndNumbersInTheWordsAreNotOrdered() {
    char s[MAX_STRING_SIZE] = "uht678 45dr uiog567";
    digitAtTheBeginningLettersAtTheEnd(s);
    ASSERT_STRING("678uht 45dr 567uiog", s);
}

void test_digitAtTheBeginningLettersAtTheEnd_firstLettersThenNumbersInTheWord() {
    char s[MAX_STRING_SIZE] = "ffiuhu8906";
    digitAtTheBeginningLettersAtTheEnd(s);
    ASSERT_STRING("8906ffiuhu", s);
}

void test_digitAtTheBeginningLettersAtTheEnd_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    digitAtTheBeginningLettersAtTheEnd(s);
    ASSERT_STRING("", s);
}

void test_3() {
    test_digitAtTheBeginningLettersAtTheEnd_everythingIsInTheRightOrderInTheWords();
    test_digitAtTheBeginningLettersAtTheEnd_lettersAndNumbersInTheWordsAreNotOrdered();
    test_digitAtTheBeginningLettersAtTheEnd_emptyString();
    test_digitAtTheBeginningLettersAtTheEnd_firstLettersThenNumbersInTheWord();
}

#endif

