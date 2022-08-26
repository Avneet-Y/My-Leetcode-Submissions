class Solution {
public:
    vector<int> Help(long n){
        vector<int> num(10);
        
        while(n)
        {
            num[n%10]++;
            n = n/10;
        }
        return num;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> vec = Help(n);
        for(int i=0; i<31; i++)
        {
            if(vec == Help(1<<i))
            {
                return true;
            }
        }
        return false;
    }
};