#include <iostream>
#include <string>
#include <stack>
#include <cmath>
 
using namespace std;
 
int main(void)
{
    string s;
    string ss = "";
    string sss = "";
 
    stack<char> stc;
 
    stack<double> stn;
 
    char temp;
    double a, b;
 
    double d;
 
    bool nt = false;
    bool na = false;
 
    getline(cin, s);
 
    //우선순위 -  ():0      +, -:1      *, /:2
 
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
        {
            if (!stc.empty())
            {
                if (nt == true)
                    stc.push('+');
 
                else if (stc.top() == '*' || stc.top() == '/')
                {
                    temp = stc.top();
                    stc.pop();
                    sss += temp;
                    sss += ' ';
                    stc.push('+');
                }
 
                else
                    stc.push('+');
            }
 
            else
                stc.push('+');
        }
 
        else if (s[i] == '-')
        {
            if (!stc.empty())
            {
                if (nt == true)
                    stc.push('-');
 
                else if (stc.top() == '*' || stc.top() == '/')
                {
                    temp = stc.top();
                    stc.pop();
                    sss += temp;
                    sss += ' ';
                    stc.push('-');
                }
 
                else
                    stc.push('-');
            }
 
            else
                stc.push('-');
        }
 
        else if (s[i] == '*')
        {
            stc.push('*');
        }
 
        else if (s[i] == '/')
        {
            stc.push('/');
        }
 
 
        else if (s[i] == '(')
        {
            nt = true;
            stc.push('(');
        }
 
        else if (s[i] == ')')
        {
            nt = false;
 
            while (stc.top() != '(')
            {
                sss += stc.top();
                sss += ' ';
                stc.pop();
            }
            stc.pop();
        }
 
        else if (s[i] >= '0' && s[i] <= '9')
        {
            ss += s[i];
 
            na = true;
        }
 
        else if (s[i] == '.')
        {
            ss += s[i];
        }
 
        else if (s[i] == ' ')
        {
            if (na == true)
            {
                na = false;
                sss += ss;
                sss += ' ';
                ss = "";
            }
 
            else
                continue;
 
        }
 
    }
 
 
    if (ss != "")
    {
        sss += ss;
        sss += ' ';
        ss = "";
        na = false;
    }
 
 
    while (!stc.empty())
    {
        sss += stc.top();
        sss += ' ';
        stc.pop();
    }
 
    for (int i = 0; i < sss.size(); i++)
    {
        for (int j = i; j<sss.size(); j++)
        {
            if (sss[j] >= '0' && sss[j] <= '9')
            {
                ss += sss[j];
            }
 
            else if (sss[j] == '.')
            {
                ss += sss[j];
            }
 
            else if (sss[j] == ' ' && ss != "")
            {
                double td = stod(ss);
                td = round(td * 100);
                td = td / 100;
                stn.push(td);
                ss = "";
            }
 
            else if (sss[j] == '+' || sss[j] == '-' || sss[j] == '*' || sss[j] == '/')
                break;
 
            i = j;
        }
 
        i++;
        temp = sss[i];
 
        if (i >= sss.size() - 1) 
            break;
 
        b = stn.top();
        stn.pop();
        a = stn.top();
        stn.pop();
 
        if (temp == '+')
        {
            d = a + b;
            stn.push(d);
        }
 
        else if (temp == '-')
        {
            d = a - b;
            stn.push(d);
        }
 
        else if (temp == '*')
        {
            d = a * b;
            stn.push(d);
        }
 
        else if (temp == '/')
        {
            if (b == 0)
            {
                cout << "Error : zero division error";
                return 0;
            }
 
 
            else
            {
                d = a / b;
                stn.push(d);
            }
        }
 
    }
 
    cout << fixed;
    cout.precision(2);
    cout <<  stn.top();
 
    return 0;
}
