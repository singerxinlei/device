#ifndef EPUIPMENT_H_INCLUDED
#define EPUIPMENT_H_INCLUDED
typedef struct device{
char name[30];//�豸����
int serialNum;//�豸��ţ����ظ���
char position[30];//�豸����ʵ��������
char user[20];//ʹ��������
double price;//�豸�۸�
char Class[20];// �豸����(�磺΢������ӡ����ɨ���ǵȵ�)
char date[20];//�豸�������ڣ���20090101��
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
