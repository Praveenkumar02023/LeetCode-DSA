class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adjList;

        //inDegree and outDegree
        unordered_map<int,int> inDegree , outDegree;

        for(auto &edge : pairs){

            adjList[edge[0]].push_back(edge[1]);
            inDegree[edge[1]] += 1;
            outDegree[edge[0]] += 1;

        }

        int startNode = pairs[0][0];

        for(auto &it : adjList){
            int edge = it.first;
            if(outDegree[edge] - inDegree[edge] == 1){
                startNode = edge;
                break;
            }
        }

        stack<int> stk;

        stk.push(startNode);
        vector<int> eulerPath;
        while(!stk.empty()){

            int curNode = stk.top();
           
            if(!adjList[curNode].empty()){
                int adjNode = adjList[curNode].back();
                adjList[curNode].pop_back();
                stk.push(adjNode);
            }else{
                   eulerPath.push_back(curNode);
                   stk.pop(); 
            }
            
        }

        reverse(eulerPath.begin(),eulerPath.end());
        vector<vector<int>> result;

        for(int i = 0 ; i < eulerPath.size() - 1 ; i++ ){

            result.push_back({eulerPath[i] , eulerPath[i+1]});

        }

        return result;
    }
};