#include "Potion.h"

Potion::Potion(string name, int price)
{
	this->name = name;
	this->price = price;
}

void Potion::PrintInfo() const
{
	cout << "[�̸�: " << name << ", ����: " << price << "G]" << endl;
}
 
int Potion::GetPrice() const
{
	return price;
}
