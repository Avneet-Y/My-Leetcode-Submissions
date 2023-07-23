class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inDegree(n + 1, 0);
        vector<int>outDegree(n + 1, 0);
        for (vector<int>&currTrust : trust)
        {
            int trustedPerson = currTrust[1];
            int trustingPerson = currTrust[0];
            inDegree[trustedPerson]++;
            outDegree[trustingPerson]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if ((inDegree[i] == (n - 1)) && (outDegree[i] == 0))
                return i;
        }
        return -1;
        
    }
};