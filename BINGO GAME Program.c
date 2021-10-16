/**
Name: MUBTASIM AHMED RAKHEEN
UTA ID: 1001848135
CODING ASSIGNMENT 3
BINGO GAME
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Rand_num_fillbingo(int bing_arr[][6]); /*fills bingo card with random numbers*/
void Bingo_card(int bing_arr[][6]); /*prints bingo card*/
int number_caller(); /*Calls number for bingo card*/
int num_Bingocard_checker(int bing_arr[][6],int random_num); /*checks bingo card for matched numbers*/
int row_check(int bing_arr[][6]); /*checks bingo card for matched rows*/
int column_check(int bing_arr[][6]); /*checks bingo card for matched columns*/

int main(void)
{
    int bing_arr[6][6]={};
    int i=0;
    bing_arr[0][0]= 66; /*ASCII Value for 'B'*/
    bing_arr[0][1]= 73; /*ASCII Value for 'I'*/
    bing_arr[0][2]= 78; /*ASCII Value for 'N'*/
    bing_arr[0][3]= 71; /*ASCII Value for 'G'*/
    bing_arr[0][4]= 79; /*ASCII Value for 'O'*/

    Rand_num_fillbingo(bing_arr);
    Bingo_card(bing_arr);
    printf("\n");

    for (i=0;;i++)
    {
        int call_value=number_caller();
        char ans;

        if(call_value>=1 && call_value<=15)
        {
            printf("The next number is %c%d\n\n",bing_arr[0][0],call_value);
        }
        else if(call_value>=16 && call_value<=30)
        {
            printf("The next number is %c%d\n\n",bing_arr[0][1],call_value);
        }
        else if(call_value>=31 && call_value<=45)
        {
            printf("The next number is %c%d\n\n",bing_arr[0][2],call_value);
        }
        else if(call_value>=46 && call_value<=60)
        {
            printf("The next number is %c%d\n\n",bing_arr[0][3],call_value);
        }
        else if(call_value>=61 && call_value<=75)
        {
            printf("The next number is %c%d\n\n",bing_arr[0][4],call_value);
        }

        printf("Do you have it?(Y/N) ");
        scanf(" %c",&ans);
        printf("\n");
        if(ans=='Y')
        {
            int val=num_Bingocard_checker(bing_arr,call_value);
            if(val==1)
            {
                Bingo_card(bing_arr);
                printf("\n");
            }
            else if(val==0)
            {
                printf("That value is not on your BINGO card - are you trying to cheat??\n\n");
                Bingo_card(bing_arr);
                printf("\n");
            }
        }
        else if(ans=='N')
        {
            Bingo_card(bing_arr);
            printf("\n");
        }
        else if(ans!='Y' && ans!='N')
        {
            Bingo_card(bing_arr);
            printf("\n");
        }
        int val2=row_check(bing_arr);
        int val3=column_check(bing_arr);
        if(val2==1 && val3==0)
        {
            printf("You filled out a row - BINGO!!!\n\n");
            exit(0);
        }
        else if(val2==0 && val3==1)
        {
            printf("You filled out a column - BINGO!!!\n\n");
            exit(0);
        }
        else if(val2==1 && val3==1)
        {
            printf("You filled out a row and a column - BINGO!!!\n\n");
            exit(0);
        }
    }
    return 0;
}

void Rand_num_fillbingo(int bing_arr[][6])
{
    int i=0, j=0, k=0, l=0, m=0, bing_value=0;
    srand(time(0));

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(bing_arr[0][i]== 66)
            {
                bing_value = rand() % (15-1+1)+1;
            }
            else if(bing_arr[0][i]== 73)
            {
                bing_value = rand() % (30-16+1)+16;
            }
            else if(bing_arr[0][i]== 78)
            {
                bing_value = rand() % (45-31+1)+31;
            }
            else if(bing_arr[0][i]== 71)
            {
                bing_value = rand() % (60-46+1)+46;
            }
            else if(bing_arr[0][i]== 79)
            {
                bing_value = rand() % (75-61+1)+61;
            }

            do
            {
                m=0;
                if(bing_arr[0][i]== 66)
                {
                    bing_value = rand() % (15-1+1)+1;
                }
                else if(bing_arr[0][i]== 73)
                {
                    bing_value = rand() % (30-16+1)+16;
                }
                else if(bing_arr[0][i]== 78)
                {
                    bing_value = rand() % (45-31+1)+31;
                }
                else if(bing_arr[0][i]== 71)
                {
                    bing_value = rand() % (60-46+1)+46;
                }
                else if(bing_arr[0][i]== 79)
                {
                    bing_value = rand() % (75-61+1)+61;
                }
                for(k=0;k<5;k++)
                {
                    for(l=0;l<5;l++)
                    {
                        if(bing_arr [l+1][k] == bing_value)
                        {
                            m++;
                        }
                    }
                }
            }
            while(m>0);
            bing_arr[j+1][i] = bing_value;
        }
    }
    bing_arr[3][2]=0; /*free space on bingo card*/
}

