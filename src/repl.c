#include <bool.h>
#include <stdio.h>

static int cnter = 1;
static char buf[]; 
void run () {    
    while (cnter) {
        printf("$[%d] ", cnter ++ );
        scanf("%s", buf);
        puts("");
    }
}