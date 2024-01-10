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
    this->_list = va_arg(*args, list_class_t *);
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
    node_t *res = NULL;

    if (this->_idx >= this->_list->_size)
        raise("Out of range");
    res = this->_list->_list;
    for (size_t i = 0; i < this->_idx; i++)
        res = res->next;
    return res->_val;
}

/* Fill this function for exercice 05 */
static void list_iter_setval(list_iter_class_t *this, ...)
{
    node_t *to_set = NULL;
    va_list ap;

    if (!this || !this->_list || !this->_list->_list)
        raise("Null pointer passed");
    if (this->_idx >= this->_list->_size)
        raise("Index out of range");
    to_set = this->_list->_list;
    for (size_t i = 0; i < this->_idx; i++)
        to_set = to_set->next;
    delete(to_set->_val);
    va_start(ap, this);
    to_set->_val = va_new(this->_list->_type, &ap);
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
    ._list = NULL,
    ._idx = 0
};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

/* Fill this function for exercice 05 */
static void list_ctor(list_class_t *this, va_list *args)
{
    va_list value;
    node_t *temp = NULL;

    if (!this || !args)
        raise("Null pointer passed");
    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, class_t *);
    for (size_t i = 0; i < this->_size; i++){
        this->_list = calloc(1, sizeof(node_t));
        if (!this->_list)
            raise("Out of memory");
        va_copy(value, *args);
        this->_list->_val = va_new(this->_type, &value);
        va_end(value);
        this->_list->next = temp;
        temp = this->_list;
    }
}

static void list_dtor(list_class_t *this)
{
    node_t *temp = NULL;

    if (!this)
        raise("Null pointer passed");
    temp = this->_list;
    for (unsigned int i = 0; i < this->_size; i++) {
        this->_list = this->_list->next;
        delete(temp->_val);
        free(temp);
        temp = this->_list;
    }
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
static object_t *list_getitem(const list_class_t *this, ...)
{
    size_t ind = 0;
    va_list ap;
    node_t *res = NULL;

    if (!this || !this->_list)
        raise("Null pointer passed");
    va_start(ap, this);
    ind = va_arg(ap, size_t);
    va_end(ap);
    if (ind >= this->_size)
        raise("Out of range");
    res = this->_list;
    for (size_t i = 0; i < ind; i++)
        res = res->next;
    return res->_val;
}

/* Fill this function for exercice 05 */
static void list_setitem(list_class_t *this, ...)
{
    node_t *to_set = NULL;
    va_list ap;
    size_t ind = 0;

    if (!this || !this->_list || !this->_list)
        raise("Null pointer passed");
    va_start(ap, this);
    ind = va_arg(ap, size_t);
    if (ind > this->_size)
        raise("Index out of range");
    to_set = this->_list;
    for (size_t i = 0; i < ind; i++)
        to_set = to_set->next;
    delete(to_set->_val);
    to_set->_val = va_new(this->_type, &ap);
    va_end(ap);
}

static
list_class_t *list_add(const list_class_t *this, const list_class_t *other)
{
    list_class_t *new_list = NULL;
    node_t *last_node = NULL;
    size_t ind = 0;

    if (!this || !other)
        raise("Null inter passed");
    if (this->_type != other->_type)
        raise("Add from different types");
    new_list = new(List, this->_size + other->_size, this->_type, 0, 0, 0);
    last_node = this->_list;
    for (; ind < this->_size; ind++){
        last_node->_val = list_getitem(this, ind);
        last_node = last_node->next;
    }
    last_node = other->_list;
    for (; ind < other->_size + this->_size; ind++){
        last_node->_val = list_getitem(this, ind - this->_size);
        last_node = last_node->next;
    }
    return new_list;
}

static char *cat_list(list_class_t *this, char **dest)
{
    char *cat = NULL;
    size_t size = 0;

    for (size_t i = 0; i < this->_size; i++){
        dest[i] = str(list_getitem(this, i));
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

static char *list_string(list_class_t *this)
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
    cat_arr = cat_list(this, arr);
    free(arr);
    size_res = snprintf(NULL, 0, "<%s (%s)>",
        this->base.base.__name__, cat_arr);
    ptr = malloc(sizeof(char) * size_res + 1);
    sprintf(ptr, "<%s (%s)>", this->base.base.__name__, cat_arr);
    free(cat_arr);
    return ptr;
}

static const list_class_t _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(list_class_t),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&list_ctor,
            .__dtor__ = (dtor_t)&list_dtor,
            .__str__ = (to_string_t)&list_string,
            .__add__ = (binary_operator_t)&list_add,
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
    ._list = NULL
};

const class_t *List = (const class_t *)&_descr;
