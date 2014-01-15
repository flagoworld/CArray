//
//  Array.c
//  xcxc
//
//  Created by Ryan Layne on 7/22/13.
//
//

#include "Array.h"
#include <stdlib.h>
#include <memory.h>

Array *_arr_new()
{
    Array *arr=malloc(sizeof(Array));
    arr->count=0;
    arr->capacity=4;
    arr->items=malloc(sizeof(void *)*4);
    return arr;
}

void _arr_delete(Array *arr,void (*handler)(void *ob))
{
    if(handler)
    {
        for(int i=0;i<arr->count;++i)
        {
            if(handler)
                handler(arr->items[i]);
        }
    }
    free(arr->items);
    free(arr);
}

void _arr_add(Array *arr,void *ob)
{
    if(arr->count==arr->capacity)
    {
        arr->capacity*=2;
        arr->items=realloc(arr->items,arr->capacity*sizeof(void *));
    }
    
    arr->items[arr->count]=ob;
    ++arr->count;
}

void _arr_remove(Array *arr,int pos,int length,void (*handler)(void *ob))
{
    if(handler)
    {
        for(int i=pos;i<pos+length;++i)
        {
            handler(arr->items[i]);
        }
    }
    
    memmove(&arr->items[pos],&arr->items[pos+length],(arr->count-pos-length)*sizeof(void *));
    arr->count-=length;
}

void *_arr_get(Array *arr,int pos)
{
    return arr->items[pos];
}