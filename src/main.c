#include <stdio.h>
#include <str.h>

static const Str VERSION = "v0.0.1";

void run();

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Lanius: %s\n", VERSION);
        run();
    }
    else {}
    return 0;
}