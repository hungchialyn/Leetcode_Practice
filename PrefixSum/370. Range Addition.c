int* getModifiedArray(int length, int** updates, int updatesSize, int* updatesColSize, int* returnSize) {
    int* diff = calloc(length, sizeof(int));

    for (int i = 0; i < updatesSize; i++) {
        int start = updates[i][0];
        int end   = updates[i][1];
        int inc   = updates[i][2];

        diff[start] += inc;

        if (end + 1 < length) {
            diff[end + 1] -= inc;
        }
    }

    for (int i = 1; i < length; i++) {
        diff[i] += diff[i - 1];
    }

    *returnSize = length;
    return diff;
}