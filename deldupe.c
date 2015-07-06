//deletes duplicates from list
//by Avan

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current;
    if (head!=NULL && head->next!= NULL){
    	while (head->val == head->next->val){
    		head->next = head->next->next;
    	}
    	current = head;
    	while (current->next!=NULL){
    		if (current->val == current->next->val){
    			current->next = current->next->next;
    		} else {
    			current = current->next;
    		}

    	}
	}
	return head;
}