class Solution {
public:
    void Sort(int i , int j , vector<int>& temp){
        if(i >= j){
            return;
        }

        int mid = (i + j)/2;

        Sort(i,mid,temp);
        Sort(mid+1,j,temp);

        Merge(i,j,mid,temp);
    }

    void Merge(int i , int j , int mid , vector<int>& temp){
        vector<int> arr;
        int left = i;
        int right = mid+1;

        while(left <= mid && right <= j){
            if(temp[left] <= temp[right]){
                arr.push_back(temp[left]);
                left++;
            }else{
                arr.push_back(temp[right]);
                right++;
            }
        }

        while(left <= mid){
            arr.push_back(temp[left]);
            left++;
        }

        while(right <= j){
            arr.push_back(temp[right]);
            right++;
        }

        for(int k = 0 ; k < arr.size() ; k++){
            temp[i+k] = arr[k];
        }

    }

    int heightChecker(vector<int>& heights) {
        vector<int> temp(heights.begin(),heights.end());

        Sort(0,heights.size()-1,temp);

        int cnt = 0; 
        for(int i = 0 ; i < heights.size() ; i++){
            if(heights[i] != temp[i]) cnt++;
        }

        return cnt;
    }
};