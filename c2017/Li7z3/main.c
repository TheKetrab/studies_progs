#include <stdio.h>
#include <stdlib.h>

char plansza[100][100];
int licznik=1; //bo zrodlo zajmuje 1

void wylej_wode(int n, int m, char c)
{
    if(plansza[n][m]!='#' && plansza[n][m]!='!' && plansza[n][m]!='X')
    {
        plansza[n][m]=c;
        licznik++;
    }
}


int main()
{
    int n,m; //wiersze,kolumny
    int t=0; //czas

    scanf(" %d %d",&n,&m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf(" %c",&plansza[i][j]);

            if(plansza[i][j]=='#') licznik++;
        }
    }


    while(licznik < m*n && t < m*n)
    {

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(plansza[i][j]=='!' && t%2==0)
                {
                    if(j-1>=0) wylej_wode(i,j-1,'X');
                    if(j+1<m) wylej_wode(i,j+1,'X');
                    if(i-1>=0) wylej_wode(i-1,j,'X');
                    if(i+1<n) wylej_wode(i+1,j,'X');
                }

                if(plansza[i][j]=='X' && t%2==1)
                {
                    if(j-1>=0) wylej_wode(i,j-1,'!');
                    if(j+1<m) wylej_wode(i,j+1,'!');
                    if(i-1>=0) wylej_wode(i-1,j,'!');
                    if(i+1<n) wylej_wode(i+1,j,'!');
                }

            }
        }


        t++;

    }

    if(licznik < m*n-1)
    {
        printf("-1");
        return 0;
    }

    printf("%d",t);

    return 0;
}

