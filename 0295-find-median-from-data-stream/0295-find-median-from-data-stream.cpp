class MedianFinder {
   priority_queue<int,vector<int>,greater<int>> Min;
   priority_queue<int> Max;
   
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(Max.empty() || Max.top() > num){
            Max.push(num);
        }else{
            Min.push(num);
        }

        if(Max.size() > Min.size() + 1){
            Min.push(Max.top());
            Max.pop();
        }else if(Min.size() > Max.size() + 1){
            Max.push(Min.top());
            Min.pop();
        }
    }
    
    double findMedian() {
        if(Max.size() == Min.size()){
            if(Max.empty()) return 0;
            else return (Max.top() + Min.top())/2.0;
        }

        else return ( Max.size() > Min.size()) ?  Max.top()  : Min.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */