#include "Weapon.h"

Weapon::Weapon(string name, int price)
{
	this->name = name;
	this->price = price;
}

void Weapon::PrintInfo() const
{
	cout << "[�̸�: " << name << ", ����: " << price << "G]" << endl;
}

int Weapon::GetPrice() const
{
	return price;
}
