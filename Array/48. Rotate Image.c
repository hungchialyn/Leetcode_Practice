void exChange(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for(int i = 0; i < matrixSize-1; i++){ 
        // exChange(&matrix[i][i], &matrix[i][*matrixColSize-1-i]);
        // exChange(&matrix[i][i], &matrix[matrixSize-1-i][*matrixColSize-1-i]);
        // exChange(&matrix[i][i], &matrix[matrixSize-1-i][i]);
        for(int j = i; j < (*matrixColSize-1-i); j++){ 
            printf("%d %d \n", i, j);
            exChange(&matrix[i][j], &matrix[j][*matrixColSize-1-i]);
            exChange(&matrix[i][j], &matrix[*matrixColSize-1-i][*matrixColSize-1-j]);
            exChange(&matrix[i][j], &matrix[*matrixColSize-1-j][i]);
        }
    }
}