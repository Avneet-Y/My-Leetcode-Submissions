class Solution {
public:
    int mah(vector<int>& heights) {
        int n = heights.size();
        vector<long long> nsl, nsr;
        stack<pair<long long, long long>> st1, st2;
        
        for(int i=0; i<n; i++)
        {
            if(st1.size() == 0)
            {
                nsl.push_back(-1);
            }
            else if(st1.size() > 0 && st1.top().first < heights[i])
            {
                nsl.push_back(st1.top().second);
            }
            else if(st1.size() > 0 && st1.top().first >= heights[i])
            {
                while(st1.size() > 0 && st1.top().first >= heights[i])
                {
                    st1.pop();
                }
                if(st1.size() == 0)
                {
                    nsl.push_back(-1);
                }
                else 
                {
                   nsl.push_back(st1.top().second); 
                }
            }
            st1.push({heights[i], i});
        }
        
        
        for(int i=n-1; i>=0; i--)
        {
            if(st2.size() == 0)
            {
                nsr.push_back(n);
            }
            else if(st2.size() > 0 && st2.top().first < heights[i])
            {
                nsr.push_back(st2.top().second);
            }
            else if(st2.size() > 0 && st2.top().first >= heights[i])
            {
                while(st2.size() > 0 && st2.top().first >= heights[i])
                {
                    st2.pop();
                }
                if(st2.size() == 0)
                {
                    nsr.push_back(n);
                }
                else 
                {
                   nsr.push_back(st2.top().second); 
                }
            }
            st2.push({heights[i], i});
        }
        reverse(nsr.begin(), nsr.end());
        
         vector<long long> width(n);
         vector<long long> area(n);
         long long maxarea = INT_MIN;
        
         for(int i=0; i<n; i++)
         {
             width[i] = nsr[i] - nsl[i] - 1;
         }
        
         for(int i=0; i<n ;i++)
         { 
             area[i] =  heights[i] * width[i];
             maxarea = max(maxarea , area[i]);
         }
         return maxarea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> vec;
        for(int j=0; j<m; j++)
        {
            vec.push_back(matrix[0][j] - '0');     
        }
        
        int maxar = mah(vec);
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == '0')
                {
                    vec[j] = 0;
                }
                else
                {
                    vec[j] = vec[j] + (matrix[i][j] - '0');
                }
            }
            maxar = max(maxar, mah(vec));
        }
        return maxar;
    }
};