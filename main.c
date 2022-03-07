#include "libs/string_.h"
#include "libs/tasks/task1.h"
#include "libs/tasks/task2.h"
#include "libs/tasks/task3.h"
#include "libs/tasks/task4.h"

void test_findNonSpace_firstCharacterIsNotWhitespace() {
    char testWord[] = "Good";
    assert(findNonSpace(testWord) == testWord);
}

void test_findNonSpace_noNonWhitespaceCharacters() {
    char testWord[] = "  ";
    assert(findNonSpace(testWord) == testWord + 2);
}

void test_findNonSpace_fourthCharacterIsNotWhitespace() {
    char testWord[] = "    Afternoon";
    assert(findNonSpace(testWord) == testWord + 4);
}

void test_findNonSpace() {
    test_findNonSpace_firstCharacterIsNotWhitespace();
    test_findNonSpace_noNonWhitespaceCharacters();
    test_findNonSpace_fourthCharacterIsNotWhitespace();
}

void test_findSpace_withoutWhitespace() {
    char testWord[] = "Good";
    assert(findSpace(testWord) == testWord + 4);
}

void test_findSpace_firstCharacterIsWhitespace() {
    char testWord[] = " Afternoon";
    assert(findSpace(testWord) == testWord);
}

void test_findSpace_spaceCharacterInTheMiddleOfAWord() {
    char testWord[] = "te   st";
    assert(findSpace(testWord) == testWord + 2);
}

void test_findSpace() {
    test_findSpace_withoutWhitespace();
    test_findSpace_firstCharacterIsWhitespace();
    test_findSpace_spaceCharacterInTheMiddleOfAWord();
}

void test_findNonSpaceReverse_firstCharacterIsNotWhitespace() {
    int size = 4;
    char testWord[] = "test";
    assert(findNonSpaceReverse(&testWord[size - 1], testWord) == testWord + 3);
}

void test_findNonSpaceReverse_noCharacters() {
    int size = 3;
    char testWord[] = "   ";
    assert(findNonSpaceReverse(&testWord[size - 1], testWord) == testWord);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_firstCharacterIsNotWhitespace();
    test_findNonSpaceReverse_noCharacters();
}

void test_findSpaceReverse_firstCharacterInTheWordSpace() {
    int size = 5;
    char testWord[] = " test";
    assert(findSpaceReverse(&testWord[size - 1], testWord) == testWord);
}

void test_findSpaceReverse_lastCharacterInTheWordSpace() {
    int size = 6;
    char testWord[] = "test  ";
    assert(findSpaceReverse(&testWord[size - 1], testWord) == testWord + 5);
}

void test_findSpaceReverse_spaceCharacterInTheMiddle() {
    int size = 5;
    char testWord[] = "test";
    assert(findSpaceReverse(&testWord[size - 1], testWord) == testWord);
}

void test_findSpaceReverse() {
    test_findSpaceReverse_firstCharacterInTheWordSpace();
    test_findSpaceReverse_lastCharacterInTheWordSpace();
    test_findSpaceReverse_spaceCharacterInTheMiddle();
}

void test() {
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
}
void test_tasks(){
    test_1();
    test_2();
    test_3();
    test_4();
}

int main() {
    test();
    test_tasks();

    return 0;
}
