class Solution {
public:
    char binaryceil(vector<char>& letters, char target, int n)
    {
        int start = 0;
        int end = n-1;
        char res = letters[0];
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(letters[mid] == target)
            {
                start = mid+1;
            }
            else if(letters[mid] > target)
            {
                res = letters[mid];
                end = mid-1;
            }
            else if(letters[mid] < target )
            {
                start = mid+1;
            }
        }
        return res;
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        char res = letters[0];
        res = binaryceil(letters, target, n);
        return res;
    }
};