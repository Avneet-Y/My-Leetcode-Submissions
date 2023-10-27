class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        //string temp = "ABCDEFGHIJKLMNEOPQRSTUVWXYZ";
        int i = columnNumber;
        while(i > 0)
        {
            i--;   //as 0 based indexinx A=0
            char currchar = 'A' + (i % 26);
            ans = currchar + ans; 
            i /= 26;
        }
        return ans;
    }
};