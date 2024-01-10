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
#include "array.h"
#include "new.h"
#include "rush.h"

static void array_iter_ctor(
    array_iter_class_t *this,
    va_list *args)
{
    this->_array = va_arg(*args, array_class_t *);
    this->_idx = va_arg(*args, int);
}

static bool array_iter_eq(
    array_iter_class_t *this,
    array_iter_class_t *other)
{
    return (this->_idx == other->_idx);
}

static bool array_iter_gt(
    array_iter_class_t *this,
    array_iter_class_t *other)
{
    return (this->_idx > other->_idx);
}

static bool array_iter_lt(
    array_iter_class_t *this,
    array_iter_class_t *other)
{
    return (this->_idx < other->_idx);
}

static void array_iter_incr(array_iter_class_t *this)
{
    this->_idx += 1;
}

static object_t *array_iter_getval(array_iter_class_t *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

/* Fill this function for exercice 05 */
static void array_iter_setval(array_iter_class_t *this, ...)
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

static const array_iter_class_t ArrayIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(array_iter_class_t),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&array_iter_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&array_iter_eq,
            .__gt__ = (binary_comparator_t)&array_iter_gt,
            .__lt__ = (binary_comparator_t)&array_iter_lt,
        },
        .__incr__ = (incr_t)&array_iter_incr,
        .__getval__ = (getval_t)&array_iter_getval,
        .__setval__ = (setval_t)&array_iter_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class *ArrayIterator = (const Class *)&ArrayIteratorDescr;

/* Fill this function for exercice 05 */
static void array_ctor(array_class_t *this, va_list *args)
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

static void array_dtor(array_class_t *this)
{
    if (!this)
        raise("Null pointer passed");
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t array_len(array_class_t *this)
{
    return (this->_size);
}

static iterator_t *array_begin(array_class_t *this)
{
    return (new(ArrayIterator, this, 0));
}

static iterator_t *array_end(array_class_t *this)
{
    return (new(ArrayIterator, this, this->_size));
}

/* Fill this function for exercice 05 */
static object_t *array_getitem(array_class_t *this, ...)
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
static void array_setitem(array_class_t *this, ...)
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
array_class_t *array_add(const array_class_t *this, const array_class_t *other)
{
    array_class_t *new_array = NULL;
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

static char *cat_array(array_class_t *this, char **dest)
{
    char *cat = NULL;
    size_t size = 0;

    for (size_t i = 0; i < this->_size; i++){
        dest[i] = str(array_getitem(this, i));
        size += strlen(dest[i]) + 2;
    }
    cat = calloc(size + 1, sizeof(char));
    if (!cat)
        raise("Out of memory");
    for (size_t i = 0; i < this->_size - 1; i++){
        strcat(strcat(cat, dest[i]), ", ");
        free(dest[i]);
    }
    strcat(cat, dest[this->_size - 1]);
    free(dest[this->_size - 1]);
    return cat;
}

static char *array_string(array_class_t *this)
{
    char *ptr = NULL;
    size_t size_res = 0;
    char *cat_arr = NULL;
    char **arr = NULL;

    if (!this)
        raise("Null pointer passed");
    arr = malloc(sizeof(char *) * this->_size);
    if (!arr)
        raise("Out of memory");
    cat_arr = cat_array(this, arr);
    free(arr);
    size_res = snprintf(NULL, 0, "<%s (%s)>",
        this->base.base.__name__, cat_arr);
    ptr = malloc(sizeof(char) * size_res + 1);
    sprintf(ptr, "<%s (%s)>", this->base.base.__name__, cat_arr);
    free(cat_arr);
    return ptr;
}

static const array_class_t _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(array_class_t),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&array_ctor,
            .__dtor__ = (dtor_t)&array_dtor,
            .__str__ = (to_string_t)&array_string,
            .__add__ = (binary_operator_t)&array_add,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&array_len,
        .__begin__ = (iter_t)&array_begin,
        .__end__ = (iter_t)&array_end,
        .__getitem__ = (getitem_t)&array_getitem,
        .__setitem__ = (setitem_t)&array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const class_t *Array = (const class_t *)&_descr;
