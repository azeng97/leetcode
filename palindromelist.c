struct ListNode* reverseList(struct ListNode* head);
bool isPalindrome(struct ListNode* head) {
	struct ListNode* reverse = malloc(sizeof(struct ListNode));
	reverse = reverseList(head);
	struct ListNode* cur1 = head;
	struct ListNode* cur2 = reverse;
/*	while (cur2!=NULL){
	    printf("%d->", cur2->val);
	    cur2 = cur2->next;
	}
	printf("X\n");
	while (cur1!=NULL){
	    printf("%d->", cur1->val);
	    cur1 = cur1->next;
	}
	printf("X\n");*/
	while (cur1 != NULL && cur2!=NULL){
		if (cur1->val != cur2->val){
			return false;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}	    
	return true;
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