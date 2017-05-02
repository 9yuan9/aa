#define MaxWidth 40
#define MaxSize 30
typedef struct treenode
{
 char name[10];
 struct treenode *left,*right;
 } *BTree;


BTree findfather(BTree p,char xm[])
{
  BTree bt;
  if(p==NULL) return(NULL);
  else
{
  if(strcmp(p->name,xm)==0)
    return(p);
  else
 {
  bt=findfather(p->left,xm);
  if(bt!=NULL) return(bt);
  else return(findfather(p->right,xm));
  }
}
}


BTree creatree()
{
 int n,m,i,contin=1,first=1;
 char xm[10];
 BTree btree,s,t,p;
 printf("\n����һ�����׶��������Կո��β)��\n");
 while(contin)
 {
 if(first==1)
 {
  btree=(BTree)malloc(sizeof(struct treenode));
  printf("\t������");
  gets(btree->name);
  btree->right=NULL;
  s=(BTree)malloc(sizeof(struct treenode));
  printf("\t���ӣ�");
  gets(s->name);
  s->left=s->right=NULL;
  btree->left=s;
  first=0;
 }
 else
 {
  printf("\t���ף�");
  gets(xm);
     if(strcmp(xm," ")==0)
  contin=0;
  else
  {
     p=findfather(btree,xm);
     if(p!=NULL)
     {
        p=p->left;
	 if(p==NULL)    /*û������*/
		printf("\tû�ж��ӣ���Ϊû�����ӣ�\n");
	 else
	 {
		while(p->right!=NULL) p=p->right;
		s=(BTree)malloc(sizeof(struct treenode));
   		s->right=NULL;
		p->right=s;
		printf("\t���ӣ�");
		gets(s->name);
		printf("\t���ޣ�");
		gets(xm);
		if(strcmp(xm,"")!=0)
		{
			t=(BTree)malloc(sizeof(struct treenode));
			strcpy(t->name,xm);
			t->left=t->right=NULL;
			s->left=t;
		}
		else s->left=NULL;
	   }
	}
	else printf("�����������ĸ���㣡\n");
	}
     }
  }
  return(btree);
}


void disptree(BTree BT)
{
      BTree stack[MaxSize],p;
      int level[MaxSize][2],top,n,i,width=4;
      if(BT!=NULL)
      {
	printf("\n���װ����ʾ��:\n");
    top=1;
	stack[top]=BT;   /*�������ջ*/
	level[top][0]=width;
	while (top>0)
      {
      p=stack[top];  /*��ջ��������ʾ�ý��ֵ*/
	  n=level[top][0];
	  for (i=1;i<=n;i++)  /*����nΪ��ʾ����,�ַ����Ҷ�����ʾ*/
	      printf(" ");
	  printf("%6s",p->name);
	  for(i=n+1;i<=MaxWidth-6;i+=2)
	      printf("��");
	  printf("\n");
	  top--;
      if(p->right!=NULL)
      {               /*���������������ջ*/
	    top++;
	    stack[top]=p->right;
	    level[top][0]=n+width;   /*��ʾ������width*/
	    level[top][1]=2;
          }
          if (p->left!=NULL)
          {               /*���������������ջ*/
	    top++;
           stack[top]=p->left;
	    level[top][0]=n+width;   /*��ʾ������width*/
	    level[top][1]=1;
          }
        }
      }
    }


 void findson(BTree bt)
    {
	char xm[10];
	BTree p;
	printf("\n����ָ�����׵����ж���\n");
	printf("���ף�");
 	gets(xm);
	p=findfather(bt,xm);
	if(p==NULL)
	   printf("������%s�ĸ��ף�\n",xm);
	else
       {
 	   p=p->left;
	   p=p->right;
	   if(p==NULL)
	     printf("%sû�ж���!\n",xm);
	   else
          {
	     printf("%s�����¶���!\n\t",xm);
	     while(p!=NULL)
		{
  		  printf("%8s  ",p->name);
	         p=p->right;
		}
	     }
	   }
	}