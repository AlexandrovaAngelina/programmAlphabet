#include "ctest.h"
#include "interface.h"
#include "sort.h"
#include "work_file.h"

CTEST(INTERFACE, CHECK_CHOISE_CORRECT)
{
    ASSERT_EQUAL(PRINT_TEXT, Check_Correct_Choice(PRINT_TEXT));
    ASSERT_EQUAL(SORT_TEXT, Check_Correct_Choice(SORT_TEXT));
    ASSERT_EQUAL(WRITE_IN_FILE, Check_Correct_Choice(WRITE_IN_FILE));
    ASSERT_EQUAL(CLEAR_SCREEN, Check_Correct_Choice(CLEAR_SCREEN));
    ASSERT_EQUAL(EXIT_FROM_PROGRAMM, Check_Correct_Choice(EXIT_FROM_PROGRAMM));
}

CTEST(INTERFACE, CHECK_CHOISE_INCORRECT)
{
    ASSERT_EQUAL(INCORECT_CHOICE, Check_Correct_Choice(-1));
    ASSERT_EQUAL(INCORECT_CHOICE, Check_Correct_Choice(4));
    ASSERT_EQUAL(INCORECT_CHOICE, Check_Correct_Choice(10));
}

CTEST(SORT, LESS)
{
    ASSERT_TRUE(Less("aaaa", "bbbb", 4, 4));
    ASSERT_TRUE(Less("a", "bbbb", 1, 4));
    ASSERT_TRUE(Less("aaaa", "b", 4, 1));
    ASSERT_FALSE(Less("aaaa", "aaaa", 4, 4));
    ASSERT_FALSE(Less("bbbb", "aaaa", 4, 4));
    ASSERT_FALSE(Less("b", "aaaa", 1, 4));
    ASSERT_FALSE(Less("bbbb", "a", 4, 1));
}

CTEST(WORK_FILE, CHECK_PUNCTUATION)
{
    ASSERT_TRUE(Check_Punctuation_Character(' '));
    ASSERT_TRUE(Check_Punctuation_Character('\n'));
    ASSERT_TRUE(Check_Punctuation_Character('\r'));
    ASSERT_TRUE(Check_Punctuation_Character('!'));
    ASSERT_TRUE(Check_Punctuation_Character('?'));
    ASSERT_TRUE(Check_Punctuation_Character(','));
    ASSERT_TRUE(Check_Punctuation_Character('.'));
    ASSERT_TRUE(Check_Punctuation_Character(':'));
    ASSERT_TRUE(Check_Punctuation_Character(';'));
    ASSERT_FALSE(Check_Punctuation_Character('a'));
    ASSERT_FALSE(Check_Punctuation_Character('1'));
}

CTEST(WORK_FILE, ERROR_OPEN_INPUT_FILE)
{
    ASSERT_EQUAL(ERROR_INPUT_FILE,Get_Size_for_Array(NULL, NULL, NULL));
}