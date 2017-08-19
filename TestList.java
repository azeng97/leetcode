package List;

public class TestList {
	public static void main(String[] arg){
		LinkedList l1 = new LinkedList();
		l1.addFirstNode(5);
		l1.addFirstNode(4);
		l1.addFirstNode(3);
		l1.addFirstNode(2);
		l1.addFirstNode(1);
		LinkedList l2 = new LinkedList();
		l2.addFirstNode(9);
		l2.addFirstNode(7);
		l2.addFirstNode(5);
		l2.addFirstNode(3);
		l2.addFirstNode(1);
		Solution n = new Solution();
		LinkedList l3 = n.addTwoNumbers(l1,l2);
		l1.printList();
		l2.printList();
		l3.printList();
		//l3.head = n.oddEvenList(l3.head);
		//l3.printList();

	}
}
