class Solution {
public:
    
    //This is same as Josephus problem (Execution vala)
    
    void solve(vector<int> vec,int k,int index,int &ans){
       if(vec.size()==1)
       {
           ans = vec[0];
           return;
       }
       index = (index+k) % vec.size();
       vec.erase(vec.begin() + index);
       solve(vec, k, index, ans);
       return;
   }
    
    int findTheWinner(int n, int k) {
        vector<int> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back(i+1);
        }
        k = k-1;
        int index = 0;
        int ans = -1;
        solve(vec, k, index, ans);
        return ans;    
    }
};