#ifndef INCLUDE_STR_H
#define INCLUDE_STR_H

#include <utils.h>

typedef char *Str;

#define str_extend( wt, ...) {                      \
    Str tmp = (wt);                              \
    if (asprintf(&(wt), __VA_ARGS__) < 0) abort();  \
    if (tmp) { free(tmp); tmp = NULL; }             \
}

/**
 * print the 'prompt' and read a line into 'str'
 * usage: readline(string buf, const string fmt, va_args);
 */
#define readline(str) {    \
    Str line = str_trim(str_getline());    \
    str_extend(line, "%s,", line);      \
    str = line;                         \
}


// str.c
Bool iswhite(char ch);
Bool isletter(char ch);
Bool islod(char ch);

Str str_from(const Str in);
Str str_fromc(const char ch);
Str str_getline();
Str str_trim(Str str);

#endif
