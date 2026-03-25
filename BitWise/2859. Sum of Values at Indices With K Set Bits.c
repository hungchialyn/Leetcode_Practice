int count(int i){
    int rtn = 0;
    while(i>0){
        rtn += i&1;
        i>>=1;
    }
    return rtn;
}
int sumIndicesWithKSetBits(int* nums, int numsSize, int k) {
    int res = 0;
    for(int i = 0; i < numsSize; i++){
        if(count(i)==k){
            res += nums[i];
        }
    }
    return res;
}