/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include "array.h"
#include "list.h"
#include "int.h"
#include "vertex.h"
#include "new.h"
#include <stdio.h>

int main(void)
{
    Object *list = new(List, 10, Vertex, 0, 0, 0);
    Object *it = begin(list);
    Object *it_end = end(list);

    printf("list size: %zu\n", len(list));
    setitem(list, 5, 12, 12, 12);
    setitem(list, 6, 13, 13, 13);
    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(list);
    return (0);
}
