class Solution {
public:
    set<vector<int>> st; //insert vector in a set for duplicate like 4,6,7 and 4,6,7 only 1
    
    void solve(vector<int>& nums, int index, int n, vector<int> temp)
    {
        if(index == n)
        {
            if(temp.size() >= 2)
            {
                st.insert(temp);
            }
            return;
        }
        if(temp.size() == 0 || nums[index] >= temp[temp.size() - 1]) //if jo insert ho rha
        {           //hai vo pehle inserted se bda hai & if empty insert 1st index tabhi==0
            
            temp.push_back(nums[index]);
            solve(nums, index + 1, n, temp);
            temp.pop_back();
        }
        solve(nums, index + 1, n, temp);
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums, 0, n, temp);
        for(auto it : st)   //insert set of vector in ans
        {
          ans.push_back(it);
        }
        return ans;   
    }
};