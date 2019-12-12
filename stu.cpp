#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct TreeNode {
	char name[30];
	struct TreeNode* FirstChild;
	struct TreeNode* NextSibling;
}*PtrToNode, Node;

PtrToNode p;                 //����һ��ȫ�ֱ���
int flag=0;                  //�ж���û���ҵ�ѧ��
PtrToNode pschool,ptrf,ptrc; //����ʱ�洢��ѧ���Ĵ���Ժ����Ϣ
void PreOrder(PtrToNode T, int depth);
void TreeInit();
void PrintName(PtrToNode T, int depth);
void MainMenu();
void AddMenu();
void ChangeMenu();
void DelMenu();
void SearchMenu();
void AddStu();             //��
void AddClass();
void AddFaculty();
void DelStu();             //ɾ
void DelClass();
void DelFaculty();
void ChangeStu();          //��
void ChangeClass();
void ChangeFaculty();
void FreeStu(PtrToNode pc);           //ɾ���ð༶����ѧ���ڵ�
void FreeClass(PtrToNode pf);         //ɾ����ѧԺ���а༶��ѧ��
PtrToNode PreSearchFaculty(char* name);
PtrToNode PreSearchClass(char* name,PtrToNode pf);
PtrToNode PreSearchStudent(char* name,PtrToNode pc);
PtrToNode SearchClass(PtrToNode t,char* name);
PtrToNode SearchFaculty(char* name);
PtrToNode SearchStudent(char* name,PtrToNode pc);
void SearchStu(PtrToNode T, int depth,char* name);
void TreeInit() {
	p = (PtrToNode)malloc(sizeof(Node));
	strcpy(p->name, "���ݵ��ӿƼ���ѧ");
	PtrToNode F1 = (PtrToNode)malloc(sizeof(Node));  //ָ��ѧԺ��ָ��
	PtrToNode F2 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode C1 = (PtrToNode)malloc(sizeof(Node));  //ָ��༶��ָ��
	PtrToNode C2 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode C3 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode C4 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu111 = (PtrToNode)malloc(sizeof(Node)); //ָ��ѧ���ڵ��ָ��
	PtrToNode Stu112 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu121 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu122 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu211 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu212 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu221 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu222 = (PtrToNode)malloc(sizeof(Node));
	p->NextSibling = NULL;
	p->FirstChild = F1;
	strcpy(F1->name, "׿ԽѧԺ");
	F1->NextSibling = F2;
	strcpy(F2->name, "�����ѧԺ");
	F2->NextSibling = NULL;

	F1->FirstChild = C1;
	strcpy(C1->name, "׿Խ1��");
	C1->NextSibling = C2;
	strcpy(C2->name, "׿Խ2��");
	C2->NextSibling = NULL;
	F2->FirstChild = C3;
	strcpy(C3->name, "�����1��");
	C3->NextSibling = C4;
	strcpy(C4->name, "�����2��");
	C4->NextSibling = NULL;

	C1->FirstChild = Stu111;
	strcpy(Stu111->name, "111������");
	Stu111->FirstChild = NULL;
	Stu111->NextSibling = Stu112;
	strcpy(Stu112->name, "112����");
	Stu112->FirstChild = NULL;
	Stu112->NextSibling = NULL;

	C2->FirstChild = Stu121;
	strcpy(Stu121->name, "121����");
	Stu121->FirstChild = NULL;
	Stu121->NextSibling = Stu122;
	strcpy(Stu122->name, "122��С��");
	Stu122->FirstChild = NULL;
	Stu122->NextSibling = NULL;

	C3->FirstChild = Stu211;
	strcpy(Stu211->name, "211���溬");
	Stu211->FirstChild = NULL;
	Stu211->NextSibling = Stu212;
	strcpy(Stu212->name, "212���ܻ�");
	Stu212->FirstChild = NULL;
	Stu212->NextSibling = NULL;

	C4->FirstChild = Stu221;
	strcpy(Stu221->name, "221����");
	Stu221->FirstChild = NULL;
	Stu221->NextSibling = Stu222;
	strcpy(Stu222->name, "222������");
	Stu222->FirstChild = NULL;
	Stu222->NextSibling = NULL;
	return;
}
void PreOrder(PtrToNode T, int depth) {
	if (T == NULL) return;
	PrintName(T, depth);
	PreOrder(T->FirstChild, depth + 1);
	PreOrder(T->NextSibling, depth);
	return;
}
void PrintName(PtrToNode T, int depth) {
	int i;
	for (i = 0; i < depth; i++)
	{
		printf("	");
	}
	printf("->%s\n", T->name);
	return;
}
void MainMenu() {
	int choice;
	printf("*********��ӭ����ѧ������ϵͳ*********\n");
	printf("	1������\n	2��ɾ��\n	3���޸�\n	4������\n	0���˳�\n��ѡ��");
	scanf("%d", &choice);
	switch (choice) {
		case 1:AddMenu(); break;
		case 2:DelMenu(); break;
		case 3:ChangeMenu(); break;
		case 4:SearchMenu(); break;
		case 0:exit(1);
	}
	return;
}
void ChangeMenu(){
	int choice;
    printf("��ѡ������Ҫ����������:1��ѧԺ2���༶3��ѧ��");
    scanf("%d",&choice);
    switch(choice){
        case(1):ChangeFaculty();break;
        case(2):ChangeClass();break;
        case(3):ChangeStu();break;
    }
    return;
}
void ChangeFaculty(){
	char falname[20];
	PtrToNode pf;
	printf("������ѧԺԭ���ƣ�");
	scanf("%s",falname);
	if((pf=SearchFaculty(falname))!=NULL)
	{
		printf("�������޸ĺ�����ƣ�");
		scanf("%s",pf->name);
	}
	else
	{
		printf("��������ȷ��ѧԺ���ƣ�\n");
        MainMenu();
	}
	PreOrder(p,0);
	MainMenu();
	return;
}
void ChangeClass(){
	char falname[20],classname[20];
	PtrToNode pf,pc;
	printf("��������Ҫ�޸ĵİ༶����ѧԺ��");
	scanf("%s",falname);
	if((pf=SearchFaculty(falname))!=NULL)
	{   printf("��������Ҫ�޸ĵİ༶ԭ����:");
		scanf("%s",classname);
        if((pc=SearchClass(pf,classname))!=NULL||!strcmp(pf->FirstChild->name,classname))      //����ҵ���Ҫ�޸ĵİ༶
		{
			printf("�������޸ĺ������:");
			scanf("%s",pc->name);
		}
		else
		{
			printf("��������ȷ�İ༶���ƣ�");
        	MainMenu();
		}
	}
	else
	{
		printf("��������ȷ��ѧԺ���ƣ�");
        MainMenu();
	}
	PreOrder(p, 0);
	MainMenu();
}
void ChangeStu(){
	PtrToNode pf,pc,ps;        //ָ��ѧ������ѧԺ�Ͱ༶��ָ�� 
    PtrToNode temp;
    char facname[20];
	char classname[20];
	char stuname[20];
    printf("������ѧ������ѧԺ����:");
    scanf("%s",facname);
    if((pf=SearchFaculty(facname))!=NULL)            //����ҵ�����Ҫ���ѧԺ
    {   
		printf("������ѧ�����ڰ༶����:");
		scanf("%s",classname);
        if((pc=SearchClass(pf,classname))!=NULL)      //����ҵ���ѧ�����ڰ༶
		{
			printf("������ѧ����ԭѧ��������");
			scanf("%s",stuname);
			if((ps=SearchStudent(stuname,pc))!=NULL||!strcmp(pc->FirstChild->name,stuname))
			{
				printf("������ѧ������ѧ��������");
				scanf("%s",ps->name);
			}
			else
			{
				printf("��������ȷ��ѧ������");
				MainMenu();
			}
		}
		else
		{
			printf("��������ȷ�İ༶���ƣ�");
        	MainMenu();
		}
	}
	else
	{
		printf("��������ȷ��ѧԺ���ƣ�");
        MainMenu();
	}
	PreOrder(p, 0);
	MainMenu();
	return;

}
void SearchMenu(){
	char stuname[20];
	printf("��������Ҫ���ҵ�ѧ��ѧ������");
	scanf("%s",stuname);
	SearchStu(p,0,stuname);
	if(!flag)
	{
		printf("�����ڸ�ѧ����");
	}
	MainMenu();
	return;
}
void SearchStu(PtrToNode T, int depth,char* name) {
	if (T == NULL) return;
	switch(depth){                 //��¼��ѧ������Ժϵ�༶��Ϣ
		case(0):pschool=T;break;     
		case(1):ptrf=T;break;
		case(2):ptrc=T;break;
		default:break;
	}
	if(depth==3)
	{
		if(!strcmp(T->name,name))       //����ҵ���ѧ��
		{	
			flag=1;
			PrintName(pschool,0);
			PrintName(ptrf,1);
			PrintName(ptrc,2);
			PrintName(T,3);
			return;
		} 
	}
	SearchStu(T->FirstChild, depth + 1,name);
	SearchStu(T->NextSibling, depth,name);
	return;
}
void AddMenu(){
    int choice;
    printf("��ѡ������Ҫ����������:1��ѧԺ2���༶3��ѧ��");
    scanf("%d",&choice);
    switch(choice){
        case(1):AddFaculty();break;
        case(2):AddClass();break;
        case(3):AddStu();break;
    }
    return;
}
void FreeStu(PtrToNode pc)      //ɾ���ð༶������ѧ��
{	
	PtrToNode temp;
	if(!(pc->FirstChild)) return;
	while(pc->FirstChild!=NULL)
	{
	temp=pc->FirstChild;
	pc->FirstChild=pc->FirstChild->NextSibling;
	free(temp);
	}
	return;
}
void FreeClass(PtrToNode pf)
{
	PtrToNode temp;
	if(!(pf->FirstChild)) return;
	while(pf->FirstChild!=NULL)
	{
	temp=pf->FirstChild;
	pf->FirstChild=pf->FirstChild->NextSibling;
	FreeStu(temp);
	free(temp);
	}
	return;
}
void DelMenu(){
	int choice;
    printf("��ѡ������Ҫ����������:1��ѧԺ2���༶3��ѧ��");
    scanf("%d",&choice);
    switch(choice){
        case(1):DelFaculty();break;
        case(2):DelClass();break;
        case(3):DelStu();break;
    }
    return;
}
void DelStu(){
	PtrToNode pf,pc,ps;        //ָ��ѧ������ѧԺ�Ͱ༶��ָ�� 
    PtrToNode temp;
    char facname[20];
	char classname[20];
	char stuname[20];
    printf("������ѧ������ѧԺ����:");
    scanf("%s",facname);
    if((pf=SearchFaculty(facname))!=NULL)            //����ҵ�����Ҫ���ѧԺ
    {   
		printf("������ѧ�����ڰ༶����:");
		scanf("%s",classname);
        if((pc=SearchClass(pf,classname))!=NULL)      //����ҵ���ѧ�����ڰ༶
		{
			printf("������ѧ����ѧ��������");
			scanf("%s",stuname);
			if((ps=PreSearchStudent(stuname,pc))!=NULL)
			{
				temp=ps->NextSibling;
				ps->NextSibling=ps->NextSibling->NextSibling;
				free(temp);
			}
			else if(!strcmp(pc->FirstChild->name,stuname))
			{
				temp=pc->FirstChild;
				pc->FirstChild=pc->FirstChild->NextSibling;
				free(temp);
			}
			else
			{
				printf("��������ȷ��ѧ������");
				MainMenu();
			}
		}
		else
		{
			printf("��������ȷ�İ༶���ƣ�");
        	MainMenu();
		}
	}
	else
	{
		printf("��������ȷ��ѧԺ���ƣ�");
        MainMenu();
	}
	PreOrder(p, 0);
	MainMenu();
	return;
}
void DelClass(){
	char falname[20],classname[20];
	PtrToNode pf,pc,temp;
	printf("��������Ҫɾ���İ༶����ѧԺ��");
	scanf("%s",falname);
	if((pf=SearchFaculty(falname))!=NULL)
	{   printf("��������Ҫɾ���İ༶����:");
		scanf("%s",classname);
        if((pc=PreSearchClass(classname,pf))!=NULL)      //����ҵ���Ҫɾ���İ༶
		{
			temp=pc->NextSibling;
			pc->NextSibling=pc->NextSibling->NextSibling;
			FreeStu(temp);           //ɾ���ð༶����ѧ���ڵ�
			free(temp);
		}
		else if(!strcmp(pf->FirstChild->name,classname))  //���Ҫɾ�İ༶�ǵ�һ��
		{
			temp=pf->FirstChild;
			pf->FirstChild=pf->FirstChild->NextSibling;
			FreeStu(temp);           //ɾ���ð༶����ѧ���ڵ�
			free(temp);
		}
		else
		{
			printf("��������ȷ�İ༶���ƣ�");
        	MainMenu();
		}
	}
	else
	{
		printf("��������ȷ��ѧԺ���ƣ�");
        MainMenu();
	}
	PreOrder(p, 0);
	MainMenu();
}
void DelFaculty(){
	char falname[20];
	PtrToNode pf,temp;
	printf("��������Ҫɾ����ѧԺ����:");
    scanf("%s",falname);
	if((pf=PreSearchFaculty(falname))!=NULL)
	{	
		temp=pf->NextSibling;
		pf->NextSibling=pf->NextSibling->NextSibling;
		FreeClass(temp);
		free(temp);
	}
	else if(!strcmp(p->FirstChild->name,falname))    //���Ҫɾ�����ǵ�һ��ѧԺ
	{	
		temp=p->FirstChild;
		p->FirstChild=p->FirstChild->NextSibling;
		FreeClass(temp);
		free(temp);
	}
	else
	{
		printf("��������ȷ��ѧԺ���ƣ�");
        MainMenu();
	}
	PreOrder(p,0);
	MainMenu();
	return;
}
void AddFaculty(){
    PtrToNode t=p->FirstChild;
    PtrToNode Ptr=(PtrToNode)malloc(sizeof(Node));
    printf("��������Ҫ��ӵ�ѧԺ����:");
    scanf("%s",Ptr->name);
    Ptr->FirstChild=NULL;
    Ptr->NextSibling=NULL;
    if(t==NULL)
	{
    	p->FirstChild=Ptr;
	}
    else
	{
    	while(t->NextSibling!=NULL)
    	{
        	t=t->NextSibling;
    	}
    	t->NextSibling=Ptr;
	}
    PreOrder(p,0);
    MainMenu();
    return;
}
PtrToNode SearchFaculty(char* name){
    PtrToNode t=p->FirstChild;
    if(t==NULL) return t;
    while(t!=NULL)
	{	
    	if(strcmp(t->name,name)==0) return t;
    	t=t->NextSibling;
	}
    return t;
}
PtrToNode SearchStudent(char* name,PtrToNode pc){
	PtrToNode t=pc->FirstChild;
    if(t==NULL) return t;
    while(t!=NULL)
	{	
    	if(strcmp(t->name,name)==0) return t;
    	t=t->NextSibling;
	}
    return t;
}
PtrToNode PreSearchStudent(char* name,PtrToNode pc){   //Ѱ������ѧ��ǰ���ڵ�
	PtrToNode ps=pc->FirstChild;
	if(ps==NULL) return NULL;
    while(ps->NextSibling!=NULL)
	{	
    	if(strcmp(ps->NextSibling->name,name)==0) return ps;
    	ps=ps->NextSibling;
	}
    return NULL;
}
PtrToNode PreSearchFaculty(char* name){    //Ѱ������ѧԺǰ���ڵ�
    PtrToNode t=p->FirstChild;
    if(t==NULL) return NULL;
    while(t->NextSibling!=NULL)
	{	
    	if(strcmp(t->NextSibling->name,name)==0) return t;
    	t=t->NextSibling;
	}
    return NULL;
}
PtrToNode PreSearchClass(char* name,PtrToNode pf){   //Ѱ������༶ǰ���ڵ�
	PtrToNode pc=pf->FirstChild;
	if(pc==NULL) return NULL;
    while(pc->NextSibling!=NULL)
	{	
    	if(strcmp(pc->NextSibling->name,name)==0) return pc;
    	pc=pc->NextSibling;
	}
    return NULL;
}
PtrToNode SearchClass(PtrToNode t,char* name){   //tΪָ��ð༶����ѧԺ��ָ�� 
	PtrToNode temp=t->FirstChild;
    while(temp!=NULL)
	{	
    	if(strcmp(temp->name,name)==0) return temp;
    	temp=temp->NextSibling;
	}
    return temp;
}
void AddClass(){
    char temp[20];
    PtrToNode t,q;
    PtrToNode Ptr=(PtrToNode)malloc(sizeof(Node));
    printf("��������Ҫ��ӵİ༶����ѧԺ����:");
    scanf("%s",temp);
    t=SearchFaculty(temp); //ָ������ѧԺ��ָ��
    if(t!=NULL)            //����ҵ�����Ҫ���ѧԺ
    {   
        q=t->FirstChild;
        if(q==NULL)
		{	
        	t->FirstChild=Ptr;
		}
		else
		{
        	while(q->NextSibling!=NULL)
			{
            	q=q->NextSibling;
        	}
        	 q->NextSibling=Ptr;
    	}
        printf("��������Ҫ��ӵİ༶����:");
        scanf("%s",Ptr->name);      
        Ptr->FirstChild=NULL;
        Ptr->NextSibling=NULL;
    }
    else
    {
        free(Ptr);
        printf("��������ȷ��ѧԺ���ƣ�");
        MainMenu();
    }
    PreOrder(p,0);
    MainMenu();
    return;
}
void AddStu(){
    PtrToNode pf,pc;        //ָ��ѧ������ѧԺ�Ͱ༶��ָ�� 
    PtrToNode temp;
    PtrToNode ps=(PtrToNode)malloc(sizeof(Node));
    char facname[20];
	char classname[20];
    printf("������������ѧԺ����:");
    scanf("%s",facname);
    if((pf=SearchFaculty(facname))!=NULL)            //����ҵ�����Ҫ���ѧԺ
    {   
		printf("������ѧ�����ڰ༶����:");
		scanf("%s",classname);
        if((pc=SearchClass(pf,classname))!=NULL)      //����ҵ���ѧ�����ڰ༶
		{	
			temp=pc->FirstChild;
			if(temp==NULL) pc->FirstChild=ps;
			else
			{
				while(temp->NextSibling!=NULL)
				{
					temp=temp->NextSibling;
				}
				temp->NextSibling=ps;
			}
        	printf("��������Ҫ��ӵ�ѧ��ѧ���������м䲻�üӿո�:");
        	scanf("%s",ps->name);      
        	ps->FirstChild=NULL;
        	ps->NextSibling=NULL;
		}
		else
		{
			free(ps);
        	printf("��������ȷ�İ༶���ƣ�");
        	MainMenu();
		}
		
    }
    else
    {
        free(ps);
        printf("��������ȷ��ѧԺ���ƣ�");
        MainMenu();
    }
    PreOrder(p,0);
    MainMenu();
    return;
}
int main() {
    TreeInit();
	PreOrder(p, 0);
	MainMenu();
	return 0;
}
