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
            printf("空间不足无法储存信息");
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
        printf("请输入设备编号\n");
        scanf("%d",&(p->serialNum));
        if(find(&prev,&cur,&(p->serialNum))==1)
        {
        printf("您输入的编号已存在！\n");
        return;
        }
        getchar();
        printf("请输入设备名称\n");
        gets(p->name);
        printf("请输入设备所在实验室名称\n");
        gets(p->position);
        printf("请输入使用者姓名\n");
        gets(p->user);
        printf("请输入设备价格\n");
        scanf("%lf",&(p->price));
        getchar();
        printf("请输入设备种类\n");
        gets(p->Class);
        insert_type(p->Class);
        printf("请输入设备购买日期，如20090101\n");
        gets(p->date);
        if(prev==NULL)//头插
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
    printf("请输入设备编号\n");
    scanf("%d",&num);
    if(find(&p,&q,&num)==0)
    {
        printf("该编号不存在请重新输入");
        return;
    }

    for(;;)
    {
        printf("请选择修改项目（编号不可修改）\n");
        printf("修改设备名称输入1\n修改设备所在实验室输入2\n修改使用者姓名输入3\n修改设备价格输入4\n修改设备种类输入5\n修改设备购买日期输入6\n");
        printf("不再进行修改输入7\n");
        int a;
        scanf("%d",&a);
        getchar();
        if(a!=7)
            printf("请输入修改后的信息：\n");
        getchar();
        switch(a)
        {
        case 1:gets(q->name);break;
        case 2:gets(q->position);break;
        case 3:gets(q->user);break;
        case 4:scanf("%lf",&(q->price));getchar();break;
        case 5:delete_type(q->Class);gets(q->Class);insert_type(q->Class);break;//设备种类
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
   printf("请输入设备编号\n");
   scanf("%d",&num);
   if(find(&p,&q,&num)!=0)
   {
       printf("设备信息已被删除");
       p->next=q->next;
       free(q);
   }
}
void Search ()
{
    printf("请选择查询方式\n");
    printf("按编号查询请输入1按价格查询请输入2");
    printf("其他方式查询请输入3");
    int a,m;
    double b;
    pdevice p;
    char information[30];
    scanf("%d",&a);
    getchar();
    if(a==1)
    {
        printf("请输入编号\n");
        scanf("%d",&m);
        for(p=head;p!=NULL;p=p->next)
        {
            if(m==(p->serialNum))
                print(p);
        }
    }
    else if(a==2)
    {
        printf("请输入价格\n");
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
        printf("请输入查询依据\n");
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
    printf("设备名称：%s\n设备编号：%d\n设备所在实验室名称：%s\n使用者姓名：%s\n设备价格：%lf\n设备种类：%s\n设备购买日期：%s\n",p->name,p->serialNum,p->position,p->user,p->price,p->Class,p->date);

}
void insert_type(char *a)
{
    if(first==NULL)
    {
        first=malloc(sizeof(struct type));
        if(first==NULL)
           {
                printf("空间不足，无法储存信息");
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









