#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"epuipment.h"
pdevice head=NULL;
ptype first=NULL;
int main()
{

    int code;
    if(head==NULL)
    printf("当前无设备信息建议您先录入信息");
    for(;;)
    {
        printf("请选择服务项目\n");
        printf("录入设备信息请输入1\n修改设备信息请输入2\n删除设备信息请输入3\n查询设备信息请输入4\n查询设备种类及数量请输入5\n安全退出请输入6\n");
        scanf("%d",&code);
        getchar();
        switch(code)
        {
            case 1:insert();break;
            case 2:change();break;
            case 3:Delete();break;
            case 4:Search();break;
            case 5:search_type();break;
            case 6:return 0;
            default:printf("输入错误请重新输入\n");
        }
    }
}
