#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;
int *list;
// int n = 50001;
// int list[50001] = {0,};

int Partition(int l, int r)
{
    int pivot = list[l];
    int low = l + 1;
    int high = r;

    while (low < high)
    {
        while (low <= r && list[low] < pivot) low ++;
        while (high >= l && list[high] > pivot) high --;

        if (low < high)
        {
            int t = list[low];
            list[low] = list[high];
            list[high] = t;
        }
    }

    int t = list[l];
    list[l] = list[high];
    list[high] = t;

    return high;
}

void QuickSort(int l, int r)
{
    if (l >= r) return;

    int pi = Partition(l, r);
    QuickSort(l, pi - 1);
    QuickSort(pi + 1, r);
}

int main()
{
    int i, j, t;
    clock_t start, end;
    scanf("%d", &n);
    list = malloc(sizeof(int) * n);
    srand((unsigned int)time(NULL));

    for (i = 0; i < n; i ++)
    {
        list[i] = rand() % n + 1;
        printf("%d ", list[i]);
    }
    
    start = clock();
    printf("start: %f\n", (float)start / CLOCKS_PER_SEC);
    QuickSort(0, n - 1);
    end = clock();

    for (j = 0; j < n; j ++)
        printf("%d ", list[j]);
    printf("\nb");
    printf("\nn = %d, time = %f\n", n, (float)(end - start) / CLOCKS_PER_SEC);

    free(list);
}
