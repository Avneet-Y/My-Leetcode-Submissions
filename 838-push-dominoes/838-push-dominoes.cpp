/*
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> lt(n, 0);
        vector<int> rt(n, 0);
        char prev = '.';
        int count = 1;
        for(int i = 0; i<n ; i++)
        {
            if(dominoes[i] == 'R')
            {
                prev = 'R';
                count = 1;
                continue;
            }
            else if(dominoes[i] == 'L')
            {
                prev = 'L';
            }
            if(prev == 'R' and dominoes[i] == '.')
            {
                rt[i] = count;
                count++;
            }
        }
        
        prev = '.';
        count = 1;
        for(int i = n-1; i>=0 ; i--)
        {
            if(dominoes[i] == 'L')
            {
                prev = 'L';
                count = 1;
                continue;
            }
            else if(dominoes[i] == 'R')
            {
                prev = 'R';
            }
            if(prev == 'L' and dominoes[i] == '.')
            {
                lt[i] = count;
                count++;
            }
        }
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(lt[i] == 0 and rt[i] == 0)
            {
                ans += dominoes[i];
            }
            
            else if(lt[i] == 0)
            {
                ans += 'R';
            }
            
            else if(rt[i] == 0)
            {
                ans += 'L';
            }
            
            else if(lt[i] == rt[i])
            {
                ans += '.';
            }
            else if(lt[i] > rt[i])
            {
                ans += 'R';
            }
            else
            {
                ans += 'L';
            }
            
        }
        return ans;
    }
};
*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int left = 0;
        int right = 0;
        while(right < n)
        {
            if(dominoes[right] == '.')
            {
                right++; 
                continue;
            }
            if(dominoes[right] == dominoes[left] || (dominoes[left] == '.' && dominoes[right] == 'L'))
            {
                int i = left;
                while(i < right)
                {
                    dominoes[i] = dominoes[right];
                    i++;
                }
            }
            else if(dominoes[left] == 'R' && dominoes[right] == 'L')
            {
                int i = left;
                int j = right;
                while(i < j)
                {
                    dominoes[i] = 'R';
                    dominoes[j] = 'L';
                    i++;
                    j--;
                }
            }
            
            left = right;
            right++;
        }
        
        // if  last is 'R' replace all right to it with 'R'
        
        if(dominoes[left] == 'R')
        {
            int i = left;
            while(i < n)
            {
                dominoes[i] = 'R';
                i++;
            }
        }
        return dominoes;
    }
};