/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** int
*/

#include "rush.h"
#include "int.h"
#include "new.h"
#include <stdio.h>

static void int_ctor(int_class_t *this, va_list *args)
{
    if (!this || !args)
        raise("Null pointer passed");
    this->v = va_arg(*args, int);
}

static void int_dtor(int_class_t *this)
{
    if (!this)
        raise("Null pointer passed");
    this->v = 0;
}

static char *int_string(int_class_t *this)
{
    char *ptr = NULL;
    size_t size_res = 0;

    if (!this)
        raise("Null pointer passed");
    size_res = snprintf(NULL, 0, "<%s (%d)>", this->base.__name__, this->v);
    ptr = malloc(sizeof(char) * size_res + 1);
    sprintf(ptr, "<%s (%d)>", this->base.__name__, this->v);
    return ptr;
}

static
int_class_t *int_add(const int_class_t *this, const int_class_t *other)
{
    if (!this || !other)
        raise("Null inter passed");
    return new(Int, this->v + other->v);
}

static
int_class_t *int_sub(const int_class_t *this, const int_class_t *other)
{
    if (!this || !other)
        raise("Null inter passed");
    return new(Int, this->v - other->v);
}

static
int_class_t *int_mul(const int_class_t *this, const int_class_t *other)
{
    if (!this || !other)
        raise("Null inter passed");
    return new(Int, this->v * other->v);
}

static
int_class_t *int_div(const int_class_t *this, const int_class_t *other)
{
    if (!this || !other)
        raise("Null inter passed");
    return new(Int, this->v / other->v);
}

static
bool int_eq(const int_class_t *this, const int_class_t *other)
{
    if (!this || !other)
        raise("Null inter passed");
    return this->v == other->v;
}

static
bool int_lt(const int_class_t *this, const int_class_t *other)
{
    if (!this || !other)
        raise("Null inter passed");
    return this->v < other->v;
}

static
bool int_gt(const int_class_t *this, const int_class_t *other)
{
    if (!this || !other)
        raise("Null inter passed");
    return this->v > other->v;
}

static const int_class_t _description = {
    {   /* Class struct */
        .__size__ = sizeof(int_class_t),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_ctor,
        .__dtor__ = (dtor_t)&int_dtor,
        .__str__ = (to_string_t)&int_string,
        .__add__ = (binary_operator_t)&int_add,
        .__sub__ = (binary_operator_t)&int_sub,
        .__mul__ = (binary_operator_t)&int_mul,
        .__div__ = (binary_operator_t)&int_div,
        .__eq__ = (binary_comparator_t)&int_eq,
        .__gt__ = (binary_comparator_t)&int_gt,
        .__lt__ = (binary_comparator_t)&int_lt
    },
    .v = 0
};

const class_t *Int = (const class_t *)&_description;
