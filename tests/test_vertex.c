/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** test_vertex
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include "new.h"
#include "../rush.h"
#include "vertex.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (test_new_vertex_constructor, testvertex) {
    vertex_class_t *vertex = new(Vertex, 1, 2, 3);
    cr_assert_eq(vertex->x, 1);
    cr_assert_eq(vertex->y, 2);
    cr_assert_eq(vertex->z, 3);
    delete(vertex);
}

Test (test_new_vertex_with_null_value, test2, .signal=SIGABRT) {
    vertex_class_t *vertex = new(NULL, 1, 2, 3);
    cr_assert_null(vertex);
    delete(vertex);
}

Test (test_va_new_vertex_with_null_values, test2, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex = va_new(NULL, NULL);
    cr_assert_stderr_eq_str("Null pointer passed");
}

Test (test_va_new_vertex_string, test_3) {
    vertex_class_t *vertex = new(Vertex, 1, 2, 3);
    char *str = str(vertex);
    cr_assert_str_eq(str, "<Vertex (1, 2, 3)>");
    free(str);
    delete(vertex);
}

Test (test_new_vertex_string_null, test3, .signal=SIGABRT) {
    vertex_class_t *vertex = new(NULL, 1, 2, 3);
    char *str = str(vertex);
    cr_assert_null(str);
    free(str);
    delete(vertex);
}

Test (test_va_new_vertex_string_null_values, test3, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex = va_new(NULL, NULL);
    char *str = str(vertex);
    cr_assert_stderr_eq_str("Null pointer passed");
    free(str);
}

Test (test_va_new_vertex_add, test_4) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    vertex_class_t *vertex2 = new(Vertex, 4, 5, 6);
    vertex_class_t *vertex3 = addition(vertex1, vertex2);
    cr_assert_eq(vertex3->x, 5);
    cr_assert_eq(vertex3->y, 7);
    cr_assert_eq(vertex3->z, 9);
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_va_new_vertex_add_null, test4, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(NULL, 1, 2, 3);
    vertex_class_t *vertex2 = new(NULL, 4, 5, 6);
    vertex_class_t *vertex3 = addition(vertex1, vertex2);
    cr_assert_null(vertex3);
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_va_new_vertex_add_null_values, test4, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = va_new(NULL, NULL);
    vertex_class_t *vertex2 = va_new(NULL, NULL);
    vertex_class_t *vertex3 = addition(vertex1, vertex2);
    cr_assert_stderr_eq_str("Null pointer passed");
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_vertex_add_with_null_value1, test4, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    vertex_class_t *vertex2 = new(NULL, 4, 5, 6);
    addition(vertex1, NULL);
}

Test (test_va_new_vertex_sub, test_5) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    vertex_class_t *vertex2 = new(Vertex, 4, 5, 6);
    vertex_class_t *vertex3 = subtraction(vertex1, vertex2);
    cr_assert_eq(vertex3->x, -3);
    cr_assert_eq(vertex3->y, -3);
    cr_assert_eq(vertex3->z, -3);
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_va_new_vertex_sub_null, test5, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(NULL, 1, 2, 3);
    vertex_class_t *vertex2 = new(NULL, 4, 5, 6);
    vertex_class_t *vertex3 = subtraction(vertex1, vertex2);
    cr_assert_null(vertex3);
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_va_new_vertex_sub_null_values, test5, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = va_new(NULL, NULL);
    vertex_class_t *vertex2 = va_new(NULL, NULL);
    vertex_class_t *vertex3 = subtraction(vertex1, vertex2);
    cr_assert_stderr_eq_str("Null pointer passed");
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_vertex_sub_with_null_value1, test5, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    vertex_class_t *vertex2 = new(NULL, 4, 5, 6);
    subtraction(vertex1, NULL);
}

Test (test_va_vertex_mul, test_6) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    vertex_class_t *vertex2 = new(Vertex, 4, 5, 6);
    vertex_class_t *vertex3 = multiplication(vertex1, vertex2);
    cr_assert_eq(vertex3->x, 4);
    cr_assert_eq(vertex3->y, 10);
    cr_assert_eq(vertex3->z, 18);
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_va_vertex_mul_null, test_6, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(NULL, 1, 2, 3);
    vertex_class_t *vertex2 = new(NULL, 4, 5, 6);
    vertex_class_t *vertex3 = multiplication(vertex1, vertex2);
    cr_assert_null(vertex3);
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_va_vertex_mul_null_values, test_6, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = va_new(NULL, NULL);
    vertex_class_t *vertex2 = va_new(NULL, NULL);
    vertex_class_t *vertex3 = multiplication(vertex1, vertex2);
    cr_assert_stderr_eq_str("Null pointer passed");
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_vertex_with_null_value2, test5, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    vertex_class_t *vertex2 = new(NULL, 4, 5, 6);
    multiplication(vertex1, NULL);
}

Test (test_vertex_div, test7) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    vertex_class_t *vertex2 = new(Vertex, 4, 5, 6);
    vertex_class_t *vertex3 = division(vertex1, vertex2);
    cr_assert_eq(vertex3->x, 0);
    cr_assert_eq(vertex3->y, 0);
    cr_assert_eq(vertex3->z, 0);
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_vertex_div_null, test7, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(NULL, 1, 2, 3);
    vertex_class_t *vertex2 = new(NULL, 4, 5, 6);
    vertex_class_t *vertex3 = division(vertex1, vertex2);
    cr_assert_null(vertex3);
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_vertex_div_null_values, test7, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = va_new(NULL, NULL);
    vertex_class_t *vertex2 = va_new(NULL, NULL);
    vertex_class_t *vertex3 = division(vertex1, vertex2);
    cr_assert_stderr_eq_str("Null pointer passed");
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test (test_vertex_div_with_null_value1, test7, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    vertex_class_t *vertex2 = new(NULL, 4, 5, 6);
    division(vertex1, NULL);
}

Test (test_vertex_eq, test8) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    vertex_class_t *vertex2 = new(Vertex, 1, 2, 3);
    bool res = eq(vertex1, vertex2);
    cr_assert_eq(res, true);
    delete(vertex1);
    delete(vertex2);
}

Test (test_vertex_eq_null, test8, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(NULL, 1, 2, 3);
    vertex_class_t *vertex2 = new(NULL, 1, 2, 3);
    bool res = eq(vertex1, vertex2);
    cr_assert_null(res);
    delete(vertex1);
    delete(vertex2);
}

Test (test_vertex_eq_null_values, test8, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = va_new(NULL, NULL);
    vertex_class_t *vertex2 = va_new(NULL, NULL);
    bool res = eq(vertex1, vertex2);
    cr_assert_stderr_eq_str("Null pointer passed");
    delete(vertex1);
    delete(vertex2);
}

Test (test_vertex_eq_with_null_value1, test8, .init = redirect_all_std, .signal=SIGABRT) {
    vertex_class_t *vertex1 = new(Vertex, 1, 2, 3);
    bool res = eq(vertex1, NULL);
}