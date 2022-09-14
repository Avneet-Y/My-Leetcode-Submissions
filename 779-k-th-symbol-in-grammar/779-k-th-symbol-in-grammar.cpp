class Solution {
public:
    int kthGrammar(int n, int k) {
         if(n==1 && k==1)
         {
            return 0;
        }
        int prev=kthGrammar(n-1,(k+1)/2);
        if(k%2)
        {
            return prev;
        }
        else
        {
            return !prev;
        }
        return -1;
    }
};