class Solution {
public:
    
    //find subarray that only has atmost diff two elements
    int totalFruit(vector<int>& fruits) {
        int n  = fruits.size();
        set<int> s;
        for(auto it : fruits)
        {
            s.insert(it);
        }

        if(s.size() <= 2)
            return n;
        
        fruits.push_back(100001);
        int j = 0, total = 0;
        int maxi = 0;
        vector<int> freq(100005);
        for(int i=0; i<=n; i++)
        {
            if(freq[fruits[i]] == 0 && total == 2) // am inserting new fruit
            {
                maxi = max(maxi, i-j);
            
                while(j < i) //move left ptr to right while insert new fruit
                {
                    if(freq[fruits[j]] > 1)  //if freq more than 1 del it
                    {
                        freq[fruits[j]]--;
                        j++;
                    }
                    else if(freq[fruits[j]] == 1) //if freq is 1 
                    {
                        freq[fruits[j]]--;
                        j++;
                        break;
                    }
                }
                freq[fruits[i]]++;
            }
            else if(freq[fruits[i]] == 0) //inserting a new fruit
            {
                total++;
                freq[fruits[i]]++;
            }
            else
                freq[fruits[i]]++;  //inserting a current fruit
        }
        return maxi;
    }
};
