#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "max.h"
/* forward definition of functions */

//////////////////////////////////////////////////////////////////
int main ()
{
	FILE *input;
	input=fopen("input.txt","r");
 char ch;

 printf ("Starting Fast Food Order Management Program\n\n");
 printf ("Enter command: ");
 while (!feof(input))
 	{
 	fscanf(input,"%c",&ch);
 	switch(ch){
 		case 'q':{
 			printf ("Quitting Program\n");
       		return (0);
			break;
		 }
		case '?':{
 			printCommands();
			break;
		 }
		case 'a':{
 			doAdd(input);
			break;
		 }
		 case 'c':{
 			doCallAhead(input);
			break;
		 }
		 case 'w':{
 			doWaiting(input);
			break;
		 }
		 case 'r':{
 			doRetrieve(input);
			break;
		 }
		 case 'l':{
		 	printf("doList");
 			doList(input);
			break;
		 }
		 case 'd':{
		 	printf("calling Display");
 			doDisplay(input);
			break;
		 }
		 case 't':{
 			doEstimateTime(input);
			break;
		 }  
		 default:{
		 	printf ("%c - in not a valid command\n", ch);
       		printf ("For a list of valid commands, type ?\n");
			break;
		 }
	 }printf ("\nEnter command: ");
   }
   fclose(input);
 printf ("Quiting Program\n");
 return 1;
}
