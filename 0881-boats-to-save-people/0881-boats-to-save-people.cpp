class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       int n = people.size();
       int boats = 0;
       sort(people.begin(), people.end()); 
        int light = 0;
        for(int heavy = n - 1; heavy >= 0; heavy--) 
        { 
            if(light <= heavy)
            {
                if(people[light] + people[heavy] <= limit) 
                    light++;
                boats++;
            }
        }
        return boats;
    }
};