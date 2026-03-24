int similarPairs(char** words, int wordsSize) {
    int check[wordsSize];
    int res = 0;
    for(int i = 0; i < wordsSize; i++){
        check[i] = 0;
    }
    for(int i = 0; i < wordsSize; i++){
        for(int j = 0; words[i][j] != '\0'; j++){
            check[i] |= 1 << (words[i][j] - 'a');
        }
    }
    for(int i = 0; i < wordsSize -1; i++){
        for(int j = i+1; j < wordsSize; j++){
            if(check[i]==check[j]){
                res++;
            }
        }
    }
    return res;
}