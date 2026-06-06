
int arr1[n];
int arr2[k][3];

//arr2 = [[a,b,c][a,b,c],...]

[1,3,5]
[2,6,1]

arr1 = [0,0,0,0,0,0]
arr1 = [0,5,5,0,0,0]
arr1 = [0,5,6,1,1,1]

for(int i = 0; i < k; i++){
    for(int j = arr2[i][0]; j < arr2[i][1]; j++){
        arr1[j] += arr2[i][2];
    }
}

n = 100000000
k = 1

for(int i = 0; i < n; i++){
    
}

[1,10]
[5,20]