package wdx.java.study;

import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Random;

public class Employee extends Person implements Comparable<Employee>, Cloneable
{
	public Employee(String n, double s, int year, int month, int day)
	{
		super(n);
		salary = s;
		GregorianCalendar calendar = new GregorianCalendar(year, month - 1, day);
		hireDay = calendar.getTime();
		id = 0;
	}
	
	public Employee(String n)
	{
		super(n);
		salary = 0;
		hireDay = new Date();
	}
	
	public Employee(String n, double s)
	{
		super(n);
		salary = s;
		hireDay = new Date();
	}
	
	public Employee clone() throws CloneNotSupportedException
	{
		Employee cloned = (Employee) super.clone();
		
		cloned.hireDay = (Date) hireDay.clone();
		return cloned;
	}
	
	/**
	 * 将方法或类声明为final主要是为了确保它们不会在子类中改变语意。
	 * 而若是把某个类加上final修饰符，则不允许这个类拥有子类。
	 */

	
	public double getSalary()
	{
		return salary;
	}
	
	public Date getHireDay()
	{
		return hireDay;
	}
	
	public void setHireDay(int year, int month, int day)
	{
		Date newHireDay = new GregorianCalendar(year, month - 1, day).getTime();
		
		// Example of instance field mutation
		hireDay.setTime(newHireDay.getTime());
	}
	
	public int getId()
	{
		return id;
	}
	
	public void raiseSalary(double byPercent)
	{
		double raise = salary * byPercent / 100;
		salary += raise;
	}
	
	public void setId()
	{
		id = nextId;
		nextId++;
	}
	
	public String getDescription()
	{
		return String.format("an employee with a salary of $%.2f", salary);
	}
	
	// 静态方法只能访问静态类成员
	public static int getNextId()
	{
		return nextId;
	}
	
	/**
	 * Object 类中的equals方法用于检测一个对象是否等于另外一个对象。
	 */
	public boolean equals(Object otherObject)
	{
		// a quick test to see if the objects are identical
		if (this == otherObject) return true;
		
		// must return false if the explicit parameter is null
		if (otherObject == null) return false;
		
		// if the classes don't match, they can't be equal
		if (getClass() != otherObject.getClass()) return false;
		
		// now we know other Object is a non-null Employee
		Employee other = (Employee) otherObject;
		
		// test whether the fields have identical values
		return getName().equals(other.getName()) && salary == other.salary && hireDay.equals(other.hireDay);
	}
	
	public int hashCode()
	{
		return 7 * getName().hashCode() + 11 * new Double(salary).hashCode() + 13 * hireDay.hashCode();
	}
	
	/**
	 * 强烈建议为自定义的每一个类增加toString方法。这样做能让所有人受益匪浅
	 */
	public String toString()
	{
		return getClass().getName() + "[name=" + getName() + ",salary=" + salary + ",hireDay=" + hireDay + "]";
	}
	
	
	
	
	private double salary;
	private Date hireDay;
	private int id;
	private static int nextId = 1; // 这个值属于类，而不属于任何独立的对象，但是每个对象都可以访问这个值。
	
	
	
	
	// static initialization block
	static
	{
		Random generator = new Random();
		nextId = generator.nextInt();
	}
	
	// object initialization block
	{
		id = nextId;
		nextId++;
	}

	
	@Override
	public int compareTo(Employee o) {
		if (salary < o.salary) return -1;
		if (salary > o.salary) return 1;
		return 0;
	}
}
