package wdx.java.study;

import java.util.*;

public class Welcome 
{

	private static Scanner in;

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		String[] greeting = new String[3];
		greeting[0] = "Welcome to wdxtub's Java-Study Project.";
		greeting[1] = "I hope you enjoy this project-based course!";
		greeting[2] = "Want more? visit wdxtub.github.io";
		
		for(String g : greeting)
		{
			System.out.println(g);
		}
		
		// The list of chapters
		Chapter1 c1 = new Chapter1();
		Chapter2 c2 = new Chapter2();
		Chapter3 c3 = new Chapter3();
		Chapter4 c4 = new Chapter4();
		Chapter5 c5 = new Chapter5();
		Chapter6 c6 = new Chapter6();
		
		// flag for exit.
		boolean flag = true;
		
		while(flag)
		{
			in = new Scanner(System.in);
			
			// This is where you choose chapters
			System.out.println("#>---------------------------------<#");
			System.out.println("   Category of the project:");
			System.out.println("   1.Bases of Java Programming.");
			System.out.println("   2.Object and Class.");
			System.out.println("   3.Inheritance.");
			System.out.println("   4.Interface and Inner Class");
			System.out.println("   5.Collections");
			System.out.println("   6.Multi Treads");
			System.out.println("   0.Exit the project.");
			System.out.print("   Input number to select chapter:");
			int index = in.nextInt();
			System.out.println("#>---------------------------------<#");
			switch(index)
			{
			case 1:
				c1.Content();
				break;
			case 2:
				c2.Content();
				break;
			case 3:
				c3.Content();
				break;
			case 4:
				c4.Content();
				break;
			case 5:
				c5.Content();
				break;
			case 6:
				c6.Content();
				break;
			default:
				flag = false;
				break;
			}
		}
		System.out.println("Thanks for your attention!");
	}

}
