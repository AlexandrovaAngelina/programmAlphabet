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

CTEST(SORT, COMPARISON)
{
    ASSERT_EQUAL(Comparison("aaaa", "bbbb", 4, 4), LESS);
    ASSERT_EQUAL(Comparison("a", "bbbb", 1, 4), LESS);
    ASSERT_EQUAL(Comparison("aaaa", "b", 4, 1), LESS);
    ASSERT_EQUAL(Comparison("aaaa", "aaaa", 4, 4), EQUALLY);
    ASSERT_EQUAL(Comparison("bbbb", "aaaa", 4, 4), LARGE);
    ASSERT_EQUAL(Comparison("b", "aaaa", 1, 4), LARGE);
    ASSERT_EQUAL(Comparison("bbbb", "a", 4, 1), LARGE);
}

CTEST(WORK_FILE, CHECK_ENGLISH_SYMBOL)
{
    for (short int i = 0; i < QUANTITY_SYMBOL_IN_ENGLISH; i++) {
        ASSERT_TRUE(Check_English_Symbol('a' + i));
        ASSERT_TRUE(Check_English_Symbol('A' + i));
    }
}

CTEST(WORK_FILE, ERROR_OPEN_INPUT_FILE)
{
    ASSERT_EQUAL(ERROR_INPUT_FILE, Get_Size_for_Array(NULL, NULL, NULL));
}