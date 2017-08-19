package List;

public class RandomListNode {
	int label;
	RandomListNode next, random;
	public RandomListNode(int x){
		this.label = x;
	}
	
	public void printRandomList(){
		for (RandomListNode curr = this; curr!=null; curr=curr.next) System.out.print(curr.label + " ");
		System.out.println();		
	}
}
