package wdx.java.study;

import java.util.*;
import java.text.*;

/**
 * Java程序设计语言总是采用值调用，方法不能修改传递给它的任何参数变量的内容。
 * 1.一个方法不能修改一个基本数据类型的参数。
 * 2.一个方法可以改变一个对象参数的状态。
 * 一个方法不能实现让对象参数引用一个新的对象。
 * @author wangda
 * @version 1.0 2013-10-27
 */
public class Chapter2 
{
	public void Content()
	{
		System.out.println("# Use Class to solve complex problems");
		
		GregorianCalendar d = new GregorianCalendar();
		
		int today = d.get(Calendar.DAY_OF_MONTH);
		int month = d.get(Calendar.MONTH);
		
		// set d to start date of the month
		d.set(Calendar.DAY_OF_MONTH, 1);
		
		int weekday = d.get(Calendar.DAY_OF_WEEK);
		
		// get first day of week (Sunday)
		int firstDayOfWeek = d.getFirstDayOfWeek();
		
		// determine the required indentation for the first line
		int indent = 0;
		while (weekday != firstDayOfWeek)
		{
			indent++;
			d.add(Calendar.DAY_OF_MONTH, -1);
			weekday = d.get(Calendar.DAY_OF_WEEK);
		}
		
		// print weekday names
		String[] weekdayNames = new DateFormatSymbols().getShortWeekdays();
		do
		{
			System.out.printf("%4s", weekdayNames[weekday]);
			d.add(Calendar.DAY_OF_MONTH, 1);
			weekday = d.get(Calendar.DAY_OF_WEEK);
		}
		while (weekday != firstDayOfWeek);
		System.out.println();
		
		for (int i = 1; i <= indent; i++)
			System.out.print("    ");
		
		d.set(Calendar.DAY_OF_MONTH, 1);
		do
		{
			// print day
			int day = d.get(Calendar.DAY_OF_MONTH);
			System.out.printf("%3d", day);
			
			// mark current day with *
			if (day == today) System.out.print("*");
			else System.out.print(" ");
			
			// advance d to the next day
			d.add(Calendar.DAY_OF_MONTH, 1);
			weekday = d.get(Calendar.DAY_OF_WEEK);
			
			// start a new line at the start of week
			if (weekday == firstDayOfWeek) System.out.println(); 
		}
		while (d.get(Calendar.MONTH) == month);
		// the loop exits when d is the 1 of the next month
		
		// print final end of line if necessary
		if (weekday != firstDayOfWeek) System.out.println();
		
		System.out.println("# Use your own class");
		Employee[] staff = new Employee[3];
		
		staff[0] = new Employee("Carl Cracker", 75000, 1987, 12, 15);
		staff[1] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
		staff[2] = new Employee("Tony Tester", 40000, 1990, 3, 15);
		
		for (Employee e: staff)
			e.raiseSalary(5);
		
		for (Employee e: staff)
		{
			e.setId();
			System.out.println("name=" + e.getName() + ",salary=" + e.getSalary() + ",hireDay=" + e.getHireDay() + ",id=" + e.getId());
			
		}
		
		System.out.println("&&& Here is the End of Chapter 2! &&&");
	}

}
