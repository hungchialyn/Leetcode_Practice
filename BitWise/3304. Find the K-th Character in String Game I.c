char kthCharacter(int k) {
    int kk=k-1;
    int bit=0;
    while(kk>0){
        bit++;
        kk>>=1;
    }
    int ch=1<<bit;
    char* ans=malloc((ch+1)*sizeof(char));
    ans[ch]='\0';
    ans[0]='a';
    for(int i=0; i<bit; i++){
        int idx=(1<<i);
        for(int j=0; j<(1<<i); j++){
            if(ans[j]=='z'){
                ans[idx++]='a';
                continue;
            }
            ans[idx++]=ans[j]+1;
        }
    }
    return ans[k-1];
}

