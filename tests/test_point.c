/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include <stdarg.h>
#include "new.h"
#include "../rush.h"
#include "vertex.h"
#include "point.h"

static
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
/*-----------------Test on New function------------------*/

Test (test_new_simple, test1) {
    point_class_t *point = new(Point, 5, 6);
    cr_assert_eq(point->x, 5);
    cr_assert_eq(point->y, 6);
    delete(point);
}

Test (test_new_with_null_value, test1, .signal=SIGABRT, .init = redirect_all_std) {
    point_class_t *point = new(NULL, 5, 6);
    cr_assert_null(point);
    cr_assert_stderr_eq_str("Null pointer passed");
    delete(point);
}

/*-----------------Test on Del function------------------*/

Test (test_del_with_null_value, test1, .init = redirect_all_std) {
    delete(NULL);
}

/*-----------------Test on Va_new function------------------*/

Test (test_va_new_with_null_value, test1, .signal=SIGABRT) {
    va_list ap;
    point_class_t *point = va_new(NULL, &ap);
    (void)point;
    cr_assert_stderr_eq_str("Null pointer passed");
}

Test (test_va_new_with_null_value_2, test1, .init = redirect_all_std, .signal=SIGABRT) {
    point_class_t *point = va_new(NULL, NULL);
    (void)point;
    cr_assert_stderr_eq_str("Null pointer passed");
}

/*-----------------Test on point functions------------------*/

/* Display content */

Test (test_point_simple, test1, .init = redirect_all_std) {
    point_class_t *point = new(Point, 5, 6);
    char *ptr = str(point);
    cr_assert_str_eq(ptr, "<Point (5, 6)>");
}

/* Add */

Test (test_point_add_simple, test1, .init = redirect_all_std) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *point2 = new(Point, 5, 6);
    point_class_t *new_point = addition(point, point2);
    cr_assert_eq(new_point->x, 10, "Got %d", new_point->x);
    cr_assert_eq(new_point->y, 12, "Got %d", new_point->y);
}

Test (test_point_add_with_null_value_bis, test1, .init = redirect_all_std, .signal=SIGABRT) {
    point_class_t *point = new(Point, 5, 6);
    addition(point, NULL);
}

/* Substration */

Test (test_point_sub_simple, test1, .init = redirect_all_std) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *point2 = new(Point, 5, 6);
    point_class_t *new_point = subtraction(point, point2);
    cr_assert_eq(new_point->x, 0);
    cr_assert_eq(new_point->y, 0);
}

Test (test_point_sub_with_null_value, test1, .init = redirect_all_std, .signal=SIGABRT) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *new_point = subtraction(point, NULL);
    (void)new_point;
    cr_assert_stderr_eq_str("Null pointer passed");
}

Test (test_point_sub_with_null_value_bis, test1, .init = redirect_all_std, .signal=SIGABRT) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *new_point = subtraction(point, NULL);
    (void)new_point;
    cr_assert_stderr_eq_str("Null pointer passed");
}

 /* Multiplication */

Test (test_point_mul_simple, test1, .init = redirect_all_std) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *point2 = new(Point, 5, 6);
    point_class_t *new_point = multiplication(point, point2);
    cr_assert_eq(new_point->x, 25);
    cr_assert_eq(new_point->y, 36);
}

Test (test_point_mul_with_null_value, test1, .init = redirect_all_std, .signal=SIGABRT) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *new_point = multiplication(point, NULL);
    (void)new_point;
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Division */

Test (test_point_div_simple, test1, .init = redirect_all_std) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *point2 = new(Point, 5, 6);
    point_class_t *new_point = division(point, point2);
    cr_assert_eq(new_point->x, 1);
    cr_assert_eq(new_point->y, 1);
}


Test (test_point_div_with_null_value, test1, .init = redirect_all_std, .signal=SIGABRT) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *new_point = division(point, NULL);
    (void)new_point;
    cr_assert_stderr_eq_str("Null pointer passed");
}

/* Equality */

Test (test_point_eq_with_null_value, test1, .init = redirect_all_std, .signal=SIGABRT) {
    point_class_t *point = new(Point, 5, 6);
    eq(point, NULL);
    cr_assert_stderr_eq_str("Null pointer passed");
}

Test (test_point_eq_simple_true, test1, .init = redirect_all_std) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *point2 = new(Point, 5, 6);
    cr_assert(eq(point, point2));
}

Test (test_point_eq_simple_false, test1, .init = redirect_all_std) {
    point_class_t *point = new(Point, 5, 6);
    point_class_t *point2 = new(Point, 8, 9);
    cr_assert(!eq(point, point2));
}
