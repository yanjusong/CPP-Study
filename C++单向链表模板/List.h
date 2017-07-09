#pragma once

#define u_int unsigned int 

template <class T>
class Node {
public:
	Node();
	Node(const T &value);

	T m_value;
	Node *m_next;
};

template <class T>
class List {
	template<class T>
	friend ostream& operator<<(ostream &os, List<T> li);
public:
	List();
	List(const List<T> &other);
	List<T> &operator=(const List<T> &other);
	~List();

	bool empty() const;
	u_int size() const;

	T front() const;
	T back() const;

	void push_back(const T &value);
	void push_front(const T &value);
	void pop_front();
	void pop_back();

	void clear();
	void remove(u_int index);
	void insert(u_int index, const T &value);

	void reverse();
	void sort();
	bool find(const T& value) const;
	u_int count(const T& value) const;
	bool modify(u_int index, const T &value);
	void printList() const;
private:
	void swap(Node<T> *lhs, Node<T> *rhs); // 假交换

private:
	u_int m_cnt;
	Node<T> *m_head;
	Node<T> *m_rear;
};

template<class T>
List<T>::List()
	: m_head(NULL)
	, m_rear(NULL)
	, m_cnt(0)
{
}

template<class T>
List<T>::List(const List<T>& other)
{
	m_head = m_rear = NULL;
	m_cnt = 0;

	Node<T> *tmpNode = other.m_head;
	
	while (tmpNode) {
		push_back(tmpNode->m_value);
		tmpNode = tmpNode->m_next;
	}
}

template<class T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this != &other) {
		clear();
		Node<T> *tmpNode = other.m_head;
		while (tmpNode) {
			push_back(tmpNode->m_value);
			tmpNode = tmpNode->m_next;
		}
	}
	return *this;
}

template<class T>
List<T>::~List()
{
	Node<T> *tmpNode;
	while (m_head) {
		tmpNode = m_head->m_next;
		delete m_head;
		m_head = tmpNode;
	}
}

template<class T>
bool List<T>::empty() const
{
	return (m_cnt == 0 ? true : false);
}

template<class T>
u_int List<T>::size() const
{
	return m_cnt;
}

template<class T>
T List<T>::front() const
{
	return m_head->m_value;
}

template<class T>
T List<T>::back() const
{
	return m_rear->m_value;
}

template<class T>
void List<T>::push_back(const T & value)
{
	Node<T> *node = new Node<int>(value);
	if (m_head == NULL && m_rear == NULL) {
		m_head = m_rear = node;
	}
	else {
		m_rear->m_next = node;
		m_rear = node;
	}
	++m_cnt;
}

template<class T>
void List<T>::push_front(const T & value)
{
	Node<T> *tmpNode = new Node<T>(value);

	if (m_head == NULL && m_rear == NULL) {
		m_head = m_rear = tmpNode;
	}
	else {
		tmpNode->m_next = m_head;
		m_head = tmpNode;
	}

	++m_cnt;
}

template<class T>
void List<T>::pop_front()
{
	if (m_head == NULL) {
		return;
	}

	if (m_head == m_rear) {
		delete m_head;
		m_head = m_rear = NULL;
	}
	else {
		Node<int> *tmpNode = m_head;
		m_head = m_head->m_next;
		delete tmpNode;
	}

	--m_cnt;
}

template<class T>
void List<T>::pop_back()
{
	if (m_head == NULL) {
		return;
	}

	remove(m_cnt);
}

template<class T>
void List<T>::clear()
{
	Node<int> *tmpNode = m_head;
	while (m_head) {
		tmpNode = m_head->m_next;
		delete m_head;
		m_head = tmpNode;
	}
	m_head = m_rear = NULL;
	m_cnt = 0;
}

