class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       
       int n = temperatures.size();
       map<int, int> mp;
       stack<pair<int, int>> st;
       vector<int> temp;
       for(int i=n-1; i>=0; i--)
       {
           if(st.size() == 0)
                temp.push_back(0);
           else if(st.size() > 0 && st.top().first > temperatures[i])
           {
               temp.push_back(st.top().second - i);
           }
           else if(st.size() > 0 && st.top().first <= temperatures[i])
           {
               while(st.size() > 0 && st.top().first <= temperatures[i])
               {
                   st.pop();
               }
               if(st.size() == 0)
                    temp.push_back(0);
               else 
                    temp.push_back(st.top().second - i);
           }
           st.push({temperatures[i], i});
       }
       reverse(temp.begin(), temp.end());
       return temp;
    }
};