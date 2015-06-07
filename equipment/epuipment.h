#ifndef EPUIPMENT_H_INCLUDED
#define EPUIPMENT_H_INCLUDED
typedef struct device{
char name[30];//设备名称
int serialNum;//设备编号（不重复）
char position[30];//设备所在实验室名称
char user[20];//使用者姓名
double price;//设备价格
char Class[20];// 设备种类(如：微机、打印机、扫描仪等等)
char date[20];//设备购买日期，如20090101等
struct device *next;
}device,*pdevice;
typedef struct type{
    char kind[20];
    int num;
    struct type *next;
}type,*ptype;
extern pdevice head;
extern ptype first;
struct device *creatnode(void);
int find(pdevice *p,pdevice *q,int *infor);
void insert();
void change();
void print(pdevice p);
void Search ();
void Delete();
void insert_type(char *a);
void search_type();
void delete_type(char *a);
#endif // EPUIPMENT_H_INCLUDED
