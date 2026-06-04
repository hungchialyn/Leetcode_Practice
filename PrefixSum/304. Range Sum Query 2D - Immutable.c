


typedef struct {
    int **prefix;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix* obj = malloc(sizeof(NumMatrix));
    obj->prefix = malloc((matrixSize+1) * sizeof(int*));
    for(int i = 0; i < (matrixSize+1); i++){
        obj->prefix[i] = malloc((*matrixColSize + 1) * sizeof(int));
    }
    for(int i = 0; i < matrixSize + 1; i++){
        obj->prefix[i][0] = 0;
    }
    for(int i = 0; i < *matrixColSize + 1; i++){
        obj->prefix[0][i] = 0;
    }
    for(int i = 1; i < matrixSize + 1; i++){
        for(int j = 1; j < *matrixColSize + 1; j++){
            obj->prefix[i][j] = matrix[i-1][j-1] + obj->prefix[i][j-1];
        }
    }

    for(int i = 1; i < matrixSize + 1; i++){
        for(int j = 1; j < *matrixColSize + 1; j++){
            obj->prefix[i][j] += obj->prefix[i-1][j];
            // printf("%d ",obj->prefix[i][j]);
        }
        // printf("\n");
    }
    
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int res = 0;
    res = obj->prefix[row2+1][col2+1] - obj->prefix[row1][col2+1]  - obj->prefix[row2+1][col1] + obj->prefix[row1][col1];
    return res;
}

void numMatrixFree(NumMatrix* obj) {
    free(obj->prefix);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/