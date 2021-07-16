#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pack{
    char name[200];
    int size;
}/*打包文件所需数据*/
int getsize(char* name)/*获取文件大小*/
{
    FILE* fp;
    int size;
    if((fp=fopen(name,"r"))=NULL)
    return -1;
    fseek(fp,0,SEEK_END);/*指针移动到文件最后*/
    size=ftell(fp);/*判断文件大小*/
    rewind(fp);/*指针返回文件首位置*/
    fclose(fp);
    return size;
}
int main(int argc,char *argv[])
{
    int num=argc-1;/*打包文件个数*/
    FILE* fp;/*打包后文件*/
    FILE* fd;/*工具文件*/
    int r;
    char a[1024];/*工具数组*/
    struct pack *info=(struct pack*)malloc(num*sizeof(struct pack));
    for(int i=0;i<num;i++)
    {
       info[i].size=getsize(argv[i+1]);
       strcpy(info[i].name,argv[i+1]);
       printf("%d %s %ld\n",i,info[i].name,info[i].size);
    }/*获取文件信息*/
    fp=fopen("packed.c","wb");
    if(fp==NULL)
    return -1;
    fwrite(&num,1,4,fp);/*写入打包文件个数*/
    fwrite(info,1,num*sizeof(struct pack),fp);/*写入文件信息*/
    for(int i=0;i<num;i++)
    {
        fd=fopen(info[i].name,"rb");
        if(fd==NULL)
        return -1;
        while(1)
        {
            r=fread(a,1,1024,fd);
            if(r>0)
            {
                fwrite(a,1,r,fp);
            }
            else
            {
                break;
            }
        }/*写入文件内容*/
        fclose(fd);
    }
    fclose(fp);
    return 0;
}