class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int sum  = 0, count  =  0, i = 1;
        while(sum < n)
        {
            sum += i;
            if(sum > n)
                break;
            count++;
            i++;
        }
        return count;
    }
};