class Solution {
    public int gcd(int m, int n){
        if(n==0){
            return m;
        }
        else{
            return gcd(n, m%n);
        }
    }
    public int gcdOfOddEvenSums(int n) {
        int odd = (1+2*n-1)*n/2;
        int even = (2+2*n)*n/2;

        return gcd(odd, even);
    }
}