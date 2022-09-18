#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
 
void checkMatching(string s)
{
    int pair = 0;
    int line = 0;
    stack<int> st;
 
    for(int i=0; i < s.size(); i++)
    {
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
                    cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                    return;
                }
            }
 
            else
            {
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
                    cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                    return;
                }
            }
 
            else
            {
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
                    cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                    return;
                }
            }
 
            else
            {
                cout << "Error, Line_count : " << line << ", bracket_count : " << pair;
                return;
            }
        }
 
        else if (s[i] == '\n')
            line++;
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
