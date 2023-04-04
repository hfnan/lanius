#include <utils.h>
#include <str.h>
#include <stdio.h>

Bool iswhite(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

String str_init(const String in) {
    if (!in) return NULL;
    String out;
    asprintf(&out, "%s", in);
    return out;
}

String getstring() {
    String s = str_init("");
    char c;
    while ((c = getchar()) != '\n')
        str_extend(s, "%s%c", s, c);
    str_extend(s, "%s\n", s);
    return s;
}

String trim(String str) {
    int length = strlen(str);   
    if (length == 0) return str;

    int i = 0, j = length - 1; 
    while (i <= j) {
        if (!iswhite(str[i]) && !iswhite(str[j])) break;
        if (iswhite(str[i])) i ++ ;
        if (iswhite(str[j])) j -- ;
    }
    str[j + 1] = 0;

    String res;
    asprintf(&res, "%s", str + i);
    free(str);
    return res;
}
