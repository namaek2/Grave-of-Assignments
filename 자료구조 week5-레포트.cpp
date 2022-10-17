#include <cstdio>

class Node {
	Node* link;
	int data;
public:
	Node(int val = 0) : data(val), link(NULL) {	}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	void display() { printf(" <%2d>", data); }
	bool hasData(int val) { return data == val; }
	void insertNext(Node *n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};

class LinkedList {
	Node org;
public:
	LinkedList() : org(0) { }
	~LinkedList() { clear(); }
	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; }

	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}
	Node* find(int val) {
		for (Node *p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) return p;
	}
	void replace(int pos, Node *n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}
	int size() {
		int cnt = 0;
		for (Node *p = getHead(); p != NULL; p = p->getLink())
			cnt++;
		return cnt;
	}
	void display() {
		for (Node *p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
	void reverse()
	{
		Node *t1;
		Node *t2;
		Node *t3;
		
		int a = size();
		t1 = getHead(); //Head 불러오기
		t3 = NULL;

		for (int i = 0; i < a - 2; i++) //마지막 두 번을 제외하고 반복
		{
			t2 = t1->getLink(); //t1이 가리키는 값 t2에 불러오기
			t1->setLink(t3); //t1이 가리키는 값 t3로 바꾸기

			t3 = t1;	//다음 순서를 위해 하나씩 밀기
			t1 = t2;	
		}

		t2 = t1->getLink();  //밀지 않고 한 연산 진행
		t1->setLink(t3); 

		t2->setLink(t1); //마지막노드가 가리키는 값 그 전 값으로 바꿔주기
		org.setLink(t2); //org이 가리키는 값 마지막 노드로 바꿔주기
	}
};

int main() {
	LinkedList list;

	list.insert(0, new Node(10));
	list.insert(1, new Node(20));
	list.insert(2, new Node(30));
	list.insert(3, new Node(40));
	list.insert(4, new Node(50));
	list.reverse();
	list.display();

}
