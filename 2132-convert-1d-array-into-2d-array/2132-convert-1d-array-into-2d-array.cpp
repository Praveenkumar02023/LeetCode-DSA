class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if((original.size() > m * n) ||( original.size() < m*n )) return {};

        vector<vector<int>> arr(m,vector<int>(n));

        int i = 0 , j = 0;
        int size = m * n;    

        while(j < size){

            int mod = (j+1) % n;
            if(mod == 0){

                arr[i][n-1] = original[j];
                i++;
                j++;
            }else{
                arr[i][mod-1] = original[j]; 
                j++;
            }

        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){

                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        return arr;

    }
};