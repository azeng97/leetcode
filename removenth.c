struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	head = reverseList(head);
    struct ListNode* current = head;
    if (n == 1){
        head = head->next;
    } else {
    int x = 1;
	while (x<n-1){
		current = current->next;
		x++;
	}
	current->next = current->next->next;
	}
	head = reverseList(head);
	return head;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* prev = NULL;
    struct ListNode* next;
    while (current!=NULL){
    	next = current->next;
    	current->next = prev;
    	prev = current;
    	current = next;	
    }
    head = prev; 
    return head;
}