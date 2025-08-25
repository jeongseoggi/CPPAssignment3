#include "Inventory.h"
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include <iostream>

using namespace std;

int main()
{
	Inventory<Item*>* inventory = new Inventory<Item*>(4);
	Inventory<Item*>* inventory2 = new Inventory<Item*>(4);

	Weapon* sword = new Weapon("八", 200);
	Weapon* armor = new Weapon("规绢备", 300);
	Potion* hpPotion = new Potion("HP 器记", 15);
	Potion* mpPoiton = new Potion("MP 器记", 15);

	inventory->AddItem(sword);
	inventory->AddItem(armor);
	inventory->AddItem(hpPotion);
	inventory->AddItem(mpPoiton);
	inventory->AddItem(mpPoiton);

	inventory->PrintAllItems();

	cout << "----------------" << endl;



	inventory2->Assign(*inventory);
	inventory2->PrintAllItems();
	inventory2->SortItems();
	cout << "----------------" << endl;
	inventory2->PrintAllItems();

	return 0;
}