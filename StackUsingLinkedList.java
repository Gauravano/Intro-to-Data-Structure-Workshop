package l13;
import l12.Nodes;

public class StackUsingLinkedList<T> {
	
	private Nodes<T> node;
	private int length;
	
	public  StackUsingLinkedList() {
		length=0;
		node=null;
		
	}
	
	public int size(){
		return length;
	}
	
	public void print(){
		Nodes<T> temp;
		temp=node;
		
		while(temp!=null){
			System.out.print(temp.data+"-->");
			temp=temp.next;
		}
	}
	
	public boolean isEmpty(){
			
		if(length==0){
				return true;
		}
		return false;
	}
	
	public void push(T element){
		Nodes<T> temp=new Nodes<T>(element);
	
		if(this.size()==0){
			temp.next=null;
			node=temp;
		}else{
			temp.next=node;
			node=temp;
		}
		length++;
}
	public T pop()throws StackEmptyException{
		if(node==null){
			StackEmptyException e = new StackEmptyException("pop");
			throw e;
		}
		T elementToReturned;
		elementToReturned= node.data;
		node=node.next;
		length--;
		return elementToReturned;
	}
	
	public T top()throws StackEmptyException{
		if(node==null){
			StackEmptyException e=new StackEmptyException("Top");
			throw e;
		}
		return node.data;
	}
}
