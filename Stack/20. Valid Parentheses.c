bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int idx = -1;
    for(int i = 0; i < len; i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            stack[++idx] = s[i];
        }
        else{
            if(idx<0){
                return false;
            }
            if(s[i]==')' && stack[idx]!='('){
                return false;
            }
            if(s[i]==']' && stack[idx]!='['){
                return false;
            }
            if(s[i]=='}' && stack[idx]!='{'){
                return false;
            }
            idx--;
        }
    }
    if(idx>=0){
        return false;
    }
    return true;
}