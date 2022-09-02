#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<long long int>
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()
#define nl cout << "\n";
#define out(v) cout << v;

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

string add(string a, string b)
{
    string res = "";
    int temp = 0;
    int s_a = a.size() - 1;
    int s_b = b.size() - 1;
    while (s_a >= 0 || s_b >= 0 || temp == 1)
    {
        temp += ((s_a >= 0) ? a[s_a] - '0' : 0);
        temp += ((s_b >= 0) ? b[s_b] - '0' : 0);
        res = char(temp % 2 + '0') + res;
        temp /= 2;
        s_a--;
        s_b--;
    }
    return res;
}

int main()
{
    char x;
    out("Enter the data(SEPARATED BY SPACES): ");
    string data,
        e, m;
    getline(cin, data);
    vector<string> v;
    SplitString(data, v);
    // adding datablocks if carry is obtained it is again added to obtained sum
    e = add(v[0], v[1]);
    if (e.size() > v[0].size())
    {
        x = e[0];

        f(i, 0, v[0].size() - 1)
        {
            m.pb('0');
        }
        m.pb(x);
        e.erase(0, 1);
        e = add(e, m);
    }
    for (int j = 2; j < v.size(); j++)
    {
        e = add(e, v[j]);
        if (e.size() > v[j].size())
        {
            int y = e[0];
            string z;
            f(i, 0, v[0].size() - 1)
            {
                z.pb('0');
            }
            z.pb(y);
            e.erase(0, 1);
            e = add(e, z);
        }
    }
    // changing to one's complement
    f(i, 0, e.size())
    {
        if (e[i] == '1')
        {
            e[i] = '0';
        }
        else
        {
            e[i] = '1';
        }
    }
    out("************ SENDER ************");
    nl;
    out("Obtained Sum is: ");
    out(e);
    nl;
    out("************ RECIVER ************");
    nl;
    // just uncomment for false transmission
    // if (e[0] == '1')
    // {
    //     e[0] = '0';
    // }
    // else
    // {
    //     e[0] = '1';
    // }
    v.pb(e);
    string u, r;
    // adding datablocks if carry is obtained it is again added to obtained sum
    u = add(v[0], v[1]);
    if (u.size() > v[0].size())
    {
        int p = u[0];

        f(i, 0, v[0].size() - 1)
        {
            r.pb('0');
        }
        r.pb(p);
        u.erase(0, 1);
        u = add(u, r);
    }
    for (int j = 2; j < v.size(); j++)
    {
        u = add(u, v[j]);
        if (u.size() > v[j].size())
        {
            int g = u[0];
            string y;
            f(i, 0, v[0].size() - 1)
            {
                y.pb('0');
            }
            y.pb(g);
            u.erase(0, 1);
            u = add(u, y);
        }
    }
    // changing to one's complement
    f(i, 0, u.size())
    {
        if (u[i] == '1')
        {
            u[i] = '0';
        }
        else
        {
            u[i] = '1';
        }
    }
    int flag = 0;
    f(i, 0, u.size())
    {
        if (u[i] != '0')
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        out("Incorrect Data");
        nl;
        out("Because checksum Data is: ");
        out(e);
        nl;
    }
    else
    {
        out("Correct Data");
        nl;
        out("Because Obtained Sum is: ");
        out(u);
        nl;
    }

    return 0;
}
