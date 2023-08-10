/*
 * Ersin Alçin - 1801042692
 */
/**
 * This is the test file...
 */
public class Main {
	
	public static void test_Iterator(Integer[] other,String[] other2) throws Exception {
		
		Iterator<Integer> iter = new Iterator<Integer>(other);
		
		System.out.println("\n___________ Testing Iterator Class ___________\n");
		iter.printIter();
		System.out.println("\nhasNext() : " + iter.hasNext());
		System.out.println("\nnext() : " + iter.next());
		System.out.println("next() : " + iter.next());
		System.out.println("next() : " + iter.next());
		System.out.println("next() : " + iter.next());
		System.out.println("next() : " + iter.next());
		System.out.println("\nremove() : " + iter.remove() + "\n");
		iter.printIter();

		Iterator<String> iter2 = new Iterator<String>(other2);

		iter2.printIter();
		System.out.println("\nhasNext() : " + iter2.hasNext());
		System.out.println("\nnext() : " + iter2.next());
		System.out.println("next() : " + iter2.next());
		System.out.println("\nremove() : " + iter2.remove() + "\n");
		iter.printIter();
		
	}
	
	public static void test_HashSet(Integer[] other1,Integer[] other2,String[] other3,String[] other4) throws Exception {
		
		HashSet<Integer> hash_set1 = new HashSet<Integer>(other1);
		HashSet<Integer> hash_set2 = new HashSet<Integer>(other2);
		
		System.out.println("\n___________ Testing HashSet Class  ___________");
		hash_set1.printArray();
		System.out.println("\nadd(100) : "); hash_set1.add(100); hash_set1.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set1.addAll(hash_set2); hash_set1.printArray();
		System.out.println("\ncontains(-40) : " + hash_set1.contains(-40));
		System.out.println("\ncontainsAll(c) : " + hash_set1.containsAll(hash_set2));
		System.out.println("\nisEmpty() : " + hash_set1.isEmpty());
		System.out.println("\nremove(100) : "); hash_set1.remove(100); hash_set1.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set1.retainAll(hash_set2); hash_set1.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set1.removeAll(hash_set2); hash_set1.printArray();
		System.out.println("\nsize() : " + hash_set1.size());
		System.out.println("\nclear() : "); hash_set1.clear();

		HashSet<String> hash_set3 = new HashSet<String>(other3);
		HashSet<String> hash_set4 = new HashSet<String>(other4);
		
		hash_set3.printArray();
		System.out.println("\nadd(Veli) : "); hash_set3.add("Veli"); hash_set3.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set3.addAll(hash_set4); hash_set3.printArray();
		System.out.println("\ncontains(Veli) : " + hash_set3.contains("Veli"));
		System.out.println("\ncontainsAll(c) : " + hash_set3.containsAll(hash_set4));
		System.out.println("\nisEmpty() : " + hash_set3.isEmpty());
		System.out.println("\nremove(Ece) : "); hash_set3.remove("Ece"); hash_set3.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set3.removeAll(hash_set4); hash_set3.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set3.retainAll(hash_set4); hash_set3.printArray();
		System.out.println("\nsize() : " + hash_set3.size());
		System.out.println("\nclear() : "); hash_set3.clear();
		
	}
	

