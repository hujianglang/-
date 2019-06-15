#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
*实现一个大小固定的有序数组，支持动态增删改查操作
*/

struct array
{
    int size;
    int used;
    int *arr;
};

void traverse(struct array* array)
{
    for(int idx = 0; idx < array->used; idx++)
    {
        printf("a=%d\n",array->arr[idx]);
    }
}

void alloc(struct array* array)
{
    array->arr = (int*)malloc(array->size*sizeof(int));
}

int insertElem(struct array* array, int elem)
{
    int idx;
    if(array->used >= array->size)
        return -1;
    for(idx = 0; idx < array->used; idx++)
    {
        if(array->arr[idx] > elem)
            break;
    }

    if(idx < array->used)
        memmove(&array->arr[idx+1],&array->arr[idx],(array->used-idx)*sizeof(int));
    array->arr[idx] = elem;
    array->used++;
    return idx;
}

int deleteElem(struct array *array, int idx)
{
    if(idx < 0 || idx >= array->used)
        return -1;
    memmove(&array->arr[idx],&array->arr[idx+1],(array->used-idx-1)*sizeof(int));
    array->used--;
    return 0;
}

int searchElem(struct array* array, int elem)
{
    for(int idx = 0; idx < array->used; idx++)
    {
        if(array->arr[idx] == elem)
            return idx;
        if(array->arr[idx] > elem)
            return -1;
    }
    return -1;
}


int main()
{
    int idx;
    struct array  test = {20,0,NULL};
    alloc(&test);
    if(!test.arr)
        return -1;
    insertElem(&test,1);
    insertElem(&test,2);
    insertElem(&test,3);
    insertElem(&test,4);
    insertElem(&test,5);

    traverse(&test);
    idx = searchElem(&test,2);
    printf("2 is at position%d\n",idx);

    deleteElem(&test,10);
    traverse(&test);
    deleteElem(&test,1);
    traverse(&test);
    printf("Hello World!\n");
    return 0;
}




































