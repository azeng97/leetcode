struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
 	struct ListNode *a = headA;
 	struct ListNode *b = headB;
 	if (headA==NULL || headB==NULL){
 		return NULL;
 	}
 	while (a!=NULL){
 		while (b!=NULL){
 			if (a == b){
 				return a;
 			} else {
 				b=b->next;
 			}
 		}
 		a=a->next;
 	}
 	return NULL; 
}