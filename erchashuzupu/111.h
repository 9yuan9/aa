#define MAXSIZE 100
typedef int datatype;
typedef struct {
	datatype a[MAXSIZE];
	int size;
}sequence_list;

typedef struct linknode{
	datatype info;
	struct linknode *next;

}node;

/*****************************************************/
/*  �������ܣ�����һ���յĵ�����                     */
/*  ������������                                     */
/*  ��������ֵ��ָ��node���ͱ�����ָ��              */
/*  �ļ�����slnklist.c����������init()                    */
/******************************************************/
 node *init() /*����һ���յĵ�����*/
 {
   return NULL;
 }


/****************************************************/
/*  �������ܣ�����������и�������ֵ              */
/*  ����������ָ��node���ͱ�����ָ��head           */
/*  ��������ֵ����                                  */
/*  �ļ���slnklist.c��������display()                  */
/*****************************************************/
 void display(node *head)
 {
   node *p;
   p=head;
   if(!p) printf("\n�������ǿյģ�");
   else
     {
       printf("\n��������������ֵΪ��\n");
       while(p) { printf("%5d",p->info);p=p->next;}
     }
 }


/*****************************************************/
/*  �������ܣ��ڵ������в��ҵ�i�����Ĵ�ŵ�ַ     */
/*  ����������ָ��node���ͱ�����ָ��head��int�ͱ���i*/
/*  ��������ֵ��ָ��node���ͱ�����ָ��              */
/*  �ļ�����slnklist.c����������find()                  */
/*****************************************************/
 node *find(node *head,int i)
 {
   int j=1;
   node *p=head;
   if(i<1) return NULL;
   while(p&&i!=j)
   {
     p=p->next;j++;
   }
   return p;
 }


/*****************************************************/
/*  �������ܣ���������i���������ֵΪx���½��   */
/*  ����������ָ��node���ͱ�����ָ��head            */
/*            datatype ���ͱ���x��int�ͱ���i          */
/*  ��������ֵ��ָ��node���ͱ�����ָ��              */
/* �ļ�����slnklist.c����������insert()       */
/*****************************************************/
 node *insert(node *head,datatype x,int i)
 {
   node *p,*q;
   q=find(head,i);/*���ҵ�i�����*/
   if(!q&&i!=0)
       printf("\n�Ҳ�����%d����㣬���ܲ���%d��",i,x);
   else{
        p=(node*)malloc(sizeof(node));/*����ռ�*/
        p->info=x;/*�����½��*/
        if(i==0){/* ����Ľ����Ϊ�������ĵ�һ�����*/
                  p->next=head;  /*����(1)*/
                  head=p; /*����(2)*/
                }
        else {
              p->next=q->next;/*����(1)*/
              q->next=p;/*����(2)*/
             }
       }
   return head;
 }


/*****************************************************/
/*  �������ܣ��ڵ�������ɾ��һ��ֵΪx�Ľ��         */
/*  ����������ָ��node���ͱ�����ָ��head            */
/*            datatype ���ͱ���x                      */
/*  ��������ֵ��ָ��node���ͱ�����ָ��              */
/*  �ļ�����slnklist.c,��������dele()                  */
/*****************************************************/
 node *dele(node *head,datatype x)
 {
   node *pre=NULL,*p;
   if(!head) {printf("�������ǿյģ�\n");return head;}
   p=head;
   while(p&&p->info!=x)/*û���ҵ�����û������*/ 
     {pre=p;p=p->next;}/*preָ��p��ǰ�����*/
  
   if (p)   			         /*�ҵ��˱�ɾ�����*/
     {  if  (!pre)  head=head->next;  /*Ҫɾ�����ǵ�һ�����*/
        else  pre->next=p->next;
        free(p);
     }

   return head;
 }








