class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> vec;
        long temp = n;
        while(temp > 0)
        {
            vec.push_back(temp%10);
            temp /= 10;
        }
        reverse(vec.begin(), vec.end());
        next_permutation(vec.begin() , vec.end());
        
        temp = 0;
        for(int i=0; i<vec.size(); i++)
        {
            temp *= 10;
            temp += vec[i];
        }
        if(temp > INT_MAX || temp <= n)
        {
            return -1;
        } 
        else 
        {
            return temp;
        }
    }
};