#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"epuipment.h"
struct device *creatnode(void)
{
    pdevice p=NULL;
    if((p=(struct device *)malloc(sizeof(struct device)))!=NULL)
        p->next=NULL;
    else
        {
            printf("�ռ䲻���޷�������Ϣ");
            return NULL;
        }
    return p;
}
int find(pdevice *p,pdevice *q,int *infor)
{
    if(head==NULL)
    {
        *q=*p=NULL;
        return 0;
    }
    pdevice prev,cur;
    for(prev=NULL,cur=head;(cur!=NULL)&&((*infor)>(cur->serialNum));prev=cur,cur=cur->next)
        ;
    *p=prev;
    *q=cur;
    if((cur!=NULL)&&((*infor)==(cur->serialNum)))
        return 1;
    else
        return 0;
}
void insert()
{
    pdevice prev,cur,p;
    if((p=creatnode())!=NULL)
    {
        printf("�������豸���\n");
        scanf("%d",&(p->serialNum));
        if(find(&prev,&cur,&(p->serialNum))==1)
        {
        printf("������ı���Ѵ��ڣ�\n");
        return;
        }
        getchar();
        printf("�������豸����\n");
        gets(p->name);
        printf("�������豸����ʵ��������\n");
        gets(p->position);
        printf("������ʹ��������\n");
        gets(p->user);
        printf("�������豸�۸�\n");
        scanf("%lf",&(p->price));
        getchar();
        printf("�������豸����\n");
        gets(p->Class);
        insert_type(p->Class);
        printf("�������豸�������ڣ���20090101\n");
        gets(p->date);
        if(prev==NULL)//ͷ��
        {
            p->next=head;
            head=p;
        }
        else
        {
            prev->next=p;
            p->next=cur;
        }
    }

}
void change()
{
    pdevice p=NULL,q=NULL;
    int num;
    printf("�������豸���\n");
    scanf("%d",&num);
    if(find(&p,&q,&num)==0)
    {
        printf("�ñ�Ų���������������");
        return;
    }

    for(;;)
    {
        printf("��ѡ���޸���Ŀ����Ų����޸ģ�\n");
        printf("�޸��豸��������1\n�޸��豸����ʵ��������2\n�޸�ʹ������������3\n�޸��豸�۸�����4\n�޸��豸��������5\n�޸��豸������������6\n");
        printf("���ٽ����޸�����7\n");
        int a;
        scanf("%d",&a);
        getchar();
        if(a!=7)
            printf("�������޸ĺ����Ϣ��\n");
        getchar();
        switch(a)
        {
        case 1:gets(q->name);break;
        case 2:gets(q->position);break;
        case 3:gets(q->user);break;
        case 4:scanf("%lf",&(q->price));getchar();break;
        case 5:delete_type(q->Class);gets(q->Class);insert_type(q->Class);break;//�豸����
        case 6:gets(q->date);break;
        }
        if(a==7)
        return;
        getchar();
    }
}
void Delete()
{
   pdevice p=NULL,q=NULL;
   int num;
   printf("�������豸���\n");
   scanf("%d",&num);
   if(find(&p,&q,&num)!=0)
   {
       printf("�豸��Ϣ�ѱ�ɾ��");
       p->next=q->next;
       free(q);
   }
}
void Search ()
{
    printf("��ѡ���ѯ��ʽ\n");
    printf("����Ų�ѯ������1���۸��ѯ������2");
    printf("������ʽ��ѯ������3");
    int a,m;
    double b;
    pdevice p;
    char information[30];
    scanf("%d",&a);
    getchar();
    if(a==1)
    {
        printf("��������\n");
        scanf("%d",&m);
        for(p=head;p!=NULL;p=p->next)
        {
            if(m==(p->serialNum))
                print(p);
        }
    }
    else if(a==2)
    {
        printf("������۸�\n");
        scanf("%lf",&b);
        for(p=head;p!=NULL;p=p->next);
        {
            if(b==(p->price))
              {
                  print(p);
              }
        }
        if(p==NULL)
            return;
    }
    else if(a==3)
    {
        printf("�������ѯ����\n");
        gets(information);
        for(p=head;p!=NULL;p=p->next)
        {
            if(strcmp(information,p->Class)==0||strcmp(information,p->date)==0||strcmp(information,p->name)==0||strcmp(information,p->position)==0||strcmp(information,p->user)==0)
                print(p);
        }
    }
}
void print(pdevice p)
{
    printf("�豸���ƣ�%s\n�豸��ţ�%d\n�豸����ʵ�������ƣ�%s\nʹ����������%s\n�豸�۸�%lf\n�豸���ࣺ%s\n�豸�������ڣ�%s\n",p->name,p->serialNum,p->position,p->user,p->price,p->Class,p->date);

}
void insert_type(char *a)
{
    if(first==NULL)
    {
        first=malloc(sizeof(struct type));
        if(first==NULL)
           {
                printf("�ռ䲻�㣬�޷�������Ϣ");
                return;
           }
        first->next=NULL;
        strcpy(first->kind,a);
        first->num=1;
    }
    else
    {
        int i=0;
        ptype p,q;
        for(p=NULL,q=first;q!=NULL;p=q,q=q->next)
        {
              if(strcmp(a,q->kind)==0)
              {
                  q->num++;
                  i++;
                  return;
              }
        }
        if(i==0)
        {
            q=malloc(sizeof(struct type));
            strcpy(p->kind,a);
            q->num=1;
            q->next=NULL;
            p->next=q;
        }
    }
}
void delete_type(char *a)
{
    ptype p;
    for(p=first;p!=NULL;p=p->next)
    {
        if(strcmp(p->kind,a)==0)
        {
            p->num--;
            return;
        }
    }
}
void search_type()
{
    ptype p;
    for(p=first;p!=NULL;p=p->next)
    {
        printf("%s:%d",p->kind,p->num);
    }
}









