#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<long long int>
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()
#define nl cout << "\n";
#define out(v) cout << v;

string getString(char x)
{
    string s(1, x);
    return s;
}

int count_ones(string d)
{
    int count = 0;
    f(i, 0, d.size())
    {
        if (d[i] == '1')
        {
            count++;
        }
    }
    return count;
}

void SplitString(string s, vector<string> &v)
{

    string temp = "";
    for (int i = 0; i < s.length(); ++i)
    {

        if (s[i] == ' ')
        {
            v.pb(temp);
            temp = "";
        }
        else
        {
            temp.pb(s[i]);
        }
    }
    v.pb(temp);
}

int main()
{

    out("Enter the data(SEPARATED BY SPACES): ");

    string data, e, m, t, p;
    getline(cin, data);

    vector<string> v, x, u, y;
    SplitString(data, v);
    f(i, 0, v[0].size())
    {
        f(j, 0, v.size())
        {
            e.pb(v[j][i]);
        }
    }
    f(i, 0, e.size())
    {
        if (i % (v.size() + 1) == 0)
        {
            e.insert(i, " ");
        }
    }
    SplitString(e, x);
    f(i, 0, x.size())
    {
        if (count_ones(x[i]) % 2 != 0)
        {
            m.pb('1');
        }
        else
        {
            m.pb('0');
        }
    }
    out("************ SENDER ************");
    nl;
    m.erase(0, 1);
    f(i, 0, v.size())
    {
        out(v[i]);
        nl;
    }
    f(i, 0, v[0].size())
    {
        out("-");
    }
    nl;
    out(m);
    nl;
    out("LRC is: ");
    out(m);
    nl;
    SplitString(data, u);
    f(i, 0, u[0].size())
    {
        f(j, 0, u.size())
        {
            t.pb(u[j][i]);
        }
    }
    f(i, 0, t.size())
    {
        if (i % (v.size() + 1) == 0)
        {
            t.insert(i, " ");
        }
    }
    SplitString(t, y);
    f(i, 0, y.size())
    {
        if (count_ones(y[i]) % 2 != 0)
        {
            p.pb('1');
        }
        else
        {
            p.pb('0');
        }
    }
    p.erase(0, 1);
    out("************ RECIVER ************");
    nl;
    // just uncomment for false transmission
    // if (m[0] == '1')
    // {
    //     m[0] = '0';
    // }
    // else
    // {
    //     m[0] = '1';
    // }
    if (m == p)
    {
        out("Correct Data");
    }
    else
    {
        out("Incorrect Data");
        nl;
        out("Because Data is: ");

        out(m);
        nl;
    }

    return 0;
}
