bool canConstruct(char* ransomNote, char* magazine) {
    int hash[26] = {0};
    int mlen = strlen(magazine);
    for(int i = 0; i < mlen; i++){
        hash[magazine[i] - 'a']++;
    }
    int rlen = strlen(ransomNote);
    for(int i = 0; i < rlen; i++){
        hash[ransomNote[i] - 'a']--;
        if(hash[ransomNote[i] - 'a'] < 0){
            return false;
        }
    }
    return true;
}