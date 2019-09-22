#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Orfilia Qiu */

struct node{
	char last[30];
	char first[20];
	unsigned int id;
	struct node *link;

};
void SortedInsert(struct node** head, struct node* newN){

	if (*head == NULL || (*head)->id >= newN->id){
		newN->link = *head;
		*head = newN;
		return;
	}

	struct node* current = *head;
	while(current->link != NULL && current->link->id < newN->id)
		current = current->link;

	newN->link = current->link;
	current->link = newN;
}

int main(){

	int itemCount = 0;

	char str[30];
	struct node *head;
	head = malloc(sizeof(struct node));
	FILE *textFile = fopen("Cse2421.Lab4.Data.txt", "r+");
	//creating head node
	char tempArr1[30];
	char tempArr2[20];

	while(fscanf(textFile, "%s", &str)!=EOF){
		if(atoi(str)==0){
			int t, c = 0, tc=0;
			for(t=0; t < strlen(str);t++){
				if(str[t] != 44 && tc == 0){
					tempArr1[t] = str[t];
				}else if(str[t] == 44){
					tc = 1;
				}else if((tc == 1) && (str[t]!=44)){
					tempArr2[c]= str[t];
					c++;
				}
			}
		}else{
			head->id = (unsigned)(atoi(str));
			break;
		}
	}
		strcpy(head->last, tempArr1);
		strcpy(head->first, tempArr2);
		head->link=NULL;

	itemCount++;

/******************************************************************************************************************/
	while(fscanf(textFile, "%s", &str)!=EOF){
		char tempArr11[30];
		char tempArr22[20];
		int fn=0, sn=0;
		
		if(atoi(str)==0){
			int t, tc=0,c=0;
			for(t=0; t<strlen(str);t++){
				if(str[t] != 44 && tc == 0){
					fn++;
					tempArr11[t] = str[t];
				}else if(str[t] == 44){
					tc = 1;
				}else if((tc == 1) && (str[t]!=44)){
					sn++;
					tempArr22[c]= str[t];
					c++;
				}}
		
		while(fn<30){tempArr11[fn]=0;fn++;}
		while(sn<20){tempArr22[sn]=0;sn++;}
		}else{
			struct node *temp;
			temp = malloc(sizeof(struct node));
			temp->id= (unsigned)(atoi(str));
			strcpy(temp->last, tempArr11);
			strcpy(temp->first, tempArr22);
			int isIn = 0;
			itemCount++;
			struct node* ptr = malloc(sizeof(struct node));
			ptr = head;

			while (ptr->link != NULL){
				if(ptr->id==temp->id){
					isIn=1; 
					itemCount--;
					printf("Input:%d %s,%s its id =%d already exists; Not added to the list!\n",itemCount,temp->last,temp->first,temp->id);
					ptr = head;
					
					break;}
				ptr = ptr->link;
				
			}
			if(!isIn){
				SortedInsert(&head, temp);
			}
		}	

	}
		printf("Number of Nodes=%d\n\n\n", itemCount);
			/*struct node* ptr = malloc(sizeof(struct node));
			ptr = head;
			int ii = 1;
			while (ptr){
				printf("%d  %s   %s  %u\n", ii,ptr->last, ptr->first,ptr->id);
				ii++;
				ptr = ptr->link;
				
			}*/
			
	//asking for user command
	char in;
	while(1){
		
		//if(itemCount==0){printf("Nothing left to do anything!\n");break;}
		printf("Enter p to print list, a to add node, d to delete node, e to exit: \n");
		scanf(" %c", &in);
		printf("You entered: %c\n", in);
		if(in=='a' || in=='A'){			
			char c;
			printf("Enter First, Last and id: \n");
			char s1[30];
			char s2[20];
			unsigned int itgr =0,exst=0;
			scanf("%s %s %d", &s1,&s2,&itgr);
			printf("You entered: %s %s %u\n", s1,s2,itgr);

			printf("Is it correct(y/n)? \n");
			scanf(" %c", &c);
			
			if(c == 'y' || c == 'Y'){
				if(itemCount==0){head = malloc(sizeof(struct node));strcpy(head->last, s1);
		strcpy(head->first, s2);head->id=itgr;itemCount++;
		printf("Node added to the list; Number of nodes= %d\n", itemCount);
			}else{
			    itemCount++;
				
				struct node* ptr = malloc(sizeof(struct node));
			    ptr = head;
			
			    while (ptr->link != NULL){
			    	if(ptr->id==itgr){
			    	    printf("Input:%d %s a node with id=%d already exists; Not added to the list!\n",itemCount,s1,itgr);
			    	    itemCount--;
			    	    exst=1;
			    	    break;
			    	}
			    	ptr = ptr->link;
			}
			
				if(!exst){
					
                    			struct node* temp = malloc(sizeof(struct node));
                    			strcpy(temp->last,s1);
                    			strcpy(temp->first,s2);
                   			temp->id=itgr;
                   			SortedInsert(&head, temp);
					printf("Node added to the list; Number of nodes= %d\n", itemCount);
				}
			}
}
		}else if(in=='d' || in=='D'){
			int num;
			printf("Enter Node number to delete: \n");
			scanf(" %d", &num);
			printf("You entered: %d \nIs it correct(y/n)?\n", num);
			char c2;
			scanf(" %c", &c2);
			if(c2=='y' || c2=='Y'){
				if((num<=itemCount) && (num>0)){
					//delete the node
					if(num==1){
						if(itemCount==1){head=NULL;}
						else{
						head=head->link;}
						
					}else if(num==itemCount){
						struct node* ptr = malloc(sizeof(struct node));
						ptr=head;
						while(ptr->link->link!=NULL){ptr=ptr->link;}
						ptr->link=NULL;
						
					}else{
						struct node* ptr = malloc(sizeof(struct node));
						struct node* del = malloc(sizeof(struct node));
						ptr=head;
						int flag=1;
						while(ptr){
							flag++;
							
							if(flag==num){del->link=ptr->link->link;ptr->link=NULL;break;}
							ptr=ptr->link;
							
						}
						
						ptr->link=del->link;	
					}
					itemCount--;
					printf("Node deleted from the list; Number of nodes: %d\n", itemCount);
				}else if(itemCount==0){
					printf("Nothing left to delete.\n");
					
				}else{
					printf("Illegal Node number!\n");
				}
			}

		}else if(in=='p' || in=='P'){
			struct node* ptr = malloc(sizeof(struct node));
			ptr = head;
			int ii = 1;
			while (ptr){
				printf("%d  %s   %s  %u\n", ii,ptr->last, ptr->first,ptr->id);
				ii++;
				ptr = ptr->link;
				
			}
		}else if(in=='e' || in=='E'){
			printf("\n");
			break;
		}
	}
fclose(textFile);
return 0;
}
