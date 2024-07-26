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
    unordered_map<Node*, Node*>visited;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(visited.count(node))
            return visited[node];
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for(const auto& it : node->neighbors){
            if(it->neighbors.empty())
                newNode->neighbors.push_back(new Node(it->val));
            else
                newNode->neighbors.push_back(cloneGraph(it));
        }
        return newNode;
    }
};