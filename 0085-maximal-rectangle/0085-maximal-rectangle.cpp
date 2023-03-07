class Solution {
public:
    int mah(vector<int> heights)
    {
        int n = heights.size();
        stack<pair<long long, long long>> st1, st2;
        vector<long long> left, right;
        // NSL
        long long pseudoindex = -1;
        for(int i=0; i<n; i++)
        {
            if(st1.size() == 0)
                left.push_back(pseudoindex);
            else if(st1.size() > 0 && st1.top().first < heights[i])
                left.push_back(st1.top().second);
            else if(st1.size() > 0 && st1.top().first >= heights[i])
            {
                while(st1.size() >0 && st1.top().first >= heights[i])
                {
                    st1.pop();
                }
                if(st1.size() == 0)
                    left.push_back(pseudoindex);
                else
                    left.push_back(st1.top().second);
            }
            st1.push({heights[i], i});
        }
        
        //NSR  
        pseudoindex = n;
        for(int i = n-1; i >= 0; i--)
        {
            if(st2.size() == 0)
                right.push_back(pseudoindex);
            else if(st2.size() > 0 && st2.top().first < heights[i])
                right.push_back(st2.top().second);
            else if(st2.size() > 0 && st2.top().first >= heights[i])
            {
                while(st2.size() > 0 && st2.top().first >= heights[i])
                {
                    st2.pop();
                }
                if(st2.size() == 0)
                    right.push_back(pseudoindex);
                else
                    right.push_back(st2.top().second);
            }
            st2.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        
        vector<long long> width(n);
        vector<long long> area(n);
        
        long long maxarea = INT_MIN;
        for(int i=0; i<n; i++)
        {
            width[i] = right[i] - left[i] - 1;
        }
        
        for(int i=0; i<n; i++)
        {
            area[i] = width[i] * heights[i];
            maxarea = max(maxarea, area[i]);
        }
        return maxarea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 0)
            return 0;
        vector<int> vec;
        for(int j=0; j<m; j++)
            vec.push_back(matrix[0][j] - '0');//1 0 1 0 0
        
        int mx = mah(vec);
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == '0')
                    vec[j] = 0;
                else
                    vec[j] = vec[j] + (matrix[i][j] - '0');
            }
            mx = max(mx, mah(vec));
        }
        return mx;
    }
};