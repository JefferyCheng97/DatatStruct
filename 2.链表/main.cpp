#include <iostream>
#include <stdexcept>

using namespace std;

#define eleType int

// 定义链接结构体节点
struct ListNode 
{
	eleType data;
	ListNode* next;
	ListNode(eleType x) :data(x), next(NULL) {}
};

// 定义链表类
class LinkedList
{
private:
	ListNode* head;
	int size;

public:
	LinkedList() :head(NULL), size(0) {}
	~LinkedList();

	void insert(int i, eleType value);
	void remove(int i);
	ListNode* find(eleType value);
	ListNode* get(int i);
	void update(int i, eleType value);
	void print();
};

LinkedList::~LinkedList()
{
	ListNode* curr = head;

	while (curr != NULL) 
	{
		ListNode* tmp = curr;
		curr = curr->next;
		delete tmp;
	}
}


// 在位置 i 插入值为 value 的元素
void LinkedList::insert(int i, eleType value) 
{
	if (i < 0 || i > size)
	{
		throw std::out_of_range("Invalid position");
	}

	ListNode* newNode = new ListNode(value);

	if (i == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		ListNode* curr = head;

		for (int j = 0; j < i - 1; j++)
		{
			curr = curr->next;
		}

		newNode->next = curr->next;
		curr->next = newNode;
	}

	++size;
}


// 删除位置 i 的元素
void LinkedList::remove(int i) 
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid position");
	}

	if (i == 0)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
	else 
	{
		ListNode* curr = head;

		for (int j = 0; j < i - 1; j++)
		{
			curr = curr->next;
		}

		ListNode* temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}

	--size;
}


// 查找值为 value 的元素，返回其节点指针
ListNode* LinkedList::find(eleType value) 
{
	ListNode* curr = head;

	while (curr && curr->data != value) 
	{
		curr = curr->next;
	}

	return curr;
}


// 获取位置 i 的节点指针
ListNode* LinkedList::get(int i)
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid position");
	}

	ListNode* curr = head;

	for (int j = 0; j < i; j++) 
	{
		curr = curr->next;
	}

	return curr;
}


// 更新位置 i 的元素值为 value
void LinkedList::update(int i, eleType value) 
{
	get(i)->data = value;
}


// 打印链表元素
void LinkedList::print() 
{
	ListNode* curr = head;

	while (curr) 
	{
		cout << curr->data << " ";
		curr = curr->next;
	}

	cout << endl;
}


int main() 
{
	LinkedList list;
	list.insert(0, 10);
	list.insert(1, 20);
	list.insert(2, 30);
	list.insert(3, 40);
	list.insert(4, 50);
	list.print();
}