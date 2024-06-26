/*
** EPITECH PROJECT, 2024
** rush2
** File description:
** rush
*/

#ifndef RUSH2_H_
    #define RUSH2_H_

    #include "container.h"
    #include "iterator.h"
    #include "point.h"

typedef Object object_t;
typedef Iterator iterator_t;
typedef Class class_t;
typedef Container container_t;

typedef struct {
    Class base;
    char *identifier;
    int power;
} PlayerClass;

typedef struct {
    class_t base;
    int x, y;
} point_class_t;

typedef struct {
    class_t base;
    int x, y, z;
} vertex_class_t;

typedef struct {
    class_t base;
    int v;
} int_class_t;

typedef struct {
    class_t base;
    float v;
} float_class_t;

typedef struct {
    class_t base;
    char v;
} char_class_t;

typedef struct {
    container_t base;
    class_t *_type;
    size_t _size;
    object_t **_tab;
} array_class_t;

typedef struct {
    iterator_t base;
    array_class_t *_array;
    size_t _idx;
} array_iter_class_t;

typedef struct {
    container_t base;
    class_t *_type;
    size_t _size;
    object_t **_tab;
} string_class_t;

typedef struct {
    iterator_t base;
    string_class_t *_array;
    size_t _idx;
} string_iter_class_t;

typedef struct node_s {
    object_t *_val;
    struct node_s *next;
} node_t;

typedef struct {
    container_t base;
    class_t *_type;
    size_t _size;
    node_t *_list;
} list_class_t;

typedef struct {
    iterator_t base;
    list_class_t *_list;
    size_t _idx;
} list_iter_class_t;

#endif /* !RUSH2_H_ */
