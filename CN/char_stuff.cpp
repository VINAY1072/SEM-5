// byte stuffing file

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define f(i, a, b) for (int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()
#define nl cout << "\n";
#define out(v) cout << v;

int main()
{
    int n;
    out("Enter the size: ");
    cin >> n;
    string v;
    out("Enter the data: ");

    cin >> v;

    v.insert(v.begin(), 'F');
    v.insert(v.end(), 'F');
    f(i, 0, v.size())
    {
        if ((i != 0) && (i != v.size() - 1))
        {
            if ((v[i] == 'F' || v[i] == 'E'))
            {
                v.insert(v.begin() + i, 'E');
                i++;
            }
        }
    }
    out("Data after character stuffing is: ");
    nl;
    f(i, 0, v.size())
    {
        out(v[i]);
        out(" ");
    }
    nl;
    out("--------------- Receiver Side ---------------\n");
    v.erase(v.begin());
    v.erase(v.end() - 1);
    f(i, 0, v.size())
    {
        if ((v[i] == 'F' || v[i] == 'E'))
        {
            v.erase(v.begin() + i);
        }
    }
    out("Data after character Destuffing is: ");
    nl;
    f(i, 0, v.size())
    {
        out(v[i]);
        out(" ");
    }
    nl;
    return 0;
}
