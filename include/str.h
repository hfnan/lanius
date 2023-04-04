#ifndef INCLUDE_STR_H
#define INCLUDE_STR_H

#define _GNU_SOURCE // cause stdio.h to include asprintf
#include <stdlib.h>
#include <string.h>
#include <utils.h>

typedef char *String;

#define str_extend( wt, ...) {                      \
    String tmp = (wt);                              \
    if (asprintf(&(wt), __VA_ARGS__) < 0) abort();  \
    if (tmp) { free(tmp); tmp = NULL; }             \
}

/**
 * print the 'prompt' and read a line into 'str'
 * usage: readline(string buf, const string fmt, va_args);
 */
#define readline(str, prompt, ...) {    \
    printf(prompt, __VA_ARGS__);        \
    String line = trim(getstring());    \
    int length = strlen(line);          \
    str_extend(line, "%s;", line);      \
    str = line;                         \
}


// str.c
Bool iswhite(char c);

String str_init(const String in);
String getstring();
String trim(String str);

#endif
