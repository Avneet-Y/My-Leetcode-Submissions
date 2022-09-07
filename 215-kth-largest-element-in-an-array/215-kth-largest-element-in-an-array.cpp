class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Using Minheap prioriy queue
        
        // priority_queue<int, vector<int>, greater<int>> minheap;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     minheap.push(nums[i]);
        //     if(minheap.size() > k)
        //     {
        //         minheap.pop();
        //     }
        // }
        // return minheap.top();
        
        // Using Maxheap 
        priority_queue<int> maxheap(nums.begin(),nums.end());
	    for(int i=1; i<k; i++) 
            maxheap.pop();
	    
        return maxheap.top();
        
    }
};