#include<stdio.h>
#include<alloc.h>
#define n 10
void pack()
{
    FILE * g_fp;/*总文件*/
    FILE * fp[n];/*分文件*/
    char *a;
    int i=0;
    for(i=0;i<n;i++)
    {
        if((fp[i]=fopen("data[i].txt","r")==NULL))
        {
            printf("\nOpen file error,press any key exit!");
            getchar();
            exit(0);
        }
              if((g_fp=fopen("data.txt","w")==NULL))
        {
            printf("\nOpen file error,press any key exit!");
            getchar();
            exit(0);
        }
        a=(char *)malloc(sizeof(fp[i])+1);
        fgets(a,sizeof(a),fp[i])/*从分文件中读出*/
        fputs(a,g_fp);/*写入主文件*/
        free(a);
        fclose(fp[i]);
        fclose(g_fp);
    }
}
void unpack()
{
    FILE * g_fp;/*总文件*/
    FILE * fp[n];/*分文件*/
    int i=0;
    for(i=0;i<n;i++)
    {
        if((fp[i]=fopen("data[i].txt","w")==NULL))
        {
            printf("\nOpen file error,press any key exit!");
            getchar();
            exit(0);
        }
        if((g_fp=fopen("data.txt","r")==NULL))
        {
            printf("\nOpen file error,press any key exit!");
            getchar();
            exit(0);
        }
        a=(char *)malloc(sizeof(fp[i])+1); 
        fgets(a,sizeof(a),g_fp);
        fputs(a,fp[i]);
        fclose(g_fp);
        fclose(fp[i]);
        free(a);
    }
}