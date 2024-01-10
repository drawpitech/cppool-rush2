/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** test_list
*/

#include <signal.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "new.h"
#include "../list.h"
#include "int.h"
#include "point.h"

static
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(list, int_list) {
    Object *list = new(List, 10, Int, 0);
    Object *it = begin(list);
    Object *it_end = end(list);

    setitem(list, 5, 12);
    setitem(list, 6, 13);

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
    delete(list);
}

Test(list, point_list) {
    Object *list = new(List, 2, Point, 0, 2);
    Object *it = begin(list);
    Object *it_end = end(list);

    setitem(list, 1, 42, 69);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Point (0, 2)>");
    incr(it);

    cr_assert_eq(lt(it, it_end), true);
    cr_assert_str_eq(str(getval(it)), "<Point (42, 69)>");
    incr(it);

    delete(it);
    delete(it_end);
    delete(list);
}

Test(list, invalid_type, .signal = SIGABRT) {
    (void)new(List, 2, NULL, 0, 2);
}

Test(list, print) {
    Object *list = new(List, 3, Int, 0);

    setitem(list, 1, 69);
    setitem(list, 2, 84);

    cr_assert_str_eq(str(list), "<List (<Int (0)>, <Int (69)>, <Int (84)>)>");

    delete(list);
}
