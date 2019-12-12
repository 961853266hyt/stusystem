#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct TreeNode {
	char name[30];
	struct TreeNode* FirstChild;
	struct TreeNode* NextSibling;
}*PtrToNode, Node;

PtrToNode p;                 //定义一个全局变量
int flag=0;                  //判断有没有找到学生
PtrToNode pschool,ptrf,ptrc; //查找时存储该学生的从属院班信息
void PreOrder(PtrToNode T, int depth);
void TreeInit();
void PrintName(PtrToNode T, int depth);
void MainMenu();
void AddMenu();
void ChangeMenu();
void DelMenu();
void SearchMenu();
void AddStu();             //增
void AddClass();
void AddFaculty();
void DelStu();             //删
void DelClass();
void DelFaculty();
void ChangeStu();          //改
void ChangeClass();
void ChangeFaculty();
void FreeStu(PtrToNode pc);           //删除该班级所有学生节点
void FreeClass(PtrToNode pf);         //删除该学院所有班级及学生
PtrToNode PreSearchFaculty(char* name);
PtrToNode PreSearchClass(char* name,PtrToNode pf);
PtrToNode PreSearchStudent(char* name,PtrToNode pc);
PtrToNode SearchClass(PtrToNode t,char* name);
PtrToNode SearchFaculty(char* name);
PtrToNode SearchStudent(char* name,PtrToNode pc);
void SearchStu(PtrToNode T, int depth,char* name);
void TreeInit() {
	p = (PtrToNode)malloc(sizeof(Node));
	strcpy(p->name, "杭州电子科技大学");
	PtrToNode F1 = (PtrToNode)malloc(sizeof(Node));  //指向学院的指针
	PtrToNode F2 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode C1 = (PtrToNode)malloc(sizeof(Node));  //指向班级的指针
	PtrToNode C2 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode C3 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode C4 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu111 = (PtrToNode)malloc(sizeof(Node)); //指向学生节点的指针
	PtrToNode Stu112 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu121 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu122 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu211 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu212 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu221 = (PtrToNode)malloc(sizeof(Node));
	PtrToNode Stu222 = (PtrToNode)malloc(sizeof(Node));
	p->NextSibling = NULL;
	p->FirstChild = F1;
	strcpy(F1->name, "卓越学院");
	F1->NextSibling = F2;
	strcpy(F2->name, "计算机学院");
	F2->NextSibling = NULL;

	F1->FirstChild = C1;
	strcpy(C1->name, "卓越1班");
	C1->NextSibling = C2;
	strcpy(C2->name, "卓越2班");
	C2->NextSibling = NULL;
	F2->FirstChild = C3;
	strcpy(C3->name, "计算机1班");
	C3->NextSibling = C4;
	strcpy(C4->name, "计算机2班");
	C4->NextSibling = NULL;

	C1->FirstChild = Stu111;
	strcpy(Stu111->name, "111胡逸藤");
	Stu111->FirstChild = NULL;
	Stu111->NextSibling = Stu112;
	strcpy(Stu112->name, "112何熙");
	Stu112->FirstChild = NULL;
	Stu112->NextSibling = NULL;

	C2->FirstChild = Stu121;
	strcpy(Stu121->name, "121赵旭");
	Stu121->FirstChild = NULL;
	Stu121->NextSibling = Stu122;
	strcpy(Stu122->name, "122黄小凝");
	Stu122->FirstChild = NULL;
	Stu122->NextSibling = NULL;

	C3->FirstChild = Stu211;
	strcpy(Stu211->name, "211林真含");
	Stu211->FirstChild = NULL;
	Stu211->NextSibling = Stu212;
	strcpy(Stu212->name, "212王杰辉");
	Stu212->FirstChild = NULL;
	Stu212->NextSibling = NULL;

	C4->FirstChild = Stu221;
	strcpy(Stu221->name, "221胡子");
	Stu221->FirstChild = NULL;
	Stu221->NextSibling = Stu222;
	strcpy(Stu222->name, "222王章涛");
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
	printf("*********欢迎来到学生管理系统*********\n");
	printf("	1、增加\n	2、删除\n	3、修改\n	4、查找\n	0、退出\n请选择：");
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
    printf("请选择入您要操作的类型:1、学院2、班级3、学生");
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
	printf("请输入学院原名称：");
	scanf("%s",falname);
	if((pf=SearchFaculty(falname))!=NULL)
	{
		printf("请输入修改后的名称：");
		scanf("%s",pf->name);
	}
	else
	{
		printf("请输入正确的学院名称！\n");
        MainMenu();
	}
	PreOrder(p,0);
	MainMenu();
	return;
}
void ChangeClass(){
	char falname[20],classname[20];
	PtrToNode pf,pc;
	printf("请输入您要修改的班级所属学院：");
	scanf("%s",falname);
	if((pf=SearchFaculty(falname))!=NULL)
	{   printf("请输入所要修改的班级原名称:");
		scanf("%s",classname);
        if((pc=SearchClass(pf,classname))!=NULL||!strcmp(pf->FirstChild->name,classname))      //如果找到了要修改的班级
		{
			printf("请输入修改后的名称:");
			scanf("%s",pc->name);
		}
		else
		{
			printf("请输入正确的班级名称！");
        	MainMenu();
		}
	}
	else
	{
		printf("请输入正确的学院名称！");
        MainMenu();
	}
	PreOrder(p, 0);
	MainMenu();
}
void ChangeStu(){
	PtrToNode pf,pc,ps;        //指向学生所在学院和班级的指针 
    PtrToNode temp;
    char facname[20];
	char classname[20];
	char stuname[20];
    printf("请输入学生所属学院名称:");
    scanf("%s",facname);
    if((pf=SearchFaculty(facname))!=NULL)            //如果找到了所要求的学院
    {   
		printf("请输入学生所在班级名称:");
		scanf("%s",classname);
        if((pc=SearchClass(pf,classname))!=NULL)      //如果找到了学生所在班级
		{
			printf("请输入学生的原学号姓名：");
			scanf("%s",stuname);
			if((ps=SearchStudent(stuname,pc))!=NULL||!strcmp(pc->FirstChild->name,stuname))
			{
				printf("请输入学生的新学号姓名：");
				scanf("%s",ps->name);
			}
			else
			{
				printf("请输入正确的学号姓名");
				MainMenu();
			}
		}
		else
		{
			printf("请输入正确的班级名称！");
        	MainMenu();
		}
	}
	else
	{
		printf("请输入正确的学院名称！");
        MainMenu();
	}
	PreOrder(p, 0);
	MainMenu();
	return;

}
void SearchMenu(){
	char stuname[20];
	printf("请输入您要查找的学生学号姓名");
	scanf("%s",stuname);
	SearchStu(p,0,stuname);
	if(!flag)
	{
		printf("不存在该学生！");
	}
	MainMenu();
	return;
}
void SearchStu(PtrToNode T, int depth,char* name) {
	if (T == NULL) return;
	switch(depth){                 //记录该学生所属院系班级信息
		case(0):pschool=T;break;     
		case(1):ptrf=T;break;
		case(2):ptrc=T;break;
		default:break;
	}
	if(depth==3)
	{
		if(!strcmp(T->name,name))       //如果找到该学生
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
    printf("请选择入您要操作的类型:1、学院2、班级3、学生");
    scanf("%d",&choice);
    switch(choice){
        case(1):AddFaculty();break;
        case(2):AddClass();break;
        case(3):AddStu();break;
    }
    return;
}
void FreeStu(PtrToNode pc)      //删除该班级的所有学生
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
    printf("请选择入您要操作的类型:1、学院2、班级3、学生");
    scanf("%d",&choice);
    switch(choice){
        case(1):DelFaculty();break;
        case(2):DelClass();break;
        case(3):DelStu();break;
    }
    return;
}
void DelStu(){
	PtrToNode pf,pc,ps;        //指向学生所在学院和班级的指针 
    PtrToNode temp;
    char facname[20];
	char classname[20];
	char stuname[20];
    printf("请输入学生所属学院名称:");
    scanf("%s",facname);
    if((pf=SearchFaculty(facname))!=NULL)            //如果找到了所要求的学院
    {   
		printf("请输入学生所在班级名称:");
		scanf("%s",classname);
        if((pc=SearchClass(pf,classname))!=NULL)      //如果找到了学生所在班级
		{
			printf("请输入学生的学号姓名：");
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
				printf("请输入正确的学号姓名");
				MainMenu();
			}
		}
		else
		{
			printf("请输入正确的班级名称！");
        	MainMenu();
		}
	}
	else
	{
		printf("请输入正确的学院名称！");
        MainMenu();
	}
	PreOrder(p, 0);
	MainMenu();
	return;
}
void DelClass(){
	char falname[20],classname[20];
	PtrToNode pf,pc,temp;
	printf("请输入您要删除的班级所属学院：");
	scanf("%s",falname);
	if((pf=SearchFaculty(falname))!=NULL)
	{   printf("请输入所要删除的班级名称:");
		scanf("%s",classname);
        if((pc=PreSearchClass(classname,pf))!=NULL)      //如果找到了要删除的班级
		{
			temp=pc->NextSibling;
			pc->NextSibling=pc->NextSibling->NextSibling;
			FreeStu(temp);           //删除该班级所有学生节点
			free(temp);
		}
		else if(!strcmp(pf->FirstChild->name,classname))  //如果要删的班级是第一个
		{
			temp=pf->FirstChild;
			pf->FirstChild=pf->FirstChild->NextSibling;
			FreeStu(temp);           //删除该班级所有学生节点
			free(temp);
		}
		else
		{
			printf("请输入正确的班级名称！");
        	MainMenu();
		}
	}
	else
	{
		printf("请输入正确的学院名称！");
        MainMenu();
	}
	PreOrder(p, 0);
	MainMenu();
}
void DelFaculty(){
	char falname[20];
	PtrToNode pf,temp;
	printf("请输入您要删除的学院名称:");
    scanf("%s",falname);
	if((pf=PreSearchFaculty(falname))!=NULL)
	{	
		temp=pf->NextSibling;
		pf->NextSibling=pf->NextSibling->NextSibling;
		FreeClass(temp);
		free(temp);
	}
	else if(!strcmp(p->FirstChild->name,falname))    //如果要删除的是第一个学院
	{	
		temp=p->FirstChild;
		p->FirstChild=p->FirstChild->NextSibling;
		FreeClass(temp);
		free(temp);
	}
	else
	{
		printf("请输入正确的学院名称！");
        MainMenu();
	}
	PreOrder(p,0);
	MainMenu();
	return;
}
void AddFaculty(){
    PtrToNode t=p->FirstChild;
    PtrToNode Ptr=(PtrToNode)malloc(sizeof(Node));
    printf("请输入您要添加的学院名称:");
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
PtrToNode PreSearchStudent(char* name,PtrToNode pc){   //寻找所需学生前驱节点
	PtrToNode ps=pc->FirstChild;
	if(ps==NULL) return NULL;
    while(ps->NextSibling!=NULL)
	{	
    	if(strcmp(ps->NextSibling->name,name)==0) return ps;
    	ps=ps->NextSibling;
	}
    return NULL;
}
PtrToNode PreSearchFaculty(char* name){    //寻找所需学院前驱节点
    PtrToNode t=p->FirstChild;
    if(t==NULL) return NULL;
    while(t->NextSibling!=NULL)
	{	
    	if(strcmp(t->NextSibling->name,name)==0) return t;
    	t=t->NextSibling;
	}
    return NULL;
}
PtrToNode PreSearchClass(char* name,PtrToNode pf){   //寻找所需班级前驱节点
	PtrToNode pc=pf->FirstChild;
	if(pc==NULL) return NULL;
    while(pc->NextSibling!=NULL)
	{	
    	if(strcmp(pc->NextSibling->name,name)==0) return pc;
    	pc=pc->NextSibling;
	}
    return NULL;
}
PtrToNode SearchClass(PtrToNode t,char* name){   //t为指向该班级所属学院的指针 
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
    printf("请输入您要添加的班级所属学院名称:");
    scanf("%s",temp);
    t=SearchFaculty(temp); //指向所属学院的指针
    if(t!=NULL)            //如果找到了所要求的学院
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
        printf("请输入您要添加的班级名称:");
        scanf("%s",Ptr->name);      
        Ptr->FirstChild=NULL;
        Ptr->NextSibling=NULL;
    }
    else
    {
        free(Ptr);
        printf("请输入正确的学院名称！");
        MainMenu();
    }
    PreOrder(p,0);
    MainMenu();
    return;
}
void AddStu(){
    PtrToNode pf,pc;        //指向学生所在学院和班级的指针 
    PtrToNode temp;
    PtrToNode ps=(PtrToNode)malloc(sizeof(Node));
    char facname[20];
	char classname[20];
    printf("请输入您所属学院名称:");
    scanf("%s",facname);
    if((pf=SearchFaculty(facname))!=NULL)            //如果找到了所要求的学院
    {   
		printf("请输入学生所在班级名称:");
		scanf("%s",classname);
        if((pc=SearchClass(pf,classname))!=NULL)      //如果找到了学生所在班级
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
        	printf("请输入您要添加的学生学号姓名（中间不得加空格）:");
        	scanf("%s",ps->name);      
        	ps->FirstChild=NULL;
        	ps->NextSibling=NULL;
		}
		else
		{
			free(ps);
        	printf("请输入正确的班级名称！");
        	MainMenu();
		}
		
    }
    else
    {
        free(ps);
        printf("请输入正确的学院名称！");
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
