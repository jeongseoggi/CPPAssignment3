#include "Inventory.h"
#include "Item.h"
#include <algorithm>

using namespace std;

template class Inventory<Item*>;

template<typename T>
Inventory<T>::Inventory(int capacity)
{
	capacity = capacity <= 0 ? 1 : capacity; // 0 이하의 숫자 보정

	this->capacity = capacity;
	size = 0;
	pItems = new T[capacity]; // 배열 동적할당
}

/// <summary>
/// 복사 연산자 -> 객체 생성 및 초기화 시에 사용됨
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
	cout << "인벤토리 복사 완료" << endl;
}

/// <summary>
/// 아이템 추가 함수 -> size가 초과 시 현재 크기의 2배 배열 재할당 후 아이템 넣기
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
/// 배열의 마지막 원소 삭제 함수 -> size를 줄여 접근하지 못하게 막음 (실제로 삭제하는 것은 아님)
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Inventory<T>::RemoveLastItem()
{
	if (size <= 0)
	{
		cout << "인벤토리가 비어있습니다." << endl;
	}
	else
	{
		size--;
	}
}

/// <summary>
/// 사이즈 크기 리턴 함수
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
int Inventory<T>::GetSize() const
{
	return size;
}

/// <summary>
/// Capacity 크기 리턴 함수
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
int Inventory<T>::GetCapacity() const
{
	return capacity;
}

/// <summary>
/// 출력 함수
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Inventory<T>::PrintAllItems() const
{
	if (size <= 0)
	{
		cout << "(비어있음)" << endl;
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
/// 이미 만들어진 객체에 인벤토리 대입 시 호출되는 함수
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
	cout << "인벤토리 복사 완료" << endl;
}

/// <summary>
/// capacity 사이즈 변경
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="newCapacity"></param>
template<typename T>
void Inventory<T>::Resize(int newCapacity)
{
	capacity = newCapacity;
}

/// <summary>
/// 오름차순 정렬
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
/// 정렬 함수
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
	delete[] pItems;  // 메모리 해제
	pItems = nullptr; // 안정성을 위해 nullptr
}

