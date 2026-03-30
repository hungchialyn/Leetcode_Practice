
int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int allow = 0;
    int len = strlen(allowed);
    int res = 0;
    for(int i = 0; i < len; i++){
        allow |= 1 << (allowed[i] - 'a');
    }
    for(int i = 0; i < wordsSize; i++){
        int cmp = 0;
        len = strlen(words[i]);
        for(int j = 0; j < len; j++){
            cmp |= 1 << (words[i][j] - 'a');
        }
        if((allow | cmp) == allow){
            res++;
        }
    }
    return res;
}