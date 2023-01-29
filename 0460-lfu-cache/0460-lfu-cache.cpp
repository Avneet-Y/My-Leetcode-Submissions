class LFUCache {
public:
    unordered_map<int, vector<int>> mp;
    set<vector<int>> s;
    int cap;
    int counter = 0;
    
    LFUCache(int capacity) 
    {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if(cap == 0 || mp.find(key) == mp.end())
            return -1;

        counter++;
        int val = mp[key][0];
        int fre = mp[key][1];
        int cnt = mp[key][2];
        auto it = s.find({fre, cnt, key});
        
        s.erase(it);

        mp[key] = {val, fre + 1, counter};
        s.insert({fre + 1, counter, key});

        return val;        
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;

        counter++;
        //when key is present in Cache
        if(mp.find(key) != mp.end())
        {
            //if present in map, then for sure present in set
            int val = value;
            int fre = mp[key][1];
            int coun = mp[key][2];
            auto it = s.find({fre, coun, key});
            s.erase(it);

            mp[key] = {val, fre + 1, counter};
            s.insert({fre + 1, counter, key});
        }
        //key aint present
        else
        {
            //capacity of cache is reached
            if(s.size() >= cap)
            {
                vector<int> it = *s.begin();
                int key1 = it[2];
                mp.erase(key1);
                s.erase(s.begin());
            }

            mp[key] = {value, 1, counter};
            s.insert({1, counter, key});
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */