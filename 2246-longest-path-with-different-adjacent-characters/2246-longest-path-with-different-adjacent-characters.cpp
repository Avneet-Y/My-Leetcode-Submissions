class Solution {
public:
   int longestPath(vector<int>& parent, string s) 
   {
        int n = parent.size();
        int ans=1; //any way the min longest path that we get will be particular node i.e 1
        vector<vector<int>>adj(n);
        for(int i=1; i<n; i++) 
            adj[parent[i]].push_back(i);
        longestPathDfs(0,adj,s,ans);
        return ans;
    }
    int longestPathDfs(int currNode,vector<vector<int>>&adjacentNodes,string &stringInput,int &maxLength)
    {
        int currMax = 0;
        int secondMax = 0;
        for(auto nextNode : adjacentNodes[currNode])
        {
            int result = longestPathDfs(nextNode,adjacentNodes,stringInput,maxLength);
            if(stringInput[currNode] == stringInput[nextNode])
            { 
                continue;   // adjacent are same character
            }
            if(result > currMax)
            {
                secondMax = currMax;
                currMax = result;
            }
            else if(result > secondMax)
            {
                secondMax = result;
            }
        }
        maxLength = max(maxLength, 1 + currMax + secondMax);
        return 1 + currMax; 
    }
};