class Trie {
public:
    class trienode
    {
        public:
            bool end;
            trienode* v[26];
            trienode()
            {
                end = false;
                for(int i = 0; i < 26; i++)
                {
                    v[i] = NULL;
                }
            }
    };
    trienode* ans = new trienode();
    Trie() {
        
    }
    
    void insert(string word) {
        trienode* p = ans;
        for(int i = 0; i < word.length(); i++)
        {
            if(p -> v[word[i]-'a'] == NULL)
            {
                p -> v[word[i]-'a'] = new trienode();
            }
            p = p -> v[word[i]-'a'];
        }
        p -> end = true;
    }
    
    bool search(string word) {
        trienode* p = ans;
        int i;
        for(i = 0; i < word.length(); i++)
        {
            if(p->v[word[i]-'a'] == NULL){
                return false;
            }
            p = p->v[word[i]-'a'];
        }
        return p->end;
    }
    
    bool startsWith(string prefix) {
        trienode* p = ans;
        int i;
        for(i = 0; i < prefix.length(); i++)
        {
            if(p->v[prefix[i]-'a']==NULL)
            {
                return false;
            }
            p = p->v[prefix[i]-'a'];
        }
        return i == prefix.length();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */