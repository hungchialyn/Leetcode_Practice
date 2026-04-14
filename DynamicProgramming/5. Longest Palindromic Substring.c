char* longestPalindrome(char* s) {
    int len = strlen(s);
    if(len<2){
        return s;
    }
    int l=0;
    int r=0;
    int maxlen=1;
    int start=0;
    for(int i = 0; i < len; i++){
        //odd
        l=i;
        r=i;
        while(l>=0 && r<len && s[l]==s[r]){
            if(r-l+1>maxlen){
                maxlen=r-l+1;
                start=l;
            }
            l--;
            r++;
        }
        //even
        l=i;
        r=i+1;
        while(l>=0 && r<len && s[l]==s[r]){
            if(r-l+1>maxlen){
                maxlen=r-l+1;
                start=l;
            }
            l--;
            r++;
        }
    }
    s[start+maxlen]='\0';
    return s+start;
}