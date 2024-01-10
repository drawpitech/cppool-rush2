/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** new
*/

#include "raise.h"
#include <stdarg.h>
#include "new.h"

Object *va_new(const Class *class, va_list* ap)
{
    Class *new_obj = NULL;

    if (!class)
        raise("Null pointer passed");
    new_obj = malloc(class->__size__);
    memcpy(new_obj, class, class->__size__);
    if (!new_obj)
        raise("Out of memory");
    if (class->__ctor__)
        class->__ctor__(new_obj, ap);
    return (Object *)new_obj;
}

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *new_obj = NULL;

    va_start(ap, class);
    new_obj = va_new(class, &ap);
    va_end(ap);
    return new_obj;
}

void delete(Object *ptr)
{
    if ((Class *)ptr && ((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    if (ptr)
        free(ptr);
}
