/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "rush.h"
#include <stdio.h>

/* Fill this function for exercice 02 */
static void point_ctor(PointClass *this, va_list *args)
{
    if (!this || !args)
        raise("Null pointer passed");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    printf("Point()\n");
}

/* Fill this function for exercice 02 */
static void point_dtor(PointClass *this)
{
    if (!this)
        raise("Null pointer passed");
    this->x = 0;
    this->y = 0;
    printf("~Point()\n");
}

static char *point_string(PointClass *this)
{
    char *ptr = NULL;

    if (!this)
        raise("Null pointer passed");
    asprintf(&ptr, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return ptr;
}

// Create additional functions here
static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = (dtor_t)&point_dtor,
        .__str__ = (to_string_t)&point_string,
        .__add__ = NULL,    /* Implement this method for exercice 03 */
        .__sub__ = NULL,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
