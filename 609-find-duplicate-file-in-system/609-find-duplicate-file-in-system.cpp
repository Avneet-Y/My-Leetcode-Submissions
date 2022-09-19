class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string>> hash;        
        unordered_map<string, vector<string>> mp;
        
        for(auto str : paths)
        {
            int n = str.size();      
            int i = 0;      
            string path = ""; 
            while(i < n && str[i] != ' ')
            {
                path += str[i];     
                i++;
            } 
            path += '/';
            i++; 
            while(i < n)
            {
                string file_name = "";  
                string file_ext = ""; 
                while(i < n && str[i] != '(')
                {
                    file_ext += str[i];     
                    i++;
                }
                while(i < n && str[i] != ' ')
                {
                    file_name += str[i];
                    
                    i++;
                }
                mp[file_name].push_back(path + file_ext);  
                i++;
            }
        } 
        vector<vector<string>> ans;
        for(auto x : mp)
        {
            if(x.second.size() > 1)
            {
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};