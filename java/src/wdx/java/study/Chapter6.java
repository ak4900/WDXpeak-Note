package wdx.java.study;

public class Chapter6 
{
	public static final int NACCOUNTS = 100;
	public static final double INITIAL_BALANCE = 1000;
	
	public void Content()
	{
		
		System.out.println("Unsync Bank Test");
		Bank b = new Bank(NACCOUNTS, INITIAL_BALANCE);
		int i;
		for (i = 0; i < NACCOUNTS; i++)
		{
			TransferRunnable r = new TransferRunnable(b, i, INITIAL_BALANCE);
			Thread t = new Thread(r);
			t.start();
		}
		
		
		System.out.println("&&& Here is the End of Chapter 6! &&&");
	}
}
