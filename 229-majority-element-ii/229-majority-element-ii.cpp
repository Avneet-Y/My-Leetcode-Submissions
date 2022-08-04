// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int> m;
        
//         int n = nums.size();
//         for(int i=0; i<n; i++)
//         {
//             m[nums[i]]++;
//         }

//         vector<int> ans;
//         int ele;
//         for(auto i : m)
//          {
//             if(i.second > n / 3)
//             {
//                 ele = i.first;
//                 ans.push_back(ele);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int nums1 = -1;
        int nums2 = -1;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] == nums1)
                count1++;
            else if(nums[i] == nums2)
                count2++;
            
            else if(count1 == 0)
            {
                nums1 = nums[i];
                count1 = 1;
            }
            
            else if(count2 == 0)
            {
                nums2 = nums[i];
                count2 = 1;
            }
            
            else
            {
                count1--;
                count2--;
            }   
        }
           
    vector<int> ans;
        count1 = count2 = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == nums1)
                count1++;
            else if(nums[i] == nums2)
                count2++;
        }
            if(count1 > n/3)
                ans.push_back(nums1);
            if(count2 > n/3)
                ans.push_back(nums2);
        return ans;
    }
};


