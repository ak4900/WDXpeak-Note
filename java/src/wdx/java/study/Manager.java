package wdx.java.study;


/**
 * "is-a" 关系是继承的一个明显特征，关键字extends表示继承。
 * 超类中的有些方法对子类并不一定适用，需要提供新的方法覆盖（override）
 * 要调用超类中的方法，使用super关键字
 * 利用继承可以实现多态，一个对象变量可以引用多种实际类型。
 * 在运行时能够自动地选择调用哪个方法，称为动态绑定。
 * @author wangda
 * @version v1.0 2013.10.27
 */
public class Manager extends Employee
{

	public Manager(String n, double s, int year, int month, int day) 
	{
		super(n, s, year, month, day);
		bonus = 0;
	}
	
	public double getSalary()
	{
		double baseSalary = super.getSalary();
		return baseSalary + bonus;
	}
	
	public void setBonus(double b)
	{
		bonus = b;
	}
	
	public boolean equals(Object otherObject)
	{
		if (!super.equals(otherObject)) return false;
		Manager other = (Manager) otherObject;
		// super.equals checked that this and other belong to the same class
		return bonus == other.bonus;
	}
	
	public int hashCode()
	{
		return super.hashCode() + 17 * new Double(bonus).hashCode();
	}
	
	public String toString()
	{
		return super.toString() + "[bonus=" + bonus + "]"; 
	}
	
	private double bonus;
}
