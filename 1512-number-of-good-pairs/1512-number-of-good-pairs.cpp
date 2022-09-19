class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0 ; i<n; i++)
//         {
//             for(int j = i+1; j<n; j++)
//             {
//                 if(nums[i]==nums[j])
//                     count++;

//             }
//         }
//         return count;
        
        // int count_arr[101] = {};
        // int count = 0;
        // for(int i=0; i < nums.size(); i++)
        // {
        //     count += count_arr[nums[i]];
        //     count_arr[nums[i]]++;
        // }
        // return count;

        //Using hash map
        unordered_map<int,int> umap; 
        for(int i=0; i<nums.size(); i++) 
        {
            ++umap[nums[i]];
        }
        int good_pairs = 0;
        for(auto i:umap) //Using the formula 
        {
            int n = i.second; 
            good_pairs += ((n)*(n-1))/2;
            
        }
        return good_pairs;
    }
};