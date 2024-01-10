/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "rush.h"

// You need to initialize internal resources at the start of the function
static void player_ctor(PlayerClass *this, va_list *args)
{
    this->identifier = strdup("Kreog");
    this->power = rand() % 42;
    printf("Player()\n");
}

// You need to release internal resources at the start of the function
static void player_dtor(PlayerClass *this)
{
    free(this->identifier);
    printf("~Player()\n");
}

static const PlayerClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PlayerClass),
        .__name__ = "Player",
        .__ctor__ = (ctor_t)&player_ctor,
        .__dtor__ = (dtor_t)&player_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .identifier = NULL,
    .power = -1
};

const Class *Player = (const Class *)&_description;
