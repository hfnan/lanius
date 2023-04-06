#ifndef INCLUDE_VECTOR_H
#define INCLUDE_VECTOR_H

// vector
typedef struct Vector {
    void**array;
    int len, maxlen;
} Vector;


#define vector_init(vector) { \
    (vector).array = malloc(sizeof(void*) * BASE_LENGTH); \
    (vector).len = 0; \
    (vector).maxlen = BASE_LENGTH; \
}


#define vector_free(vector) { \
    free((vector).array); \
}

// vector push_back
// Use ## to make things easy
#define push_back(Type, vec, val) { \
    Type ## Vec *typevec = (Type ## Vec *)(vec);    \
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
#define pop_back(Type, vec, val) {  \
    Type ## Vec *typevec = (Type ## Vec *)(vec);    \
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