/*
** EPITECH PROJECT, 2024
** rush2
** File description:
** tests for array
*/

#include <signal.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "new.h"
#include "array.h"
#include "int.h"
#include "point.h"

static
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(array, int_array) {
    Object *array = new(Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    setitem(array, 5, 12);
    setitem(array, 6, 13);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (0)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (0)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (0)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (0)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (0)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (12)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (13)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (0)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (0)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Int (0)>");
    incr(it);

    delete(it);
    delete(it_end);
    delete(array);
}

Test(array, point_array) {
    Object *array = new(Array, 2, Point, 0, 2);
    Object *it = begin(array);
    Object *it_end = end(array);

    setitem(array, 1, 42, 69);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Point (0, 2)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Point (42, 69)>");
    incr(it);

    delete(it);
    delete(it_end);
    delete(array);
}

Test(array, invalid_type, .signal = SIGABRT) {
    (void)new(Array, 2, NULL, 0, 2);
}

Test(array, print) {
    Object *array = new(Array, 3, Int, 0);

    setitem(array, 1, 69);
    setitem(array, 2, 84);

    cr_assert_str_eq(str(array), "<Array (<Int (0)>, <Int (69)>, <Int (84)>)>");

    delete(array);
}
