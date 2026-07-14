#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ClubMember{
	int studentNo;
	char studentName[50];
	char clubName[50];
	int eventcount;
	int activityPoint;
	struct ClubMember *next;
}ClubMember;
void menu(void);
ClubMember* createMember(int No,char *name,char *clubname,int count);
void addMember(ClubMember**head,ClubMember*new);
void listMembers(ClubMember *head);
ClubMember* searchMember(int No,ClubMember *head);
int countMembersRecursive(ClubMember *head);
int standardPoint(int count);
int bonusPoint(int count);
void calculateActivityPoints(ClubMember *head,int(*pointfunc)(int));
void freeMembers(ClubMember **head);
int main(){
    int no;
	char name[50];
	char clubname[50];
	int count;
	int choice;
	ClubMember *head;
	ClubMember* new;
	head=NULL;
	menu();

	while(choice!=7){
		printf("\nCHOICE:");
	    scanf("%d",&choice);
		if(choice==1){
		   printf("No:\n");
		   scanf("%d",&no);
		   printf("Name:\n");
		   scanf("%s",name);
		   printf("Club Name:\n");
		   scanf("%s",clubname);
		   printf("Event Count:\n");
		   scanf("%d",&count);
		   new=createMember(no,name,clubname,count);
		   addMember(&head,new);
		}else if(choice==2){
			listMembers(head);
		}else if(choice==3){
			printf("No:");
			scanf("%d",&no);
			searchMember(no,head);

		}else if(choice==4){
			countMembersRecursive(head);
		}else if(choice==5){
			
		}else if(choice==6){
			
		}
		
		
	}
	freeMembers(&head);
	return 0;	
}
ClubMember* createMember(int No,char *name,char *clubname,int count){
	ClubMember *p;
	p=(ClubMember*)malloc(sizeof(ClubMember));
	strcpy(p->clubName,clubname);
	p->eventcount=count;
	strcpy(p->studentName,name);
	p->studentNo=No;
	p->next=NULL;
	return p;
}
void addMember(ClubMember**head,ClubMember*new){
	ClubMember *temp;
	temp=*head;
	if(*head==NULL){
		*head=new;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new;
	}
	
}
void listMembers(ClubMember *head){
	ClubMember *i;
	if(head==NULL){
		printf("\n!!HENUZ KULLANICI GIRMEDINIZ!!\n");
	}else{
		for(i=head;i!=NULL;i=i->next){
			printf("NO:%d\n",i->studentNo);
			printf("STUDENT NAME:%s\n",i->studentName);
			printf("CLUB NAME:%s\n",i->clubName);
			printf("EVENT COUNT:%d\n",i->eventcount);
			printf("ACTIVITY POINT:%d\n",i->activityPoint);
			}
	}
}
ClubMember* searchMember(int No,ClubMember *head){
	ClubMember *i;
	for(i=head;i->studentNo!=No&&i!=NULL;i=i->next);
	return i;
}
int countMembersRecursive(ClubMember *head){
	ClubMember *i;
	int count;
	count=0;
	if(head==NULL){
		printf("\n!!HENUZ KULLANICI GIRMEDINIZ!!\n");
	}else{
		for(i=head;i!=NULL;i=i->next){
            count++;
		}
	}
	return count;
}
int standardPoint(int count){
	int standard;
	standard=count*10;
	return standard;
}
int bonusPoint(int count){
	int bonus;
	bonus=count*15;
	return bonus;
}
void calculateActivityPoints(ClubMember *head,int(*pointfunc)(int)){
	

}
void freeMembers(ClubMember **head){
     ClubMember* i;
    while((*head)->next!=NULL){
         i=(*head)->next;
         free(*head);
         *head=i;
	}
    free(*head);
}
void menu(void){
        printf("1-Add Club Member\n");
		printf("2-List All Members\n");
		printf("3-Search By Student Number\n");
		printf("4-Calculate member count recursively\n");
		printf("7-Apply standard point calculation\n");
		printf("6-Apply bonus point calculation\n");
		printf("7-Exit\n");
}
