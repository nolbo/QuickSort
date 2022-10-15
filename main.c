#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 50000, p, pi;
// int list[50001];
int list[9] = {5, 3, 8, 4, 3, 1, 6, 2, 7};

void Partition(int l, int r)
{
    int m, M;

    if (pi == l) m = l + 1;
    else m = l;

    if (pi == r) M = r - 1;
    else M = r;
    // printf("%d %d\n", m, M);

    while (m <= M)
    {
        if (m == M) m -= 1;
        int mv = list[m];
        int Mv = list[M];

        if (mv > Mv)
        {
            // printf("%d %d\n", m, M);
            list[m] = Mv;
            list[M] = mv;
        }

        m += 1;
        M -= 1;
    }

    // M += 1;
    if (list[pi] > list[M])
    {
        list[pi] = list[M];
        list[M] = p;
        pi = M;
    }

    // printf("pi: %d\nM: %d\n\n", pi, M);
}

void QuickSort(int l, int r)
{
    if (l >= r) return;
    printf("%d %d\n", l, r);
    pi = l;
    p = list[pi];
    Partition(l, r);
    for (int i = 0; i < 9; i ++)
        printf("%d ", list[i]);
    printf("\n");
    QuickSort(l, pi - 1);
    QuickSort(pi + 1, r);

}

int main()
{
    /*
    int i, j, t;
    srand((unsigned int) time(NULL));

    for (i = 1; i < n + 1; i ++)
        list[i] = rand() % n + 1;

    QuickSort(1, n);
    */
    for (int i = 0; i < 9; i ++)
        printf("%d ", list[i]);
    printf("\n");

    QuickSort(0, 8);


    for (int i = 0; i < 9; i ++)
        printf("%d ", list[i]);
}
