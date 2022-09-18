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
        if (s[i] == '\'')
        {
            if (!st.empty())
            {
                st.pop();
                pair++;
            }
                 
            else
                st.push(1);
        }
 
        else if (s[i] == '\n')
            line++;
    }
 
 
    if (!st.empty())
    {
        cout << "Error, Line_count : " << line << ", quotes_count : " << pair;
        return;
    }
 
    cout << "OK, Line_count : " << line << ", quotes_count : " << pair;
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
