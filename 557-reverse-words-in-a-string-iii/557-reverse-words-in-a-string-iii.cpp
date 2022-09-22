class Solution {
public:
    string reverseWords(string s) {
        
        // int i = 0;
        // int j = 0;
        // while(i < s.size())
        // {
        //     while(j < s.size() && s[j] != ' ')
        //     {
        //         j++;
        //     }
        //     reverse(s.begin() + i, s.begin() + j);
        //     i = j+1;
        //     j = i;
        // }
        // return s;
        
        stringstream str(s);
        string temp;
        string ans = "";
        while (str >> temp)    //word by word read
        { 
            reverse(temp.begin(), temp.end());
            ans += temp + " ";
        }
        ans.pop_back();    //remove last space
        return ans;
    }
};