#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
/* Print out a list of the commands for this program */
void printCommands()
{
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("a <# burgers> <# salads> <name> - to add your order to the order list\n");
 printf ("c <# burgers> <# salads> <name> - to add a call-ahead order to the order list\n");
 printf ("w <name> - to specify a call-ahead group is now waiting in the restaurant\n");
 printf ("r <# burgers> <# salads> - to retrieve the first waiting group whose order matches the items on the counter\n");
 printf ("l <name> - list how many orders are ahead of the named order\n");
 printf ("d - display the order list information\n");
 printf ("t <name> - display an estimated wait time for the given order name\n");
       
 /* clear input to End of Line */
}
void clearToEoln()
{
 int ch;
 
 do {
     ch = getc(stdin);
    }
 while ((ch != '\n') && (ch != EOF));
}
char *getName(FILE *input)
{
 char *ch;
 ch=(char*)malloc(sizeof(char[30]));
 fscanf(input,"%s",ch);
 return ch;
}
int getPosInt(FILE *input)
{
	int i;
	fscanf(input,"%d",&i);
	return i;
	
}

bool doesNameExist(char *name)
{
	group *temp=head;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0)
		return true;
		temp=temp->next;
	}
	
	return false;
}
void doList (FILE *input)
{
 /* get order name from input */
 char *name = getName(input);
 if (NULL == name)
   {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command format: l <name>\n");
    return;
   }

  printf ("Order for \"%s\" is behind the following orders\n", name);
	
 // add code to perform this operation here
  if(doesNameExist(name))
  {
  	group *temp=head;
  	while(strcmp(temp->name,name)!=0){
  		printf("%s:%d Burgers %d Salads\n",temp->name,temp->numBurger,temp->numSalad);
  		temp=temp->next;
	  }
  }
  else{
  	printf("No matching orders found.\n"); 
  }
  char ch1;
  fscanf(input,"%c",&ch1);
}
void doEstimateTime(FILE *input)
{
  /* get order name from input */
 
 char *name = getName(input);
/* char name[30];
 printf("Enter Name to get Estimate: ");
 scanf("%s",name);*/
 if (NULL == name)
   {
    printf ("Error: Time command requires a name to be given\n");
    printf ("Time command format: t <name>\n");
    return;
   }


  // add code to perform this operation here
  int mins=0;
  group *temp=head;
  if(doesNameExist(name)) 
  {
  	while(strcmp(temp->name,name)!=0)
  	{
  		mins+=(temp->numBurger)*(5);
  		mins+=(temp->numSalad)*(2);
  		temp=temp->next;
	  }
	printf("Estimated wait time for %s is %d minutes:\n", temp->name , mins);  
  }
  else{
  	printf("No matching orders found.\n"); 
  }
  
  char ch1;
  fscanf(input,"%c",&ch1);
}

