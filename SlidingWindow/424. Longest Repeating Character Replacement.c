int characterReplacement(char* s, int k) {
    int slen = strlen(s);
    int maxFreq = 0;
    int left = 0;
    int res = 0;
    int c[26] = {0};

    for(int right = 0; right < slen; right++){
        int idx = s[right] - 'A';
        c[idx]++;

        if(c[idx] > maxFreq){
            maxFreq = c[idx];
        }

        while((right-left+1) - maxFreq > k){
            c[s[left] - 'A']--;
            left++;
        }
        
        int window = right - left + 1;
        if(window > res){
            res = window;
        }
    }
    return res;
}