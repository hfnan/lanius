#include <utils.h>
#include <str.h>
#include <stdio.h>

Bool iswhite(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

Str str_from(const Str in) {
    if (!in) return NULL;
    Str out;
    asprintf(&out, "%s", in);
    return out;
}

Str str_fromc(const char ch) {
    Str out;
    asprintf(&out, "%c", ch);
    return out;
}

Str str_getline() {
    Str s = str_from("");
    char c;
    while ((c = getchar()) != '\n')
        str_extend(s, "%s%c", s, c);
    str_extend(s, "%s\n", s);
    return s;
}

Str str_trim(Str str) {
    int length = strlen(str);   
    if (length == 0) return str;

    int i = 0, j = length - 1; 
    while (i <= j) {
        if (!iswhite(str[i]) && !iswhite(str[j])) break;
        if (iswhite(str[i])) i ++ ;
        if (iswhite(str[j])) j -- ;
    }
    str[j + 1] = 0;

    Str res;
    asprintf(&res, "%s", str + i);
    free(str);
    return res;
}
