/**
Name: MUBTASIM AHMED RAKHEEN
UTA ID: 1001848135 
CODING ASSIGNMENT 3
**/
#include <stdio.h>
#include <stdlib.h>

void Rand_num_fillbingo(int bing_arr[][5]); /*Prints bingo card with random numbers*/
void Bingo_card(int bing_arr[][5]); /*Prints bingo card*/
int number_caller(); /*Calls number for bingo card*/
bool num_Bingocard_checker(int bing_arr[][5],int random_num); /*checks bingo card for matched numbers*/
bool row_check(int bing_arr[][5]); /*checks bingo card for matched rows*/
bool column_check(int bing_arr[][5]); /*checks bingo card for matched columns*/

int main(void)
{
    int bing_arr[6][6]={};
    bing_arr[0][0]= 66; /*ASCII Value for 'B'*/
    bing_arr[0][1]= 73; /*ASCII Value for 'I'*/
    bing_arr[0][2]= 78; /*ASCII Value for 'N'*/
    bing_arr[0][3]= 71; /*ASCII Value for 'G'*/
    bing_arr[0][4]= 79; /*ASCII Value for 'O'*/
}

void Rand_num_fillbingo(int bing_arr[][5])
{
    int i=0, j=0, k=0, l=0, bing_value=0; 

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

            for(k=0;k<5;k++)   
            {
                for(l=0;l<5;l++)
                {
                    LABEL1: if(bing_arr [k+1][l] == bing_value)
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
                        go to LABEL1;
                    }
                }
            }
            bing_arr[i+1][j] = bing_value; 
        }    
    }
    bing_arr[2][2]=0;
}

void Bingo_card(int bing_arr[][5])
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
            printf("%9c",bing_arr[0][i]);
        }   
    }
    printf("\n");
    printf("---------------------------------------------\n");
    for(i=1;i<=5;i++)
    {
        for(k=0;k<5;k++)
        {
            if(k==0)
            {
                printf("%c%4d%4c",div,bing_arr[i][k],div); 
            }
            else
            {
                printf("%4d%4c",bing_arr[i][k],div);
            }
        }
        printf("\n");
        printf("---------------------------------------------\n");
    }
}

int number_caller()
{
    
}

























