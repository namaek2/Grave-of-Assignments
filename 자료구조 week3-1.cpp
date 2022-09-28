#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void)
{
	deque<string> male;
	deque<string> female;

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
				male.push_front(s);
			}

			else if (pos == 'R')
			{
				male.push_back(s);
			}
		}

		else if (gen == 'f')
		{
			if (pos == 'F')
			{
				female.push_front(s);
			}

			else if (pos == 'R')
			{
				female.push_back(s);
			}
		}

		if (!male.empty() && !female.empty())
		{
			cout << "Matched : " << male.front() << " " << female.front() << "\n";
			male.pop_front();
			female.pop_front();
			c++;
		}
	}

	cout << c << " " << male.size() << " " << female.size();



	return 0;
}
