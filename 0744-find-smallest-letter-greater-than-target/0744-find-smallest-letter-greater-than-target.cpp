class Solution {
public:
    char solve(vector<char>& letters, int start, int end, char target)
    {
        char res = letters[0];
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(letters[mid] == target)
            {
                start = mid + 1;    //bcz we want next greater
            }
            else if(letters[mid] > target)
            {
                res = letters[mid];
                end = mid - 1;
            }
            else if(letters[mid] < target)
            {
                start = mid + 1;
            }
        }
        return res;
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        char ans = solve(letters, 0, n-1, target);
        return ans;   
    }
};