class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        vector<string> rows(numRows);
        bool moveDown = true;
        int rowindex = 0;
        
        for (auto &ch : s) 
        {
            rows[rowindex] += ch;
            
            if (rowindex == numRows - 1)
                moveDown = false;
            else if (rowindex == 0)
                moveDown = true;

            rowindex += (moveDown ? 1 : -1);
        }

        string ans = "";
        for (int i = 0; i < numRows; i++)
        {
            ans += rows[i];
        }
        return ans;
    }
};