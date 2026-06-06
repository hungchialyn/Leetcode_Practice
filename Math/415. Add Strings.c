char* addStrings(char* num1, char* num2) {
    
    char* res = malloc((strlen(num1) + strlen(num2) + 1) * sizeof(char));
    int idx = strlen(num1) + strlen(num2);
    res[idx--] = '\0';

    int carry = 0;
    while((carry != 0) || (num1[0] != '\0') || (num2[0] != '\0')){
        int n1 = 0;
        int n2 = 0;
        // printf("%s %s \n", num1, num2);
        if(num1[0] != '\0'){
            n1 = num1[strlen(num1) - 1] - '0';
            num1[strlen(num1) - 1] = '\0';
        }
        if(num2[0] != '\0'){
            n2 = num2[strlen(num2) - 1] - '0';
            num2[strlen(num2) - 1] = '\0';
        }
        int sum = n1 + n2 + carry;
        if(sum >= 10){
            carry = 1;
            sum -= 10;
        }else{
            carry = 0;
        }
        printf("%d %d %d %d\n", n1, n2, sum, carry);
        res[idx--] = sum + '0';
        
    }

    return &res[idx + 1];
    
}