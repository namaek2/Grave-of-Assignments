#include <iostream>
#include <string>

using namespace std;

int eq[21];
int pq[21];
int st[21];

int eq_head = 0;
int eq_rear = 0;

int pq_head = 0;
int pq_rear = 0;

int st_top = 0;

void enqueue(int temp)
{
	pq[pq_rear] = temp;
	pq_rear++;
}

void t_enqueue(int temp)
{
	eq[eq_rear] = temp;
	eq_rear++;
}


int dequeue()
{
	int temp = eq[eq_head];
	eq_head++;

	return temp;
}

int t_dequeue()
{
	int temp = pq[pq_head];
	pq_head++;

	return temp;
}

int front()
{
	return eq[eq_head];
}

void push(int temp)
{
	st[st_top] = temp;
	st_top++;
}

int pop()
{
	st_top--;
	return st[st_top];
}

int top()
{
	return st[st_top-1];
}

int main(void)
{
	int num = 0;
	char c;

	cin >> num >> c;

	for (int i = 0; i < num; i++)
	{
		int k;
		cin >> k;
		t_enqueue(k);
	}

	int a = 0;

	if (c == 'a')
	{
		while (1)
		{
			if (st_top == 0)
			{
				push(dequeue());
			}

			else if (st_top > 0)
			{
				if (top() < front())
				{
					enqueue(pop());
				}

				else
				{
					push(dequeue());
				}
			}

			if (eq_head == eq_rear)
				break;
		}
	}

	if (c == 'd')
	{
		while (1)
		{
			if (st_top == 0)
			{
				push(dequeue());
			}

			else if (st_top > 0)
			{
				if (top() > front())
				{
					enqueue(pop());
				}

				else
				{
					push(dequeue());
				}
			}

			if (eq_head == eq_rear)
				break;
		}
	}

	while (st_top - 1 > 0)
	{
		enqueue(pop());
	}

	a = 0;

	if (c == 'a')
	{
		for (int i = pq_head; i < pq_rear-1; i++)
		{
			if (pq[i] > pq[i + 1])
			{
				cout << "No";
				return 0;
			}
		}
	}

	else if (c == 'd')
	{
		for (int i = pq_head; i < pq_rear - 1; i++)
		{
			if (pq[i] < pq[i + 1])
			{
				cout << "No";
				return 0;
			}
		}
	}

	cout << "Yes";

	return 0;
}
