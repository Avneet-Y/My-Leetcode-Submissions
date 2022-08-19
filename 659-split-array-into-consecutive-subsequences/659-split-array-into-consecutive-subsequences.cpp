class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;   //frequency of each element in count map
        unordered_map<int, int> end;   //store the no. of subsequence ending with nums[i]
        
        for(int i = 0; i < n; i++)
        {
            count[nums[i]]++;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(count[nums[i]] == 0)     //nums[i] is already included
                continue;
            count[nums[i]]--;   // dec frequency of curr element            
            
            if(end[nums[i] - 1] > 0)  // 1st check can we include in existing subsequence
            {
                end[nums[i] - 1]--;
                end[nums[i]]++;
            }
            
            // 2nd check can we form a new subsequence starting with nums[i] and ending with nums[i] + 2
            
            else if(count[nums[i] + 1] && count[nums[i] + 2])
            {
                count[nums[i] + 1]--;
                count[nums[i] + 2]--;
                end[nums[i] + 2]++;
            }
            else
                return false;
        }
        return true;
    }
};