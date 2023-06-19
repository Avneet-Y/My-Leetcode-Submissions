class Solution {
public:
    
    void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
    {
        if(index >= digits.size())
        {
            ans.push_back(output);
            return; 
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i=0; i<value.size(); i++)
        {
            output.push_back(value[i]);
            solve(digits, output, index+1, ans, mapping);
            output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0)
            return {};
        
        vector<string> ans;
        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tvu", "wxyz"};
        int index = 0;
        solve(digits, output, index, ans, mapping);
        return ans;
        
    }
};