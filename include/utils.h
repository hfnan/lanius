#ifndef INCLUDE_UTILS_H
#define INCLUDE_UTILS_H

#define BASE_LENGTH 3

// boolean
typedef int Bool;
#define true    1
#define false   0


// vector
typedef struct Vector {
    int len, maxlen;
} Vector;

#define push_back(Typevec, Type, vec, val) { \
    Typevec *typevec = (Typevec *)(vec);    \
    Type *new_array_ptr = typevec->array;   \
    if (typevec->len >= typevec->maxlen) {   \
        new_array_ptr = realloc(typevec->array, sizeof(Type) * typevec->maxlen * 2);   \
        if (!new_array_ptr) \
            abort();        \
        typevec->array = new_array_ptr; \
        typevec->maxlen = 2 * typevec->maxlen;   \
    }   \
    typevec->array[typevec->len ++ ] = *(val); \
}


#endif