//removes elements from list with given value
//by Avan


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* current = head;
    if (head!=NULL){
    	if (head->val == val){
    		head=current->next;
    	}
    	while (current->next!=NULL){
    		if (current->next->val == val){
    			current->next = current->next->next;
    		}
    		current = current->next;
    	}
	}
	return head;
}