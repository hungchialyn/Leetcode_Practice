


typedef struct {
    bool* key;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet* HM = malloc(sizeof(MyHashSet));
    HM->key = calloc(1000001, sizeof(bool));
    return HM;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->key[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->key[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->key[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/