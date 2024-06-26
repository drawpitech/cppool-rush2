/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "rush.h"
#include "new.h"
#include <stdio.h>

/* Fill this function for exercice 02 */
static void point_ctor(point_class_t *this, va_list *args)
{
    if (!this || !args)
        raise("Null pointer passed");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

/* Fill this function for exercice 02 */
static void point_dtor(point_class_t *this)
{
    if (!this)
        raise("Null pointer passed");
    this->x = 0;
    this->y = 0;
}

static char *point_string(point_class_t *this)
{
    char *ptr = NULL;
    size_t size_res = 0;

    if (!this)
        raise("Null pointer passed");
    size_res = snprintf(NULL, 0, "<%s (%d, %d)>",
            this->base.__name__, this->x, this->y);
    ptr = malloc(sizeof(char) * size_res + 1);
    sprintf(ptr, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return ptr;
}

static
point_class_t *point_add(const point_class_t *this, const point_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Point, this->x + other->x, this->y + other->y);
}

static
point_class_t *point_sub(const point_class_t *this, const point_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Point, this->x - other->x, this->y - other->y);
}

static
point_class_t *point_mul(const point_class_t *this, const point_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Point, this->x * other->x, this->y * other->y);
}

static
point_class_t *point_div(const point_class_t *this, const point_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Point, this->x / other->x, this->y / other->y);
}

static
bool point_eq(const point_class_t *this, const point_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return (this->x == other->x && this->y == other->y);
}

static const point_class_t _description = {
    {   /* Class struct */
        .__size__ = sizeof(point_class_t),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = (dtor_t)&point_dtor,
        .__str__ = (to_string_t)&point_string,
        .__add__ = (binary_operator_t)&point_add,
        .__sub__ = (binary_operator_t)&point_sub,
        .__mul__ = (binary_operator_t)&point_mul,
        .__div__ = (binary_operator_t)&point_div,
        .__eq__ = (binary_comparator_t)&point_eq,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const class_t *Point = (const class_t *)&_description;
