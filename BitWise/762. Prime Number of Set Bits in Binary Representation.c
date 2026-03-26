int count(int n){
    int bit = 0;
    while(n > 0){
        if(n&1){
            bit++;
        }
        n>>=1;
    }
    return bit;
}
int countPrimeSetBits(int left, int right) {
    int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int res = 0;
    for(int i = left; i <= right; i++){
        int bit = count(i);
        for(int j = 0; j < 11; j++){
            if(bit == prime[j]){
                res++;
                break;
            }
        }
    }
    return res;
}