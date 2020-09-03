
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node {
 struct node *next;
 struct node *previous;
 int data;
};
int bigobeb=0;
struct node *temp1;
struct node *temp2;
struct node *head;
struct node *end;


int obebCalculate(int num1,int num2)
{
    while(num1!=num2)
    {
        if(num1>num2)
            num1=num1-num2;
        else
			num2=num2-num1;
    }
    return num1;
}
void freeAll()
{
	head=NULL;
	end=NULL;
	temp1=NULL;
	temp2=NULL;
	free(head);
	free(end);
	free(temp1);
	free(temp2);
}

void addList(int number)
{
	int obebsonuc,mod;
	if(head==NULL)
	 {
	  head=(struct node *)malloc(sizeof(struct node ));
	  head->data=number;
	  head->next=NULL; 
	  head->previous=NULL;
	  end=head;
	  bigobeb=0;
	 }
	else
	 {
		temp1=head;
		temp2=(struct node *)malloc(sizeof(struct node ));
		obebsonuc=obebCalculate(temp1->data,number);
		temp2->data=number;
		while(obebsonuc < bigobeb && (temp1!=end))
		{
			temp1=temp1->next;
			obebsonuc=obebCalculate(temp1->data,number);
		}
		if(obebsonuc > bigobeb)
		{
			bigobeb=obebsonuc;
		}
		if(temp1->data >= number)
		{
			mod = temp1->data % number;
		}
		else
		{
			mod = number % temp1->data;
		}
		if(mod!=0)
		{
			for(int i=0;i<mod && temp1!=head;i++)
			{
				temp1=temp1->previous;
			}
			if(temp1==head)
			{
				temp2->next=head;
				temp2->previous=end;
				head->previous=temp2;
				end->next=temp2;
				head=temp2;
			}
			else if(temp1==end)
			{
				temp2->next=head;
				temp2->previous=end;
				head->previous=temp2;
				end->next=temp2;
				end=temp2;
			}
			else
			{
				temp1->next->previous=temp2;
				temp2->next=temp1->next;
				temp1->next=temp2;
				temp2->previous=temp1;
			}
		}
		else
		{
			if(temp1==head)
			{
				head->next->previous=temp2;
				temp2->next=head->next;
				temp2->previous=head;
				head->next=temp2;
			}
			else if(temp1==end)
			{
				temp2->next=head;
				temp2->previous=end;
				head->previous=temp2;
				end->next=temp2;
				end=temp2;
			}
			else
			{
				temp1->next->previous=temp2;
				temp2->next=temp1->next;
				temp1->next=temp2;
				temp2->previous=temp1;
			}
		}
	 }
}

void printList(){
 temp1=head;
 printf("%d ",temp1->data);
 temp1=temp1->next;
 while(temp1!=head)
 {
 printf("%d ",temp1->data);
 temp1=temp1->next;
 }
 temp1=head;
 printf("\n");
 printf("%c",temp1->data);
 temp1=temp1->next;
 while(temp1!=head)
 {
 printf("%c",temp1->data);
 temp1=temp1->next;
 }
 printf("\n");
}


int main(){
 int file_number;
 char char_veri;
 FILE *fp=fopen("./src/Sayilar.txt","r");
 while(!feof(fp))
	{
		fscanf(fp,"%d%c",&file_number,&char_veri);
		if(char_veri!='\n')
		{
			addList(file_number);
		}
		else
		{
			addList(file_number);
			printList();
			freeAll();
		}	
	}
 printList();
 fclose(fp);
 return 0;
}