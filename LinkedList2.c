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

struct strr{
	char string[30];
	};
/*struct node *PointToMe(Struct node *here, int target){
	if(here=NULL){
		return NULL;
	}
	while(here->id!=target && here->link !=NULL){
		here=here->link;
		if(here->id==target){
			return here;
		}
	}return NULL:
}*/
void SortedInsert(struct node** head, struct node* newNode)
{
	// Special case for the head end
	if (*head == NULL || (*head)->id >= newNode->id)
	{
		newNode->link = *head;
		*head = newNode;
		return;
	}

	// Locate the node before the point of insertion
	struct node* current = *head;
	while(current->link != NULL && current->link->id < newNode->id)
		current = current->link;

	newNode->link = current->link;
	current->link = newNode;
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
		//printf(" id %u",head->id);
		//printf(" %s  ",head->last);
		//printf(" %s",head->first);
	itemCount++;

/******************************************************************************************************************/
	struct strr *str11 = malloc(sizeof(struct strr));
	while(fscanf(textFile, "%s", &str11->string)!=EOF){
		struct node *tempArray = malloc(sizeof(struct node));
		
		if(atoi(str11->string)==0){
			int t, tc=0,c=0;
			for(t=0; t<strlen(str11->string);t++){
				if(str11->string[t] != 44 && tc == 0){
					tempArray->last[t] = str11->string[t];
				}else if(str11->string[t] == 44){
					tc = 1;
				}else if((tc == 1) && (str11->string[t]!=44)){
					tempArray->first[c]= str11->string[t];
					c++;
				}
			}printf("%s  %s\n",tempArray->last,tempArray->first);
		}else{
			//struct node *temp;
			//temp = malloc(sizeof(struct node));
			tempArray->id= (unsigned)(atoi(str11->string));
			//strcpy(temp->last, tempArray->last);
			//strcpy(temp->first, tempArray->first);
			int isIn = 0;

			struct node* ptr = malloc(sizeof(struct node));
			ptr = head;

			while (ptr->link != NULL){

				if(ptr->id==tempArray->id){
					isIn=1; 
					printf("Already exist  %d item %d\n", tempArray->id, itemCount);
					ptr = head;
					break;}
				ptr = ptr->link;
				
			}
			if(!isIn){
				SortedInsert(&head, tempArray);
				
				
			}itemCount++;
			
		}
		str11 = malloc(sizeof(struct strr));
	}
			struct node* ptr = malloc(sizeof(struct node));
			ptr = head;
			int ii = 1;
			while (ptr->link != NULL){
				printf("%d  %s   %s  %u\n", ii,ptr->last, ptr->first,ptr->id);
				ii++;
				ptr = ptr->link;
				
			}
			/*struct node* ptr = head;
			int i = 1;
			while (ptr != NULL){
				printf("%d %d    %s   %s", i,ptr->last, ptr->first ,ptr->id);
				ptr = ptr->link;
				i++;
			}
printf("null");*/
/**********************************************************************************************************************************/
/*
	//asking for user command
	char in;
	while(1){
		printf("Enter p to print list, a to add node, d to delete node, e to exit: ");
		fscanf(" %c", &in);
		printf("You entered: %c", in);
		if(in=='a' || in=='A'){
			printf("Enter First, Last and id: ");
			printf("You entered: ");
			char c;
			printf("Is it correct(y/n)? ");
			scanf(" %c", &c);
			if(c == 'y' || c == 'Y'){
				//check for existence, if new, add to list
				// print [Node added to the list; Number if nodes: ]
				if(//exist){

					itemCount++;
					printf("Node added to the list; Number of nodes= %d", itemCount);
				}else{
					printf();
				}
			}

		}else if(in=='d' || in=='D'){
			int num;
			printf("Enter Node number to delete: ");
			scanf(" %d", num);
			printf("You entered: %d \nIs it correct(y/n)?", num);
			char c2;
			scanf(" %c", c2);
			if(c2=='y' || c2=='Y'){
				if(num<=itemCount){
					//delete the node
					itemCount--;
					printf("Node deleted from the list; Number of nodes: %d", itemCount);
				}else{
					printf("Illegal Node number!\n");
				}
			}

		}else if(in=='p' || in=='P'){
			//print every nodes in list
			struct node* ptr = head;
			int i = 1;
			while (ptr){
				printf("%d %d    %s   %s -> ", i,ptr->last, ptr->first ,ptr->id);
				ptr = ptr->link;
				i++;
			}

			printf("null");
		}else{
			break;
		}
	}*/

return 0;
}
