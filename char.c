/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** char
*/

#include "rush.h"
#include "char.h"
#include "new.h"
#include <stdio.h>

static void char_ctor(char_class_t *this, va_list *args)
{
    if (!this || !args)
        raise("Null pointer passed");
    this->v = va_arg(*args, int);
}

static void char_dtor(char_class_t *this)
{
    if (!this)
        raise("Null pointer passed");
    this->v = 0;
}

static char *char_string(char_class_t *this)
{
    char *ptr = NULL;

    if (!this)
        raise("Null pointer passed");
    asprintf(&ptr, "<%s (%c)>", this->base.__name__, this->v);
    return ptr;
}

static
char_class_t *char_add(const char_class_t *this, const char_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Char, this->v + other->v);
}

static
char_class_t *char_sub(const char_class_t *this, const char_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Char, this->v - other->v);
}

static
char_class_t *char_mul(const char_class_t *this, const char_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Char, this->v * other->v);
}

static
char_class_t *char_div(const char_class_t *this, const char_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Char, this->v / other->v);
}

static
bool char_eq(const char_class_t *this, const char_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return this->v == other->v;
}

static
bool char_lt(const char_class_t *this, const char_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return this->v < other->v;
}

static
bool char_gt(const char_class_t *this, const char_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return this->v > other->v;
}

static const char_class_t _description = {
    {   /* Class struct */
        .__size__ = sizeof(char_class_t),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&char_ctor,
        .__dtor__ = (dtor_t)&char_dtor,
        .__str__ = (to_string_t)&char_string,
        .__add__ = (binary_operator_t)&char_add,
        .__sub__ = (binary_operator_t)&char_sub,
        .__mul__ = (binary_operator_t)&char_mul,
        .__div__ = (binary_operator_t)&char_div,
        .__eq__ = (binary_comparator_t)&char_eq,
        .__gt__ = (binary_comparator_t)&char_gt,
        .__lt__ = (binary_comparator_t)&char_lt
    },
    .v = 0
};

const Class *Char = (const Class *)&_description;
