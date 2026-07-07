#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int arr[200000];
    int size;
} RandomizedSet;

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->size = 0;
    return obj;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    for(int i = 0; i < obj->size; i++)
    {
        if(obj->arr[i] == val)
            return false;
    }

    obj->arr[obj->size] = val;
    obj->size++;

    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    for(int i = 0; i < obj->size; i++)
    {
        if(obj->arr[i] == val)
        {
            obj->arr[i] = obj->arr[obj->size - 1];
            obj->size--;
            return true;
        }
    }

    return false;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int index = rand() % obj->size;
    return obj->arr[index];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj);
}