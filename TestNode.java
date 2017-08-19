package List;

public class TestNode {
	public static void main(String[] arg){
		ListNode lists[] = new ListNode[5];
		ListNode l1 = new ListNode(5);
		l1 = l1.addNode(4);
		l1 = l1.addNode(3);
		l1 = l1.addNode(2);
		l1 = l1.addNode(1);
		ListNode l2 = new ListNode(11);
		l2 = l2.addNode(9);
		l2 = l2.addNode(7);
		l2 = l2.addNode(5);
		l2 = l2.addNode(3);
		ListNode l3 = new ListNode(12);
		l3 = l3.addNode(10);
		l3 = l3.addNode(8);
		l3 = l3.addNode(6);
		l3 = l3.addNode(4);
		//l1.printList();
		//l2.printList();
		//l3.printList();
		ListNode l4 = new ListNode(15);
		l4 = l4.addNode(12);
		l4 = l4.addNode(9);
		l4 = l4.addNode(6);
		l4 = l4.addNode(3);
		//l4.printList();
		ListNode l6 = new ListNode(0);
		l6 = l6.addNode(3);
		l6 = l6.addNode(1);
		l6 = l6.addNode(2);
		l6 = l6.addNode(6);
		l6 = l6.addNode(3);
		l6 = l6.addNode(7);
		l6 = l6.addNode(9);
		//l6 = l6.addNode(16);
		l6.printList();
		ListNode l7 = new ListNode(1);
		l7 = l7.addNode(2);
		Solution s = new Solution();
		lists[0] = l1;
		lists[1] = l2;
		lists[2] = l3;
		lists[3] = l4;
		lists[4] = l6;
		//l3.head = n.oddEvenList(l3.head);
		//l7.printList();
		//ListNode l5 = s.mergeKLists(lists);
		//ListNode l5 = s.insertionSortList(l6);
		s.reorderList(l6);
		//if (s.isPalindrome(l6)) System.out.println("yes");
		l6.printList();
	}
}
