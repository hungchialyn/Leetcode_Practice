void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
char* reverseVowels(char* s) {
    int left = 0;
    int right = strlen(s)-1;

    while(left < right){
        int found = 0;

        for(int i = left; i < right; i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
            || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                left = i;
                found = 1;
                break;
            }
        }
        for(int i = right; i >= left; i--){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
            || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                right = i;
                break;
            }
        }

        // printf("%d %d\n", left, right);
        if(found){
            swap(&s[left], &s[right]);
        }
        left++;
        right--;
    }

    return s;
}