/*
** EPITECH PROJECT, 2018
** brainfuck
** File description:
** Created by antoine_dh,
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 30000

void interpret(char *str);

char *readfile(int fd, bool toclose);
ssize_t stridx(const char *str, char c);

void add_ptr(unsigned char **ptr);
void sub_ptr(unsigned char **ptr);
void add_val(unsigned char **ptr);
void sub_val(unsigned char **ptr);
void put_val(unsigned char **ptr);
void get_val(unsigned char **ptr);

typedef struct bf {
    const char *read;
    unsigned char *ptr;
} bf_t;

void start_loop(bf_t *bf);
void end_loop(bf_t *bf);

static const char *BF_CHAR = "><+-.,[]";
static void (*const BF_FUNC[])(unsigned char **) = {
    &add_ptr,
    &sub_ptr,
    &add_val,
    &sub_val,
    &put_val,
    &get_val,
};
