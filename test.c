#include <stdio.h>
#include <string.h>
int main()
{
    char * arr []={
        "100",
        "011",
        "111",
        NULL
    } ;

    int j;
    int i = -1;
    int test = 0;
    int x;
    int y;
    while(i < 2)
    {
        j = -1;
        while(j < 2)
        {
            x = i + 1;
            y = j + 1;
            test <<= 1;
                test += (arr[y][x] == '1');

            j++;
        }
        i++;
    }
    printf("%d\n",test);
}
