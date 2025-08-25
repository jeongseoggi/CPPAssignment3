#pragma once
#include "Item.h"
class Potion : public Item
{
public:
	Potion(string name, int price);
	virtual void PrintInfo() const override;
	int GetPrice() const override;
};

