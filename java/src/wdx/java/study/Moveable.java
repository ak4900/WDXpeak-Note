package wdx.java.study;

/**
 * 接口不是类，尤其不能使用new运算符实例化一个接口
 * 尽管不能构造接口对象，却能声明接口的变量。
 * 接口变量必须引用实现了接口的类对象
 * @author wangda
 * @version v1.0 2013-10-28
 */
public interface Moveable 
{
	void move(double x, double y);
}
