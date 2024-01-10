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
} PointClass;

typedef struct {
    Class base;
    int x, y, z;
} VertexClass;

#endif /* !RUSH2_H_ */
