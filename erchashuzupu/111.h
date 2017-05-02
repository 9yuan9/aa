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
/*  函数功能：建立一个空的单链表                     */
/*  函数参数：无                                     */
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：slnklist.c，函数名：init()                    */
/******************************************************/
 node *init() /*建立一个空的单链表*/
 {
   return NULL;
 }


/****************************************************/
/*  函数功能：输出单链表中各个结点的值              */
/*  函数参数：指向node类型变量的指针head           */
/*  函数返回值：空                                  */
/*  文件名slnklist.c，函数名display()                  */
/*****************************************************/
 void display(node *head)
 {
   node *p;
   p=head;
   if(!p) printf("\n单链表是空的！");
   else
     {
       printf("\n单链表各个结点的值为：\n");
       while(p) { printf("%5d",p->info);p=p->next;}
     }
 }


/*****************************************************/
/*  函数功能：在单链表中查找第i个结点的存放地址     */
/*  函数参数：指向node类型变量的指针head，int型变量i*/
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：slnklist.c，函数名：find()                  */
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
/*  函数功能：单链表第i个结点后插入值为x的新结点   */
/*  函数参数：指向node类型变量的指针head            */
/*            datatype 类型变量x，int型变量i          */
/*  函数返回值：指向node类型变量的指针              */
/* 文件名：slnklist.c，函数名：insert()       */
/*****************************************************/
 node *insert(node *head,datatype x,int i)
 {
   node *p,*q;
   q=find(head,i);/*查找第i个结点*/
   if(!q&&i!=0)
       printf("\n找不到第%d个结点，不能插入%d！",i,x);
   else{
        p=(node*)malloc(sizeof(node));/*分配空间*/
        p->info=x;/*设置新结点*/
        if(i==0){/* 插入的结点作为单链表的第一个结点*/
                  p->next=head;  /*插入(1)*/
                  head=p; /*插入(2)*/
                }
        else {
              p->next=q->next;/*插入(1)*/
              q->next=p;/*插入(2)*/
             }
       }
   return head;
 }


/*****************************************************/
/*  函数功能：在单链表中删除一个值为x的结点         */
/*  函数参数：指向node类型变量的指针head            */
/*            datatype 类型变量x                      */
/*  函数返回值：指向node类型变量的指针              */
/*  文件名：slnklist.c,函数名：dele()                  */
/*****************************************************/
 node *dele(node *head,datatype x)
 {
   node *pre=NULL,*p;
   if(!head) {printf("单链表是空的！\n");return head;}
   p=head;
   while(p&&p->info!=x)/*没有找到并且没有找完*/ 
     {pre=p;p=p->next;}/*pre指向p的前驱结点*/
  
   if (p)   			         /*找到了被删除结点*/
     {  if  (!pre)  head=head->next;  /*要删除的是第一个结点*/
        else  pre->next=p->next;
        free(p);
     }

   return head;
 }









