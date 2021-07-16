#include<stdio.h>
struct pack{
    char name[200];
    int size;
}/*解包文件所需数据*/
int main(int argc,char *argv[])
{
    int num;
    FILE*fd;
    char c;
    int r;
    FILE*fp=fopen(argv[1],"rb");
    if(fp=NULL)
    return -1;
    fread(&num,1,4,fp)/*读出文件个数*/
    struct pack *info=(struct pack*)malloc(num*sizeof(struct pack));
    fread(info,1,num*sizeof(struct pack),fp);/*读出文件信息*/
    int j;
    for(i=0;i<num,i++)
    {
        fd=fopen(info[i].name,"wb");
        for(j=0;j<info[i].size;j++)
        {
            fread(&c,1,1,fp);
            fwrite(&c,1,1,fd);
        }
        fclose(fd);
    }
    fclose(fp);
    return 0;
}