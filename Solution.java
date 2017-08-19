package List;

import java.lang.reflect.Array;

public class Solution {
	 public ListNode addTwoNumbersIterative(ListNode l1, ListNode l2) {
			l1 = reverseList(l1);
			l2 = reverseList(l2);
			ListNode c1 = l1.next;
			ListNode c2 = l2.next;
			int carry = 0;
			int val1 = l1.val;
			int val2 = l2.val;
			ListNode sum = new ListNode((val1+val2)%10);
			if (val1+val2>9) carry = 1; 
			while (c1!= null || c2!=null){
				if (c1==null){
					val1 = 0;
					val2 = c2.val;
				} else if (c2==null){
					val1 = c1.val;
					val2 = 0;
				} else {
					val1 = c1.val;
					val2 = c2.val;
				}
				ListNode s = new ListNode((val1+val2+carry)%10);
	            
				s.next = sum;
				sum = s;
				if (val1+val2+carry>9){
					carry = 1;
				} else {
					carry = 0;
				}
				if (c1!=null) c1 = c1.next;
				if (c2!=null) c2 = c2.next;
			}
	        if (carry == 1) {
	            ListNode s = new ListNode(carry);
	            s.next = sum;
	            sum = s;
	        }
			return sum;
		 }
	 
	 public LinkedList addTwoNumbers(LinkedList l1, LinkedList l2){
		 ListNode c1;
		 int length1 = 0;
		 int length2 = 0;
		 for (c1 = l1.head; c1!=null; c1 = c1.next) length1++;
		 for (c1 = l2.head; c1!=null; c1 = c1.next) length2++;
		 if (length1>length2) {
			 for (int n = 0; n<length1-length2; n++) {
				 l2.addFirstNode(0);
			 }
		 } else if (length2>length1) {
			 for (int n = 0; n<length2-length1; n++) {
				 l1.addFirstNode(0);
			 }
		 }
		 
		 LinkedList tail1 = l1;
		 LinkedList tail2 = l2;
		 LinkedList result = addTwoNumbersRecursive(tail1, tail2);
		 if (result.head.val == 0) result.deleteFirstNode();
		 return result;
		 
		 
	 }
	 public LinkedList addTwoNumbersRecursive (LinkedList tail1, LinkedList tail2){
		 LinkedList sum;
		 if (tail1.head.next == null && tail2.head.next == null) {
			 int curSum = tail1.head.val+tail2.head.val;
			 sum = new LinkedList();
			 sum.addFirstNode(curSum%10);
			 if (curSum > 9) {
				 sum.addFirstNode(1);
			 } else {
				 sum.addFirstNode(0);
			 }
			 //System.out.println(sum.head.next.val);
			 return sum;
		 } else {
			 LinkedList newTail1 = new LinkedList();
			 newTail1.head = tail1.head.next;
			 LinkedList newTail2 = new LinkedList();
			 newTail2.head = tail2.head.next;
			 LinkedList currSum = addTwoNumbersRecursive(newTail1, newTail2);
			 //System.out.print(tail1.head.val+" " + tail2.head.val+ " " + currSum.head.val+ "\n");
			 int headSum = tail1.head.val+tail2.head.val+currSum.head.val;
			 //System.out.println(headSum);
			 if (headSum > 9) {
				 currSum.head.val = headSum%10;
				 currSum.addFirstNode(1);
			 } else {
				 currSum.head.val = headSum;
				 currSum.addFirstNode(0);
			 }
			 return currSum;
		 }
	 }
	 public void deleteNode(ListNode node){
		 node.val = node.next.val;
		 node.next = node.next.next;
	 }
	 
	 public ListNode reverseList (ListNode head){
		 if (head == null) return null;
		 if (head.next == null) return head;
		 ListNode curr = head;
		 ListNode next = curr.next;
		 head.next = null;
		 ListNode temp = null;
		 while (next != null){
			 temp = next.next;
			 next.next = curr;
			 curr = next;
			 next = temp;
		 }
		 return curr;
	 }
	 

