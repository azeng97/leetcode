//removes elements from list with given value
//by Avan


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* current = head;
    struct ListNode* prev = head;
        if (head!=NULL){
            current = head->next;
            while (head != NULL && head->val == val){
                head = head->next;
            }
            
    	    while (current!=NULL){
    		      if (current->val == val){
    			     prev->next = current->next;
                     current = current->next;
    		      } else {
                     prev = current;
                     current = current->next;
                
    	           }       
           
           
	       }
        }
	return head;
}