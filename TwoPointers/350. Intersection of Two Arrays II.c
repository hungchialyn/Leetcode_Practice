/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *n1 = malloc(1001 * sizeof(int));
    int *n2 = malloc(1001 * sizeof(int));
    for(int i = 0; i < 1001; i++){
        n1[i] = 0;
        n2[i] = 0;
    } 

    for(int i = 0; i < nums1Size; i++){
        n1[nums1[i]]++;
    }
    for(int i = 0; i < nums2Size; i++){
        n2[nums2[i]]++;
    }

    int *res = malloc(1001 * sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < 1001; i++){
        int cnt = n1[i] < n2[i] ? n1[i] : n2[i];
        for(int j = 0; j < cnt; j++){
            res[(*returnSize)++] = i;
        }
    }

    return res;
}