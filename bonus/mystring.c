/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "object.h"
#include "raise.h"
#include "char.h"
#include "array.h"
#include "new.h"
#include "../rush.h"

static void string_iter_ctor(
    string_iter_class_t *this,
    va_list *args)
{
    this->_array = va_arg(*args, string_class_t *);
    this->_idx = va_arg(*args, int);
}

static bool string_iter_eq(
    string_iter_class_t *this,
    string_iter_class_t *other)
{
    return (this->_idx == other->_idx);
}

static bool string_iter_gt(
    string_iter_class_t *this,
    string_iter_class_t *other)
{
    return (this->_idx > other->_idx);
}

static bool string_iter_lt(
    string_iter_class_t *this,
    string_iter_class_t *other)
{
    return (this->_idx < other->_idx);
}

static void string_iter_incr(string_iter_class_t *this)
{
    this->_idx += 1;
}

static object_t *string_iter_getval(string_iter_class_t *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

/* Fill this function for exercice 05 */
static void string_iter_setval(string_iter_class_t *this, ...)
{
    size_t ind = 0;
    va_list ap;

    if (!this || !this->_array || !this->_array->_tab)
        raise("Null pointer passed");
    ind = this->_idx;
    if (ind >= this->_array->_size)
        raise("Index out of range");
    delete(this->_array->_tab[ind]);
    va_start(ap, this);
    this->_array->_tab[ind] = va_new(this->_array->_type, &ap);
    va_end(ap);
}

static const string_iter_class_t StringIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(string_iter_class_t),
            .__name__ = "StringIterator",
            .__ctor__ = (ctor_t)&string_iter_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&string_iter_eq,
            .__gt__ = (binary_comparator_t)&string_iter_gt,
            .__lt__ = (binary_comparator_t)&string_iter_lt,
        },
        .__incr__ = (incr_t)&string_iter_incr,
        .__getval__ = (getval_t)&string_iter_getval,
        .__setval__ = (setval_t)&string_iter_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class *StringIterator = (const Class *)&StringIteratorDescr;

/* Fill this function for exercice 05 */
static void string_ctor(string_class_t *this, va_list *args)
{
    char *str = NULL;

    if (!this || !args)
        raise("Null pointer passed");
    str = va_arg(*args, char *);
    this->_size = strlen(str);
    this->_type = (class_t *)Char;
    this->_tab = malloc(sizeof(object_t *) * this->_size);
    if (!this->_tab)
        raise("Out of memory");
    for (size_t i = 0; i < this->_size; i++){
        this->_tab[i] = new(Char, str[i]);
    }
}

static void string_dtor(string_class_t *this)
{
    if (!this)
        raise("Null pointer passed");
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t string_len(string_class_t *this)
{
    return (this->_size);
}

static iterator_t *string_begin(string_class_t *this)
{
    return (new(StringIterator, this, 0));
}

static iterator_t *string_end(string_class_t *this)
{
    return (new(StringIterator, this, this->_size));
}

/* Fill this function for exercice 05 */
static object_t *string_getitem(const string_class_t *this, ...)
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
static void string_setitem(string_class_t *this, ...)
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

static
string_class_t *string_add(
    const string_class_t *this, const string_class_t *other)
{
    string_class_t *new_array = NULL;
    size_t ind = 0;

    if (!this || !other)
        raise("Null inter passed");
    if (this->_type != other->_type)
        raise("Add from different types");
    new_array = new(Array, this->_size + other->_size, this->_type, 0, 0, 0);
    for (; ind < this->_size; ind++)
        new_array->_tab[ind] = this->_tab[ind];
    for (; ind < other->_size + this->_size; ind++)
        new_array->_tab[ind] = other->_tab[ind - this->_size];
    return new_array;
}

static char *string_string(string_class_t *this)
{
    char *ptr = NULL;
    size_t size_res = 0;
    char *arr = NULL;

    if (!this)
        raise("Null pointer passed");
    arr = calloc(this->_size + 1, sizeof(char));
    if (!arr)
        raise("Out of memory");
    for (size_t i = 0; i < this->_size; i++){
        arr[i] = ((char_class_t *)string_getitem(this, i))->v;
    }
    size_res = snprintf(NULL, 0, "<%s (%s)>",
        this->base.base.__name__, arr);
    ptr = malloc(sizeof(char) * size_res + 1);
    sprintf(ptr, "<%s (%s)>", this->base.base.__name__, arr);
    free(arr);
    return ptr;
}

static
bool arr_eq(const string_class_t *this, const string_class_t *other)
{
    if (!this || !other)
        raise("Null pointer passed");
    if (this->_size != other->_size)
        return false;
    for (size_t i = 0; i < this->_size; i++) {
        if (!eq(string_getitem(this, i), string_getitem(other, i)))
            return false;
    }
    return true;
}

static const string_class_t _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(string_class_t),
            .__name__ = "String",
            .__ctor__ = (ctor_t)&string_ctor,
            .__dtor__ = (dtor_t)&string_dtor,
            .__str__ = (to_string_t)&string_string,
            .__add__ = (binary_operator_t)&string_add,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&arr_eq,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&string_len,
        .__begin__ = (iter_t)&string_begin,
        .__end__ = (iter_t)&string_end,
        .__getitem__ = (getitem_t)&string_getitem,
        .__setitem__ = (setitem_t)&string_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const class_t *String = (const class_t *)&_descr;
