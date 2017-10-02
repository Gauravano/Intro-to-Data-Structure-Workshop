package l14;


 class Nodes<T> {
	public T data;
	public Nodes<T> next;

	public Nodes(T data) {
		this.data = data;
		this.next = null;
	}
}

public class QueueUsingLinkedList<T> {
	private Nodes<T> front;
	private int length;
	private Nodes<T> back;

	public QueueUsingLinkedList() {
		front = null;
		length = 0;
		back = front;
	}

	public int size() {
		return length;
	}

	public T frontElement() throws QueueEmptyException {
		if (size()==0) {
			throw new QueueEmptyException("");
		}
		return front.data;
	}

	public void enqueue(T element) {
		Nodes<T> newNode = new Nodes<T>(element);
		if (back != null)  {
			back.next = newNode;
			back = newNode;
		} else {
			front = newNode;
			back = newNode;
		}

		length++;
	}

	public boolean isEmpty(){
		if (size()==0) {
			return true;
		}
		else
			return false;
	}

	public T dequeue() throws QueueEmptyException {

		if (size()==0) {
			throw new QueueEmptyException(" ");
		}
		T dataToBeRemoved = front.data;
		front = front.next;
		length--;
		if (front == null) {
			back = null;
		}
		return dataToBeRemoved;
	}

}

