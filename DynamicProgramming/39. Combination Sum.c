/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtracing(int* candidates, int candidatesSize,
                 int target, int start, int* path, int pathSize,
                 int** res, int* returnSize, int** returnColumnSizes){
    if(target == 0){
        res[*returnSize] = malloc(pathSize * sizeof(int));
        for(int i = 0; i < pathSize; i++){
            res[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for(int i = start; i < candidatesSize; i++){
        if(candidates[i] > target){
            continue;
        }

        path[pathSize] = candidates[i];

        backtracing(candidates, candidatesSize, 
                    target - candidates[i], i, path, pathSize + 1, 
                    res, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int **res = malloc(1000*sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = malloc(1000*sizeof(int));
    int path[150];
    int pathSize = 0;
    int start = 0;

    backtracing(candidates, candidatesSize, 
                target, start, path, pathSize, 
                res, returnSize, returnColumnSizes);

    return res;
}