/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> oldToNewNodeMap;

        Node* tmp = head;
        while(tmp!=nullptr){
            Node* newNode = new Node(tmp->val);
            oldToNewNodeMap[tmp] = newNode;
            tmp = tmp->next;
        }
        tmp = head;

        while(tmp!=nullptr){
            Node* currNewNode = oldToNewNodeMap[tmp];
            oldToNewNodeMap[tmp]->next = oldToNewNodeMap[tmp->next];
            oldToNewNodeMap[tmp]->random = oldToNewNodeMap[tmp->random];
            tmp = tmp->next;
        }

        return oldToNewNodeMap[head];
        
    }
};