#include <stdlib.h>

#define TABLE_SIZE 10007

typedef struct Node {
    int key;            // nums[i]
    int value;          // index
    struct Node* next;
} Node;

int hash(int key) {
    if (key < 0)
        key = -key;

    return key % TABLE_SIZE;
}

Node* find(Node** table, int key) {
    int idx = hash(key);

    Node* cur = table[idx];

    while (cur) {
        if (cur->key == key)
            return cur;

        cur = cur->next;
    }

    return NULL;
}

void insert(Node** table, int key, int value) {
    int idx = hash(key);

    Node* node = malloc(sizeof(Node));

    node->key = key;
    node->value = value;

    node->next = table[idx];
    table[idx] = node;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    Node* table[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }

    *returnSize = 2;

    int* ans = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {

        int need = target - nums[i];

        Node* found = find(table, need);

        if (found) {
            ans[0] = found->value;
            ans[1] = i;

            return ans;
        }

        insert(table, nums[i], i);
    }

    return NULL;
}