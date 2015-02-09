package wdx.java.study;

/**
 * 包含一个或多个抽象方法的类本身必须被声明为抽象的。
 * 除了抽象方法之外，抽象类还可以包含具体数据和具体方法。
 * 抽象类不能被实例化。
 * 抽象方法充当着占位的角色。
 * @author wangda
 * @version v1.0 2013-10-27
 */
public abstract class Person 
{
	public Person(String n)
	{
		name = n;
	}
	
	public abstract String getDescription();
	
	public String getName()
	{
		return name;
	}
	
	private String name;
}
