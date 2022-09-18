#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
 
void checkMatching(string s)
{
    int pair = 0;
    int line = 0;
    stack<int> st;
    int temp = 0;
    int temp1 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '/' && temp == 0)
        {
            if (i != s.size() - 1 && s[i + 1] == '/')
            {
                temp1 = 1;
            }
 
            else if (i != s.size() - 1 && s[i + 1] == '*')
            {
                temp1 = 2;
            }
 
            else
                continue;
        }
 
        else if (s[i] == '*')
        {
            if (i != s.size() - 1 && s[i + 1] == '/')
            {
                temp1 = 0;
            }
 
            else
                continue;
        }
 
        else if (s[i] == '\n')
        {
            line++;
 
            if (temp1 == 1)
                temp1 = 0;
 
            continue;
        }
 
        else if (temp1 == 2 || temp1 == 1)
                continue;
         
 
        if (s[i] == '\"')
        {
            if (temp == 0)
                temp = 1;
            else
            {
                temp = 0;
            }
        }
 
        else
        {
            if (temp == 1)
                continue;
        }
 
        if (s[i] == '(')
        {
            st.push(1);
        }
 
        else if (s[i] == '{')
        {
            st.push(2);
        }
 
        else if (s[i] == '[')
        {
            st.push(3);
        }
 
        else if (s[i] == ')')
        {
            if (!st.empty())
            {
                if (st.top() == 1)
                {
                    st.pop();
                    pair++;
                }
 
                else
                {
                    line++;
                    cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                    return;
                }
            }
 
            else
            {
                line++;
                cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                return;
            }
        }
 
        else if (s[i] == '}')
        {
            if (!st.empty())
            {
                if (st.top() == 2)
                {
                    st.pop();
                    pair++;
                }
 
                else
                {
                    line++;
                    cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                    return;
                }
            }
 
            else
            {
                line++;
                cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                return;
            }
        }
 
        else if (s[i] == ']')
        {
            if (!st.empty())
            {
                if (st.top() == 3)
                {
                    st.pop();
                    pair++;
                }
 
                else
                {
                    line++;
                    cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                    return;
                }
            }
 
            else
            {
                line++;
                cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                return;
            }
        }
 
 
    }
 
 
    if (!st.empty())
    {
        cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
        return;
    }
 
    cout << "OK, Line_count : " << line << ", bracket_count : " << pair;
    return;
}
 
int main() {
    string Str, temp;
    while (true) {
        getline(cin, temp);
        if (temp == "EOF")break;
        Str.append(temp);
        Str.append("\n");
        cin.clear();
    }
    checkMatching(Str);
 
    return 0;
}
