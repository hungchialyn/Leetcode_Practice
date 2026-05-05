int longestCommonSubsequence(char* text1, char* text2) {
    int res = 0;
    int len1 = strlen(text1);
    int len2 = strlen(text2);

    int dp[len1+1][len2+1];

    // 初始化第一行和第一列為 0
    for(int i = 0; i < len1+1; i++) dp[i][0] = 0;
    for(int j = 0; j < len2+1; j++) dp[0][j] = 0;

    //dp[i][j] = text1 前 i 個字元 與 text2 前 j 個字元的 LCS 長度
    for(int i = 1; i < len1+1; i++){
        for(int j = 1; j < len2+1; j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    return dp[len1][len2];
    //字元相同就「繼承左上角再 +1」，字元不同就「看上方和左方哪個比較大」。每格都建立在已解決的子問題上，最終累積出全域最佳解
}