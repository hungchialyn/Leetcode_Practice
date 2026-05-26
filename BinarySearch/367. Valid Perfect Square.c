bool isPerfectSquare(int num) {
    if(num == 1) return true;
    for(int i = 1; i <= (num/2); i++){
        if(i > 46340) return false;
        if((i == num/i) && (num % i == 0)) return true; // 不可以用 i*i == num 會爆掉 
    }
    return false;
}
