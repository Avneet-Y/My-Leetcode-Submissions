class Solution {
public:
    bool isPalindrome(int x) {
        string check;
        check = to_string(x);
        string check2 = check;
        reverse(check2.begin(), check2.end());
        if(check2 == check)
            return true;
        return false;
    }
};