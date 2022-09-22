class Solution {
public:
    void solve(int op, int cp, string output, vector<string> &vec)
    {
         if(op == 0 && cp == 0)
         {
            vec.push_back(output);
            return;
        }

        if(op != 0)
        {
           string op1 = output + '(';
           solve(op-1 , cp, op1, vec);
        }

        if(cp > op)
        {
            string op2 = output + ')';
            solve(op, cp-1, op2, vec);
        }
    }
        
    
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        int op = n;
        int cp = n;
        string output = "";
        solve(op, cp, output, vec);
        return vec;
    }
};