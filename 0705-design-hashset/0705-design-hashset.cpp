class MyHashSet {
public:
    vector<bool> hash;
    MyHashSet() {
        hash.resize(1e6 +1);
    }
    
    void add(int key) {
        hash[key] = 1;
        
    }
    
    void remove(int key) {
        hash[key] = 0;
        
    }
    
    bool contains(int key) {
        return hash[key] == 1;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */