class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<long long> left, right;
        stack<pair<long long, long long>> st1, st2;
        
        //NSL and left
        long long pseudoindex = -1;
        for(int i=0; i<n; i++)
        {
            if(st1.size() == 0)
                left.push_back(pseudoindex);
            else if(st1.size() > 0 && heights[i] > st1.top().first)
                left.push_back(st1.top().second);
            else if(st1.size() > 0 && heights[i] <= st1.top().first)
            {
                while(st1.size() > 0 && heights[i] <= st1.top().first)
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
        
        //NSR right
        pseudoindex = n;
        for(int i = n-1; i >= 0; i--)
        {
            if(st2.size() == 0)
                right.push_back(pseudoindex);
            else if(st2.size() > 0 && heights[i] > st2.top().first)
                right.push_back(st2.top().second);
            else if(st2.size() > 0 && heights[i] <= st2.top().first)
            {
                while(st2.size() > 0 && heights[i] <= st2.top().first)
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
        
        //calc
        reverse(right.begin(), right.end());
        
        vector<long long> width(n);
        vector<long long> area(n);
        long long maxarea = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            width[i] = right[i] - left[i] - 1;
        }
        
        for(int i=0; i<n ;i++)
        {
            area[i] =  heights[i] * width[i];
            maxarea = max(maxarea , area[i]);
        }
        
        return maxarea;
        
    }
};