	 public ListNode oddEvenList(ListNode head){
		 ListNode c1 = head;
		 ListNode c2 = head;
		 ListNode t1, t2, t3;
		 while (c2.next.next!=null) {
			 t1 = c1.next;
			 t2 = c2.next; 
			 t3 = c2.next.next;
			 c1.next = t3;
			 t2.next = t3.next;
			 t3.next = t1;
			 c1 = t3;
			 c2 = t2;
		 }
		 return head;
	 }
	 
	 public boolean isPalindrome(ListNode head){
		 if (head == null) return true;
		 if (head.next == null) return true;
		 ListNode copy = new ListNode(head.val);
		 ListNode newCopy = copy;
		 copy.next = newCopy;
		 ListNode curr = head;
		 ListNode next = curr.next;
		 int length = 1;
		 head.next = null;
		 ListNode temp = null;
		 while (next != null){
			 ListNode tempNext = new ListNode(next.val);
			 newCopy.next = tempNext;
			 newCopy = tempNext;
			 length++;
			 temp = next.next;
			 next.next = curr;
			 curr = next;
			 next = temp;
		 }
		 copy.printList();
		 for (int n =0; n<length/2; n++){
			 if (curr.val!=copy.val) return false;
			 curr=curr.next;
			 copy=copy.next;
		 }
		 return true;   
	 }
	 

	 
	 public ListNode detectCycle(ListNode head) {
		 ListNode p1 = head;
		 ListNode p2 = head;
         if (head == null || head.next == null || head.next.next == null) return null; 
		 while (p2!=null && p2.next!=null){
			 p1 = p1.next;
			 p2 = p2.next.next;
             if (p1 == p2) {
            	p2 = head;
            	while (p1!=p2){
            		p1 = p1.next;
            		p2 = p2.next;
            	}
            	return p1;
             }
		 }
		 return null;
	 }
	 
