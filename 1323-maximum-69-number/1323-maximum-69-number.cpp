class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int ct = 0;
        string s = to_string(num);
        while(n > 0)
        {
            n = n/10;
            ct++;
        }
        for(int i = 0; i < ct; i++)
        {
            if(s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        }
        num = stoi(s);
        return num;
    }
};