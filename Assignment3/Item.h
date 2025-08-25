#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item
{
public:
	virtual void PrintInfo() const;
	virtual ~Item();
	virtual int GetPrice() const;

protected:
	string name;
	int price;
};