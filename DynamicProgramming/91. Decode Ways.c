// A = 1; B = 2; C = 3; D = 4; E = 5; F = 6; G = 7; H = 8; I = 9; J = 10
// K = 11; L = 12; M = 13; N = 14; O = 15; P = 16; Q = 17; R = 18; S = 19 ;T = 20
// U = 21; V = 22; W = 23; X = 24; Y = 25; Z = 26

int numDecodings(char* s) {
    if(s[0]=='0') return 0;
    int slen = strlen(s);
    int res[slen+1];
    for(int i = 0; i < slen+1; i++){
        res[i] = 0;
    }
    res[0] = 1;
    res[1] = 1;
    for(int i = 2; i <= slen; i++){
        if(s[i-1]!='0') {
            res[i] = res[i-1];
        }
        int sum = (s[i-2]-'0')*10 + (s[i-1]-'0');
        if((10 <= sum) && (sum <= 26)){
            res[i] += res[i-2];
        }
        if(res[i]<=0){
            return 0;
        }
    }
    return res[slen];
}