// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count = 0;
//         while(n>0)
//         {
//             n &= (n - 1);
//             count++;
//     }
// };

// inbuilt function bitset.

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
        
//         return bitset<32>(n).count();
//     }
        
// };

class Solution {
public:
    int hammingWeight(uint32_t n) {
         
        return __builtin_popcount(n);
    }
};
    


