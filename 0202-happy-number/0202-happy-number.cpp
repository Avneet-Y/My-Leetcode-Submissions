class Solution {
public:
    bool isHappy(int n) {
        int val, i;
        set<int> st;
        while(true)
        {
            val = 0;
            while(n > 0)
            {
                i = n%10;
                val += i*i;
                n /= 10;
            }
            if(val == 1)
            {
                return true;
            }
            else if(st.find(val) != st.end())
            {
                return false;
            }
            st.insert(val);
            n = val;
        }
        return false;
    }
};