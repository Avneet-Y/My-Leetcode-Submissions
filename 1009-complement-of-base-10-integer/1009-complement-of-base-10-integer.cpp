class Solution {
public:
    int bitwiseComplement(int n) {
//         long num = 1;
//         while(num-1 < n)
//         {
//             num <<= 1;
//         }
//         num--;
//         return num-n;
        
        int mask = 1;

        while (mask < n)
            mask = (mask << 1) + 1;

        return mask ^ n;
    }
};