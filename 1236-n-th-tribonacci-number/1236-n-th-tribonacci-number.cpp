class Solution {
public:
    int tribonacci(int n) {
        int arr[4];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;


        for(int i = 3 ; i <= n ; i++){
            arr[i%4] = arr[(i-1)%4] + arr[(i-2) % 4] + arr[(i-3) % 4];
        }


        return arr[n%4];

    }
};