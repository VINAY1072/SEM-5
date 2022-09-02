#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int a[], int b[], int p[], int t[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
                swap(&b[i], &b[j]);
                swap(&p[i], &p[j]);
                swap(&t[i], &t[j]);
            }
            else if (a[i] == a[j])
            {
                if (p[i] > p[j])
                {
                    swap(&a[i], &a[j]);
                    swap(&b[i], &b[j]);
                    swap(&p[i], &p[j]);
                    swap(&t[i], &t[j]);
                }
            }
        }
    }
}

int main()
{
    int i, n, r_t = 0, total = 0, count = 0, x, counter = 0, t_q, w_t = 0, t_a_t = 0, p_id[10], a_t[10], b_t[10], temp[10];
    float A_w_t, A_t_a_t, A_t_r_t;
    printf("\nEnter number of Processes:\t");
    scanf("%d", &n);
    x = n;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Details of Process:\t\n");

        scanf("%d", &p_id[i]);

        printf("Arrival Time:\t");

        scanf("%d", &a_t[i]);

        printf("Burst Time:\t");

        scanf("%d", &b_t[i]);

        temp[i] = b_t[i];
    }
    sort(a_t, b_t, p_id, temp, n);
    printf("\nEnter Time Quantum:\t");
    scanf("%d", &t_q);
    int C_S_O;
    printf("Enter Context Switch Overhead: ");
    scanf("%d", &C_S_O);
    printf("\nProcess ID\tArrival time Burst Time Completion Time Turnaround Time Waiting Time\n");
    for (total = 0, i = 0; x != 0;)
    {
        if (temp[i] <= t_q && temp[i] > 0)
        {
            total = total + temp[i] + C_S_O;
            temp[i] = 0;
            counter = 1;
            count++;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - t_q;
            total = total + t_q + C_S_O;
            count++;
        }
        if (temp[i] == 0 && counter == 1)
        {
            x--;
            if (C_S_O == 0)
            {
                printf("\nProcess[%d]\t\t%d\t\t %d\t\t%d\t\t%d\t\t%d", p_id[i], a_t[i], b_t[i], total, total - a_t[i], total - a_t[i] - b_t[i]);
                w_t = w_t + total - a_t[i] - b_t[i];
                t_a_t = t_a_t + total - a_t[i];
                r_t += total - 2 * (a_t[i]);
                counter = 0;
            }
            else
            {
                printf("\nProcess[%d]\t\t%d\t\t %d\t\t%d\t\t%d\t\t%d", p_id[i], a_t[i], b_t[i], total - 1, total - a_t[i] - 1, total - a_t[i] - b_t[i] - 1);
                w_t = w_t + total - a_t[i] - b_t[i] - 1;
                t_a_t = t_a_t + total - a_t[i] - 1;
                r_t += total - 2 * (a_t[i]) - 1;
                counter = 0;
            }
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (a_t[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    A_w_t = (float)w_t / (float)n;
    A_t_a_t = (float)t_a_t / (float)n;
    A_t_r_t = (float)r_t / (float)n;
    printf("\n\nAverage Waiting Time:\t%f", A_w_t);
    printf("\nAverage Turnaround Time:\t%f\n", A_t_a_t);
    printf("\nAverage Response Time:\t%f\n", A_t_r_t);
    printf("\nNo of Context Switching:\t%d\n", count - 1);
    return 0;
}