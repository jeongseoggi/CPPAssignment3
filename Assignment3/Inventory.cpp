#include "Inventory.h"
#include "Item.h"
#include <algorithm>

using namespace std;

template class Inventory<Item*>;

template<typename T>
Inventory<T>::Inventory(int capacity)
{
	capacity = capacity <= 0 ? 1 : capacity; // 0 ������ ���� ����

	this->capacity = capacity;
	size = 0;
	pItems = new T[capacity]; // �迭 �����Ҵ�
}

/// <summary>
/// ���� ������ -> ��ü ���� �� �ʱ�ȭ �ÿ� ����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="other"></param>
template<typename T>
Inventory<T>::Inventory(const Inventory<T>& other)
{
	capacity = other.capacity;
	size = other.size;
	pItems = new T[capacity];

	for (int i = 0; i < size; ++i) 
	{
		pItems[i] = other.pItems[i];
	}
	cout << "�κ��丮 ���� �Ϸ�" << endl;
}

/// <summary>
/// ������ �߰� �Լ� -> size�� �ʰ� �� ���� ũ���� 2�� �迭 ���Ҵ� �� ������ �ֱ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="item"></param>
template<typename T>
void Inventory<T>::AddItem(const T& item)
{
	if (size < capacity)
	{
		pItems[size] = item;
	}
	else
	{
		Resize(capacity * 2);
		T* newItems = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			newItems[i] = pItems[i];
		}

		delete[] pItems;
		newItems[size] = item;
		pItems = newItems;
	}
	size++;
}

/// <summary>
/// �迭�� ������ ���� ���� �Լ� -> size�� �ٿ� �������� ���ϰ� ���� (������ �����ϴ� ���� �ƴ�)
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Inventory<T>::RemoveLastItem()
{
	if (size <= 0)
	{
		cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
	}
	else
	{
		size--;
	}
}

/// <summary>
/// ������ ũ�� ���� �Լ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
int Inventory<T>::GetSize() const
{
	return size;
}

/// <summary>
/// Capacity ũ�� ���� �Լ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
int Inventory<T>::GetCapacity() const
{
	return capacity;
}

/// <summary>
/// ��� �Լ�
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Inventory<T>::PrintAllItems() const
{
	if (size <= 0)
	{
		cout << "(�������)" << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			pItems[i]->PrintInfo();
		}
	}

}

/// <summary>
/// �̹� ������� ��ü�� �κ��丮 ���� �� ȣ��Ǵ� �Լ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="other"></param>
template<typename T>
void Inventory<T>::Assign(const Inventory<T>& other)
{
	capacity = other.capacity;
	size = other.size;
	pItems = new T[capacity];

	for (int i = 0; i < size; ++i)
	{
		pItems[i] = other.pItems[i];
	}
	cout << "�κ��丮 ���� �Ϸ�" << endl;
}

/// <summary>
/// capacity ������ ����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="newCapacity"></param>
template<typename T>
void Inventory<T>::Resize(int newCapacity)
{
	capacity = newCapacity;
}

/// <summary>
/// �������� ����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
template<typename T>
bool compareItemsByPrice(const T& a, const T& b)
{
	return a->GetPrice() < b->GetPrice();
}

/// <summary>
/// ���� �Լ�
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Inventory<T>::SortItems()
{
	sort(pItems, pItems + size, compareItemsByPrice<T>);
}


template<typename T>
Inventory<T>::~Inventory()
{
	delete[] pItems;  // �޸� ����
	pItems = nullptr; // �������� ���� nullptr
}

