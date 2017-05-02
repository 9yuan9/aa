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
 printf("\n建立一个家谱二叉树（以空格结尾)：\n");
 while(contin)
 {
 if(first==1)
 {
  btree=(BTree)malloc(sizeof(struct treenode));
  printf("\t姓名：");
  gets(btree->name);
  btree->right=NULL;
  s=(BTree)malloc(sizeof(struct treenode));
  printf("\t妻子：");
  gets(s->name);
  s->left=s->right=NULL;
  btree->left=s;
  first=0;
 }
 else
 {
  printf("\t父亲：");
  gets(xm);
     if(strcmp(xm," ")==0)
  contin=0;
  else
  {
     p=findfather(btree,xm);
     if(p!=NULL)
     {
        p=p->left;
	 if(p==NULL)    /*没有妻子*/
		printf("\t没有儿子（因为没有妻子）\n");
	 else
	 {
		while(p->right!=NULL) p=p->right;
		s=(BTree)malloc(sizeof(struct treenode));
   		s->right=NULL;
		p->right=s;
		printf("\t儿子：");
		gets(s->name);
		printf("\t儿妻：");
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
	else printf("不存在这样的父结点！\n");
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
	printf("\n家谱凹入表示法:\n");
    top=1;
	stack[top]=BT;   /*根结点入栈*/
	level[top][0]=width;
	while (top>0)
      {
      p=stack[top];  /*退栈并凹入显示该结点值*/
	  n=level[top][0];
	  for (i=1;i<=n;i++)  /*其中n为显示场宽,字符以右对齐显示*/
	      printf(" ");
	  printf("%6s",p->name);
	  for(i=n+1;i<=MaxWidth-6;i+=2)
	      printf("━");
	  printf("\n");
	  top--;
      if(p->right!=NULL)
      {               /*将右子树根结点入栈*/
	    top++;
	    stack[top]=p->right;
	    level[top][0]=n+width;   /*显示场宽增width*/
	    level[top][1]=2;
          }
          if (p->left!=NULL)
          {               /*将左子树根结点入栈*/
	    top++;
           stack[top]=p->left;
	    level[top][0]=n+width;   /*显示场宽增width*/
	    level[top][1]=1;
          }
        }
      }
    }


 void findson(BTree bt)
    {
	char xm[10];
	BTree p;
	printf("\n查找指定父亲的所有儿子\n");
	printf("父亲：");
 	gets(xm);
	p=findfather(bt,xm);
	if(p==NULL)
	   printf("不存在%s的父亲！\n",xm);
	else
       {
 	   p=p->left;
	   p=p->right;
	   if(p==NULL)
	     printf("%s没有儿子!\n",xm);
	   else
          {
	     printf("%s有以下儿子!\n\t",xm);
	     while(p!=NULL)
		{
  		  printf("%8s  ",p->name);
	         p=p->right;
		}
	     }
	   }
	}