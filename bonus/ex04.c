/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** ex04
*/

#include "point.h"
#include "vertex.h"
#include "float.h"
#include "char.h"
#include "int.h"
#include "new.h"
#include <stdio.h>

void compareAndDivide(Object *a, Object *b)
{
    printf("%s\n", str(addition(a, b)));
    printf("%s\n", str(subtraction(a, b)));

    if ( gt (a , b ) )
        printf (" a > b\n") ;
    else if ( lt (a , b ) )
        printf (" a < b\n") ;
    else
        printf (" a == b\n") ;

    printf (" b / a = %s\n" , str ( division (b , a ) ) ) ;
}

int main(void)
{
    Object *p1 = new(Char, 'a');
    Object *p2 = new(Char, 'b');

    compareAndDivide(p1, p2);
    // printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
    // printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));
    // printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
    // printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    return (0);
}
