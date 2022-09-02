// character count file

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
    int n, x, y, fs;
    out("Enter the size: ");
    cin >> n;
    out("Enter the frame size: ");
    cin >> fs;
    vi v, fr, fr1;
    out("Enter the data(separated by spaces): ");
    f(i, 0, n)
    {
        cin >> x;
        v.pb(x);
    }
    int df, tf, nof, s, j = 0;
    s = fs;
    df = n;
    tf = fs - 1;
    nof = (df / tf) + 1;
    f(i, 0, (df + nof))
    {
        if (i % fs == 0)
        {
            if ((df - j) < fs)
            {
                fs = df - j + 1;
            }
            v.insert(v.begin() + i, fs);
            fs = s;
        }
        else
        {
            j++;
        }
    }
    int m = v.size();
    out("Data After framing is: \n");
    f(i, 0, v.size())
    {
        out(v[i]);
        out(" ");
    }
    nl;

    j = 0;
    f(i, 0, (df + nof))
    {
        if (i % fs != 0)
        {
            fr1.pb(v[i]);
        }
    }
    out("Data After Deframing is: \n");
    f(i, 0, fr1.size())
    {
        out(fr1[i]);
        out(" ");
    }
    nl;
    return 0;
}
