package wdx.java.study;

import java.util.*;

public class Chapter5 
{
	// private Scanner in;

	public void Content()
	{
		System.out.println("# Use of LinkedList");
		
		List<String> a = new LinkedList<String>();
		a.add("Amy");
		a.add("Carl");
		a.add("Erica");
		
		List<String> b = new LinkedList<String>();
		b.add("Bob");
		b.add("Doug");
		b.add("Frances");
		b.add("Gloria");
		
		// merge the words from b into a
		
		ListIterator<String> aIter = a.listIterator();
		Iterator<String> bIter = b.iterator();
		
		while(bIter.hasNext())
		{
			if (aIter.hasNext())
				aIter.next();
			aIter.add(bIter.next());
		}
		
		System.out.println(a);
		
		// remove every second word from b
		
		bIter = b.iterator();
		while(bIter.hasNext())
		{
			bIter.next(); // skip one element
			if (bIter.hasNext())
			{
				bIter.next(); // skip next element
				bIter.remove(); // remove that element
			}
		}
		
		System.out.println(b);
		
		// bulk operation: remove all words in b from a
		a.removeAll(b);
		
		System.out.println(a);
		
		/*
		System.out.println("# Use of HashSet");
		Set<String> words = new HashSet<String>(); // HashSet implements set
		long totalTime = 0;
		
		in = new Scanner(System.in);
		while (in.hasNext())
		{
			String word = in.next();
			long callTime = System.currentTimeMillis();
			words.add(word);
			callTime = System.currentTimeMillis() - callTime;
			totalTime += callTime;
		}
		
		Iterator<String> iter = words.iterator();
		for (int i = 1; i <= 20; i++)
			System.out.println(iter.next());
		System.out.println(". . .");
		System.out.println(words.size() + " distinct words. " + totalTime + " milliseconds");
		*/
		
		System.out.println("# Use of TreeSet");
		SortedSet<Item> parts = new TreeSet<Item>();
		parts.add(new Item("Toaster", 1234));
		parts.add(new Item("Widget", 4562));
		parts.add(new Item("Modem", 9912));
		System.out.println(parts);
		
		SortedSet<Item> sortByDescription = new TreeSet<Item>(new Comparator<Item>()
				{
					public int compare(Item a, Item b)
					{
						String descrA = a.getDescription();
						String descrB = b.getDescription();
						return descrA.compareTo(descrB);
					}
				});
		
		sortByDescription.addAll(parts);
		System.out.println(sortByDescription);
		
		System.out.println("# Use of PriorityQueue");
		PriorityQueue<GregorianCalendar> pq = new PriorityQueue<GregorianCalendar>();
		pq.add(new GregorianCalendar(1906, Calendar.DECEMBER, 9)); // G.Hopper
		pq.add(new GregorianCalendar(1815, Calendar.DECEMBER, 10)); // A.Lovelace
		pq.add(new GregorianCalendar(1903, Calendar.DECEMBER, 3)); // J. von Neumann
		pq.add(new GregorianCalendar(1910, Calendar.JUNE, 22)); // K. Zuse
		
		System.out.println("Iterating over elements...");
		for (GregorianCalendar date : pq)
			System.out.println(date.get(Calendar.YEAR));
		System.out.println("Removing elements...");
		while(!pq.isEmpty())
			System.out.println(pq.remove().get(Calendar.YEAR));
		
		System.out.println("# Use of Map");
		Map<String, Employee> staff = new HashMap<String, Employee>();
		staff.put("144-25-5464", new Employee("Amy Lee"));
		staff.put("567-24-2546", new Employee("Harry Hacker"));
		staff.put("157-62-7935", new Employee("Gary Cooper"));
		staff.put("456-62-5527", new Employee("Francesca Cruz"));
		
		// print all entries
		System.out.println(staff);
		
		// remove an entry
		staff.remove("567-24-2546");
		
		// replace an entry
		staff.put("456-62-5527", new Employee("Francesca Miller"));
		
		// look up a value
		System.out.println(staff.get("157-62-7935"));
		
		// iterate through all entries
		for (Map.Entry<String, Employee> entry : staff.entrySet())
		{
			String key = entry.getKey();
			Employee value = entry.getValue();
			System.out.println("key=" + key + ", value=" + value);
		}
		
		
		System.out.println("&&& Here is the End of Chapter 4! &&&");
	}
}
