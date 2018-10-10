/*
** EPITECH PROJECT, 2018
** brainfuck
** File description:
** Created by antoine_dh,
*/

#include <stdio.h>
#include "brainfuck.h"

void add_ptr(unsigned char **ptr)
{
    (*ptr)++;
}

void sub_ptr(unsigned char **ptr)
{
    (*ptr)--;
}

void add_val(unsigned char **ptr)
{
    (**ptr)++;
}

void sub_val(unsigned char **ptr)
{
    (**ptr)--;
}

void put_val(unsigned char **ptr)
{
    putchar(**ptr);
}

void get_val(unsigned char **ptr)
{
    int chr = getchar();

    if (chr == EOF)
        (**ptr) = 0;
    else
        (**ptr) = (unsigned char)chr;
}
