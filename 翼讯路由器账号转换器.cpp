#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char s[88];
	int changdu,i=0;
	printf("�ǵ�Ҫ��ѹ�������������ʲô�ļ�����ʹ�á���\n��Ȼ�ᷢ���ֲܿ�����23333\n\n");
	printf("�������ѧ��\n");
	gets (s);
	changdu=strlen(s);
	///printf("%s\n%d\n",s,changdu);
	for(i;i<changdu;i++){
		s[i]+=4;
	}
	FILE *fp=fopen("��Ѷ.txt","w");
	
	if(fp==NULL){
		printf("\n���ѹ����ʹ�á���������������󡣡�\n\n\n�Լ����Ű��><������������"); 
		return 0; 
	} 
	
	fprintf(fp,"��Ѷ�Ĳ����˺�Ϊ:   {SRUN2}x%s@dx\n",s);
	fprintf(fp,"��Ѷ��½����Ϊ���֤����λ\n�����X�Ŀ��Գ�����ǰ��һλ.\n���˺������Ӧ����·�������������˺����뼴�ɡ�");
	
	fclose(fp); 
	printf("ת���ɹ�����鿴��Ŀ¼����Ѷ.txt�ļ�\n");
	
	Sleep(888);
	
	

 } 
