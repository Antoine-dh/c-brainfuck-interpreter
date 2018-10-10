#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>
#include "brainfuck.h"

char *readfile(int fd, bool toclose)
{
    char buf[BUFSIZ] = "";
    char *str = NULL;

    if (fd == -1)
        return (NULL);
    for (size_t i = 1 ; read(fd, buf, BUFSIZ) > 0 ; ++i) {
        str = realloc(str, (BUFSIZ * i) + 1);
        memset(&str[BUFSIZ * i - BUFSIZ], 0, BUFSIZ + 1);
        strncpy(&str[BUFSIZ * i - BUFSIZ], buf, BUFSIZ);
    }
    if (toclose)
        close(fd);
    return (str);
}

static void _interpret(bf_t *bf)
{
    ssize_t index = *bf->read ? stridx(BF_CHAR, *(bf->read)) : -1;

    if (*bf->read == '\0')
        return;
    if (index == -1) {
        bf->read++;
        _interpret(bf);
        return;
    }
    if (*(bf->read) == ']')
        return;
    if (*(bf->read) == '[')
        start_loop(bf);
    else
        BF_FUNC[index](&(bf->ptr));
    bf->read++;
    _interpret(bf);
}

void start_loop(bf_t *bf)
{
    const char *begin = ++bf->read;

    while (*bf->ptr) {
        _interpret(bf);
        if (*(bf->ptr))
            bf->read = begin;
    }
    while (*bf->read++ != ']');
}

ssize_t stridx(const char *str, char c) {
    for (ssize_t i = 0 ; str[i] != '\0' ; ++i)
        if (str[i] == c)
            return (i);
    return (-1);
}

void interpret(char *str)
{
    unsigned char stack[STACK_SIZE] = {0};
    bf_t bf = {str, stack};

    if (str == NULL) {
        fprintf(stderr, "Error parsing file.\n");
        return;
    }
    _interpret(&bf);
    free(str);
}
