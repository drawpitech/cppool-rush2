/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "rush.h"
#include <stdio.h>

/* Fill this function for exercice 02 */
static void vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this || !args)
        raise("Null pointer passed");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
    printf("Vertex()\n");
}

/* Fill this function for exercice 02 */
static void vertex_dtor(VertexClass *this)
{
    if (!this)
        raise("Null pointer passed");
    this->x = 0;
    this->y = 0;
    this->z = 0;
    printf("~Vertex()\n");
}

static char *vertex_string(VertexClass *this)
{
    char *ptr = NULL;

    if (!this)
        raise("Null pointer passed");
    asprintf(&ptr, "<%s (%d, %d, %d)>",
        this->base.__name__, this->x, this->y, this->z);
    return ptr;
}

// Create additional functions here
static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = (dtor_t)&vertex_dtor,
        .__str__ = (to_string_t)&vertex_string,
        .__add__ = NULL,    /* Implement this method for exercice 03 */
        .__sub__ = NULL,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0,
};

const Class *Vertex = (const Class *)&_description;
