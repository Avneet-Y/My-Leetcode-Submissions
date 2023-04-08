/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) 
            return node;
        unordered_map<Node*, Node*> mp;
        Node* ans = new Node(node->val, {});
        mp[node] = ans;
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node* currNode = q.front();
            q.pop();
            vector<Node*> tempneighbour = currNode->neighbors;
            for(auto i : tempneighbour)
            {
                if(mp.find(i) == mp.end())
                {
                    mp[i] = new Node(i->val, {});
                    q.push(i);
                }
                mp[currNode]->neighbors.push_back(mp[i]);
            }
        }
        return ans;
        
    }
};