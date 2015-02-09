package wdx.java.study;

/**
 * 由于不能构造抽象类的对象，对于抽象类方法的具体调用，会引用具体子类对象
 * @author wangda
 * @version v1.0 2013-10-27
 */
public class Student extends Person
{
	public Student(String n, String m)
	{
		// pass n to superclass constructor
		super(n);
		major = m;
	}
	
	@Override
	public String getDescription() 
	{
		return "a student majoring in " + major;
	}
	
	private String major;
}
