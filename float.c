/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** float
*/

#include "rush.h"
#include "float.h"
#include "char.h"
#include "new.h"
#include <stdio.h>

static void float_ctor(float_class_t *this, va_list *args)
{
    if (!this || !args)
        raise("Null pointer passed");
    this->v = va_arg(*args, double);
}

static void float_dtor(float_class_t *this)
{
    if (!this)
        raise("Null pointer passed");
    this->v = 0;
}

static char *float_string(float_class_t *this)
{
    char *ptr = NULL;

    if (!this)
        raise("Null pointer passed");
    asprintf(&ptr, "<%s %f>", this->base.__name__, this->v);
    return ptr;
}

static
float_class_t *float_add(const float_class_t *this, const float_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Float, this->v + other->v);
}

static
float_class_t *float_sub(const float_class_t *this, const float_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Float, this->v - other->v);
}

static
float_class_t *float_mul(const float_class_t *this, const float_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Float, this->v * other->v);
}

static
float_class_t *float_div(const float_class_t *this, const float_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(Float, this->v / other->v);
}

static
bool float_eq(const float_class_t *this, const float_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return this->v == other->v;
}

static
bool float_lt(const float_class_t *this, const float_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return this->v < other->v;
}

static
bool float_gt(const float_class_t *this, const float_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return this->v > other->v;
}

static const float_class_t _description = {
    {   /* Class struct */
        .__size__ = sizeof(float_class_t),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_string,
        .__add__ = (binary_operator_t)&float_add,
        .__sub__ = (binary_operator_t)&float_sub,
        .__mul__ = (binary_operator_t)&float_mul,
        .__div__ = (binary_operator_t)&float_div,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__gt__ = (binary_comparator_t)&float_gt,
        .__lt__ = (binary_comparator_t)&float_lt
    },
    .v = 0
};

const Class *Float = (const Class *)&_description;
