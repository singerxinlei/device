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
    printf("��ǰ���豸��Ϣ��������¼����Ϣ");
    for(;;)
    {
        printf("��ѡ�������Ŀ\n");
        printf("¼���豸��Ϣ������1\n�޸��豸��Ϣ������2\nɾ���豸��Ϣ������3\n��ѯ�豸��Ϣ������4\n��ѯ�豸���༰����������5\n��ȫ�˳�������6\n");
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
            default:printf("�����������������\n");
        }
    }
}
