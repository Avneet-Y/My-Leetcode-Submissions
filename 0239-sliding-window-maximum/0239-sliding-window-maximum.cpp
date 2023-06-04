class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i=0,j=0;        
        priority_queue<pair<int,int>> pq;       
    
        if(k>nums.size()) return ans;
        
        while(j<nums.size())
        {
            pq.push({nums[j],j});
            if(j-i+1<k)
            {        
                j++;
            }
            else
            {
                //if(r<nums.size()) pq.push({nums[r],r});
                
                if(i<=pq.top().second)
                    ans.push_back(pq.top().first);
                else
                {
                    while(i>pq.top().second)
                    {
                        pq.pop();
                    }
                    ans.push_back(pq.top().first);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};