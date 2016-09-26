#pragma once
#include <iostream>
class ChocolateBoiler
{
private:
	ChocolateBoiler(void);
	//static ChocolateBoiler *singletonBoiler; //������������ʾ���Ӵ���
public:	
	~ChocolateBoiler(void);
	static ChocolateBoiler* getInstance()
	{	
		static ChocolateBoiler *singletonBoiler;
		if (NULL == singletonBoiler)
		{
			singletonBoiler = new ChocolateBoiler();
		}
		return singletonBoiler;
	}
	
public:
	void fill();		//���ԭ��
	void drain();		//�ų�
	void boil();		//�󿧷�
	bool isEmpty();
	bool isBoiled();
private:
	bool m_empty;
	bool m_boiled;	
};
//const SingletonStatic* SingletonStatic::m_instance = new SingletonStatic;



