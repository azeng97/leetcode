package List; 

public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int val) {
        this.val = val;
        this.next = null;
    }
    
    public ListNode addNode(int val){
    	ListNode newNode = new ListNode(val);
    	newNode.next = this;
    	return newNode;   	
    }
    
	 public void printList(){
			for (ListNode curr = this; curr!=null; curr=curr.next) System.out.print(curr.val + " ");
			System.out.println();
	}
    //  try to finish https://leetcode.com/tag/linked-list/, as many as you can 
}