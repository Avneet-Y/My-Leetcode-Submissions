class Solution {
public:
    class Node{
        public:
        Node* links[26]={NULL};
        string flag;
        void put(char ch,Node* node){
            links[ch-'a']=node;
        }
        Node* next(char ch){
            return links[ch-'a'];
        }
        void set(string w){
            flag=w;
        }
        int isEnd(){
            return flag.length();
        }
    };
    int dr[4] = {1, -1, 0, 0}; 
    int dc[4] = {0, 0, -1, 1}; 
    int n,m;
    void dfs(int r, int c, vector<vector<char>>& grid, Node *trie, vector<string>&ans) {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c]=='0' || trie->next(grid[r][c])==nullptr) return;
        char ch=grid[r][c];
        trie=trie->next(ch);
        if(trie->isEnd()){
            ans.push_back(trie->flag);
            trie->flag="";
        }
        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) { 
            dfs(r + dr[i], c + dc[i],grid,trie,ans);
        }
        grid[r][c]=ch;
    }
    
    void insert(string s,Node *root){
        Node *node=root;
        for(int i=0;i<s.length();i++){
            if(node->links[s[i]-'a']==nullptr){
                node->put(s[i],new Node);
            }
            node=node->next(s[i]);
        }
        node->set(s);
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        Node *trie=new Node();
        for(auto w:words){
            insert(w,trie);
        }
        vector<string>ans;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                    dfs(j,k,board,trie,ans);
                }
            }
        return ans;
    }
};