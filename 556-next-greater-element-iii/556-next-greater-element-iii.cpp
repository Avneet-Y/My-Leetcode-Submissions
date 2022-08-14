class Solution {
public:
    int nextGreaterElement(int n) {
       if(n<10)
           return -1;
        string s=to_string(n);
        int maxind,ind, i;
        for(i = s.size()-2; i>=0; i--)
        {
            if(s[i]>=s[i+1]) 
                maxind=i;
            else 
                break;  
        }
        if(i == -1)
            return -1;
        char c='9';
        maxind=i;
        for(i++; i<s.size(); i++){
            if(c >= s[i] && s[i] > s[maxind]){
                c = s[i];
                ind = i;
            }
        }
        swap(s[ind], s[maxind]);
        sort(s.begin() + maxind + 1, s.end());
        long long res=stoll(s);
        if( res<=INT_MAX && res>n ) 
            return res;
        return -1;
    }
};