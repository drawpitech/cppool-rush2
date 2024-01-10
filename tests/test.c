/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "../rush.h"
#include <signal.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (test_new_simple, test1) {
    point_class_t *point = new(Point, 5, 6);
    cr_assert_eq(point->x, 5);
    cr_assert_eq(point->y, 6);
    delete(point);
}

Test (test_new_with_null_value, test1) {
    point_class_t *point = new(NULL, 5, 6);
    cr_assert_null(point);
    delete(point);
}

Test (test_va_new_with_null_value, test1, .init = redirect_all_std, .signal=SIGABRT) {
    point_class_t *point = va_new(NULL, NULL);
    cr_assert_stderr_eq_str("Null pointer passed");
}
