#ifndef INCLUDE_VECTOR_H
#define INCLUDE_VECTOR_H

// vector
typedef struct Vector {
    int len, maxlen;
} Vector;

// vector push_back
// todo: too many args! can be optimize
#define push_back(Typevec, Type, vec, val) { \
    Typevec *typevec = (Typevec *)(vec);    \
    Type *new_array_ptr = typevec->array;   \
    if (typevec->len >= typevec->maxlen) {   \
        new_array_ptr = realloc(typevec->array, sizeof(Type) * (typevec->maxlen << 1));   \
        if (!new_array_ptr) \
            abort();        \
        typevec->array = new_array_ptr; \
        typevec->maxlen <<= 1;   \
    }   \
    typevec->array[typevec->len ++ ] = *(val);\
}

// untested!
#define pop_back(Typevec, Type, vec, val) {  \
    Typevec *typevec = (Typevec *)(vec);    \
    *(val) = typevec->array[ -- typevec->len];  \
    Type *new_array_ptr = typevec->array;   \
    if (typevec->len <= (typevec->maxlen >> 1)) { \
        new_array_ptr = realloc(typevec->array, sizeof(Type) * (typevec->maxlen >> 1)); \
        if (!new_array_ptr) \
            abort();        \
        typevec->maxlen >>= 1;  \
    }   \
}

#endif