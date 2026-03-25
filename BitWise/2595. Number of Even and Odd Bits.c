/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
    int *res = calloc(2,sizeof(int));
    while(n>0){
        res[0] += n&1;
        n >>= 1;
        res[1] += n&1;
        n >>= 1;
    }
    *returnSize = 2;
    return res;
}