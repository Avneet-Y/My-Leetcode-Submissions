class Solution {
public:
    bool checkIfPangram(string sentence) {
        // unordered_map<char, bool> check;
        // for(auto it : sentence)
        //     check[it] = 1;
        // return check.size()==26; 
        
        int n = sentence.size();
        if(n < 26)
            return false;
        unordered_map<char, int> check;
     
        for(int i=0; i<n; i++)
            check[sentence[i]]++;
    
        if(check.size() == 26)
            return true;
        else
            return false;
        
    }
};