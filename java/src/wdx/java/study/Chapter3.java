package wdx.java.study;

/**
 * 继承设计的技巧
 * 1.将公共操作和域放在超类。
 * 2.不要使用受保护的域。
 * 3.使用继承实现『is-a』关系。
 * 4.除非所有继承的方法都有意义，否则不要使用继承
 * 5.在覆盖方法时，不要改变预期的行为。
 * 6.使用多态，而非类型信息。
 * 7.不要过多的使用反射。
 * @author wangda
 * @version v1.0 2013-10-27
 */
import java.util.ArrayList;
import java.util.Scanner;

public class Chapter3 
{
	private Scanner in;

	public void Content()
	{
		// construct a Manager object
		Manager boss = new Manager("Carl Cracker", 80000, 1987, 12, 15);
		boss.setBonus(5000);
		
		Employee[] staff = new Employee[3];
		
		// fill the staff array with Manager and Employee objects
		staff[0] = boss;
		staff[1] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
		staff[2] = new Employee("Tommy Tester", 40000, 1990, 3, 15);
		
		// print out information about all Employee objects
		for (Employee e : staff)
			System.out.println("name=" + e.getName() + ",salary=" + e.getSalary());
		
		Person[] people = new Person[2];
		
		// fill the people array with Student and Employee objects
		people[0] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
		people[1] = new Student("Maria Morris", "computer science");
		
		// print out names and descriptions of all Person objects
		for (Person p : people)
			System.out.println(p.getName() + "," + p.getDescription());
		
		Employee alice1 = new Employee("Alice Adams", 75000, 1987, 12, 15);
		Employee alice2 = alice1;
		Employee alice3 = new Employee("Alice Adams", 75000, 1987, 12, 15);
		Employee bob = new Employee("Bob Brandson", 50000, 1989, 10, 1);
		
		System.out.println("alice1 == alice2: " + (alice1 == alice2));
		System.out.println("alice1 == alice3: " + (alice1 == alice3));
		System.out.println("alice1.equals(alice3): " + alice1.equals(alice3));
		System.out.println("alice1.equals(bob): " + alice1.equals(bob));
		System.out.println("bob.toString: " + bob);
		
		Manager carl = new Manager("Carl Cracker", 80000, 1987, 12, 15);
		// the definition of boss can be seen above
		boss.setBonus(5000);
		
		System.out.println("boss.toString(): " + boss);
		System.out.println("carl.equals(boss): " + carl.equals(boss));
		System.out.println("alice1.hashCode(): " + alice1.hashCode());
		System.out.println("alice3.hashCode(): " + alice3.hashCode());
		System.out.println("bob.hashCode(): " + bob.hashCode());
		System.out.println("carl.hashCode(): " + carl.hashCode());
		
		System.out.println("# Use of Arraylist");
		
		ArrayList<Employee> stafflist = new ArrayList<Employee>();
		
		stafflist.add(new Employee("Carl Cracker", 75000, 1987, 12, 15));
		stafflist.add(new Employee("Harry Hacker", 50000, 1989, 10, 1));
		stafflist.add(new Employee("Tony Tester", 40000, 1987, 3, 15));
		
		// raise everyone's salary by 5%
		for (Employee e : stafflist)
			e.raiseSalary(5);
		
		// print out information about all Employee objects
		for (Employee e : stafflist)
			System.out.println(e);
		
		System.out.println("# Use of Enum");
		
		in = new Scanner(System.in);
		System.out.print("Enter a size: (SMALL, MEDIUM, LARGE, EXTRA_LARGE) ");
		String input = in.next().toUpperCase();
		Size size = Enum.valueOf(Size.class, input);
		System.out.println("size=" + size);
		System.out.println("abbreviation=" + size.getAbbreviation());
		if (size == Size.EXTRA_LARGE)
			System.out.println("Good job -- you paid attention to the _");
		
		System.out.println("# I have to skip the reflection library here.");
		
		
		System.out.println("&&& Here is the End of Chapter 3! &&&");
	}
}

enum Size
{
	SAMLL("S"), MEDIUM("M"), LARGE("L"), EXTRA_LARGE("XL");
	
	private Size(String abbreviation) { this.abbreviation = abbreviation; }
	public String getAbbreviation() { return abbreviation; }
	
	private String abbreviation;
}
