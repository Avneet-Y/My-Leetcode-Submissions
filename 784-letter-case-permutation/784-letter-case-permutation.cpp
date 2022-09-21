class Solution {
public:
    void solve(string ip, string op, vector<string> &vec)
    {
        if(ip.length() == 0)
        {
            vec.push_back(op);
            return;
        }
        if(isalpha(ip[0]))
        {
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin() + 0);
            solve(ip, op1, vec);
            solve(ip, op2, vec);
        }
        else
        {
            string op1 = op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin() + 0);
            solve(ip, op1, vec);
            
        }
        

    }
    
    
    vector<string> letterCasePermutation(string s) {
        vector<string> vec;
        string ip = s;
        string op = "";
        solve(ip, op, vec);
        return vec;
        
        
    }
};