/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** test_int
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include <stdarg.h>
#include "int.h"
#include "new.h"
#include "../rush.h"

static
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/*-----------------Test on New function------------------*/

Test (test_new_simple_int, test1, .init = redirect_all_std) {
    int_class_t *test_int = new(Int, 5);
    cr_assert_eq(test_int->v, 5);
    delete(test_int);
}

Test (test_new_with_null_value_int_, test1, .signal=SIGABRT) {
    int_class_t *test_int = new(NULL, 5);
    cr_assert_stderr_eq_str("Null pointer passed");
    delete(test_int);
}

/*-----------------Test on New function------------------*/

/* Add*/

Test (test_add_with_int, test1, .init=redirect_all_std) {
    int_class_t *test_int = new(Int, 5);
    int_class_t *test_int_2 = new(Int, 6);
    int_class_t *res = addition(test_int, test_int_2);
    char *ptr = str(res);
    cr_assert_str_eq(ptr, "<Int (11)>");
    delete(test_int);
    delete(test_int_2);
    delete(res);
}

Test (test_add_with_null_value_int_, test1, .signal=SIGABRT) {
    int_class_t *test_int = new(Int, 5);
    addition(test_int, NULL);
    cr_assert_stderr_eq_str("Null pointer passed");
    delete(test_int);
}

/* Sub*/

Test (test_int_sub_simple, test1, .init = redirect_all_std) {
    int_class_t *test_int = new(Int, 5);
    int_class_t *test_int2 = new(Int, 5);
    int_class_t *new_test_int = subtraction(test_int, test_int2);
    char *ptr = str(new_test_int);
    cr_assert_str_eq(ptr, "<Int (0)>");
    delete(test_int);
    delete(test_int2);
    delete(new_test_int);
}

Test (test_int_sub_with_null_value, test1, .init = redirect_all_std, .signal=SIGABRT) {
    int_class_t *test_int = new(Int, 5);
    int_class_t *new_test_int = subtraction(test_int, NULL);
    (void)new_test_int;
    cr_assert_stderr_eq_str("Null pointer passed");
}

Test (test_int_sub_with_null_value_bis, test1, .init = redirect_all_std, .signal=SIGABRT) {
    int_class_t *test_int = new(Int, 5);
    int_class_t *new_test_int = subtraction(test_int, NULL);
    (void)new_test_int;
    cr_assert_stderr_eq_str("Null pointer passed");
}

 /* Multiplication */

Test (test_int_mul_simple, test1, .init = redirect_all_std) {
    int_class_t *test_int = new(Int, 5);
    int_class_t *test_int2 = new(Int, 5);
    int_class_t *new_test_int = multiplication(test_int, test_int2);
    cr_assert_eq(new_test_int->v, 25);
}

Test (test_int_mul_with_null_value, test1, .init = redirect_all_std, .signal=SIGABRT) {
    int_class_t *test_int = new(Int, 5);
    int_class_t *new_test_int = multiplication(test_int, NULL);
    (void)new_test_int;
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Division */

Test (test_int_div_simple, test1, .init = redirect_all_std) {
    point_class_t *test_int = new(Int, 5);
    int_class_t *test_int2 = new(Int, 5);
    int_class_t *new_test_int = division(test_int, test_int2);
    cr_assert_eq(new_test_int->v, 1);
}

Test (test_int_div_with_null_value, test1, .init = redirect_all_std, .signal=SIGABRT) {
    int_class_t *test_int = new(Int, 5, 6);
    int_class_t *new_test_int = division(test_int, NULL);
    (void)new_test_int;
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Equality */

Test (test_int_eq_with_null_value, test1, .init = redirect_all_std, .signal=SIGABRT) {
    int_class_t *test_int = new(Int, 5, 6);
    eq(test_int, NULL);
    cr_assert_stderr_eq_str("Null pointer passed");
}

Test (test_int_eq_simple_true, test1, .init = redirect_all_std) {
    int_class_t *test_int = new(Int, 5);
    int_class_t *test_int2 = new(Int, 5);
    cr_assert(eq(test_int, test_int2));
}

Test (test_int_eq_simple_false, test1, .init = redirect_all_std) {
    int_class_t *test_int = new(Int, 5, 6);
    int_class_t *test_int2 = new(Int, 8, 9);
    cr_assert(!eq(test_int, test_int2));
}
