
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

typedef struct node{
	struct node *next;
	int x,y; 						
	char name[100];
	int type;					
	int number; 				
	float distance; 		

}linklist;


void color(const unsigned short color1)
{        /*仅限改变0-15的颜色;如果在0-15那么实现他的颜色   因为如果超过15后面的改变的是文本背景色。*/
    if(color1>=0&&color1<=15)
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
        /*如果不在0-15的范围颜色，那么改为默认的颜色白色；*/
    else
   		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int password1()    ////密码系统 
{  
	int n=10086,x,i=0,j=0;
	system("cls");
	color(2);
	printf("please key password\n");
	
	char ch;
	char passWord[20]; //密码长度不要超过十九位
	while((ch=getch())!=13) //将输入的密码转换成字符****
	{ 
	putchar('*');
	passWord[j]=ch;
	j++;
	}
	passWord[j]='\0'; //字符数组的最后一位为'\0',故要加该语句
	x=atoi(passWord) ; 
	if(x==n) return 1;
	fflush(stdin);
	
	color(14);
	for(i;i<2;i++){	
		color(4);
		printf("\nwrong password,please input again\n");
		j=0;
		while((ch=getch())!=13) 
		{ 
				
			putchar('*');
			passWord[j]=ch;
			j++;
		}
		passWord[j]='\0'; //字符数组的最后一位为'\0',故要加该语句
		x=atoi(passWord) ; 
		if(x==n) return 1;

	}
	color(12);
	printf("\nPassword error three times\n\nBye-bye.\n\n");
	color(7);
	return 0;   //密码错误三次返回0
	

}



linklist *newshop(linklist *p)////新加商店   
{
	
	void revise1(linklist *head,int shopnumber); 
	void output1(linklist *n);
	
	linklist *head,*n;
	head=p;
	char ch;

	n=(linklist*)malloc(sizeof(linklist));
	color(2);
	printf("------------------------------------------------------");
	color(14);
	printf("\nplease key the coordinate(x,y)\n");
	scanf("%d,%d",&n->x,&n->y);
	fflush(stdin);    
	printf("please key the name of shop\n");
	gets(n->name);
	printf("please choose the type of shop\n\n");
	printf("[1.restaurant\n2.bank\n3.barber shop\n4.supermarket\n5.express\n6.entertainment \n7.cafe]\n\n");
	printf("the type is: ");
	scanf("%d",&n->type);
	fflush(stdin); 
	n->number=0;
	n->distance=0;
	n->next=NULL;
	
	output1(n);
	color(2);
	printf("------------------------------------------------------\n");
	color(14);

	printf("\nare you sure?(Y/N)\n");
	ch=getchar();
	
	while(ch=='N'){
		revise1(n,n->number);
		output1(n);
		printf("are you sure?(Y/N)\n");
		ch=getchar();
	}

	if(p==NULL)	{
		n->number=1;
		color(2);
		printf("Succeed\n");
		color(14);
		Sleep(200);
		return n;

	}
	else{
		while(p->next!=NULL){
			p=p->next;
		}
		n->number=p->number+1;
		p->next=n; ///误n=p->next;
		n->next=NULL;
		color(2);
		printf("Succeed\n");
		color(14);
		Sleep(200);
		
		return head;	
	}


}



linklist *delete1(linklist *head) ///删除商店 
{
	linklist *s,*r;
	s=head;

	int shopnumber;
	printf("please key the number of shop\n");
	scanf("%d",&shopnumber);

	if(s->number==shopnumber){ 	
		r=s->next;
		color(2);
		printf("succeed\n");
		color(14);
		free(s);
		Sleep(200);
		return r;
	}
	else {
		while(s->next->number!=shopnumber){
			s=s->next;
		}		////遍历匹配编号
		r=s->next;
		s->next=r->next;
		color(2);
		printf("succeed\n");
		color(14); 
		free(r);
		Sleep(200);
		return head;
	}

}



void revise1(linklist *head,int shopnumber) ////修改信息 
{
	void output1(linklist *n);
	
	
	linklist *s;
	s=head;
	

	while(s->number!=shopnumber){
		s=s->next;
	}
	color(13);
	printf("please key what you want revise:");
	printf("[1.name  2.coordinate  3.type]\n\n");
	int x;
	scanf("%d",&x);
	fflush(stdin);
	printf("\n");
	switch(x)
	{
		case 1:printf("please key the right name:");
				gets(s->name); 
				color(2);
				printf("succeed\n");
				color(14);
				Sleep(200);
				break;
		case 2:printf("please key the right coordinate(x,y):");
				scanf("%d,%d",&s->x,&s->y);
				fflush(stdin);
				color(2);
				printf("succeed\n");
				color(14);	
				Sleep(200);
				break;		
		case 3:printf("please key the right type:\n");
				printf("[1.restaurant\n2.bank\n3.barber shop\n4.supermarket\n5.express\n6.entertainment \n7.cafe]\n\n");
				scanf("%d",&s->type);
				fflush(stdin);
				color(2);
				
				printf("succeed\n");
				color(14);	
				Sleep(200);
				break;

	}
	color(7);



}



void revise2(linklist *n)  ///自定义修改信息 
{
	void revise1(linklist *head,int shopnumber);
	
	int x=0;
	printf("please key the shop number:");
	scanf("%d",&x);
	revise1(n,x);
}



void output1(linklist *n)  ///输出需要确认的信息  
{
	color(2);
	printf("\nplease confirm the data\n\n");
	color(14);
	color(2);
	printf("------------------------------------------------------\n");
	color(14);
	printf("name:          %s\n",n->name);
	printf("coordinate:    (%d,%d)\n",n->x,n->y);

	switch(n->type)
	{
		case 1: printf("type:          restaurant\n");break;

		case 2: printf("type:          bank\n");break;	
		case 3: printf("type:          barber shop\n");break;
		case 4: printf("type:          supermarket\n");break;	
		case 5: printf("type:          express\n");break;
		case 6: printf("type:          entertainment\n");break;
		case 7: printf("type:          cafe\n");break;
		
	}
	color(2);
	printf("------------------------------------------------------\n");
	color(14);
}



void output2(linklist *head)   ///表格输出链表 
{
	color(2);
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	color(14);
	printf("number  name                        type                 x      y        \n");
	linklist *s=head;
	while(s!=NULL)
	{
	     color(11);
		printf("%5d  ",s->number);
		printf("%-25s  ",s->name);
		switch(s->type)
		{
		case 1: printf("restaurant		");break;
  
		case 2: printf("bank                  ");break;	
		case 3: printf("barber shop		");break;
		case 4: printf("supermarket		");break;	
		case 5: printf("express               ");break;
		case 6: printf("entertainment         ");break;
		case 7: printf("cafe                  ");break;
		}
		
		printf("%4d  %4d",s->x,s->y);
		printf("\n");
		
		s=s->next;
	}
		color(2);
	    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	        
		color(14);
}



void save(linklist *p)   //保存到文件 
{
	FILE *fp;
	fp = fopen("shopdata.dat","wb+");

	while(p!=NULL){
		fwrite(p,sizeof(linklist),1,fp);
		p=p->next;
	}
	
	fclose(fp);
	
}



linklist *read_list()    //从文件读取 
{
	FILE *fp;
	 if ((fp = fopen("shopdata.dat", "rb")) == NULL)
    {
    	color(12);
        printf("read failure\n");
        color(14);
        return NULL;
    }
    int sign;
    linklist *s,*p,*head;    
    head= (linklist*)malloc(sizeof(linklist));
    p = head;
    p->next = NULL;

    int wjcd;
    fseek(fp,0,2);  ///把文件内部指针移动到文件尾部
    wjcd = ftell(fp);  ///用一个整形变量记录这个文件尾部的位置
    fseek(fp,0,0);  ///把文件内部指针移到到文件头部
    
    while(wjcd != ftell(fp))
    {
        s = (linklist*)malloc(sizeof(linklist));
        fread(s, sizeof(linklist), 1, fp);
        p->next=s;
        p = s;
        p->next = NULL;
        if (feof(fp))  break;
    }
    
    fclose(fp);
    return head->next;
}

int management()    ///后台管理系统
{
	
	int password;
	int command;
	linklist *head=NULL;
	
	password=password1();
	color(2);
	if(password==0)	return 0;
	else printf("\npassword is right, now come to management\n") ;
	Sleep(300);
	system("cls"); //清屏
	
	color(15);
	printf("File is reading,please waiting\n");
	color(14);
	 
	printf("L");
	 Sleep(250); ///延时0.25S输出
	 	printf("o");
	 Sleep(250); ///延时0.25S输出
	 	printf("a");
	 Sleep(250); ///延时0.25S输出
	 	printf("d");
	 Sleep(250); ///延时0.25S输出
	 
	 printf("i");
	 Sleep(250); ///延时0.25S输出
	 printf("n");
	 Sleep(250); ///延时0.25S输出
	 printf("g");
	 Sleep(250); ///延时0.25S输出
	 
	 printf("...\n");
	 Sleep(250); ///延时0.25S输出
	head=read_list();
	if(head!=NULL)  
	{
	color(2);
	printf("File read successfully.\n");
	color(14);
	}
	else 
	{
		color(12);
	printf("there is no file, please creat a new file") ;
	color(14);

	}
	
	do {
			 
            
            printf("\n\n\t 店铺资料管理系统\n");
            color(2);
	        printf("-------------------------------\n");
	        color(14);
	        printf("\t1.新加商店\n");
	        printf("\t2.删除商店\n");
	        printf("\t3.修改商店信息\n");
	        printf("\t4.存入文件\n");
	        printf("\t5.读取文件\n");

	        printf("\t6.输出\n");
	        printf("\t0.退出后台\n");
	        color(2);
	        printf("-------------------------------\n");
	        color(14);
	        printf("\t请选择:\n");
	        scanf("%d",&command);
	        fflush(stdin);

		switch(command){
			case 1:
				head=newshop(head);
				break;
			case 2:
				head=delete1(head);
				break;
			case 3:
				revise2(head);
				break;
			case 4:
				save(head);
				color(2);
				printf("File save successfully\n");
				color(14);
				Sleep(300);
				break;
			case 5:
				head=read_list();
				if(head!=NULL) 
				color(2);
				printf("File read successfully\n");
				color(14);
				Sleep(300);
				break;
			case 6:
				output2(head);
				break;
			}

		}while (command!=0);
		system("cls");

}

float distance1(int X1,int Y1,int X2,int Y2)    ////地图上两点间距离计算 
{
	float distance;
	distance=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
	return distance;
}

int find()   ///查找系统 
{
	float distance1(int X1,int Y1,int X2,int Y2);
	linklist *choose(linklist *group[100],int i);
	void sort(linklist *group[100],int i);
	void output3(linklist *shop,int xx, int yy);

	linklist *read_list(),*shop;
	int x2,y2,type2,i=0;
	int xx,yy,choose1;
	linklist *head=NULL,*s,*group[100];
	
	system("cls");
	color(15);
	printf("File is reading,please waiting......\n");
	color(13);
	Sleep(250); ///延时0.25S输出 
	printf("W");
	Sleep(250); ///延时0.25S输出
	printf("a");
	Sleep(250); ///延时0.25S输出
	printf("i");
	Sleep(250); ///延时0.25S输出
	printf("t");
	Sleep(250); ///延时0.25S输出
	printf("i");
	Sleep(250); ///延时0.25S输出
	printf("n");
	Sleep(250); ///延时0.25S输出
	printf("g");
	Sleep(250); ///延时0.25S输出	 
	printf("...\n");
	Sleep(250); ///延时0.25S输出
	color(14);
	head=read_list();
	if(head==NULL) {

		return 0;
	}
	else 
	{
		color(2);
	printf("File read successfully.\n\n");
	color(14);
	Sleep(500);
}
	s=head;
	color(2);
	printf("* 	*	*	*	*	*	*	*	*\n");
	printf("***************************************************************\n");
	color(9);
	printf("please choose your location\n");
	printf("1.East door\n2.North door\n3.Dahuo\n4.Library\n5.A Building\n6.E Building\n7.Lilac\n8.Begonia\n9.Bamboo\n");
	printf("10.I know my coordinate\n");
	color(2);
	printf("***************************************************************\n");
	printf("* 	*	*	*	*	*	*	*	*\n");
	color(14);
	scanf("%d",&choose1);
	
	switch(choose1){
		case 1:
			x2=640; y2=1100;break;  ///东门坐标
		case 2:
			x2=100; y2=1100;break;
		case 3:
		 	x2=700; y2=3100;break; 
		case 4:
		 	x2=1000; y2=1100;break; 
		case 5:
			x2=400; y2=1100;break;
		case 6:
		 	x2=800; y2=1100;break; 
		case 7:
		 	x2=400; y2=400;break;   
		case 8:
			x2=300; y2=1200;break;
		case 9:
		 	x2=900; y2=1500;break; 
		case 10:
			printf("please key your coordinate(x,y):");
			scanf("%d,%d",&x2,&y2);
			break;
			
	}
	color(2);
	printf("*****************************************\n");
	color(13);		
	printf("please key the type of shop you want find:\n");
	color(14);
	printf("[1.restaurant\n2.bank\n3.barber shop\n4.supermarket\n5.express\n6.entertainment \n7.cafe]\n\n");
	color(2);
	printf("*****************************************\n");
	color(14);
	scanf("%d",&type2);
	
	while(s!=NULL){
		if(s->type==type2)	{
			group[i]=s;				////用一个指针数组来存储符合要求的店铺结点的地址 
			i++;
		}
		s=s->next;
	}



	for(int k=0;k<i;k++){
		group[k]->distance=distance1(group[k]->x,group[k]->y,x2,y2);
	}
	sort(group,i);
	shop=choose(group,i);
	xx=shop->x - x2;
	yy=shop->y - y2;

	output3(shop,xx,yy);


}

void sort(linklist *group[100],int i)		////按类型排列的结点根据distance排序~ 
{
	int j,k;
	linklist *t;
	////冒泡法
	for(j=0;j<i-1;j++) {		
		for(k=0;k<i-j-1;k++){
			if( (group[k]->distance) > (group[k+1]->distance) ){
				t=group[k];
				group[k]=group[k+1];
				group[k+1]=t;
			}
			
		}
	} 
}

void output3(linklist *shop,int xx, int yy)
{
	printf("the shop you choose is: ");
	color(15);
	printf("%s\n",shop->name);

	if(xx>0)	printf("Go east %d meters\n",xx);
	else if(xx<0) printf("Go west %d meters\n",-xx);
	
	
	if(yy>0){
		printf("Go north %d north meters\n",yy);
	color(6);
	}
	else if(yy<0) printf("Go south %d south meters\n",-yy);
	Sleep(888);
	color(11);
	printf("\nGood Luck~\n");
	color(7);
	Sleep(4000);
	
}
 
linklist *choose(linklist *group[100],int i)     ////输出符合要求的店铺，进行选择 
{ 
	int x;	
	color(2);
	printf("* 	*	*	*	*	*	*	*	*\n");
	printf("***************************************************************\n");
	color(9);
	printf("number  name                 distance \n");
	for(int k=0;k<i;k++){
		printf("%5d  ",k+1);
		printf("%-20s  ",group[k]->name);
		printf("%.2f\n",group[k]->distance);
	
	
}
	color(2);
	printf("***************************************************************\n");
	printf("* 	*	*	*	*	*	*	*	*\n");
	color(14);
	
	printf("please key the number of shop you want to go: ");
	scanf("%d",&x);
	x--; 
	return group[x];
}


int main(int argc,char *argv[])
{
	int key=0;
	do {
			time_t rawtime;  
			struct tm * timeinfo;  
			time ( &rawtime );  
			timeinfo = localtime ( &rawtime );  
			color(15);
			printf ( "\nThe current date/time is:\n    %s", asctime (timeinfo) );  ///输出当前系统时间
			
			Sleep(222);

			color(6);
	        printf("\n\n\t西电生活服务导航系统\n");
	        color(2);
	        printf("-----------------------------------\n");
			color(14);
	        printf("\t1.查询\n");
	        printf("\t2.后台管理系统\n");

	        printf("\t0.退出系统\n");
	        color(2);
	        printf("-----------------------------------\n");
	        printf("\t请选择:\n");
	        color(14);
	        scanf("%d",&key);
	        fflush(stdin);

		switch(key){
			case 1:

				find();
				break;
			case 2:
				management();
				break;

			}

		}while (key!=0);

}

