#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char s[88];
	int changdu,i=0;
	printf("记得要解压到桌面或者其他什么文件夹中使用。。\n不然会发生很恐怖的事23333\n\n");
	printf("输入你的学号\n");
	gets (s);
	changdu=strlen(s);
	///printf("%s\n%d\n",s,changdu);
	for(i;i<changdu;i++){
		s[i]+=4;
	}
	FILE *fp=fopen("翼讯.txt","w");
	
	if(fp==NULL){
		printf("\n请解压缩后使用。如果还有其他错误。。\n\n\n自己看着办吧><哈哈哈哈哈哈"); 
		return 0; 
	} 
	
	fprintf(fp,"翼讯的拨号账号为:   {SRUN2}x%s@dx\n",s);
	fprintf(fp,"翼讯登陆密码为身份证后六位\n如果有X的可以尝试往前推一位.\n将账号密码对应填入路由器拨号上网账号密码即可。");
	
	fclose(fp); 
	printf("转换成功，请查看本目录下翼讯.txt文件\n");
	
	Sleep(888);
	
	

 } 