	 public boolean hasCycle(ListNode head) {
		 ListNode p1 = head;
		 ListNode p2 = head;
         if (head == null || head.next == null || head.next.next == null) return false; 
		 while (p2!=null && p2.next!=null){
			 p1 = p1.next;
			 p2 = p2.next.next;
             if (p1 == p2) return true;
		 }
		 return false;
	 }	 
	 public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode l3;
        if (l2 == null) return l1;
        if (l1 == null) return l2;
        if (l1.val<l2.val){
        	l3 = new ListNode(l1.val);
        	l1 = l1.next;
        } else {
        	l3 = new ListNode(l2.val);
        	l2 = l2.next;
        }
        ListNode curr = l3;
        while (l1!=null && l2!=null) {
        	if (l1.val<l2.val){
	        	ListNode n = new ListNode(l1.val);
	        	curr.next = n;
	        	curr = n;
	        	l1 = l1.next;
	        } else {
	        	ListNode n = new ListNode(l2.val);
	        	curr.next = n;
	        	curr = n;
	        	l2 = l2.next;
	        }
        	
        }
    	if (l1!=null) curr.next = l1; 
    	if (l2!=null) curr.next = l2;
    	return l3;
	 }
	 
	 public ListNode reverseBetween(ListNode head, int m, int n) {
		 if (head == null) return null;
		 if (head.next == null) return head;		 
		 ListNode prev = new ListNode(0);
		 prev.next = head;
		 int k=1;
		 for (;k<m;k++) prev = prev.next;
		 ListNode start = prev.next;
		 ListNode curr = start;
		 ListNode next = curr.next;
		 curr.next = null;
		 ListNode temp = null;
		 for (;k<n;k++){
			 temp = next.next;
			 next.next = curr;
			 curr = next;
			 next = temp;
		 }
		 start.next = next;
		 prev.next = curr;
		 if (m==1) return prev.next;
		 return head;
	 }	 
	 
	 public ListNode mergeKLists(ListNode[] lists){
		double size = lists.length;
		ListNode newList[] = new ListNode[(int)size];
		for (int x = 0; x<size;x++) newList[x] = lists[x];
		double steps = Math.ceil(Math.log(size)/Math.log(2));
		for (int k =0; k<steps; k++){
			for (int n=0; n<Math.ceil(size/(2*(k+1))); n++){
				if (2*n+1==Math.ceil(size/(Math.pow(2,k)))) {
					newList[n] = newList[2*n];
					continue;
				}
				newList[n] = mergeTwoLists(newList[2*n],newList[2*n+1]);				
			}
		}
		if (newList.length ==0 ) return null;
		return newList[0];
	 }
	 
	 public ListNode sortList(ListNode head){
		 int size = 1;
		 for (ListNode curr = head; curr!=null; curr=curr.next) size++; 
		 ListNode[] lists = new ListNode[size/2];
		 for (int n=0; n<size/2; n++){
			 ListNode first = head;
			 if (first.next==null){
				 lists[n] = first;
				 continue;
			 }
			 ListNode second = head.next;
			 head = second.next;
			 if (second.val<first.val){
				 second.next = first;
				 first.next = null;
				 lists[n]=second;
			 } else {
				second.next = null;
			 	lists[n]=first;
			 }
		 }
		 return mergeKLists(lists);
	 }
	 
	 public ListNode[] splitPairs(ListNode head){
		 int size = 1;
		 for (ListNode curr = head; curr!=null; curr=curr.next) size++; 
		 ListNode[] lists = new ListNode[size/2];
		 for (int n=0; n<size/2; n++){
			 ListNode first = head;
			 if (first.next==null){
				 lists[n] = first;
				 continue;
			 }
			 ListNode second = head.next;
			 head = second.next;
			 if (second.val<first.val){
				 second.next = first;
				 first.next = null;
				 lists[n]=second;
			 } else {
				second.next = null;
			 	lists[n]=first;
			 }
			 lists[n].printList();
		 }
		 return lists;
	 }
	 public ListNode partition(ListNode head, int x) {
		 ListNode l1 = null, l2= null, l3 = null, curr = head, curr1 = null, curr2 = null, curr3 = null;
		 while (curr!=null){
			 if (curr.val < x) {
				 if (l1 == null){
					 l1 = new ListNode(curr.val);
					 curr1 = l1;
				 } else {
					 ListNode temp1 = new ListNode(curr.val);
					 curr1.next = temp1;
					 curr1 = temp1;
				 }
			 } else {
				 if (l2 == null){
					 l2 = new ListNode(curr.val);
					 curr2 = l2;
				 } else {
					 ListNode temp2 = new ListNode(curr.val);
					 curr2.next = temp2;
					 curr2 = temp2;
				 } 
			 } 
             curr = curr.next;
		 }

         if (l1==null){
           l1 = l2;  
         } else { 
		    curr1.next = l2;
         }
         
         return l1;
		 
	 }
    public ListNode swapPairs(ListNode head) {
    	if (head==null) return null;
    	if (head.next==null) return head;
    	ListNode curr = head.next, temp = curr.next, temp2;
    	head.next = temp;
    	curr.next = head;
    	head = curr;
    	curr = curr.next;
    	while (curr.next!=null && curr.next.next!=null){
    		temp = curr.next;
    		temp2 = temp.next;
    		curr.next = temp.next;
    		temp.next = temp2.next;
    		temp2.next = temp;
    		curr = temp;
    	}
    	return head;
    }
    public RandomListNode copyRandomList(RandomListNode head){
    	RandomListNode copy;
    	if (head==null) return null;
    	for (RandomListNode curr = head; curr!=null; curr = curr.next){
    		RandomListNode temp = new RandomListNode(curr.label);
    		RandomListNode next = curr.next;
    		curr.next = temp;
    		temp.next = next;
    		curr = next;
    	}
    	
    	for (RandomListNode curr = head; curr!=null; curr = curr.next.next){
    		curr.next.random = curr.random.next;
    	}
    	copy = head.next;
    	RandomListNode currCopy = copy;
    	for (RandomListNode curr = head; curr!=null;){
    		RandomListNode next = currCopy.next;
    		currCopy.next = next.next;
    		curr.next = next;
    		curr = curr.next;
    		currCopy = currCopy.next;
    	}
    	return copy;
    }
    
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head==null) return null;
        if (head.next==null) return head;
        if (k==1) return reverseList(head);
        if (k==2) return swapPairs(head);
        ListNode curr = head;
        ListNode next = curr.next;
        ListNode temp;
        for (int n = 0; n<k; n++){
        	if (curr==head){
        		
        	}
        }
        return null;
    }
    
    public ListNode deleteDuplicates(ListNode head) {
        if (head==null) return null;
        if (head.next==null) return head;
        ListNode start = new ListNode(0);
        start.next = head;
        ListNode prev = start;
        ListNode curr = head;
        ListNode next = curr;
        while (next!=null){
        	next = next.next;
        	if (next!=null && curr.val==next.val){
	        	while (next!= null && curr.val==next.val){
	        		next = next.next;
	        	}
	        	curr = next;
	        	prev.next = next;
        	} else {
        		prev = curr;
        		curr = next;
        	}
        }
        return start.next;
    }
    public ListNode rotateRight(ListNode head, int k) {
        if (k==0) return head;
        if (head==null) return null;
        if (head.next==null) return head;
        int length = 1;
        ListNode tail;
        ListNode newHead = head;
        ListNode newTail = head;
        for (tail = head; tail.next!=null; tail=tail.next) length++;
        tail.next = head;
        newTail = tail;
        k=length-k%length;
        
        for (int n=0; n<k; n++){
        	newHead = newHead.next;
        	newTail = newTail.next;
        }
        newTail.next = null;
        return newHead;
        
    }
    
    public ListNode insertionSortList(ListNode head) {
    	if (head==null) return null;
    	if (head.next==null) return head;
    	ListNode sorted = new ListNode(0);
    	sorted.next = head;
    	head = head.next;
    	sorted.next.next = null;
    	ListNode curr;
    	while(head!=null){
    		ListNode tail = head.next;
    		for(curr=sorted; curr.next!=null; curr=curr.next){
    			if(head.val<=curr.next.val){
    				ListNode next = curr.next;
    				curr.next = head;
    				head.next = next;
    				break;
    			}
    		}
    		if (curr.next==null) {
	    		curr.next = head;
	    		head.next = null;
    		}
    		head = tail;
    	}
    	return sorted.next;
    }
    public void reorderList(ListNode head) {
		 if (head == null) return;
		 if (head.next == null) return;
		 int length= 1;
		 ListNode curr;
		 for(curr = head; curr!=null; curr = curr.next) length++;
 		 ListNode[] copy = new ListNode[length];
 		 int k = 0;
 		 for(curr = head; curr!=null; curr = curr.next){
 			 copy[k] = curr;
 			 k++;
 		 }
 		 k--;
 		 curr = head;
 		 ListNode next;
 		 while (curr.next!=null && curr.next.next!=null){
 			 next = curr.next;
 			 copy[k-1].next = null;
 			 curr.next = copy[k];
 			 copy[k].next = next;
 			 curr = next;
 			 k--;
 			 head.printList();
 		 }
    }
    public TreeNode sortedListToBST(ListNode head) {
		 if (head==null) return null;
		 return toBST(head, null);		  	
    }
    public TreeNode toBST(ListNode start, ListNode end){
		ListNode middle = start;
		ListNode curr = start;
		if (start==end) return null;
		while (curr.next!=end && curr!=end){
			middle = middle.next;
			curr = curr.next.next;
		}
		TreeNode node = new TreeNode(middle.val);
		node.left = toBST(start, middle);
		node.right = toBST(middle.next, end);
    	return node;
    }
	 public void printList(ListNode head){
			for (ListNode curr = head; curr!=null; curr=curr.next) System.out.print(curr.val);
			System.out.println();
		}
    
}
