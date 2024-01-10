/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** test_char
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include "new.h"
#include "../rush.h"
#include "char.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/* ------------Tests on char functions -------------- */

/* Test the constructor of char */

Test(test_new_char_constructor, testchar)
{
    char_class_t *character = new(Char, 'a');
    cr_assert_eq(character->v, 'a');
    delete(character);
}

Test(test_new_char_with_null_value, test2, .signal = SIGABRT)
{
    char_class_t *character = new(NULL, 'a');
    cr_assert_null(character);
    delete(character);
}

Test(test_new_char_with_null_struct, test2, .init = redirect_all_std, .signal = SIGABRT)
{
    char_class_t *character = new(NULL, 'a');
    (void)character;
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Test the addition of char */

Test(test_add_char, test3)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(Char, 'b');
    char_class_t *character3 = addition(character, character2);
    cr_assert_eq(character3->v, -61);
    delete(character);
    delete(character2);
    delete(character3);
}

Test(test_add_char_with_null_value, test4, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    char_class_t *character3 = addition(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    delete(character3);
}

Test(test_add_char_with_null_struct, test5, .init = redirect_all_std, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    char_class_t *character3 = addition(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    delete(character3);
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Test the substraction of char */

Test(test_sub_char, test6)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(Char, 'b');
    char_class_t *character3 = subtraction(character, character2);
    cr_assert_eq(character3->v, -1);
    delete(character);
    delete(character2);
    delete(character3);
}

Test(test_sub_char_with_null_value, test7, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    char_class_t *character3 = subtraction(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    delete(character3);
}

Test(test_sub_char_with_null_struct, test8, .init = redirect_all_std, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    char_class_t *character3 = subtraction(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    delete(character3);
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Test the multiplication of char */

Test(test_mul_char, test9)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(Char, 'b');
    char_class_t *character3 = multiplication(character, character2);
    cr_assert_eq(character3->v, 34);
    delete(character);
    delete(character2);
    delete(character3);
}

Test(test_mul_char_with_null_value, test10, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    char_class_t *character3 = multiplication(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    delete(character3);
}

Test(test_mul_char_with_null_struct, test11, .init = redirect_all_std, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    char_class_t *character3 = multiplication(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    delete(character3);
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Test the division of char */

Test(test_div_char, test12)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(Char, 'b');
    char_class_t *character3 = division(character, character2);
    cr_assert_eq(character3->v, 0);
    delete(character);
    delete(character2);
    delete(character3);
}

Test(test_div_char_with_null_value, test13, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    char_class_t *character3 = division(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    delete(character3);
}

Test(test_div_char_with_null_struct, test14, .init = redirect_all_std, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    char_class_t *character3 = division(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    delete(character3);
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Test the equality of char */

Test(test_eq_char, test15)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(Char, 'b');
    bool character3 = eq(character, character2);
    cr_assert_eq(character3, false);
    delete(character);
    delete(character2);
}

Test(test_eq_char_with_null_value, test16, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    bool character3 = eq(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
}

Test(test_eq_char_with_null_struct, test17, .init = redirect_all_std, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    bool character3 = eq(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Test the greater than of char */

Test(test_gt_char, test18)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(Char, 'b');
    bool character3 = gt(character, character2);
    cr_assert_eq(character3, false);
    delete(character);
    delete(character2);
}

Test(test_gt_char_with_null_value, test19, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    bool character3 = gt(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
}

Test(test_gt_char_with_null_struct, test20, .init = redirect_all_std, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    bool character3 = gt(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Test the lower than of char */

Test(test_lt_char, test21)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(Char, 'b');
    bool character3 = lt(character, character2);
    cr_assert_eq(character3, true);
    delete(character);
    delete(character2);
}

Test(test_lt_char_with_null_value, test22, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    bool character3 = lt(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
}

Test(test_lt_char_with_null_struct, test23, .init = redirect_all_std, .signal = SIGABRT)
{
    char_class_t *character = new(Char, 'a');
    char_class_t *character2 = new(NULL, 'b');
    bool character3 = lt(character, character2);
    (void)character3;
    delete(character);
    delete(character2);
    cr_assert_stderr_eq_str("Null pointer passed");
}