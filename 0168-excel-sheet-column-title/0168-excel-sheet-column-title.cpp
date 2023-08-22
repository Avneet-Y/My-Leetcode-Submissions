class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) 
        {
            columnNumber--;  //as 0 based indexing bcz 0=A
            char currchar = 'A' + (columnNumber % 26);
            ans = currchar + ans;
            columnNumber /= 26;
        }
        return ans;

    }
};