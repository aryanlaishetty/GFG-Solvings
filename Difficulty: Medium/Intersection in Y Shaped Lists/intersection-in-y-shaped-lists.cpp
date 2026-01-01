/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getSize(Node* head) {
        Node* temp = head;
        int size = 0;
        
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }
        
        return size;
    }
  
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int s1 = getSize(head1);
        int s2 = getSize(head2);
        
        int diff = abs(s1-s2);
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        
        if(s1 > s2) {
            for(int i=0; i<diff; i++) {
                temp1 = temp1->next;
            }
        } else {
            for(int i=0; i<diff; i++) {
                temp2 = temp2->next;
            }
        }
        
        while(temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return temp1;
    }
};