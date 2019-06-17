#include<stdio.h>
#include<stdlib.h>
#define max 100

int main()
{
    int in[max][max],out[max][max];
    int i,j,x=0;
    int row,col;
    char *p_f[max];


    FILE *FP;
    FILE *fp;
    if((FP=fopen("p_matrix.txt","rt"))==NULL)
    {
       printf("cannot open file!\n");
       return;
    }

    fscanf(FP,"%d",&row);
    fscanf(FP,"%d",&col);

    for(i=0;i<row;i++)
    {
       for(j=0;j<col;j++)
       fscanf(FP,"%d",&in[i][j]);
       fscanf(FP,"\n");
    }

    for(i=0;i<row;i++)
    {
       for(j=0;j<col;j++)
       fscanf(FP,"%d",&out[i][j]);
       fscanf(FP,"\n");
    }
    fclose(FP);


    printf("%d %d\n",row,col);

    for(i=0;i<row;i++)
    {
       for(j=0;j<col;j++)
       {
          printf("%d ",in[i][j]);
       }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<row;i++)
    {
       for(j=0;j<col;j++)
       {
          printf("%d ",out[i][j]);
       }
        printf("\n");
    }

    sprintf(p_f,"petri.gv");
    fp=fopen(p_f,"w");
    fprintf(fp,"digraph petri{\n");
    fprintf(fp,"rankdir=BT\n");
    for(i=0;i<col;i++)
    {
         fprintf(fp,"P%d[label=P%d,shape=circle]\n",i+1,i+1);
    }
    for(j=0;j<row;j++)
    {
        fprintf(fp,"T%d[label=T%d,shape=box]\n",j+1,j+1);
    }
    for(i=0;i<col;i++)
    {

         for(j=0;j<row;j++)
         {

          if(in[j][i]==1)
          {
               fprintf(fp,"P%d->T%d\n",i+1,j+1);

          }
          if(in[j][i]!=0&&in[j][i]!=1)
          {
              fprintf(fp,"P%d->T%d[label=%d]\n",i+1,j+1,in[j][i]);
          }


          if(out[j][i]==1)
         {

               fprintf(fp,"T%d->P%d\n",j+1,i+1);
         }
          if(out[j][i]!=0&&out[j][i]!=1)
          {
              fprintf(fp,"T%d->P%d[label=%d]\n",j+1,i+1,out[j][i]);
          }
         }

    }

    fprintf(fp,"\n}");


    }





