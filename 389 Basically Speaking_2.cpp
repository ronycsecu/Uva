#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;
long long POWER(int NUM, int EXP);

int main()
{
    char input[10000],data[8];
    int givenBase, toBase;
    char baseDigits[] = {"0123456789ABCDEF"};

    while(scanf("%s %d %d", data, &givenBase, &toBase)!=EOF)
    {
        bool overFlow = false;
        long long decimal = 0;
        int result[7];
        if(givenBase!=10)
        {
            int limit = strlen(data);
            int exp = limit-1;

            for(int l = 0; l<limit; l++)
            {
                if(data[l] >=65 && data[l] <=70)
                {
                    decimal += ((data[l]-55)*POWER(givenBase, exp));
                    exp--;
                }
                else
                {
                    decimal += ((data[l]-'0')*POWER(givenBase, exp));
                    exp--;
                }
            }
        }
        else
        {
            decimal = atoll(data);
        }

        int index = -1;
        if(decimal == 0)
        {
            printf("      0\n");
            continue;
        }
        else
        {
            while(decimal)
            {
                result[++index] = decimal%toBase;
                decimal=decimal/toBase;
                if(index>=7)
                {
                    overFlow = true;
                    break;
                }
            }
        }
        if(!overFlow)
        {
            for(int i = 1; i<(7-index); i++)
                printf(" ");
            for(int i = index; i>=0; i--)
            {
                printf("%c", baseDigits[result[i]]);
            }
        }
        else
        {
            printf("  ERROR");
        }
        printf("\n");
    }
    return 0;
}

long long POWER(int NUM, int EXP)
{
    if(NUM == 0)
        return 0;
    if(EXP == 0)
        return 1;
    long long RESULT = NUM;
    for(int i=1; i<EXP; i++)
    {
        RESULT*=NUM;
    }
    return RESULT;
}
