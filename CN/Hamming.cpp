#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define ALL(v) v.begin(), v.end()
#define nl cout << "\n";
#define out(v) cout << v;

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

void solve()
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
    solve();
    return 0;
}