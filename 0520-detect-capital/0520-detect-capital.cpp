class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int lowerct = 0;
        int upperct = 0;
        for(int i=0; i<n; i++)
        {
            if(isupper(word[i]))
                upperct++;
            else if(islower(word[i]))
                lowerct++;
        }
        if(n == upperct)
            return true;
        else if(n == lowerct)
            return true;
        else if(isupper(word[0]) and lowerct == n-1)
            return true;
        return false;
    }
};

