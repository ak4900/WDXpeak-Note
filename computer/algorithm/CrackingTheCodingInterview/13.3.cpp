/*
虚函数依赖虚函数表进行工作。如果一个类中，有函数被关键词virtual进行修饰， 那么一个虚函数表就会被构建起来保存这个类中虚函数的地址。同时， 编译器会为这个类添加一个隐藏指针指向虚函数表。如果在派生类中没有重写虚函数， 那么，派生类中虚表存储的是父类虚函数的地址。每当虚函数被调用时， 虚表会决定具体去调用哪个函数。因此，C++中的动态绑定是通过虚函数表机制进行的。

当我们用基类指针指向派生类时，虚表指针vptr指向派生类的虚函数表。 这个机制可以保证派生类中的虚函数被调用到。

C++中非虚函数的调用是在编译期静态绑定的， 而虚函数的调用则是在执行时才进行动态绑定。
*/

class Shape{
public:
    int edge_length;
    virtual int circumference () {
        cout<<"Circumference of Base Class\n";
        return 0;
    }
};
class Triangle: public Shape{
public:
    int circumference () {
        cout<<"Circumference of Triangle Class\n";
        return 3 * edge_length;
    }
};
int main(){
    Shape *x = new Shape();
    x->circumference(); // prints “Circumference of Base Class”
    Shape *y = new Triangle();
    y->circumference(); // prints “Circumference of Triangle Class”
    return 0;
}