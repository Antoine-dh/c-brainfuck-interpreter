#include <stdio.h>
#include <fcntl.h>
#include "brainfuck.h"

int main(int ac, char **av)
{
    if (ac == 2)
        interpret(readfile(open(av[1], O_RDONLY), true));
    else
        fprintf(stderr, "Please enter 1 file as argument.\n");
    return (0);
}
