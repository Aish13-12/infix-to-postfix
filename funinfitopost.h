struct charc//Defining the struct
{
	char operator;
	struct charc*nxt;
};	

#define MAX_CAP 100

void pushst(struct charc**head,char opera)//Function to push the node into a stack
{
	struct charc *temp;
	temp=(struct charc*)malloc(sizeof(struct charc));
	temp->operator=opera;
	temp->nxt=NULL;
	if(*head==NULL)
	*head=temp;
	else
	{
		struct charc *temp1 = *head;
		while(temp1->nxt!=NULL)
		temp1=temp1->nxt;
		temp1->nxt=temp;
	}
}

void popst(struct charc**head)//Function to delete or pop the top of the stack
{
	struct charc*temp1=*head;
	if(*head==NULL)
	exit(EXIT_SUCCESS);
	
	else if(temp1->nxt==NULL)
	{
		free(temp1);
		temp1=NULL;
		*head=temp1;
	}	
	else
	{
		struct charc *temp = *head;
		struct charc *prev = *head;
		while(temp->nxt!=NULL)
		{
			prev=temp;
			temp=temp->nxt;
		}
		
		prev->nxt=NULL;
		free(temp);
		temp=NULL;
	}
}	



int operator(char c)//To detect the following operators and brackets in the string
{
	switch(c)
	{
		case'+':return 0;
		case'-':return 0;
		case'*':return 1;
		case'/':return 1;
		case '^':return 2;
		case '(':return -1;
		
		case '{':return -1;
		
		case '[':return -1;
		
		default:exit(EXIT_SUCCESS);
	}
}

int isoperator(char ch)//To seperate operators and other characters
{
	switch(ch)
	{
		case '+':return 1;
		case '-':return 1;
		case '*':return 1;
		case '/':return 1;
		case '^':return 1;
		
		default:return 0;
	}
}

int isentry(char ch)//To verify whether the entered expression is valid or not
{
	if(isdigit(ch)!=0)
	return 1;
	else
	{
		
	    switch(ch)
	    {
			case '+':return 1;
		    case '-':return 1;
		    case '*':return 1;
		    case '/':return 1;
		    case '^':return 1;
		    case '.':return 1;
		    case '(':return 2;
		    case ')':return -2;
		    case '[':return 3;
		    case ']':return -3;
		    case '{':return 4;
		    case '}':return -4;
		
		    default:return 0;	
		 }
	}
}		  
	
		

			

int ismark(char ch)//For the decimal point and brackets
{
	switch(ch)
	{
		case '.':return 1;
		case '(':return 2;
		case ')':return -2;
		case '[':return 3;
		case ']':return -3;
		case '{':return 4;
		case '}':return -4;
		default:return 0;
	}
}		 

char printtop(struct charc**head)//To obtain the data in tthe top node of the stack
{
	struct charc *temp= *head;
	
	while(temp->nxt!=NULL)
	temp=temp->nxt;
	   

	return temp->operator;
}	
			
void convo(struct charc*head)
{
	
    char str[MAX_CAP],ch;
	int j=0;
	while(ch!='\n')
	{
		ch=getchar();
		str[j]=ch;
		j++;
	}	
	str[j]='\0';
	int i=0,tra=0;
	
	while(str[tra]!='\0')//Defining the conditions for invalid infix expressions
	{
		if(isoperator(str[0])==1||str[0]=='.')//Only start with a digit or a bracket
		{
			printf("Invalid infix expression\n");
			printf("Error at position 1\n");
			exit(EXIT_SUCCESS);
		}
		else if(isentry(str[i])==0)//Checking the entry's in the string
		{
			printf("\nInvalid infix expression\n");	
			printf("Unidentifable character at position %d\n",tra+1);
			exit(EXIT_SUCCESS);
			
			  
		}
		else if(ismark(str[tra])!=0&&(ismark(str[tra])==ismark(str[tra+1])))//Checking the position of the bracket's
		{
			printf("\nInvalid infix expression\n");
			printf("Error at position %d\n",tra+2);
			exit(EXIT_SUCCESS);
		}
			
		else if (str[tra]=='.'&&isoperator(str[tra-1])==1)//A decimal point after an operator is invalid
		{
			printf("Invalid infix expression\n");
			printf("Error at position %d\n",tra+1);	
			exit(EXIT_SUCCESS);
		}
		else if(isoperator(str[tra])==1&&isoperator(str[tra+1])==1)//Two operators adjacent to each other is invalid
		{
			printf("Invalid infix expression\n");
			printf("Error at position %d\n",tra+2);	
			exit(EXIT_SUCCESS);
		}	
		
		tra++;
	}
	
	
	while(str[i]!='\0')
	{
		
		if(isdigit(str[i])!=0&&(isoperator(str[i-1])==1||ismark(str[i-1])!=0))
		printf(" %c",str[i]);
		
		else if(isdigit(str[i])!=0)
		printf("%c",str[i]);
		
		else if(str[i]=='.')
	    printf("%c",str[i]);
	    
	    else if(str[i]=='(')
	    pushst(&head,str[i]);
	    
	    else if(str[i]=='{')
	    pushst(&head,str[i]);
	    
	    else if(str[i]=='[')
	    pushst(&head,str[i]);
	    
	    else if(str[i]==')')
	    {
			while(printtop(&head)!='(')
			{
				printf(" %c",printtop(&head));
				popst(&head);
			}
			popst(&head);
		}
		
		else if(str[i]=='}')
	    {
			while(printtop(&head)!='{')
			{
				printf(" %c",printtop(&head));
				popst(&head);
			}
			popst(&head);
		}
		else if(str[i]==']')
	    {
			while(printtop(&head)!='[')
			{
				printf(" %c",printtop(&head));
				popst(&head);
			}
			popst(&head);
		}
				
				
		
		else 
		{
			while(head!=NULL&&operator(str[i])<=operator(printtop(&head)))
			{
				printf(" %c",printtop(&head));
				popst(&head);
				
			}
			
			pushst(&head,str[i]);
			
		}
		i++;
		
	}
	while(head!=NULL)
	{
		printf("%c",printtop(&head));
		popst(&head);
	}
	
}	
		
	
		
		



						
			
			
			
			    
				
					
	
			
					
		