template<class T>
void List<T>::remove(u_int index)
{
	if (index <= 0 || m_cnt == 0) {
		return;
	}

	if (index > m_cnt) {
		return;
	}

	int i = 1;
	Node<int> *preHead = new Node<int>(-1);
	Node<int> *ph = preHead;
	preHead->m_next = m_head;
	while (i < index) {
		preHead = preHead->m_next;
		++i;
	}

	// 删除的节点同时是头节点和尾节点
	if (preHead->m_next == m_head && preHead->m_next == m_rear) {
		delete m_head;
		m_head = m_rear = NULL;
		--m_cnt;

		delete ph;
		return;
	}

	// 删除的节点是头节点
	if (preHead->m_next == m_head) {
		std::cout << "删除的节点是头节点" << std::endl;
		m_head = m_head->m_next;
		delete (preHead->m_next);
		--m_cnt;

		delete ph;
		return;
	}

	// 删除的节点是尾节点
	if (preHead->m_next == m_rear) {
		std::cout << "删除的节点是尾节点" << std::endl;
		delete m_rear;
		m_rear = preHead;
		m_rear->m_next = NULL;
		--m_cnt;

		delete ph;
		return;
	}

	Node<T> *tmpNode = preHead->m_next;
	preHead->m_next = preHead->m_next->m_next;
	delete tmpNode;

	delete ph;
	--m_cnt;
}

template<class T>
void List<T>::insert(u_int index, const T &value)
{
	if (index <= 0) {
		return;
	}

	if (index > m_cnt + 1) {
		return;
	}

	if (index == m_cnt + 1) {
		push_back(value);
		return;
	}

	Node<T> *preHead = new Node<T>(-1);
	preHead->m_next = m_head;
	Node<T> *ph = preHead;
	int i = 1;

	while (i < index) {
		preHead = preHead->m_next;
		++i;
	}

	Node<T> *insertNode = new Node<T>(value);

	insertNode->m_next = preHead->m_next;
	preHead->m_next = insertNode;

	if (insertNode->m_next == m_head) {
		m_head = insertNode;
	}

	++m_cnt;
	delete ph;
}

template<class T>
void List<T>::reverse()
{
	if (m_cnt == 1 || m_head == NULL) {
		return;
	}

	Node<T> *preHead = new Node<T>(-1);
	preHead->m_next = m_head;
	Node<T> *curNode = m_head->m_next;
	m_rear = m_head;
	m_rear->m_next = NULL;

	while (curNode) {
		Node<T> *tmpNode = curNode->m_next;
		curNode->m_next = preHead->m_next;
		preHead->m_next = curNode;
		curNode = tmpNode;
	}

	m_head = preHead->m_next;
	delete preHead;
}

template<class T>
void List<T>::sort()
{
	Node<T> *curNode = m_head;
	Node<T> *tmpNode = NULL;

	while (curNode->m_next) {
		tmpNode = curNode;
		Node<T> *maxNode = tmpNode;
		while (tmpNode) {
			if (tmpNode->m_value < maxNode->m_value) {
				maxNode = tmpNode;
			}
			tmpNode = tmpNode->m_next;
		}
		swap(curNode, maxNode);

		curNode = curNode->m_next;
	}
}

template<class T>
bool List<T>::find(const T & value) const
{
	Node<T> *curNode = m_head;
	while (curNode) {
		if (curNode->m_value == value) {
			return true;
		}
		curNode = curNode->m_next;
	}
	return false;
}

template<class T>
u_int List<T>::count(const T & value) const
{
	Node<T> *curNode = m_head;
	u_int res = 0;
	while (curNode) {
		if (curNode->m_value == value) {
			++res;
		}
		curNode = curNode->m_next;
	}
	return res;
}

template<class T>
bool List<T>::modify(u_int index, const T & value)
{
	if (index <= 0 || index > m_cnt) {
		return false;
	}

	Node<T> *curNode = m_head;
	int i = 1;
	while (curNode) {
		if (i == index) {
			curNode->m_value = value;
			break;
		}
		curNode = curNode->m_next;
	}

	return true;
}

template<class T>
void List<T>::swap(Node<T>* lhs, Node<T>* rhs)
{
	T tmp = lhs->m_value;
	lhs->m_value = rhs->m_value;
	rhs->m_value = tmp;
}

template<class T>
void List<T>::printList() const
{
	Node<T> *tmpNode = m_head;

	while (tmpNode) {
		std::cout << tmpNode->m_value << " ";
		tmpNode = tmpNode->m_next;
	}
	std::cout << std::endl;
}

template<class T>
Node<T>::Node()
	: m_next(NULL)
{
}

template<class T>
Node<T>::Node(const T & value)
	: m_next(NULL)
	, m_value(value)
{
}

template<class T>
ostream & operator<<(ostream & os, List<T> li)
{
	Node<T> *tmpNode = li.m_head;
	while (tmpNode) {
		os << tmpNode->m_value << " ";
		tmpNode = tmpNode->m_next;
	}
	
	return os << std::endl;
}
