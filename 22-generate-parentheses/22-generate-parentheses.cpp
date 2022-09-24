class Solution {
public:
    
    void solve(int open ,int close, string output, vector<string> &vec)
    {
        if(open == 0 && close == 0)
        {
            vec.push_back(output);
            return;
        }
        if(open != 0)
        {
            string op1 = output;
            op1.push_back('(');
            solve(open - 1, close, op1, vec);
            
        }
        if(close > open)
        {
            string op2 = output;
            op2.push_back(')');
            solve(open, close - 1, op2, vec);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        int open = n;
        int close = n;
        string output = "";
        solve(open, close, output, vec);
        return vec;
    }
};