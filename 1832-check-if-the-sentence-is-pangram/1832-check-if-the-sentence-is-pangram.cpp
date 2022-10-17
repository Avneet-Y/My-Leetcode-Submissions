class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, bool> check;
        for(auto it : sentence)
            check[it] = 1;
        return check.size()==26;      
        
    }
};