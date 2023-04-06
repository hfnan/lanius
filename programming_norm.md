# Programming Norm

1. All objects are pointers of struct.

   When using the pointer, view it as a could disappear variable, when it engaged an operation, it won't be used any more.

   We must make sure that from start to the end, there is only one pointer to a manual memory.

   the difference between plain struct and pointer struct should be shown on name -- the pointer struct's name need to be `<name>_`, means that the variable is unsafe.

   the functions receiving a pointer struct will absorb the pointer, and we need to give them a name to mark that. Maybe the same norm `<funcname>_` is a good choice.

2. each pointer struct has four basic functions, which are `init`, `copy`, `free` and `new`.

   when using the functions stored in the struct, they need the struct pointer to pass in as argument. And they will absolutely change the pointer struct's state. But cause they are infact the belongs of the struct and we really know that they are safe, so there is no necessary to regard the belongs functions will destory the pointer.
   
   the function `new` is the only function which is not stored in the struct, and also won't absorb the pointer passed in. The function will alloc the memory for the pointer and load the other funtion onto the pointer struct passed in, these are all what the `new` do.

   marco is a new thing different from functions. marco infact is a set of code, and it is hard to know from out of the marco! we should make out best to make the marco safe enough.
   
3. How to organize the C file?

   it sound a little difficult cause we need to use C as OOP, maybe we can use a header as a package, and what about the struct defined in this header will be written in the same name .c files, especially the belong functions.

   Whatever functions about a struct should have a prefix using the struct name.

4. to distinguish the pointer as array and the pointer to struct, we use `Type* var_` to refer a pointer to struct, and `Type *array`, the array won't disappear, so need not add the `_`. 
   
   an array of pointers is like this `Type* *array`.

   array is much different from a pointer, because array is maybe auto, or static, it needn't us to care about memory, it will handle itself well.