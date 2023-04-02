class Solution {
public:
    int binarySearch(int num, vector<int>& potions, long long success){
        int start = 0, end = potions.size()-1;
        double curr =(double)success / num; 
        while(start < end)
        {
            int mid = start + (end - start)/2;
            if(potions[mid] >= curr)
            { 
                end = mid;  
            }
            else
                start = mid+1;  
        }
        if(potions[end] >= curr) 
            return end;  
        else 
            return -1;  
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = potions.size();
        sort(potions.begin(), potions.end()); 
        for(int i : spells)
        {
            int idx = binarySearch(i, potions, success);  
            if(idx == -1) 
                ans.push_back(0);  
            else  
                ans.push_back(n - idx);  
        }
        return ans;  
    }
};