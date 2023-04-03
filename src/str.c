#include <bool.h>
#include <str.h>
#include <stdio.h>

bool isblank(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

string str_init(const string in) {
    if (!in) return NULL;
    string out;
    asprintf(&out, "%s", in);
    return out;
}

string getstring() {
    string s = str_init("");
    char c;
    while ((c = getchar()) != '\n')
        str_extend(s, "%s%c", s, c);
    str_extend(s, "%s\n", s);
    return s;
}

string trim(string str) {
    int length = strlen(str);   
    if (length == 0) return str;

    int i = 0, j = length - 1; 
    while (i <= j) {
        if (!isblank(str[i]) && !isblank(str[j])) break;
        if (isblank(str[i])) i ++ ;
        if (isblank(str[j])) j -- ;
    }
    str[j + 1] = 0;

    string res;
    asprintf(&res, "%s", str + i);
    free(str);
    return res;
}
