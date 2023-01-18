/*
class Solution {
    public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0, curr_sum1 = 0, curr_sum2 = 0;
        int max_sub = INT_MIN, minsum_sub = INT_MAX;   
        for(int i=0; i<n; i++)
        {
            total_sum += nums[i]; 
            curr_sum1 += nums[i]; 
            curr_sum2 += nums[i];
            max_sub = max(max_sub, curr_sum1);
            if(curr_sum1 < 0)
            {
                curr_sum1=0;
            }
            
            minsum_sub = min(curr_sum2,minsum_sub);
            
            if(curr_sum2 > 0)
            {
                curr_sum2 = 0;
            }
        }
        if(total_sum == minsum_sub)
            return max_sub;
        return max(max_sub, total_sum - minsum_sub);
        
    }
};
*/
    //Variation of Kadane
    
    /*
    ex = 2 1 -5 4 -3 1 -3 4 1
         _ _              _ _
    here max = 2+1+4+1 = x is ans
    total = 2+1-5+4-3+1-3+4+1
    now minsum(z) = -5+4-3+1-3
    to get max = x = ans we have to subtract minsum from total  
    so to do this we multiply -1 with every one
    -2 -1 5 -4 3 -1 3 -4 -1
    now here
    by kadane 5-4+3-1+3-4 = 6 give max ans as we opposite signs therefore wo -6 hua hoga actual me there total=total   total-(-minsum) = total + minsum to wo x ki value mil jayegi
    simple kadane me index 1 se last tak hame 4 mil rha hoga x
    but circular me 6 mila (z+minsum)
    so max(x, total + minsum) is our ans
    
    Problem case : when all are negative  to usme hum max return krdenge ex 
    -3 -2 -1
    total = -6
    negative krke hme 6 milega so minsum+total= -6+6 = 0 but its not ans
    so return simple x by kadane i.e. -1 that is max among them
    
    
    */

class Solution {
public:
    int kadane(vector<int>& nums)
    {
        int n = nums.size();
        int max_upto_now = INT_MIN;
        int new_max = 0;
        for(int i=0 ; i<n; i++)
        {
            new_max += nums[i];
            if(max_upto_now < new_max)
                max_upto_now = new_max;
            
            if(new_max < 0)
                new_max = 0;
        }
        return max_upto_now; 
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int x = kadane(nums);  //for circular maximum 
        int totalarrsum = 0;
        for(int i=0; i<n; i++)
        {
            totalarrsum += nums[i];
            nums[i] *= -1;
        }
        int z = kadane(nums); //minimum sum in kadane
        
        if(totalarrsum + z == 0)
            return x;
        
        return max(x, totalarrsum + z);        
    }
};