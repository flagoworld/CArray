//
//  Array.h
//  xcxc
//
//  Created by Ryan Layne on 7/22/13.
//
//

#ifndef xcxc_Array_h
#define xcxc_Array_h

#include <stddef.h>

typedef struct Array
{
    void **items;
    size_t count;
    size_t capacity;
}Array;

#define arr_delete(arr,handler) (_arr_delete(arr,(void (*)(void *))handler))
#define arr_new() (_arr_new())
#define arr_remove(arr,pos,len,handler) (_arr_remove(arr,pos,len,(void (*)(void *))handler))
#define arr_add(arr,ob) (_arr_add(arr,ob))
#define arr_get(arr,pos,type) ((type *)_arr_get(arr,pos))

Array *_arr_new();
void _arr_delete(Array *arr,void (*handler)(void *ob));
void _arr_add(Array *arr,void *ob);
void _arr_remove(Array *arr,int pos,int length,void (*handler)(void *ob));
void *_arr_get(Array *arr,int pos);

#endif
