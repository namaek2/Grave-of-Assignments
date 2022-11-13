#include <iostream>

using namespace std;

class BinaryNode {
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) : data(val), left(l), right(r) { }
	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == NULL && right == NULL; }
};

class BinaryTree {

protected:
	BinaryNode* root;

public:
	BinaryTree() : root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }

	bool isEmpty() { return root == NULL; }

	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		else if (node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}
	int getHeight() { return isEmpty() ? 0 : getCount(root); }
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;
		int hl = getHeight(node->getLeft());
		int hr = getHeight(node->getRight());
		return (hl > hr) ? hl + 1 : hr + 1;
	}

	void isBalanced(BinaryNode* root)	//isBalanced 함수
	{

		//서브트리의 높이 차가 2 미만이면 Balanced, 아니라면 Unbalanced 출력
		if (getHeight(root->getLeft()) - getHeight(root->getRight()) < 2 && getHeight(root->getLeft()) - getHeight(root->getRight()) > -2)
			printf("Balanced\n");
		else
			printf("Unbalanced\n");

		return;
	}

	void reverse(BinaryNode* root)	//reverse 함수
	{
		if (root != NULL)
		{
			//자식 노드가 있다면 계속 탐색
			if (root->getLeft() != NULL)
			{
				reverse(root->getLeft());
			}

			if (root->getRight() != NULL)
			{
				reverse(root->getRight());
			}

			//왼쪽 자식 노드와 오른쪽 자식 노드를  교체
			BinaryNode* temp;
			temp = root->getLeft();
			root->setLeft(root->getRight());
			root->setRight(temp);
		}
		return;
	}

	void insert(BinaryNode* n)
	{
		if (n == NULL)return;
		if (isEmpty()) root = n;
		else insertRecur(root, n);
	}

	void insertRecur(BinaryNode*r, BinaryNode*n)
	{
		if (n->getData() == r->getData()) return;

		else if (n->getData() < r->getData()) {
			if (r->getLeft() == NULL)
			{
				r->setLeft(n);
			}
			else insertRecur(r->getLeft(), n);
		}

		else {
			if (r->getRight() == NULL)
			{
				r->setRight(n);
			}
			else insertRecur(r->getRight(), n);
		}
	}

	void remove(int data)
	{
		if (isEmpty()) return;
		BinaryNode*parent = NULL;
		BinaryNode*node = root;
		while (node != NULL && node->getData() != data)
		{
			parent = node;
			node = (node->getData() > data)
				? node->getLeft() : node->getRight();
		}
		if (node != NULL) remove(parent, node);
	}
	void remove(BinaryNode*parent, BinaryNode*node) {
		if (node->isLeaf())
		{
			if (parent == NULL)
				root = NULL;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(NULL);
				else
					parent->setRight(NULL);
			}
		}

		else if (node->getLeft() == NULL || node->getRight() == NULL)
		{
			BinaryNode*child = (node->getLeft() != NULL)
				? node->getLeft() : node->getRight();

			if (node == root) root = child;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}
		else
		{
			BinaryNode*succp = node;
			BinaryNode*succ = node->getRight();
			while (succ->getLeft() != NULL)
			{
				succp = succ;
				succ = succ->getRight();
			}

			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getLeft());

			node->setData(succ->getData());
			node = succ;
		}
	}
};

int main(void)
{
	BinaryTree tree;
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		char c;
		int key;
		cin >> c >> key;

		if (c == 'I')
		{
			tree.insert(new BinaryNode(key, NULL, NULL));
		}

		else
		{
			tree.remove(key);
		}
	}
	tree.isBalanced(tree.getRoot());
	return 0;
}
