class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        for(int i = 0; i < arr.size() ; i++){
            bool flag = true;
            for(int j = i ; j < arr.size() ; j++){

                if(target[i] == arr[j]){
                    int s = i , e = j;
                    flag = false;
                    while(i < j){
                        swap(arr[s],arr[j]);
                        s++;
                        j--;
                    }
                    break;
                }
            }

            if(flag) return false;
        }

        return true;
    }
};