class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> pre(numCourses);

        for(int i = 0 ; i < prerequisites.size() ; i++ ){
            pre[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0 ; i < pre.size() ; i++){
                cout<<i<<" ";
            for(auto child : pre[i]){
                cout<<child;
                inDegree[child]++;

            }

            cout<<endl;
        }

        queue<int> q;
        int cnt = 0;

        for(int i = 0 ; i < numCourses ; i++ ){
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
           cnt++;

            for(auto child : pre[front]){

                inDegree[child]--;

                if(inDegree[child] == 0 ) q.push(child);

            }
        }

        return (cnt == numCourses);
    }
};