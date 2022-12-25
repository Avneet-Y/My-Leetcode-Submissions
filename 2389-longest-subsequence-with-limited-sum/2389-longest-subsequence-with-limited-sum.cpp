class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        int m = queries.size();  
        vector<int> answer;
        vector<int> prefix(n);
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            prefix[i] = sum;
        }
        for(int i=0; i<m; i++)
        {
            int count = 0; 
            for(int j=0; j<n; j++)
            {
                if(prefix[j] <= queries[i])
                    count++;
                else
                    break;
            }
            answer.push_back(count);    
        }
        return answer;                                                             
    }
};