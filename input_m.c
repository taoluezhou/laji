#include<stdio.h>
#define max 100

int main()
{
    int row=0,col=0;
    int i=0;
    int j=0;
    int x_col[max];
    char *pm[max];
    FILE *fp;
    printf("������������\n");
    scanf("%d",&row);
    printf("������������\n");
    scanf("%d",&col);
    sprintf(pm,"p_matrix.txt");
    fp=fopen(pm,"w");
    fprintf(fp,"%d\n",row);
    fprintf(fp,"%d\n",col);
    fprintf(fp,"\n");
    printf("�������\n");
    for(i=1;i<=row;i++)
    {
        printf("�������%d�е�%d������\n",i,col);
        for(j=0;j<col;j++)
        {
            scanf("%d",&x_col[j]);
            fprintf(fp,"%d ",x_col[j]);
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"\n");
    printf("�������\n");
    for(i=1;i<=row;i++)
    {
        printf("�������%d�е�%d������\n",i,col);
        for(j=0;j<col;j++)
        {
            scanf("%d",&x_col[j]);
            fprintf(fp,"%d ",x_col[j]);
        }
        fprintf(fp,"\n");
    }
}
