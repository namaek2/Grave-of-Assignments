#include <iostream>
#include <string>

using namespace std;

string male[101];
string female[101];

int male_head = 0;
int male_rear = 0;

int female_head = 0;
int female_rear = 0;

void enqueue_male_front(string temp)
{
	if (male_head == 0)
		male_head = 100;
	else
		male_head--;

	male[male_head] = temp;
}

void enqueue_male_rear(string temp)
{
	male[male_rear] = temp;

	if (male_rear == 100)
		male_rear = 0;
	else
		male_rear++;

}

string dequeue_male_front()
{
	string s = male[male_head];

	if (male_head == 100)
		male_head = 0;
	else
		male_head++;

	return s;
}

string dequeue_male_rear()
{
	string s = male[male_rear];

	if (male_rear == 0)
		male_rear = 100;
	else
		male_rear--;

	return s;
}

void enqueue_female_front(string temp)
{
	if (female_head == 0)
		female_head = 100;
	else
		female_head--;

	female[female_head] = temp;
}

void enqueue_female_rear(string temp)
{
	female[female_rear] = temp;

	if (female_rear == 100)
		female_rear = 0;
	else
		female_rear++;
}

string dequeue_female_front()
{
	string s = female[female_head];
	if (female_head == 100)
		female_head = 0;
	else
		female_head++;

	return s;
}

string dequeue_female_rear()
{
	string s = female[female_rear];
	if (female_rear == 0)
		female_rear = 100;
	else
		female_rear--;

	return s;
}


int main(void)
{
	int num = 0;

	cin >> num;

	int n = 0;
	string s;
	char gen;
	char pos;

	int c = 0;

	for (int i = 0; i < num; i++)
	{
		cin >> n >> s >> gen >> pos;

		if (gen == 'm')
		{
			if (pos == 'F')
			{
				enqueue_male_front(s);
			}

			else if (pos == 'R')
			{
				enqueue_male_rear(s);
			}
		}

		else if (gen == 'f')
		{
			if (pos == 'F')
			{
				enqueue_female_front(s);
			}

			else if (pos == 'R')
			{
				enqueue_female_rear(s);
			}
		}

		if (male_head!=male_rear && female_head!=female_rear)
		{
			cout << "Matched : " << dequeue_male_front() << " " << dequeue_female_front() << "\n";
			c++;
		}
	}

	int a, b;

	if (male_rear - male_head < 0)
	{
		a = male_rear - male_head;
		a += 101;
	}

	else
		a = (male_rear - male_head);

	if (female_rear - female_head < 0)
	{
		b = female_rear - female_head;
		b += 101;
	}

	else
		b = (female_rear - female_head);

	cout << c << " " << a << " " << b;



	return 0;
}
