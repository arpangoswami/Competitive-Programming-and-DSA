bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return true;
        }
        stack<int>s;
        ListNode *ptr = head;
        while(ptr){
            s.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while(!s.empty()){
            if(ptr->val == s.top()){
                s.pop();
                ptr = ptr->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
