/*
用对象指针来调用一个函数，有以下两种情况：

如果是虚函数，会调用派生类中的版本。

如果是非虚函数，会调用指针所指类型的实现版本。

析构函数也会遵循以上两种情况，因为析构函数也是函数嘛，不要把它看得太特殊。 当对象出了作用域或是我们删除对象指针，析构函数就会被调用。

当派生类对象出了作用域，派生类的析构函数会先调用，然后再调用它父类的析构函数， 这样能保证分配给对象的内存得到正确释放。

但是，如果我们删除一个指向派生类对象的基类指针，而基类析构函数又是非虚的话， 那么就会先调用基类的析构函数(上面第2种情况)，派生类的析构函数得不到调用。

如果我们把基类的析构函数声明为虚析构函数，这会使得所有派生类的析构函数也为虚。 从而使析构函数得到正确调用。

因此，如果我们可能会删除一个指向派生类的基类指针时，应该把析构函数声明为虚函数。 事实上，《Effective C++》中的观点是，只要一个类有可能会被其它类所继承， 就应该声明虚析构函数。

*/

class Base{
public:
    Base() { cout<<"Base Constructor"<<endl; }
    ~Base() { cout<<"Base Destructor"<<endl; }
};
class Derived: public Base{
public:
    Derived() { cout<<"Derived Constructor"<<endl; }
    ~Derived() { cout<<"Derived Destructor"<<endl; }
};
int main(){
    Base *p = new Derived();
    delete p;
    return 0;
}