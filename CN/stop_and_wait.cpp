#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define f(i, a, b) for (int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()
#define nl cout << "\n";
#define out(v) cout << v;

bool receiver(int n)
{
    int choice;
    out("\n1) choose one if reciever received frame\n");
    out("2) choose two if reciever not received frame\n");
    out("Enter your choice: ");
    cin >> choice;
    if (choice == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sender(vi &v)
{
    f(i, 0, v.size())
    {
        cout << "\n------------ Frame " << i << " is sent ------------" << endl;
        if (receiver(v[i]) == true)
        {
            out("\n------------- Data is received --------------");
            int choice;
            out("\n1) choose one if sender received Acknowledgement\n");
            out("2) choose two if sender not received Acknowledgement\n");
            out("Enter your choice: ");
            cin >> choice;
            if (choice == 1)
            {
                out("\n------------- Acknowledgement is received --------------\n");
                continue;
            }
            else
            {
                out("End Protocol(Reason:- Lost Acknowledgement)");
                break;
            }
        }
        else
        {
            out("End Protocol(Reason:- Lost Data)");
            break;
        }
    }
}

int main()
{
    int n, x, j, t_t;
    out("Enter the frame size: ");
    cin >> n;
    vi v;
    out("Enter the Data: ");
    f(i, 0, n)
    {
        cin >> x;
        v.pb(x);
    }
    sender(v);

    return 0;
}
