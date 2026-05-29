/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** res = malloc(10000*sizeof(char*));
    *returnSize = 0;

    for(int i = 1; i <= n; i++){
        if((i % 3 == 0) && (i % 5 == 0)){
            res[*returnSize] = malloc(9 * sizeof(char));
            res[*returnSize] = "FizzBuzz\0";
        }else if(i % 3 == 0){
            res[*returnSize] = malloc(5 * sizeof(char));
            res[*returnSize] = "Fizz\0";
        }else if(i % 5 == 0){
            res[*returnSize] = malloc(5 * sizeof(char));
            res[*returnSize] = "Buzz\0";
        }
        else{
            res[*returnSize] = malloc(6 * sizeof(char));
            sprintf(res[*returnSize], "%d", i);
        }
        (*returnSize)++;
    }

    return res;
}