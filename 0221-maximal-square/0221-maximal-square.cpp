class Solution {
public:
     int mah(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl, nsr;
        stack<pair<int, int>> st1, st2;
        
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
        
         vector<int> width(n);
         vector<int> area(n);
         int maxarea = INT_MIN;
         
        
        for(int i = 0; i < n; i++)
        {
            int length = heights[i];
            if(nsr[i] == -1)
            {
                nsr[i] = n;
            }

            int width = nsr[i] - nsl[i] - 1;
            // to make the length and width equal
            if(length != width)
            {
                while(length > width)
                {
                    length--;
                }
                while(width > length)
                {
                    width--;
                }
            }
            int area = length*width;
            maxarea = max(maxarea , area);
        }
        return maxarea;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxsqar = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == '1') 
                    height[j]++;
                else 
                    height[j] = 0;
            }
            maxsqar = max(maxsqar, mah(height));
        }
        return maxsqar;
    }
};