/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** new
*/

#include "raise.h"
#include "new.h"

Object *new(const Class *class, ...)
{
    Class *new_obj = NULL;

    if (!class)
        raise("Null pointer passed");
    new_obj = malloc(class->__size__);
    if (!new_obj)
        raise("Out of memory");
    if (class->__ctor__)
        class->__ctor__(new_obj, NULL);
    return (Object *)new_obj;
}

// Object *va_new(const Class *class, va_list* ap);
void delete(Object *ptr)
{
    if ((Class *)ptr && ((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    if (ptr)
        free(ptr);
}
