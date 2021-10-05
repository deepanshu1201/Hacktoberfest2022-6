#include <stdio.h>

int main()
{
    int a;

    printf("you are under age for the driving \n");
    scanf("%d", &a);

    if (a > 18)
    {
        printf("%d you are eligible for driving \n", a);
    }
    else
    {
        printf("%d you are not eligible for driving\n", a);
    }
    return 0;
}
/* code */
