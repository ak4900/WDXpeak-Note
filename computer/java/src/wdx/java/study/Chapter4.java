package wdx.java.study;

import java.util.Arrays;


/**
 * 接口主要用来描述类具有什么功能，而并不给出每个功能的具体实现。
 * 内部类定义在另外一个类的内部，其中的方法可以访问包含它们的外部类的域。
 * 为了让类实现一个接口，通常需要下面两个步骤：
 * 1.将类生命为实现给定的接口
 * 2.对接口中的所有方法进行定义。
 * 要将类声明为实现某个接口，使用关键字implements。
 * 接口中的所有方法都自动是public，不过在实现接口时，必须把方法声明为public
 * @author wangda
 * @version v1.0 2013-10-28
 */
public class Chapter4 
{
	public void Content()
	{
		Employee[] staff = new Employee[3];
		
		staff[0] = new Employee("Carl Cracker", 75000, 1987, 12, 15);
		staff[1] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
		staff[2] = new Employee("Tony Tester", 40000, 1990, 3, 15);
		
		Arrays.sort(staff);
		
		// print out information about all Employee objects
		for (Employee e : staff)
			System.out.println(e);
		
		System.out.println("# Clone Test");
		try
		{
			Employee original = new Employee("John Q. Public", 50000);
			original.setHireDay(2000, 1, 1);
			Employee copy = original.clone();
			copy.raiseSalary(10);
			copy.setHireDay(2002, 12, 31);
			System.out.println("original=" + original);
			System.out.println("copy=" + copy);
		}
		catch (CloneNotSupportedException e)
		{
			e.printStackTrace();
		}
		
		System.out.println("# Static Inner Class Test");
		double[] d = new double[20];
		for (int i = 0; i < d.length; i++)
			d[i] = 100 * Math.random();
		ArrayAlg.Pair p = ArrayAlg.minmax(d);
		System.out.println("min = " + p.getFirst());
		System.out.println("max = " + p.getSecond());
		
		System.out.println("# I have to skip the proxy method here.");
		
		System.out.println("&&& Here is the End of Chapter 4! &&&");
	}
}