	public static void test_ArrayList(Integer[] other1,Integer[] other2,String[] other3,String[] other4) throws Exception {
		
		ArrayList<Integer> hash_set1 = new ArrayList<Integer>(other1);
		ArrayList<Integer> hash_set2 = new ArrayList<Integer>(other2);
		
		System.out.println("\n___________ Testing ArrayList Class ___________");
		hash_set1.printArray();
		System.out.println("\nadd(100) : "); hash_set1.add(100); hash_set1.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set1.addAll(hash_set2); hash_set1.printArray();
		System.out.println("\ncontains(-40) : " + hash_set1.contains(-40));
		System.out.println("\ncontainsAll(c) : " + hash_set1.containsAll(hash_set2));
		System.out.println("\nisEmpty() : " + hash_set1.isEmpty());
		System.out.println("\nremove(100) : "); hash_set1.remove(100); hash_set1.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set1.retainAll(hash_set2); hash_set1.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set1.removeAll(hash_set2); hash_set1.printArray();
		System.out.println("\nsize() : " + hash_set1.size());
		System.out.println("\nclear() : "); hash_set1.clear();

		ArrayList<String> hash_set3 = new ArrayList<String>(other3);
		ArrayList<String> hash_set4 = new ArrayList<String>(other4);
		
		hash_set3.printArray();
		System.out.println("\nadd(Veli) : "); hash_set3.add("Veli"); hash_set3.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set3.addAll(hash_set4); hash_set3.printArray();
		System.out.println("\ncontains(Veli) : " + hash_set3.contains("Veli"));
		System.out.println("\ncontainsAll(c) : " + hash_set3.containsAll(hash_set4));
		System.out.println("\nisEmpty() : " + hash_set3.isEmpty());
		System.out.println("\nremove(Mehmet) : "); hash_set3.remove("Mehmet"); hash_set3.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set3.removeAll(hash_set4); hash_set3.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set4.retainAll(hash_set3); hash_set3.printArray();
		System.out.println("\nsize() : " + hash_set3.size());
		System.out.println("\nclear() : "); hash_set3.clear();
		
	}
	
	
public static void test_LinkedList(Integer[] other1,Integer[] other2,String[] other3,String[] other4) throws Exception {
		
		LinkedList<Integer> hash_set1 = new LinkedList<Integer>(other1);
		LinkedList<Integer> hash_set2 = new LinkedList<Integer>(other2);
		
		System.out.println("\n___________ Testing LinkedList Class ___________");
		hash_set1.printArray();
		System.out.println("\nadd(100) : "); hash_set1.add(100); hash_set1.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set1.addAll(hash_set2); hash_set1.printArray();
		System.out.println("\ncontains(-40) : " + hash_set1.contains(-40));
		System.out.println("\ncontainsAll(c) : " + hash_set1.containsAll(hash_set2));
		System.out.println("\nisEmpty() : " + hash_set1.isEmpty());
		System.out.println("\nremove(100) : "); hash_set1.remove(100); hash_set1.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set1.retainAll(hash_set2); hash_set1.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set1.removeAll(hash_set2); hash_set1.printArray();
		System.out.println("\nsize() : " + hash_set1.size());
		System.out.println("\nelement() : " + hash_set1.element()); 
		System.out.println("\noffer(93) : "); hash_set1.offer(93); hash_set1.printArray();
		System.out.println("\npoll() : " + hash_set1.pool()); 
		System.out.println("\nclear() : "); hash_set1.clear();

		LinkedList<String> hash_set3 = new LinkedList<String>(other3);
		LinkedList<String> hash_set4 = new LinkedList<String>(other4);
		
		hash_set3.printArray();
		System.out.println("\nadd(Veli) : "); hash_set3.add("Veli"); hash_set3.printArray();
		System.out.println("\naddAll(Collection) : "); hash_set3.addAll(hash_set4); hash_set3.printArray();
		System.out.println("\ncontains(Veli) : " + hash_set3.contains("Veli"));
		System.out.println("\ncontainsAll(c) : " + hash_set3.containsAll(hash_set4));
		System.out.println("\nisEmpty() : " + hash_set3.isEmpty());
		System.out.println("\nremove(Mehmet) : "); hash_set3.remove("Mehmet"); hash_set3.printArray();
		System.out.println("\nremoveAll(Collection) : "); hash_set3.removeAll(hash_set4); hash_set3.printArray();
		System.out.println("\nretainAll(Collection) : "); hash_set3.retainAll(hash_set3); hash_set3.printArray();
		System.out.println("\nsize() : " + hash_set3.size());
		System.out.println("\nelement() : " + hash_set3.element()); 
		System.out.println("\noffer(Ayse) : "); hash_set3.offer("Ayse"); hash_set3.printArray();
		System.out.println("\npoll() : " + hash_set3.pool());
		System.out.println("\nclear() : "); hash_set3.clear();
		
	}
	

	
	
	public static void main(String[] args) throws Exception {
		
		Integer [] arrayInt = new Integer[7];   
		arrayInt[0] = new Integer(3);
		arrayInt[1] = new Integer(3);
		arrayInt[2] = new Integer(5);
		arrayInt[3] = new Integer(4);
		arrayInt[4] = new Integer(9);
		arrayInt[5] = new Integer(7);
		arrayInt[6] = new Integer(2);
		
		String[] arrayString = new String[4];
		arrayString[0] = new String("Ersin");
		arrayString[1] = new String("Mehmet");
		arrayString[2] = new String("Emrah");
		arrayString[3] = new String("Oben");
		
		Integer [] arrayInt2 = new Integer[5];
		arrayInt2[0] = new Integer(4);
		arrayInt2[1] = new Integer(21);
		arrayInt2[2] = new Integer(0);
		arrayInt2[3] = new Integer(-12);
		arrayInt2[4] = new Integer(45);
		
		String[] arrayString2 = new String[3];
		arrayString2[0] = new String("Dilay");
		arrayString2[1] = new String("Ecem");
		arrayString2[2] = new String("Zeynep");
		
		String[] arrayString3 = new String[5];
		arrayString3[0] = new String("Göknur");
		arrayString3[1] = new String("Amine");
		arrayString3[2] = new String("Zeynep");
		arrayString3[3] = new String("Dilara");
		arrayString3[4] = new String("Deniz");
		
		String[] arrayString4 = new String[3];
		arrayString4[0] = new String("Kerem");
		arrayString4[1] = new String("Hatice");
		arrayString4[2] = new String("Mine");

		
		test_Iterator(arrayInt,arrayString);
		
		test_HashSet(arrayInt,arrayInt2,arrayString,arrayString3);
		
		test_ArrayList(arrayInt,arrayInt2,arrayString,arrayString4);
		
		test_LinkedList(arrayInt,arrayInt2,arrayString,arrayString4);
	}
}
