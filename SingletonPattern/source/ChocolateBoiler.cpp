#include "ChocolateBoiler.h"

using namespace std;


ChocolateBoiler::ChocolateBoiler(void): m_empty(true),m_boiled(false)
{
	cout<<"Make a ChocolateBoiler!"<<endl;
}


ChocolateBoiler::~ChocolateBoiler(void)
{
	cout<<"Destroy the ChocolateBoiler!"<<endl;
}
void ChocolateBoiler::fill()
{
	if (isEmpty())
	{
		m_empty = false;
		m_boiled = false;
		cout<<"Boiler is filled"<<endl;
		return;
	}
	cout<<"Boiler is already filled"<<endl;
}
void ChocolateBoiler::drain()		//ÅÅ³ö
{
	if (!isEmpty() && isBoiled())
	{
		m_empty = true; 
		cout<<"drain Coffee is OK"<<endl;
		return;
	}
	cout<<"Boiler is empty"<<endl;
}
void ChocolateBoiler::boil()		//Öó¿§·È
{
	if (!isEmpty() && !isBoiled())
	{
		m_boiled = true;
		cout<<"Coffee is Boiled"<<endl;
	}
}
bool ChocolateBoiler::isEmpty()
{
	return m_empty;
}
bool ChocolateBoiler::isBoiled()
{
	return m_boiled;
}

 
