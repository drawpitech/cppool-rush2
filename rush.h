/*
** EPITECH PROJECT, 2024
** rush2
** File description:
** rush
*/

#ifndef RUSH2_H_
    #define RUSH2_H_

    #define _GNU_SOURCE

    #include "point.h"

typedef struct {
    Class base;
    int x, y;
} point_class_t;


typedef struct {
    Class base;
    int x, y, z;
} vertex_class_t;

typedef struct {
    Class base;
    int v;
} int_class_t;

typedef struct {
    Class base;
    float v;
} float_class_t;

typedef struct {
    Class base;
    char v;
} char_class_t;

#endif /* !RUSH2_H_ */
