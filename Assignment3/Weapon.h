#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(string name, int price);
	virtual void PrintInfo() const override;
	int GetPrice() const override;

};

