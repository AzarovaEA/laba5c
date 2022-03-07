#ifndef LABA5C_TASK6_H
#define LABA5C_TASK6_H

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

#include "../string_.h"

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *beginW1 = w1.begin;
    char *beginW2 = w2.begin;
    while (*beginW1 == *beginW2 && beginW1 != w1.end) {
        beginW1++;
        beginW2++;
    }
    return *beginW1 - *beginW2;
}

int isWordsArrangedLexicographically(char *s) {
    WordDescriptor word;
    if (!getWord(s, &word))
        return 1;

    s = word.end;
    WordDescriptor lastWord = word;
    while (getWord(s, &word)) {
        if (areWordsEqual(lastWord, word) > 0)
            return 0;
        s = word.end;
        lastWord = word;
    }
    return 1;
}

void test_isWordsArrangedLexicographically_wordsAreArranged() {
    char s[] = "a b f z";
    assert(isWordsArrangedLexicographically(s) == 1);
}

void test_isWordsArrangedLexicographically_wordsAreNotArranged() {
    char s[] = "a b a";
    assert(isWordsArrangedLexicographically(s) == 0);
}

void test_isWordsArrangedLexicographically_emptyString() {
    char s[] = "";
    assert(isWordsArrangedLexicographically(s) == 1);
}

void test_isWordsArrangedLexicographically_wordsIsOrdered() {
    char s[] = "arb kimono";
    assert(isWordsArrangedLexicographically(s) == 1);
}

void test_isWordsArrangedLexicographically_wordsIsNotOrdered() {
    char s[] = "kimono arb";
    assert(isWordsArrangedLexicographically(s) == 0);
}

void test_6() {
    test_isWordsArrangedLexicographically_wordsAreArranged();
    test_isWordsArrangedLexicographically_wordsAreNotArranged();
    test_isWordsArrangedLexicographically_emptyString();
    test_isWordsArrangedLexicographically_wordsIsOrdered();
    test_isWordsArrangedLexicographically_wordsIsNotOrdered();
}

#endif
