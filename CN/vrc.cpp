#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<long long int>
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()
#define nl cout << "\n";
#define out(v) cout << v;

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
    out("*NOTE*");
    nl;
    out("VRC can show bit errors ");
    nl;
    out("VRC shows burst errors iff the number of changed bits are odd ");
    nl;
    out("Enter the data(SEPARATED BY SPACES): ");
    string data, e, m;
    getline(cin, data);
    vector<string> v, x;
    SplitString(data, v);

    f(i, 0, v.size())
    {
        if (count_ones(v[i]) % 2 != 0)
        {
            v[i].insert(0, "1");
        }
        else
        {
            v[i].insert(0, "0");
        }
    }
    out("************ SENDER ************");
    nl;
    f(i, 0, v.size())
    {
        out(v[i]);
        out(" ");
    }
    nl;
    int flag = 0;
    out("************ RECIVER ************");
    nl;
    // just uncomment for false transmission
    // v[0][4] = '1';
    f(i, 0, v.size())
    {
        if (count_ones(v[i]) % 2 != 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        out("Data Accepted");
        nl;
    }
    else
    {
        out("Data Rejected");
        nl;
        out("Because Data is: ");
        f(i, 0, v.size())
        {
            out(v[i]);
            out(" ");
        }
    }

    return 0;
}
