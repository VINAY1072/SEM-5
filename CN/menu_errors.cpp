#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define ALL(v) v.begin(), v.end()
#define nl cout << "\n";
#define out(v) cout << v;

string d;

string XOR_of_STRINGS(string x, string y)
{
    string r = "";
    int r_l = y.size();
    f(i, 1, r_l)
    {
        if (x[i] == y[i])
        {
            r += '0';
        }
        else
        {
            r += '1';
        }
    }
    return r;
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
string CRC(string data, string div)
{
    d = data;
    int m = div.size();
    f(i, 0, m - 1)
    {
        data += '0';
    }
    int n = data.size();
    string g = "\0";
    f(i, 0, m)
    {
        g += '0';
    }
    int i = m;
    string curr = data.substr(0, m);
    while (i < n)
    {
        if (curr[0] == '1')
        {
            curr = XOR_of_STRINGS(curr, div) + data[i];
        }
        else
        {
            curr = XOR_of_STRINGS(curr, g) + data[i];
        }
        i++;
    }
    if (curr[0] == '1')
    {
        curr = XOR_of_STRINGS(curr, div);
    }
    else
    {
        curr = XOR_of_STRINGS(curr, g);
    }
    return curr;
}
void reciver(string data, string div)
{
    int flag = 0;

    string c = data + CRC(data, div);
    int choice;
    nl;
    nl;
    out("1) Enter '1' for passing same CRC ");
    nl;
    out("2) Enter '2' for passing different CRC ");
    nl;
    nl;
    cin >> choice;
    if (choice == 2)
    {
        c.clear();
        out("Enter received result: ");
        cin >> c;
    }
    string check = CRC(c, div);
    f(i, 0, div.size() - 1)
    {
        if (check[i] == '1')
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        out("******************** INCORRECT DATABLOCK ********************");
        nl;
        out(" (");
        out(c);
        out(")");
        nl;
    }
    else
    {
        out("******************** CORRECT DATABLOCK ********************");
        nl;
    }
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

int check_parity(int n, int i, int result[])
{
    int count = 0, k;
    for (int j = i; j <= n; j = k + i)
    {
        for (k = j; k < j + i && k <= n; k++)
        {
            if (result[k] == 1)
            {
                count++;
            }
        }
    }
    if (count % 2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Hamming_Code(vi &data, int num_dig)
{
    int red_bit = 0, data_it = 1, check, m = 0, n;
    int result[50];

    while ((pow(2, red_bit)) < (red_bit + num_dig + 1))
    {
        red_bit++;
    }

    n = num_dig + red_bit;
    f(i, 1, n + 1)
    {
        if (m <= red_bit && i == pow(2, m))
        {
            result[i] = 0;
            m++;
        }
        else
        {
            result[i] = data[data_it];
            data_it++;
        }
    }

    m = 0;
    f(i, 1, n + 1)
    {
        if (m <= red_bit && i == pow(2, m))
        {
            check = check_parity(n, i, result);
            result[i] = check;
            m++;
        }
    }

    out("Hamming result of given data is: ");
    fr(i, n, 1)
    {
        out(result[i]);
    }
    nl;
    int choice;
    nl;
    nl;
    out("1) Enter '1' for passing same hamming code ");
    nl;
    out("2) Enter '2' for passing different hamming code ");
    nl;
    nl;
    out("Enter your choice: ");
    cin >> choice;
    if (choice == 2)
    {
        out("Enter received result(SEPERATED BY SPACES): ");
        nl;
        fr(i, n, 1)
        {
            cin >> result[i];
        }
    }
    m = 0;
    data_it = 0;
    check = 0;
    f(i, 1, n + 1)
    {
        if (m <= red_bit && i == pow(2, m))
        {
            check = check + (pow(2, data_it) * check_parity(n, i, result));
            data_it++;
            m++;
        }
    }
    if (check == 0)
    {
        out("Received word is correct.");
        nl;
    }
    else
    {
        out("There is error in ");
        out((n - check) + 1);
        out(" bit ");
        nl;
        out("The correct hamming code is: ");
        if (result[check] == 0)
        {
            result[check] = 1;
        }
        else
        {
            result[check] = 0;
        }
        fr(i, n, 1)
        {
            out(result[i]);
        }
    }
}

void solve_CRC()
{
    string di, ds, dq, r, p, g;
    out("ENTER DATA: ");
    cin >> di;
    nl;
    out("ENTER DIVISOR: ");
    cin >> ds;
    nl;
    /* ------------------ SENDER ---------------------- */
    out("REMAINDER: ");
    out(CRC(di, ds));
    nl;
    out("DATABLOCK: ");
    out(d + CRC(di, ds));
    nl;
    out("------------------ CHECKING IN RECEIVER SIDE ------------------------");
    nl;
    reciver(di, ds);
}

void solve_VRC()
{
    string data, e, m;
    out("Enter the data(SEPARATED BY SPACES): ");
    cin.ignore();
    getline(cin, data);
    vector<string> v, x;
    SplitString(data, v);
    int d = v.size();

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
    int choice;
    nl;
    nl;
    out("1) Enter '1' for passing same VRC ");
    nl;
    out("2) Enter '2' for passing different VRC ");
    nl;
    nl;
    cin >> choice;
    if (choice == 2)
    {
        v.clear();
        out("Enter received result: ");
        f(i, 0, d)
        {
            string vin;
            cin >> vin;
            v.pb(vin);
        }
    }
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
}

void solve_LRC()
{
    out("Enter the data(SEPARATED BY SPACES): ");

    string data, e, m, t, p;
    cin.ignore();
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
    int choice;
    nl;
    nl;
    out("1) Enter '1' for passing same LRC ");
    nl;
    out("2) Enter '2' for passing different LRC ");
    nl;
    nl;
    cin >> choice;
    if (choice == 2)
    {
        m.clear();
        out("Enter received result: ");
        cin >> m;
    }
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
}

void solve_Check_sum()
{
    char x;
    out("Enter the data(SEPARATED BY SPACES): ");
    string data,
        e, m;
    cin.ignore();
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
    int choice;
    nl;
    nl;
    out("1) Enter '1' for passing same Check sum ");
    nl;
    out("2) Enter '2' for passing different Check sum ");
    nl;
    nl;
    cin >> choice;
    if (choice == 2)
    {
        e.clear();
        out("Enter received result: ");
        cin >> e;
    }
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
}

void solve_Hamming()
{
    int num_dig;

    out("Enter the size of the data: ");
    cin >> num_dig;
    vi data(1, num_dig + 1);
    out("Enter the data(SEPERATED BY SPACES): ");
    f(i, 1, num_dig + 1)
    {
        cin >> data[i];
    }

    nl;
    reverse(data.begin(), data.end());
    Hamming_Code(data, num_dig);
}

int main()
{
    int choice;
    while (1)
    {
        out("1) CRC ");
        nl;
        out("2) VRC ");
        nl;
        out("3) LRC ");
        nl;
        out("4) Check Sum ");
        nl;
        out("5) Hamming ");
        nl;
        out("6) Exit ");
        nl;
        out("Enter your choice: ");
        nl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            solve_CRC();
            break;
        case 2:
            solve_VRC();
            break;
        case 3:
            solve_LRC();
            break;
        case 4:
            solve_Check_sum();
            break;
        case 5:
            solve_Hamming();
            break;
        default:
            exit(1);
            break;
        }
    }

    return 0;
}
