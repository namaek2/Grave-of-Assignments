#include <iostream>
#include <utility>
#include <list>

using namespace std;
/*
class Polynomial
{
	int degree;
	

public :
	Polynomial() { degree = 0; }

	void read()
	{
		printf("다항식의 최고 차수를 입력하시오: ");
		scanf_s("%d", &degree);
		printf("각 항의 계수를 입력하시오 (총 %d개): ", degree + 1);
		for (int i = 0; i <= degree; i++)
			scanf_s("%f", coef + i);

	}

	void display()
	{
		for (int i = 0; i < degree; i++)
			printf("%5.1f x^%d + ", coef[i], degree - i);
		printf("%4.1f\n", coef[degree]);
	}

	void add(Polynomial a, Polynomial b)
	{
		if (a.degree > b.degree)
		{
			*this = a;
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}

		else
		{
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}

	bool isZero() { return degree == 0; }
	void negate() { 
		for (int i = 0; i <= degree; i++)
			coef[i] = -coef[i];
	}
};

*/

int main()
{
	list <int> ax;
	list <int> ay;
	list <int> bx;
	list <int> by;
	list <int> cx;
	list <int> cy;
	
	auto iax = ax.begin();
	auto iay = ay.begin();
	list<int>::iterator ibx = bx.begin();
	list<int>::iterator iby = by.begin();
	list<int>::iterator icx = cx.begin();
	list<int>::iterator icy = cy.begin();
	
	int acount = 0;
	int bcount = 0;

	int tx, ty;

	cin >> acount;
	cout << "(" << acount << ") = ";
	for (int i = 0; i < acount; i++)
	{
		if (i != 0)
		{
			cout << " + ";
		}
		cin >> ty >> tx;
		ax.push_back(tx);
		ay.push_back(ty);


		cout << fixed;
		cout.precision(1);
		cout << (double)ay.back() << " x^";
		cout.unsetf(ios::fixed);
		cout << ax.back();
	}
	cout << "\n";
	cin >> bcount;
	cout << "(" << bcount << ") = ";
	for (int i = 0; i < bcount; i++)
	{
		if (i != 0)
		{
			cout << " + ";
		}
		cin >> ty >> tx;
		bx.push_back(tx);
		by.push_back(ty);

		cout << fixed;
		cout.precision(1);
		cout << (double)ty << " x^";

		cout.unsetf(ios::fixed);
		cout << tx;
	}
	cout << "\n";


	int temp;
	iax = ax.begin();
	iay = ay.begin();
	ibx = bx.begin();
	iby = by.begin();
	icx = cx.begin();
	icy = cy.begin();


	while (iax != ax.end() || ibx != bx.end())
	{
		if (iax == ax.end())
		{
			temp = *ibx;
			cx.push_back(temp);
			temp = *iby;
			cy.push_back(temp);
			ibx++; iby++;
		}

		else if (ibx == bx.end())
		{
			temp = *iax;
			cx.push_back(temp);
			temp = *iay;
			cy.push_back(temp);
			iax++; iay++;
		}

		else if (*iax == *ibx)
		{
			temp = *iax;
			cx.push_back(temp);
			temp = *iay + *iby;
			cy.push_back(temp);

			iax++; iay++; ibx++; iby++;
		}

		else if (*iax > *ibx)
		{
			temp = *iax;
			cx.push_back(temp);
			temp = *iay;
			cy.push_back(temp);
			iax++; iay++;
		}

		else if (*iax < *ibx)
		{
			temp = *ibx;
			cx.push_back(temp);
			temp = *iby;
			cy.push_back(temp);
			ibx++; iby++;
		}
	}
	int k = 0;
	for (icx = cx.begin(); icx != cx.end(); icx++)	k++;

	cout << "(" << k << ") = ";
	
	icy = cy.begin();
	for (icx = cx.begin(); icx != cx.end(); icx++)
	{
		if (icx != cx.begin())
		{
			cout << " + ";
		}

		cout << fixed;
		cout.precision(1);
		cout << (double)*icy << " x^";

		cout.unsetf(ios::fixed);
		cout << *icx;

		icy++;
	}

	return 0;

}