void doDisplay (FILE *input)
{
  group *temp=head;
 //clearToEoln();
 printf ("Display information about all orders\n");
 // add code to perform this operation here
 while(temp!=NULL){
 	printf("%s:%d Burgers %d Salads, ",temp->name,temp->numBurger,temp->numSalad);
 	if(temp->is_inRes)
 	printf("currently in restaurant\n");
 	else
 	printf("currently not in restaurant\n");
 	temp=temp->next;
 }
 char ch1;
 fscanf(input,"%c",&ch1);
}
void doCallAhead(FILE *input)
{
 /* get number of burgers ordered from input */
 int NumBurgers = getPosInt(input); 
 if (NumBurgers < 0)
   {
    printf ("Error: Add command requires an integer value of at least 0\n");
    printf ("Add command format: a <# burgers> <# salads> <name>\n");
    return;
   }

  /* get number of salads ordered from input */
 int NumSalads = getPosInt(input);
 if (NumSalads < 0)
   {
    printf ("Error: Add command requires an integer value of at least 0\n");
    printf ("Add command format: a <# burgers> <# salads> <name>\n");
    return;
   }  

 /* get group name from input */
 char *name = getName(input);
 if (NULL == name)
   {
    printf ("Error: Add command requires a name to be given\n");
    printf ("Add command format: a <# burgers> <# salads> <name>\n");
    return;
   }

// printf ("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
 
 // add code to perform this operation here
 group *temp=head;
 group *new_group;
 new_group=(group*)malloc(sizeof(group));
 new_group->name=name;
 new_group->numBurger=NumBurgers;
 new_group->numSalad=NumSalads;
 new_group->next=NULL;
 new_group->prev=NULL;
 
 new_group->is_inRes=false;
 if(head==NULL){
 	head=new_group;	
 	
 }
 else{
 	while(temp->next!=NULL){
 		temp=temp->next;
	 }
	 temp->next=new_group;
	 new_group->prev=temp;
 } 
 printf ("Adding Call_Ahead order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
 char ch1;
 fscanf(input,"%c",&ch1);
}
void doAdd(FILE *input)
{
 /* get number of burgers ordered from input */
 int NumBurgers = getPosInt(input); 
 if (NumBurgers < 0)
   {
    printf ("Error: Add command requires an integer value of at least 0\n");
    printf ("Add command format: a <# burgers> <# salads> <name>\n");
    return;
   }

  /* get number of salads ordered from input */
 int NumSalads = getPosInt(input);
 if (NumSalads < 0)
   {
    printf ("Error: Add command requires an integer value of at least 0\n");
    printf ("Add command format: a <# burgers> <# salads> <name>\n");
    return;
   }  

 /* get group name from input */
 char *name = getName(input);
 if (NULL == name)
   {
    printf ("Error: Add command requires a name to be given\n");
    printf ("Add command format: a <# burgers> <# salads> <name>\n");
    return;
   }

// printf ("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
 
 // add code to perform this operation here
 group *temp=head;
 group *new_group;
 new_group=(group*)malloc(sizeof(group));
 new_group->name=name;
 new_group->numBurger=NumBurgers;
 new_group->numSalad=NumSalads;
 new_group->next=NULL;
 new_group->prev=NULL;

 
 new_group->is_inRes=true;
 if(head==NULL){
 	head=new_group;	
 	
 }
 else{
 	while(temp->next!=NULL){
 		temp=temp->next;
	 }
	 temp->next=new_group;
	 new_group->prev=temp;
 } 
 printf ("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
 char ch1;
 fscanf(input,"%c",&ch1);
}
void doWaiting (FILE *input)
{
 /* get order name from input */
 char *name = getName(input);
 printf("%s",name);
 char ch1;
 /*char name[30];
 printf("ENter NAme: ");
 scanf("%s",name);*/
 if (NULL == name)
   {
    printf ("Error: Waiting command requires a name to be given\n");
    printf ("Wait command format: w <name>\n");
    return;
   }

 
	
 // add code to perform this operation here
 
 else if(doesNameExist(name)){
 	group *temp=head;
 	
 	while(strcmp(temp->name,name)!=0){
 		temp=temp->next;
	 }
	 temp->is_inRes=true;
	 printf ("Call-ahead order \"%s\" is now waiting in the restaurant\n", name);
	 fscanf(input,"%c",&ch1);
	 return;
 }
 printf("No matching orders found.\n"); 
 
 fscanf(input,"%c",&ch1);
 return;
}
///////////////////////////////////////////////////////////////////
void retrieveAndRemove (group *a,group *b)
{
	
	if(strcmp(b->name,head->name)==0)
	{
		head=head->next;
		free(b);
	}
	else
	{
		a->next=b->next;
		free(b);	
	}
	
	return;
}

void doRetrieve (FILE *input)
{
 /* get info of prepared food ready on the counter from input */
 int PreparedBurgers = getPosInt(input);
 if (PreparedBurgers < 0)
   {
    printf ("Error: Retrieve command requires an integer value of at least 0\n");
    printf ("Retrieve command format: r <# burgers> <# salads>\n");
  
    return;
   }

 int PreparedSalads = getPosInt(input);
 if (PreparedSalads < 0)
   {
    printf ("Error: Retrieve command requires an integer value of at least 0\n");
    printf ("Retrieve command format: r <# burgers> <# salads>\n");
    return;
   }   
// printf ("Retrieve and remove the first group that can pick up the order of %d burgers and %d salads\n", PreparedBurgers ,PreparedSalads);

 // add code to perform this operation here
 char ch1;
 fscanf(input,"%c",&ch1);
 group *temp=head;
 group *temp_prev=head;
 while(temp!=NULL){
 	if((temp->numBurger<=PreparedBurgers)&&(temp->numSalad<=PreparedSalads))
 	{
 		if(temp->is_inRes)
 		{		
 			printf("%s: %d burgers and %d salads, currently in the restaurant.(Order Removed)\n",temp->name,temp->numBurger,temp->numSalad );
 			retrieveAndRemove (temp_prev,temp);
 			
 			return;
		 }
		 else{
		 	printf("%s: %d burgers and %d salads, currently not in the restaurant.\n ",temp->name,temp->numBurger,temp->numSalad );
		 	
		 }
	 }
	 temp_prev=temp;
 	temp=temp->next;
 }
 printf("No Order Removed\n");
 
}