void Bingo_card(int bing_arr[][6])
{
    int i=0,k=0;
    char div='|';

    for(i=0;i<5;i++)
    {
        if(i==0)
        {
            printf("%5c",bing_arr[0][i]);
        }
        else
        {
            printf("%8c",bing_arr[0][i]);
        }
    }
    printf("\n");
    printf("-----------------------------------------\n");
    for(i=1;i<=5;i++)
    {
        for(k=0;k<5;k++)
        {
            if(k==0 && bing_arr[i][k]==0)
            {
                bing_arr[i][k]=88; /*ASCII value of X*/
                printf("%c%4c%4c",div,bing_arr[i][k],div);
            }
            else if(k==0 && bing_arr[i][k]==88)
            {
                printf("%c%4c%4c",div,bing_arr[i][k],div);
            }
            else if(k==0 && bing_arr[i][k]!=0)
            {
                printf("%c%4d%4c",div,bing_arr[i][k],div);
            }
            else if(k==0 && bing_arr[i][k]!=88)
            {
                printf("%c%4d%4c",div,bing_arr[i][k],div);
            }
            else if(k!=0 && bing_arr[i][k]==0)
            {
                bing_arr[i][k]=88; /*ASCII value of X*/
                printf("%4c%4c",bing_arr[i][k],div);
            }
            else if(k!=0 && bing_arr[i][k]==88)
            {
                printf("%4c%4c",bing_arr[i][k],div);
            }
            else
            {
                printf("%4d%4c",bing_arr[i][k],div);
            }
        }
        printf("\n");
        printf("-----------------------------------------\n");
    }
}

int number_caller()
{
    static int i=0;
    int j=0,k=0;
    static int call_num_arr[100]={};
    int call_value=0;
    srand(time(0));

    do
    {
        k=0; /*this resets the value of k at each new loop.*/
        call_value = rand() % (75-1+1)+1;
        for(j=0;j<75;j++)
        {
            if(call_num_arr[j]==call_value)
            {
                k++;
            }
        }
    }
    while(k>0);
    if(i==75)
    {
        printf("All numbers between 1 and 75 have been called.\n");
        exit(0);
    }
    call_num_arr[i]=call_value;
    i++; /*counts the number of values called & used as call_num_arr array index.*/
    return call_value;
}

int num_Bingocard_checker(int bing_arr[][6],int random_num)
{
    int i=0, j=0, count=0;

    for(i=1;i<=5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(bing_arr[i][j]==random_num)
            {
                bing_arr[i][j]=0;
                count++;
            }
        }
    }
    if(count==1)
    {
        return 1; /*true*/
    }
    else if(count==0)
    {
        return 0; /*false*/
    }
}

int row_check(int bing_arr[][6])
{
    int i=1, j=0, count=0;
    do
    {
        count=0;
        for(j=0;j<5;j++)
        {
            if(bing_arr[i][j]==0 || bing_arr[i][j]==88)
            {
                count++;
            }
        }
        i++;
    }
    while(count!=5 && i<=5);
    if(count==5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int column_check(int bing_arr[][6])
{
    int i=0, j=0, count=0;
    do
    {
        count=0;
        for(j=1;j<=5;j++)
        {
            if(bing_arr[j][i]==0 || bing_arr[j][i]==88)
            {
                count++;
            }
        }
        i++;
    }
    while(count!=5 && i<5);

    if(count==5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




























