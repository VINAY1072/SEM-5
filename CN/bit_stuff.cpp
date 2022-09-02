// bit stuffing file

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
    int n, x;
    out("Enter the size: ");
    cin >> n;
    vi v;
    out("Enter the data(separated by spaces): ");
    f(i, 0, n)
    {
        cin >> x;
        v.pb(x);
    }
    int count = 0, k;
    f(i, 0, v.size())
    {
        if (v[i] == 0)
        {
            count = 0;
        }
        else
        {
            count++;
            if (count == 5)
            {
                v.insert(v.begin() + (i + 1), 0);
                count = 0;
            }
        }
    }
    out("Data after bit stuffing is: ");
    nl;
    f(i, 0, v.size())
    {
        out(v[i]);
        out(" ");
    }
    nl;
    out("--------------- Receiver Side ---------------\n");
    int count_1 = 0;
    f(i, 0, v.size())
    {
        if (v[i] == 0)
        {
            count_1 = 0;
        }
        else
        {
            count_1++;
            if (count_1 == 5)
            {
                v.erase(v.begin() + (i + 1));
                count_1 = 0;
            }
        }
    }
    out("Data after bit Destuffing is: ");
    nl;
    f(i, 0, v.size())
    {
        out(v[i]);
        out(" ");
    }
    nl;
    return 0;
}
