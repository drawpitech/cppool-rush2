/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "new.h"
#include "vertex.h"
#include "rush.h"
#include <stdio.h>

/* Fill this function for exercice 02 */
static void vertex_ctor(vertex_class_t *this, va_list *args)
{
    if (!this || !args)
        raise("Null pointer passed");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

/* Fill this function for exercice 02 */
static void vertex_dtor(vertex_class_t *this)
{
    if (!this)
        raise("Null pointer passed");
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

static char *vertex_string(vertex_class_t *this)
{
    char *ptr = NULL;
    size_t size_res = 0;

    if (!this)
        raise("Null pointer passed");
    size_res = snprintf(NULL, 0, "<%s (%d, %d, %d)>",
        this->base.__name__, this->x, this->y, this->z);
    ptr = malloc(sizeof(char) * size_res + 1);
    sprintf(ptr, "<%s (%d, %d, %d)>",
        this->base.__name__, this->x, this->y, this->z);
    return ptr;
}

static
vertex_class_t *vertex_add(
    const vertex_class_t *this, const vertex_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(
        Vertex,
        this->x + other->x,
        this->y + other->y,
        this->z + other->z
        );
}

static
vertex_class_t *vertex_sub(
    const vertex_class_t *this, const vertex_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(
        Vertex,
        this->x - other->x,
        this->y - other->y,
        this->z - other->z
    );
}

static
vertex_class_t *vertex_mul(
    const vertex_class_t *this, const vertex_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(
        Vertex,
        this->x * other->x,
        this->y * other->y,
        this->z * other->z
    );
}

static
vertex_class_t *vertex_div(
    const vertex_class_t *this, const vertex_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return new(
        Vertex,
        this->x / other->x,
        this->y / other->y,
        this->z / other->z
    );
}

static
bool vertex_eq(const vertex_class_t *this, const vertex_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    return (
        this->x == other->x
        && this->y == other->y
        && this->z == other->z
    );
}

static const vertex_class_t _description = {
    {   /* Class struct */
        .__size__ = sizeof(vertex_class_t),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = (dtor_t)&vertex_dtor,
        .__str__ = (to_string_t)&vertex_string,
        .__add__ = (binary_operator_t)&vertex_add,
        .__sub__ = (binary_operator_t)&vertex_sub,
        .__mul__ = (binary_operator_t)&vertex_mul,
        .__div__ = (binary_operator_t)&vertex_div,
        .__eq__ = (binary_comparator_t)&vertex_eq,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0,
};

const class_t *Vertex = (const class_t *)&_description;
