#include <bool.h>
#include <str.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cnter = 0;
static const string prompt = "$[%d]: ";
static string buf;

void run () {

    while (++ cnter) {
        readline(buf, prompt, cnter);

        printf("(%s): %ld\n", buf, strlen(buf));

        puts("");
    }
}
