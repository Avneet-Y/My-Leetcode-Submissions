class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int flip = 0, minflip = 0;
        for(int i = 0; i < n; i++)
        {
            flip += (s[i]-'0');  // count '1's in given string
        }
        minflip = flip;
        for(int i = n-1; i >=0 ; i --)
        {
            if(s[i] == '1') // considered flip in last sequence
                flip -= 1;
            else // not considered flip in last sequence
                flip += 1;
				
            minflip = min(minflip, flip); 
        }
        return minflip;
        
    }
};