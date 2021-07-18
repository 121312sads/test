#include<stdio.h>
#include<string.h>
struct filesort{
    char name[200];
    int size;
};/*文件所需数据*/
void putsize(char* name)/*输出文件大小*/
{
    FILE* fp;
    double size;
    if((fp=fopen(name,"r"))==NULL)
    return -1;
    fseek(fp,0,SEEK_END);/*指针移动到文件最后*/
    size=ftell(fp);/*判断文件大小*/
    rewind(fp);/*指针返回文件首位置*/
    fclose(fp);
    char a[4]={" ","k","M","G"};
    int i=0;
    while(size>=1024)
    {
        size=size/1024;
        i++;
    }
    if(size<10)
    printf("%.1lf%c",size,a[i]);
    else
    {size=(int)size;
    printf("%d%c",size,a[i]);
    }
}
int main(int argc,char *argv[])
{
    FILE* fp;
    int i;
    int num=argc-1;/*文件个数*/
    struct filesort *info;/*变量*/
    for(int i=0;i<num;i++)
    {
       strcpy(info[i].name,argv[i+1]);
    }/*获取文件名*/
    FILE *fd;/*工具文件*/
    int j;
    for(i=0,i<num,i++)
    {
    if((fd=fopen("filesort.c","r+"))==NULL)
    return -1;
    fputs(argv[i+1],fd);/*将文件名读入工具文件中*/
    ch=fgetc(fd);
    printf(".");
    if(ch==".")/*是否为空扩展名*/
    {
        printf("\ninfo[i].name");/*文件名*/
        putsize(info[i].name);/*文件大小*/
    }
    fseek(fd,-4L,SEEK_END);
    for(j=0;j<3;j++)/*认为扩展名最长三位，最短一位*/
    {ch=fgetc(fd);
    if(ch==".")
    {
        printf("%s",fgets(fd));/*输出扩展名*/
        printf("\ninfo[i].name");
        putsize(info[i].name);
    }
    }
    fclose(fd);
    remove("filesort.c");
    }
    return 0;
}
