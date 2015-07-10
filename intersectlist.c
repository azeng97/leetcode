struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
 	struct ListNode *a = headA;
 	struct ListNode *b = headB;
 	int lengthA = 0;
 	int lengthB = 0;
 	int x = 0;

 	while (a!=NULL){
 		lengthA++;
 		a=a->next;
 	}
 	while (b!=NULL){
 		lengthB++;
 		b=b->next;
 	}
 	a= headA;
 	b= headB;
 	if (lengthA>lengthB){
 		while (x<(lengthA-lengthB)){
 			a=a->next;
 			x++;
 		}
 		
 	} else {
 		while (x<(lengthB-lengthA)){
 			b=b->next;
 			x++;
 		} 
 	}

 	while (a!=NULL){
 		if (a == b){
 			return a;
 		} else {
 			b=b->next;
 			a=a->next;
 		}
 	}
 	return NULL; 
}