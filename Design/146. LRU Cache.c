struct node{
    int val;
    int key;
    struct node* prev;
    struct node* next;
};

typedef struct {
    int cap;
    int size;
    struct node* rem[10001];
    struct node* head;
    struct node* tail;
} LRUCache;

void del(struct node* curr){
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
}
void add(struct node* curr, LRUCache* obj){
    curr->prev = obj->head;
    curr->next = obj->head->next;
    obj->head->next->prev = curr;
    obj->head->next = curr;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = malloc(sizeof(LRUCache));
    obj->cap = capacity;
    obj->size = 0;
    for(int i = 0; i < 10001; i++){
        obj->rem[i]=NULL;
    }
    obj->head = malloc(sizeof(struct node));
    obj->tail = malloc(sizeof(struct node));
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(!obj->rem[key]){  //key為空
        return -1;
    }
    del(obj->rem[key]);
    add(obj->rem[key], obj);
    return obj->rem[key]->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(obj->rem[key]!=NULL){ //已經存在於cache中
        obj->rem[key]->val = value;
        del(obj->rem[key]);
        add(obj->rem[key], obj);
        return;
    }
    if(obj->size>=obj->cap){  //當cache滿了,先刪掉最少使用的key
        obj->size--;
        struct node* toDel = obj->tail->prev;
        obj->rem[toDel->key] = NULL;
        del(toDel);
    }
    obj->size++;
    struct node* curr = malloc(sizeof(struct node));
    curr->val = value;
    curr->key = key;
    obj->rem[key] = curr;
    add(curr, obj);
}

void lRUCacheFree(LRUCache* obj) {
    for(int i = 0;i<10001;i++){
        if(obj->rem[i]!=NULL){
            free(obj->rem[i]);
        }
    }
    free(obj->head);
    free(obj->tail);
    free(obj);
}