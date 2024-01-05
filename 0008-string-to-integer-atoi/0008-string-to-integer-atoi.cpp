class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while(s[i] == ' ')
        { 
            i++;
        }
        int posi = 0, neg = 0; 
        if(s[i] == '+')
        {
            posi++; // no of +ve signs at the start in string
            i++;
        }
        if(s[i] == '-')
        {
            neg++; // no of -ve signs at the start in string
            i++;
        }
        double ans = 0; 
        while(i < n and s[i] >= '0' and s[i] <= '9')
        {
            ans = ans*10 + (s[i] - '0');
            i++;
        }

        if(neg > 0) // if negative sign exist
            ans = -ans;
        if(posi > 0 and neg > 0) //  Example: +-12
            return 0;
        
        if(ans > INT_MAX) 
            ans = INT_MAX;
        if(ans < INT_MIN) 
            ans = INT_MIN;

        return (int)ans;
    }
};