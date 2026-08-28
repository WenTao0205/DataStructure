#include <iostream>
#include <string>
using namespace std;

int brute_str_match(string r, string s)
{
    int i = 0, j = 0;
    while (i < r.length())
    {
        if (r[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }

        if (j >= s.length())
            return i - j;
    }
    return 0;
}

int main()
{
    string r = "ababcabcacbab";
    string s = "abcac";

    cout << brute_str_match(r, s) << endl;
}