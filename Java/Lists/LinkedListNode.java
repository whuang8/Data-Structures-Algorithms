public class LinkedListNode<E> {
	E value;
	LinkedListNode<E> next;

	/* getter/setter for this node's value */
    E getValue() {
    	return this.value;
    }

    void setValue(E value) {
    	this.value = value;
    }

    /* getter/setter for the subsequent node, or null if this is the last node */
    LinkedListNode<E> getNext() {
    	return this.next;
    }

    void setNext(LinkedListNode<E> next) {
    	this.next = next;
    }
}