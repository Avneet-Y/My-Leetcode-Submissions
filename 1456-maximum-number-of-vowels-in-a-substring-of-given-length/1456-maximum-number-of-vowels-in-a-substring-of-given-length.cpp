class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int i=0, j=0;
        int temp = 0, maxi = 0; 
        while(j < n)
        {
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                temp++;
            if(j-i+1 < k)
                j++;
            else if(j-i+1 ==  k)
            {
                maxi = max(temp, maxi);
                if(s[i] == 'a' || s[i]=='e' || s[i] == 'i' || s[i] == 'o' || s[i]== 'u')
                    temp--;
                i++;
                j++;
            }
        }
        return maxi;
        
    }
};