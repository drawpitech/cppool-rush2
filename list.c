/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdarg.h>

#include "object.h"
#include "raise.h"
#include "list.h"
#include "new.h"
#include "rush.h"

static void list_iter_ctor(
    list_iter_class_t *this,
    va_list *args)
{
    this->_array = va_arg(*args, list_class_t *);
    this->_idx = va_arg(*args, int);
}

static bool list_iter_eq(
    list_iter_class_t *this,
    list_iter_class_t *other)
{
    return (this->_idx == other->_idx);
}

static bool list_iter_gt(
    list_iter_class_t *this,
    list_iter_class_t *other)
{
    return (this->_idx > other->_idx);
}

static bool list_iter_lt(
    list_iter_class_t *this,
    list_iter_class_t *other)
{
    return (this->_idx < other->_idx);
}

static void list_iter_incr(list_iter_class_t *this)
{
    this->_idx += 1;
}

static object_t *list_iter_getval(list_iter_class_t *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

/* Fill this function for exercice 05 */
static void list_iter_setval(list_iter_class_t *this, ...)
{
    size_t ind = 0;
    va_list ap;

    if (!this || !this->_array || !this->_array->_tab)
        raise("Null pointer passed");
    va_start(ap, this);
    ind = va_arg(ap, size_t);
    if (ind > this->_array->_size)
        raise("Index out of range");
    delete(this->_array->_tab[ind]);
    this->_array->_tab[ind] = va_new(this->_array->_type, &ap);
    va_end(ap);
}

static const list_iter_class_t ListIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(list_iter_class_t),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&list_iter_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&list_iter_eq,
            .__gt__ = (binary_comparator_t)&list_iter_gt,
            .__lt__ = (binary_comparator_t)&list_iter_lt,
        },
        .__incr__ = (incr_t)&list_iter_incr,
        .__getval__ = (getval_t)&list_iter_getval,
        .__setval__ = (setval_t)&list_iter_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

/* Fill this function for exercice 05 */
static void list_ctor(list_class_t *this, va_list *args)
{
    va_list value;

    if (!this || !args)
        raise("Null pointer passed");
    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, class_t *);
    this->_tab = malloc(sizeof(object_t *) * this->_size);
    if (!this->_tab)
        raise("Out of memory");
    for (size_t i = 0; i < this->_size; i++){
        va_copy(value, *args);
        this->_tab[i] = va_new(this->_type, &value);
        va_end(value);
    }
}

static void list_dtor(list_class_t *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t list_len(list_class_t *this)
{
    return (this->_size);
}

static iterator_t *list_begin(list_class_t *this)
{
    return (new(ListIterator, this, 0));
}

static iterator_t *list_end(list_class_t *this)
{
    return (new(ListIterator, this, this->_size));
}

/* Fill this function for exercice 05 */
static object_t *list_getitem(list_class_t *this, ...)
{
    size_t ind = 0;
    va_list ap;

    if (!this || !this->_tab)
        raise("Null pointer passed");
    va_start(ap, this);
    ind = va_arg(ap, size_t);
    va_end(ap);
    if (ind > this->_size)
        raise("Index out of range");
    return this->_tab[ind];
}

/* Fill this function for exercice 05 */
static void list_setitem(list_class_t *this, ...)
{
    size_t ind = 0;
    va_list ap;

    if (!this || !this->_tab)
        raise("Null pointer passed");
    va_start(ap, this);
    ind = va_arg(ap, size_t);
    if (ind > this->_size)
        raise("Index out of range");
    delete(this->_tab[ind]);
    this->_tab[ind] = va_new(this->_type, &ap);
    va_end(ap);
}

static const list_class_t _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(list_class_t),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&list_ctor,
            .__dtor__ = (dtor_t)&list_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&list_len,
        .__begin__ = (iter_t)&list_begin,
        .__end__ = (iter_t)&list_end,
        .__getitem__ = (getitem_t)&list_getitem,
        .__setitem__ = (setitem_t)&list_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const class_t *List = (const class_t *)&_descr;
