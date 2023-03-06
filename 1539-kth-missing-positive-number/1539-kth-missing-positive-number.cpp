class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) {
        
        //O(N) solution
        // int n = arr.size();
        // int ans = 0;
        // bool mp[2001] = {0};
        // for(int i=0; i<n; i++)
        //     mp[arr[i]] = 1;
        // for(int it = 1; it < 2001; it++)
        // {
        //     if(mp[it] == 0)
        //         k--;
        //     if(k == 0)
        //     {
        //         return ans = it;
        //     }   
        // }
        // return ans;

        
        
//         int mis = 0;                        
//         int it = 0;                         
//         for(int i=1 ; i <= arr.back();i++)
//         {   //here, i== current integer
//             if(arr[it] == i)
//             {
//                 it++;
//             }
//             else
//             {
//                 mis++;
//             }
//             if(mis == k)
//             {
//                 return i;
//             }
//         }

//         return arr.back() + k - mis;
        
        
    //     for(int i=1;;++i){
    //     auto it = find(arr.begin(), arr.end(), i);
    //     if(it==arr.end()) k--;
    //     if(k==0){
    //         return i;
    //         break;
    //     }
    // } return 0;
        
        //Binary search 
        int n = arr.size();
        int start = 0, end = n - 1, mid, ans;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            int missed = arr[mid] - mid - 1;
            if (missed >= k)
            {
                ans = arr[mid] - (missed - k) - 1;
                end = mid - 1;
            }
            if (missed < k)
            {
                start = mid + 1;
                ans = arr[mid] + k - missed;
            }
        }
    return ans;    
    }
};