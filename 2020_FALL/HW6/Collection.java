public interface Collection <E>{
	/**
	 * Returns an iterator over the collection.
	 * @return Iterator
	 * @throws Exception for null errors.
	 */
	Iterator<E> iterator() throws Exception;
	
	/**
	 * Ensures that this collection contains the specified element.
	 * @param element to add concreate classes.
	 */
	void add(E element);
	
	/**
	 * Adds all of the elements in the specified collection to this collection.
	 * @param c is Collection and add.
	 */
	void addAll(Collection<E> c);
	
	/**
	 * Clear the collection.
	 */
	void clear();
	
	/**
	 * 
	 * @param element is int or string.
	 * @return true if the element in collection.
	 *
	 */
	boolean contains(E element);
	
	/**
	 * 
	 * @param c is collection
	 * @return true if the two collection is equals.
	 */
	boolean containsAll(Collection<E> c);
	
	/**
	 * 
	 * @return true if no element in collection.
	 */
	boolean isEmpty();
	
	/**
	 * Remove 
	 * @param element is int or string
	 */
	void remove(E element);
	
	/**
	 * Removes all of this collection's elements that are also contained in the specified collection.
	 * @param c is Collection.
	 */
	void removeAll(Collection<E> c);
	
	/**
	 * Retains only the elements in the collection that are contained in the specified collection.
	 * @param c is collection
	 */
	void retainAll(Collection<E> c);
	
	/**
	 * 
	 * @return the number of elements.
	 */
	int size();
	
	
	/**
	 * 
	 * @return int or string array.
	 */
	E[] getJavaArray();
}