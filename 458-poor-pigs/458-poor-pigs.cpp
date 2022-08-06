class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int ans;
        ans = ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
             return ans;
        
    }
};