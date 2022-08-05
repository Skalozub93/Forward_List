#include <iostream>
using namespace std;

template <typename T>
class Forward_List
{
	class Node {
	public:
		Node* next = nullptr;
		T data;
	};

	Node* head = nullptr;
	int size = 0;

public:

	Forward_List() {};
	Forward_List(Forward_List& other);
	Forward_List(Forward_List&& other);
	~Forward_List();

	void PushFront(const T& data); // Вставка элемента в начало 
	void PushBack(const T&data); // Вставка  элемента в конец
	void PushByIndex(int index, const T& data); // вставка элемента по индексу
	void PopByIndex(int index); // удаление элемента по индексу
	void PopFront(); // удаление элемента в начале
	void PopBack(); // удаление элемента в конце 
	void SortAsc(); // сортировка элементов в возрастанию 
	void SortDesc(); // сортировка элементов по убыванию
	int GetSize() const; // получение размера
	void Print(); // вывод на экран консоли

	T& operator[](int index);
	Forward_List& operator=(Forward_List& other);
	bool operator==(Forward_List& other);
	bool operator!=(Forward_List& other);

};


template<typename T>
Forward_List<T>::Forward_List(Forward_List& other)
{
	for (int i = other.size - 1; i >= 0; i--)
		this->PushFront(other[i]);
}

template<typename T>
Forward_List<T>::Forward_List(Forward_List&& other) 
{
	size = other.size;
	head = other.head;
	other.head = nullptr;
}

template<typename T>
Forward_List<T>::~Forward_List() 
{
	while (size > 0) PopFront();
}

template<typename T>
void Forward_List<T>::PushFront(const T& data)  
{
	if (head == nullptr) {
		head = new Node();
		head->data = data;
	}
	else {
		Node* temporary = new Node();
		temporary->next = head;
		temporary->data = data;
		head = temporary;
	}
	size++;
}

template <typename T>
void Forward_List<T>::PushBack(const T& data)
{
	PushByIndex(size - 1, data);
}

template <typename T>
void Forward_List<T>::PushByIndex(int index, const T& data)
{
	if (index < 0 || index >= size)
		throw "incorrect index!";

	Node* temporary = head;
	int ind;

	while (ind != index)
	{
		temporary = temporary->next;
		ind++;
	}

	Node* node = new Node();
	node->data = data;
	node->next = temporary->next;
	temporary->next = node;
	size++;

}

template <typename T>
void Forward_List<T>::PopByIndex(int index)
{
	if (index < 0 || index >= size - 1) 
		throw "incorect index!!!";
	Node* temporary = head;
	int _index = 0;

	while (_index != index) {
		temporary = temporary->next;
		_index++;
	}
	Node* copy = temporary->next;
	temporary->next = copy->next;
	delete copy;
	size--;
}
template <typename T>
void Forward_List<T>::PopFront()
{
	if (head->next == nullptr )
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node* temporary = head->next;
		delete head;
		head = temporary;
	}
	size--;
}

template <typename T>
void Forward_List<T>::PopBack()
{
	PushByIndex(size - 2);
}

template <typename T>
void Forward_List<T>::SortAsc()
{
	for (int i = 0; i < size - 1; i++)
	{
		Node* one = head;
		Node* two = one->next;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (one->data > two->data)
			{
				swap(one->data, two->data);
			}
			one = one->next;
			two = two->next;
		}
	}
}

template <typename T>
void Forward_List<T>::SortDesc()
{
	for (int i = 0; i < size - 1; i++)
	{
		Node* one = head;
		Node* two = one->next;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (one->data < two->data)
			{
				swap(one->data, two->data);
			}
			one = one->next;
			two = two->next;
		}
	}
}

template <typename T>
int Forward_List<T>::GetSize() const
{
	return size;
}

template <typename T>
void Forward_List<T>::Print()
{
	Node* temporary = head;
	while (temporary != nullptr)
	{
		cout << temporary->data << " ";
		temporary = temporary->next;
	}
	cout << "\n";
	
}

template<typename T>
T& Forward_List<T>::operator[](int index)  // перегрузка оператора []
{
	if (index < 0 || index >= size)
		throw "incorect index!!!";
	Node* temp = head;
	int _index = 0;

	while (_index != index) {
		temp = temp->next;
		_index++;
	}
	return temp->data;
}

template<typename T>
Forward_List<T>& Forward_List<T>::operator=(Forward_List& other)
{
	if (this == &other) return *this;
	for (int i = other.size - 1; i >= 0; i--)
		this->push_front(other[i]);
	return *this;
}

template<typename T>
bool Forward_List<T>::operator==(Forward_List& other)
{
	if (size != other.size) return false;

	Node* begin = head;
	Node* end = other.head;

	while (begin != nullptr) {
		if (begin->data != end->data) return false;
		begin = begin->next;
		end = end->next;
	}
	return true;
}

template<typename T>
bool Forward_List<T>::operator!=(Forward_List& other)
{
	if (*this == other) return false;
	return true;
}

int main()
{
	Forward_List<int> FW;
	FW.PushFront(23);
	FW.PushFront(31);
	FW.PushFront(78);
	FW.PushFront(11);
	FW.PushFront(3);
	FW.PushFront(7);
	FW.Print();

	FW.SortAsc();

	FW.Print();

	FW.SortDesc();
	
	FW.Print();



}

