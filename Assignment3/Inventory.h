#pragma once

template<typename T>
class Inventory
{
public:
	Inventory(int capacity = 10);
	Inventory(const Inventory<T>& other);
	void AddItem(const T& item);
	void RemoveLastItem();
	int GetSize() const;
	int GetCapacity() const;
	void PrintAllItems() const;
	void Assign(const Inventory<T>& other);
	void Resize(int newCapacity);
	void SortItems();
	~Inventory();
private:
	T* pItems;
	int capacity;
	int size;

};




