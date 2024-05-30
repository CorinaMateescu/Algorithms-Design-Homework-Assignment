#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "codeeditor.h"

//minimum of three numbers
int min(int a,int b,int c) {
    if (a<b && a<c)
        return a;
    if (b<a && b<c)
        return b;
    return c;
}
//minimum edit distance
int min_edit_distance(char *fragment, char *correctsyntax) {
    int x=strlen(fragment);
    int y=strlen(correctsyntax);
    //creating a dp table
    int **dp=(int **)malloc((x+1)*sizeof(int *));
    for(int i=0;i<=x;i++)
    {
        dp[i]=(int *)malloc((y+1)*sizeof(int));
    }
    //initializing the table
    for(int i=0;i<=x;i++)
    {
        dp[i][0]=i;//delete
    }
    for(int j=0;j<=y;j++)
    {
        dp[0][j]=j;//insert
    }
    //filling the table
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(fragment[i-1]==correctsyntax[j-1])
            {
                dp[i][j]=dp[i-1][j-1];//no operation needed
            }
            else
            {
                dp[i][j]=min(dp[i-1][j-1]+1,//substitution
                             dp[i][j-1]+1,//insert
                             dp[i-1][j]+1);//delete
            }
        }
    }

    int result=dp[x][y];
    //free the memory
    for(int i=0;i<=x;i++)
    {
        free(dp[i]);
    }
    free(dp);
    return result;
}
