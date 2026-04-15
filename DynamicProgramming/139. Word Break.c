bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    bool* dp = malloc((len+1)*sizeof(bool));
    for(int i = 0; i < (len+1); i++){
        dp[i] = false;
    }
    dp[0] = true;

    for(int i = 1; i <= len; i++){
        for(int j = 0; j < wordDictSize; j++){
            int wlen = strlen(wordDict[j]);
            if((i>=wlen) && dp[i - wlen]){
                if(strncmp(s + i - wlen, wordDict[j], wlen)==0){
                    dp[i] = true;
                }
            }
        }
    }
    return dp[len];
}