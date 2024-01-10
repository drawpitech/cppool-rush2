/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH2-marius.marolleau
** File description:
** new
*/

#include "raise.h"
#include <stdarg.h>
#include "new.h"
#include "rush.h"

object_t *va_new(const class_t *class, va_list *ap)
{
    class_t *new_obj = NULL;

    if (!class)
        raise("Null pointer passed");
    new_obj = malloc(class->__size__);
    if (!new_obj)
        raise("Out of memory");
    memcpy(new_obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(new_obj, ap);
    return (object_t *)new_obj;
}

object_t *new(const class_t *class, ...)
{
    va_list ap;
    object_t *new_obj = NULL;

    if (!class)
        raise("Null pointer passed");
    va_start(ap, class);
    new_obj = va_new(class, &ap);
    va_end(ap);
    return new_obj;
}

void delete(object_t *ptr)
{
    if (!ptr)
        return;
    if (((class_t *)ptr)->__dtor__)
        ((class_t *)ptr)->__dtor__(ptr);
    free(ptr);
}
