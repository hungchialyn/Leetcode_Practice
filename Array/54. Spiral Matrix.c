/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int size = matrixSize**matrixColSize;
    int *res = malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        res[i] = 0;
    }
    *returnSize = size;

    //設定邊界
    int top = 0;
    int buttom = matrixSize-1;
    int left = 0;
    int right = *matrixColSize-1;

    //res index
    int idx = 0;

    while((top<=buttom) && (left<=right)){

        //從左到右
        for(int i = left; i <= right; i++){
            res[idx++] = matrix[top][i];
        }
        top++;

        //從上到下
        for(int i = top; i <= buttom; i++){
            res[idx++] = matrix[i][right];
        }
        right--;

        //從右到左
        if(top <= buttom){
            for(int i = right; i >= left; i--){
                res[idx++] = matrix[buttom][i];
            }
            buttom--;
        }

        //從下到上
        if(left<=right){
            for(int i = buttom; i >= top; i--){
                res[idx++] = matrix[i][left];
            }
            left++;
        }
    }

    return res;
}