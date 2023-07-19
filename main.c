#include <stdio.h>
#include <stdlib.h>
char winner(char arr[3][3]);
int main()
{
    char arr[3][3]={'1','2','3','4','5','6','7','8','9'};
    char c;char z='f';char player='x';int i;int j;int b=3;
    while(z=='f')
    {
        system("cls");
        for( i=0;i<3;i++){
            for( j=0;j<3;j++)
            {
                printf("%c ",arr[i][j]);
            }
            printf("\n");
        }
        printf("choose the position for player %c",player);scanf(" %c",&c);
        for(i=0;i<3;i++)
        {
            for( j=0;j<3;j++)
            {
                if(arr[i][j]==c)
                    arr[i][j]=player;
            }
        }
        if(player=='x')
            player='o';
        else
            player='x';
        char p=winner(arr);
        if(p=='x')
            {printf("the winner is player %c",p);z='t';}
        else if(p=='o')
           {printf("the winner is player %c",p);z='t';}
        else if(p=='n')
        {printf("there is no winner");z='t';}
        else
        {printf("the game is not finished");z='f';}

    }
    return 0;
}
char winner(char arr[3][3])
{
    int counter1=0;int counter2=0;int counter3=0;int i,j;//char l='x';char o='o';
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]=='x')
                counter1++;
            else if(arr[i][j]=='o')
                counter2++;
            if(counter1==3||counter2==3)
            {
                if(counter1>counter2)
                    return 'x';
                else
                    return 'o';
            }
        }
        counter1=0;counter2=0;
    }
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            if(arr[i][j]=='x')
                counter1++;
            else if(arr[i][j]=='o')
                counter2++;
            if(counter1==3||counter2==3)
            {
                if(counter1>counter2)
                    return 'x';
                else
                    return 'o';
            }
        }
        counter1=0;counter2=0;
    }
    if(arr[0][0]=='x'&&arr[1][1]=='x'&&arr[2][2]=='x')
        return 'x';
    if(arr[0][0]=='o'&&arr[1][1]=='o'&&arr[2][2]=='o')
        return 'o';
    if(arr[0][2]=='x'&&arr[1][1]=='x'&&arr[2][0]=='x')
        return 'x';
    if(arr[0][2]=='o'&&arr[1][1]=='o'&&arr[2][0]=='o')
        return 'o';
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]!='x'&&arr[i][j]!='o')
                counter3++;
        }
    }
    if(counter3==0)
        return 'n';
    return 'f';
}
