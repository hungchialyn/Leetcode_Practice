// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    if(n==1) return 1;

    long int left = 1;
    long int right = n;

    while(left < right){
        long int mid = (right+left)/2;
        printf("%d %d %d \n", left, mid, right);
        if(isBadVersion(mid)){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }

    return left;
}