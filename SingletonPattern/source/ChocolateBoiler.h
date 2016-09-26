#pragma once
#include <iostream>
class ChocolateBoiler
{
private:
	ChocolateBoiler(void);
	static ChocolateBoiler *singletonBoiler; //声明
public:	
	~ChocolateBoiler(void);
	static ChocolateBoiler* getInstance()
	{	
		//static ChocolateBoiler *singletonBoiler;
		if (NULL == singletonBoiler)
		{
			singletonBoiler = new ChocolateBoiler();
		}
		return singletonBoiler;
	}
	
public:
	void fill();		//添加原料
	void drain();		//排出
	void boil();		//煮咖啡
	bool isEmpty();
	bool isBoiled();
private:
	bool m_empty;
	bool m_boiled;	
};




