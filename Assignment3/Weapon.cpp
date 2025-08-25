#include "Weapon.h"

Weapon::Weapon(string name, int price)
{
	this->name = name;
	this->price = price;
}

void Weapon::PrintInfo() const
{
	cout << "[이름: " << name << ", 가격: " << price << "G]" << endl;
}

int Weapon::GetPrice() const
{
	return price;
}
