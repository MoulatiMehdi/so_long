
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int f(int n)
{
    int i;

    i = 1;
    while(i < 10)
    {
        printf("%d",(n >> (i - 1)) % 2);
        if(i % 3 == 0)
            printf("\n");
        i++;
    }
    printf("\n");

    return 0;
}

int func(int a,int b , int c , int d)
{
    bool istrue ;
    int i = 0;
    while(i < pow(2,9))
    {
        istrue = true;

        istrue = istrue && (i >> a )%2 == 1;
        istrue = istrue && (i >> b )%2 == 1;
        istrue = istrue && (i >> c )%2 == 1;
        istrue = istrue && (i >> d )%2 == 1;
       if(istrue)
        {
            printf("%d\n",i);
            f(i);
        }
        i++;
    }
    return 0;
}

int main(int argc, char *argv[])
{

    func(4, 5, 7, 8);
    return 0;
}
