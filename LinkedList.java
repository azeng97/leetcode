package List;

public class LinkedList {
    public ListNode head;
    public void addFirstNode(int val) {
    	ListNode l1 = new ListNode(val);
    	if (head == null){
    		head = new ListNode(val);
    	} else {
    		l1.next = head;
    		head = l1;
    	}
    }
    
    public ListNode deleteFirstNode() {
    	ListNode temp = head;
    	head = head.next;
    	return temp;
    	
    }

    public void add(int index, int val) {
    	ListNode l = new ListNode(val);
    	if (index==0){
    		addFirstNode(val);
    		return;
    	}
    	ListNode curr = head;
    	for (int n=0; n < index-1; n++){
    		curr = curr.next;
    	}
    	ListNode temp = curr.next;
    	curr.next = l;
    	l.next = temp;
    }

    public ListNode deleteByPos(int index) {
    	if (index==0){
    		return deleteFirstNode();
    	}
    	ListNode curr = head;
    	for (int n=0; n != index-1; n++){
    		curr = curr.next;
    	}
    	ListNode temp = curr.next;
    	curr.next = temp.next;
    	return temp;
    }

    public ListNode deleteByData(int val) {
    	if (head.val == val) return deleteFirstNode();
    	ListNode curr;
    	for (curr = head; curr.next.val!=val; curr=curr.next);
		ListNode temp = curr.next;
		curr.next = temp.next;
		return temp;
    }

    public ListNode findByPos(int index) {
    	ListNode curr = head;
    	for (int n=0; n != index; n++){
    		curr = curr.next;
    	}
    	return curr;
    }
    
    public ListNode findByData( int val) {
    	ListNode curr;
    	for (curr = head; curr.val!=val; curr=curr.next);
    	return curr;
    }
    
	public void printList(){
		for (ListNode curr = head; curr!=null; curr=curr.next) System.out.print(curr.val);
		System.out.println();
	}

}
