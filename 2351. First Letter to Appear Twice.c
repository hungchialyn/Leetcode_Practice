char repeatedCharacter(char* s) {
    int bit = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(bit & (1 << (s[i]-'a'))) return s[i];
        bit |= (1 << (s[i]-'a'));
    }
    return 'b';
}