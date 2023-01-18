
//Using  Bit Manipulation  
/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int count = pow(2, n);
        vector<vector<int>> subvec(count);
        // The outer for loop will run 2^n times to print all subset .
        // Here variable i will act as a binary counter
    for (int i = 0; i < count; i++) 
    {
        // The inner for loop will run n times , 
        // As the maximum number of elements a set can have is n
        // This loop will generate a subset
        for (int j = 0; j < n; j++) 
        {
            // This if condition will check if jth bit in 
            // binary representation of  i  is set or not
            // if the value of (i & (1 << j)) is not 0 , 
            // include nums[j] in the current subset
            // otherwise exclude nums[j]
            if ((i & (1 << j)) != 0)
                subvec[i].push_back(nums[j]);
        }
    }
        return subvec;
    }
};
*/

//Using Backtracking/Recursion
// class Solution {
// public:
//     vector<vector<int>> ans;
    
//     void generate(vector<int> &subset , int i, vector<int> &nums)
//     {
//         if( i == nums.size())
//         {
//             ans.push_back(subset);
//             return;
//         }
        
//         generate(subset, i+1, nums);  // ith ele not considering in subset
        
//         subset.push_back(nums[i]);   // ith ele in subset
        
//         generate(subset, i+1, nums);  //i+1 processing in subset
        
//         subset.pop_back(); //(Backtrack)for prev functions still see the value i.e passed  
//     }
    
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> empty;
//         generate(empty, 0, nums);
//         return ans;
//     }
// };




class Solution {
public:
    
    
    void generate(vector<int> output , int i, vector<int> &nums, vector<vector<int>> &ans)
    {
        if( i >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        
        generate(output, i+1, nums, ans);  // ith ele not considering in subset
        
        int ele = nums[i];
        
        output.push_back(ele);   // ith ele in subset
        
        generate(output, i+1, nums, ans);  //i+1 processing in subset
          
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        generate(output, 0, nums, ans);
        return ans;
    }
};