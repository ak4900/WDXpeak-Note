package wdx.java.study;

import static java.lang.Math.*;

import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

/**
 * 这里是添加注释的地方，通常来说这种使用/*的地方是用来写大段的注释的，如果
 * 需要对于一行进行注释，那么使用//
 * @author wangda
 * @version 1.0 2013-10-26
 */

public class Chapter1 
{
	// 使用static final可以声明一个不能够更改的类常量，习惯上名称使用大写，
	// 它们可以在一个类中的多个方法中使用
	public static final String DESCRIPTION = "Bases of Java Programming.";
	private Scanner in;
	
	/**
	 * 对于之后每个以Chapter*为名称的类，都会有这样一个Content函数，实际上
	 * 就是所有教程的显示内容。
	 */
	public void Content()
	{
		System.out.println("# Math Function");
		double x = 4;
		double y = sqrt(x);
		System.out.println("sqrt(4)=" + y);
		
		double a = 2;
		y = pow(x,a);
		System.out.println("pow(4,2)=" + y);
		
		a = 0.5;
		y = pow(x,a);
		System.out.println("pow(4,0.5)=" + y);
		
		a = PI/6;
		y = sin(a);
		System.out.println("sin(PI/6)=" + y);
		
		a = PI/3;
		y = sin(a);
		System.out.println("cos(PI/3)=" + y);
		
		a = PI/2;
		y = tan(a);
		System.out.println("tan(PI/2)=" + y);
		
		a = 100;
		y = log(a);
		System.out.println("log(100)=" + y);
		
		System.out.println("# String Operations");
		String greeting = "Hello World";
		System.out.println("original string: " + greeting);
		
		String s = greeting.substring(0,5);
		System.out.println("substring(0,5): " + s);
		
		System.out.println("equals method to check if the strings are the same:"+ "hello".equals(s));
		System.out.println("equalsIgnoreCase method: " + "hello".equalsIgnoreCase(s));
		
		System.out.println("charAt(2): " + greeting.charAt(2));
		System.out.println("indexof('l'): " + greeting.indexOf("l"));
		System.out.println("lastIndexOf('l'): " + greeting.lastIndexOf("l"));
		
		System.out.println("length(): " + greeting.length());
		System.out.println("toLowerCase(): " + greeting.toLowerCase());
		System.out.println("toUpperCase(): " + greeting.toUpperCase());
		System.out.println("trim(): " + greeting.trim());
		
		System.out.println("# Use StringBuilder to build string");
		StringBuilder builder = new StringBuilder();
		builder.append("wdx");
		System.out.println("builder: " + builder.toString());
		
		builder.append("tub");
		System.out.println("builder: " + builder.toString());
		
		System.out.println("# Formatted Output");
		x = 22.2222222;
		System.out.printf("%.2f\n", x);
		System.out.printf("%tc", new Date());
		
		System.out.println("# While Loop Statement");
		in = new Scanner(System.in);
		System.out.print("How much money do you need to retire? ");
		double goal = in.nextDouble();
		System.out.print("How much money will you contribute every year? ");
		double payment = in.nextDouble();
		
		double balance = 0;
		int years = 0;
		double interestRate = 3.5;
		
		while (balance < goal)
		{
			balance += payment;
			double interest = balance * interestRate / 100;
			balance += interest;
			years++;
		}
		System.out.println("You can retire in " + years + " years.");
		
		System.out.println("# For Loop Statement");
		System.out.print("How many numbers do you need to draw? ");
		int k = in.nextInt();
		
		System.out.print("What is the highest number you can draw? ");
		int n = in.nextInt();
		
		int lotteryOdds = 1;
		for (int i = 1; i <= k; i++)
			lotteryOdds = lotteryOdds * (n - i + 1) / i;
		
		System.out.println("Your odds are 1 " + lotteryOdds + ". Good luck!");
		
		System.out.println("# Arrays and its Operations");
		int[] array = new int[100]; // you can't change its size after creating it
		for (int i = 0; i < 100; i++)
		{
			array[i] = i+1;
		}
		
		System.out.println("Use for each to output array");
		for (int e : array)
		{
			System.out.print(e + " ");
		}
		System.out.println();
		
		System.out.println("Array with two dimension");
		int[][] magicSquare = 
			{
				{16, 3, 2, 13},
				{5, 10, 11, 8},
				{9, 6, 7, 12},
				{4, 15, 14, 1}
			};
		System.out.println(Arrays.deepToString(magicSquare));
		
		System.out.println("&&& Here is the End of Chapter 1! &&&");
	}
}
