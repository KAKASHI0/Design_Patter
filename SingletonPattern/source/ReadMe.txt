class Singelton{
static ChocolateBoiler* getInstance();

private:
static ChocolateBoiler *singletonBoiler;

}
Singelton* Singelton::*singletonBoiler=NULL;


static ChocolateBoiler* getInstance()
	{
		if (NULL == singletonBoiler)
		{
			singletonBoiler = new ChocolateBoiler();
		}
		return singletonBoiler;
	}

错误：定义为类的私有静态成员变量 编译不过 显示连接错误 
解决：c++中静态成员变量要在类外部再定义,否则产生link2001错误.


注意：
静态成员函数不能调用非静态数据成员


1、static成员的所有者是类本身和对象，但是多有对象拥有一样的静态成员。从而在定义对象是不能通过构造函数对其进行初始化。
2、静态成员不能在类定义里边初始化，只能在class body外初始化。
3、静态成员仍然遵循public，private，protected访问准则。
4、静态成员函数没有this指针，它不能返回非静态成员，因为除了对象会调用它外，类本身也可以调用。
 
静态成员函数可以直接访问该类的静态数据和函数成员，而访问非静态数据成员必须通过参数传递的方式得到一个对象名，然后通过对象名来访问。




1、静态成员实例的懒汉模式：

复制代码
 1 class Singleton
 2 {
 3 private:
 4     static Singleton* m_instance;
 5     Singleton(){}
 6 public:
 7     static Singleton* getInstance();
 8 };
 9 
10 Singleton* Singleton::getInstance()
11 {
12     if(NULL == m_instance)
13     {
14         Lock();//借用其它类来实现，如boost
15         if(NULL == m_instance)
16         {
17             m_instance = new Singleton;
18         }
19         UnLock();
20     }
21     return m_instance;
22 }
复制代码
2、内部静态实例的懒汉模式

这里需要注意的是，C++0X以后，要求编译器保证内部静态变量的线程安全性，可以不加锁。但C++ 0X以前，仍需要加锁。

复制代码
 1 class SingletonInside
 2 {
 3 private:
 4     SingletonInside(){}
 5 public:
 6     static SingletonInside* getInstance()
 7     {
 8         Lock(); // not needed after C++0x
 9         static SingletonInside instance;
10         UnLock(); // not needed after C++0x
11         return instance; 
12     }
13 };
复制代码
二、饿汉模式：即无论是否调用该类的实例，在程序开始时就会产生一个该类的实例，并在以后仅返回此实例。

由静态初始化实例保证其线程安全性，WHY？因为静态实例初始化在程序开始时进入主函数之前就由主线程以单线程方式完成了初始化，不必担心多线程问题。

故在性能需求较高时，应使用这种模式，避免频繁的锁争夺。

复制代码
 1 class SingletonStatic
 2 {
 3 private:
 4     static const SingletonStatic* m_instance;
 5     SingletonStatic(){}
 6 public:
 7     static const SingletonStatic* getInstance()
 8     {
 9         return m_instance;
10     }
11 };
12 
13 //外部初始化 before invoke main
14 const SingletonStatic* SingletonStatic::m_instance = new SingletonStatic;

