/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdio.h>
#include "array.h"
#include "int.h"
#include "vertex.h"
#include "new.h"
#include "char.h"
#include "../list.h"
#include "mystring.h"

int main(void)
{
    Object *str1 = new(String, "hello world");
    Object *str2 = new(String, "0000000");

    setitem(str2, 5, 'q');
    printf("%s\n", str(str1));
    printf("%s\n", str(str2));
    if (eq(str1, str2))
        printf("are equal\n");
    delete(str2);
    delete(str1);
    return (0);
}
