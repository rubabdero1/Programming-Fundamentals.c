#include <stdio.h>
int sumProperDivisors(int x)
{int sum = 0;
    for (int i = 1; i <= x / 2; i++)
    { if (x % i == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}
int main()
{ int n;
    int count = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    { int j = sumProperDivisors(i);
        if (j != i && j <= n && j > i)
        {if (sumProperDivisors(j) == i)
            { printf("(%d, %d)\n", i, j);
                count++;
            }
        }
    }
    if (count == 0)
    {
        printf("No amicable pairs found.\n");
    }
    else
    {
        printf("Total amicable pairs = %d\n", count);
    }

    return 0;
}