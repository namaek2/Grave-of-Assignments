#include "BinaryNode.h"
#include "circularqueue.h"

class BinaryTree {
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	void inorder() { printf("\ninorder:"); inorder(root); }
	void inorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) inorder(node->getLeft());
			printf(" [%c]", node->getData());
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}
	void preorder() { printf("\npreorder:"); preorder(root); }
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf(" [%c]", node->getData());
			if (node->getLeft() != NULL) preorder(node->getLeft());
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}
	void postorder() { printf("\npostorder:"); postorder(root); }
	void postorder(BinaryNode* node) {
		if (node != NULL) {
			postorder(node->getLeft());
			postorder(node->getRight());
			printf(" [%c]", node->getData());
		}
	}

	void levelorder() {
		printf("\nlevelorder:");
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					printf(" [%c]", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}
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

	void isBalanced(BinaryTree tree, BinaryNode* root)	//isBalanced 함수
	{
		BinaryTree left_sub;	//왼쪽의 서브트리
		BinaryTree right_sub;	//오른쪽의 서브트리

		left_sub = tree;	//각 서브트리에 정보를 복사
		right_sub = tree;

		left_sub.setRoot(root->getLeft());	//각 서브트리의 루트노드를 설정
		right_sub.setRoot(root->getRight());

		//서브트리의 높이 차가 2 미만이면 Balanced, 아니라면 Unbalanced 출력
		if (left_sub.getHeight() - right_sub.getHeight() < 2 && left_sub.getHeight() - right_sub.getHeight() > -2)
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
};
