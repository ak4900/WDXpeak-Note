package wdx.java.study;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * 用synchronized就可以不用显式获取锁
 * @author wangda
 *
 */

public class Bank 
{
	public Bank(int n, double initialBalance)
	{
		accounts = new double[n];
		for (int i = 0; i < accounts.length; i++)
			accounts[i] = initialBalance;
		bankLock = new ReentrantLock();
		sufficientFunds = bankLock.newCondition();
	}
	
	public synchronized void transfer(int from, int to, double amount) throws InterruptedException
	{
		while(accounts[from] < amount)
			wait();
		System.out.print(Thread.currentThread());
		accounts[from] -= amount;
		System.out.printf(" %10.2f from %d to %d", amount, from, to);
		accounts[to] += amount;
		System.out.printf(" Total Balance: %10.2f\n", getTotalBalance());
		notifyAll();
		
	}
	
	public synchronized double getTotalBalance()
	{
		double sum = 0;
		for (double a : accounts)
			sum += a;
		return sum;		
	}
	
	
	/*
	public void transfer(int from, int to, double amount)
	{
		bankLock.lock();
		try
		{
			while(accounts[from] < amount)
				try 
				{
					sufficientFunds.await();
				} 
				catch (InterruptedException e) 
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			System.out.print(Thread.currentThread());
			accounts[from] -= amount;
			System.out.printf(" %10.2f from %d to %d", amount, from, to);
			accounts[to] += amount;
			System.out.printf(" Total Balance: %10.2f\n", getTotalBalance());
			sufficientFunds.signalAll();
		}
		finally
		{
			bankLock.unlock();
		}
		
		
	}
	
	public double getTotalBalance()
	{
		bankLock.lock();
		try
		{
			double sum = 0;
			for (double a : accounts)
				sum += a;
			return sum;
		}
		finally
		{
			bankLock.unlock();
		}
	}
	*/
	
	public int size()
	{
		return accounts.length;
	}
	
	private final double[] accounts;
	private Lock bankLock;
	private Condition sufficientFunds;
}
