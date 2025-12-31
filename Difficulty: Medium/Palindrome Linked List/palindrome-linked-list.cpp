/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        string str = "";
        Node* temp = head;
        
        while(temp != NULL) {
            str.push_back(temp->data);
            temp = temp->next;
        }
        
        string newStr = str;
        
        reverse(str.begin(), str.end());
        
        return str == newStr;
    }
};