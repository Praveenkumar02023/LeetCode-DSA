class KthLargest {
    vector<int> arr;
    int K;
    priority_queue<int,vector<int>,greater<int>> pq;
    bool flag = true;

   
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        arr = nums; 
        
    }
    
    int add(int val) {

        if(flag){
        arr.push_back(val);
        for(int x : arr){
            pq.push(x);

            if(pq.size() > K) pq.pop();
        }
        flag = false;   
        }else{
            pq.push(val);
            if(pq.size() > K) pq.pop();
        }


        return pq.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */