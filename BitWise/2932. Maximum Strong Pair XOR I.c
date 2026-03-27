int maximumStrongPairXor(int* nums, int numsSize) {
    int res=0;
    for(int i =0; i<numsSize; i++){
        for(int j=i; j<numsSize; j++){
            int min = nums[i]<nums[j]? nums[i]:nums[j];
            if(abs(nums[i]-nums[j])<=min){
                int xor=nums[i]^nums[j];
                if(xor>res) res=xor;
            }
        }
    } return res;
}