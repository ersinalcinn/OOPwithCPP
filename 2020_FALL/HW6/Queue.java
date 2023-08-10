public interface Queue<E> extends Collection<E> {
	
	void add(E element);
	/**
	 * Retrives,but does not remove.
	 * @return the head of queue.
	 */
	E element();
	
	/**
	 * 
	 * @param element to inserts queue.
	 */
	void offer(E element);
	
	/**
	 * Retrieves and removes.
	 * @return the head of queue.
	 * @throws Exception if this queue is empty.
	 */
	E pool() throws Exception;
}
