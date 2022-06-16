



#include <stdio.h>
#define MAXLINE		5000/*maximum input line size*/

void getlines(void);
int check_comment(char c);
int check_unbalance(char c);

char line[MAXLINE]; //current input line
int nline = 0; //lines
int ncol = 0; //columns

int main()
{
	int len; //current length

	getlines();
	//printf("-----------------------\n");
	//printf("Syntax error detected\n");
	//printf("-----------------------\n");

	return 0;
}

#define IN 1
#define OUT 0
/* getlines: rea line into s, return length with detabbing filter*/
void getlines(void)
{
	int c,i;
	//0 for undefined, 1 for semi-close waiting for / to close
	extern char line[];
	extern int comment;

	for (i = 0; i < MAXLINE - 1 && (c=getchar())!=EOF; ++i){
		line[i] = c;
		++ncol;
		if (c == '\n'){
			ncol = 0;
			++nline;
		}
   		 //Actively looking for
    		//commenting signs
		if (check_comment(c))
			  printf("Syntax error on line %d at column %d\n",nline + 1,ncol); 

		//If we are not in the comment, all bets are off.
		//Checking equal numbers of brackets, braces, parenthesis
		if (comment == OUT)
			check_unbalance(c);
	}
	if(check_unbalance(c))
		printf("Unbalanced braces, parenthesis, brackets, quotes\n");

	line[i] = '\0';
}
//braces brackets parenthesisCHECKING
int nbrace = 0;
int nbrackets = 0;
int nparenthesis = 0;
int nquote = 0;
int ndquote = 0;

//Should every pair of braces, brackets have pair
//then the open brace denote 1
//close brace denote -1
//Then it should sum up to zero for all enterity of 
//the program.
//Return for
//1 : unbalance parenthesis
//2 : unbalance braces
//3 : unbalance brackets
//4 : unbalance single quote
//5 : unbalance double quote
int check_unbalance(char c){
	//Parentheses
	if (c == '(')
		++nparenthesis;
	else if (c == ')')
		--nparenthesis;
	//Braces
	else if (c == '{')
		++nbrace;
	else if (c == '}')
		--nbrace;
	//Brackets
	else if (c == '[')
		++nbrackets;
	else if (c == ']')
		--nbrackets;
	//Quote
	else if (c == '\'' && nquote == 0)
		++nquote;
	else if (c == '\'' && nquote == 1)
		--nquote;
	//Double quote
	else if (c == '\"' && ndquote == 0)
		++ndquote;
	else if (c == '\"' && ndquote == 1)
		--ndquote;

	if (nparenthesis == 0 && nbrace == 0 && nbrackets == 0 && nquote == 0 && ndquote == 0)
		return 0;
	else if (nparenthesis != 0)
		return 1;
	else if (nbrace != 0)
		return 2;
	else if (nbrackets != 0)
		return 3;
	else if (nquote != 0)
		return 4;
	else if (ndquote != 0)
		return 5;
}

//COMENT CHECKING
//Comment state
#define IN 1
#define OUT 0
//Comment type
#define UNDEFINED 0
#define SINGLE 1
#define MULTIPLE 2
//multiline comment state
#define SEMI 1
#define IDLE 0
int comment = OUT;
int comment_type = UNDEFINED;
int multiline_comment_closing_state = IDLE;

int check_comment(char c){
	extern int comment;
	extern int comment_type;
	extern int multiline_comment_closing_state;

	if (comment == OUT){
		if (c == '/')
			comment = IN;
	}
	else if (comment == IN){
		if (comment_type == SINGLE){
			if (c == '\n'){
				comment = OUT;
				comment_type = UNDEFINED;
			}
		}
		else if (comment_type == MULTIPLE){
			if (c == '*' && multiline_comment_closing_state == IDLE)
				multiline_comment_closing_state = SEMI;
			else if (c == '/' && multiline_comment_closing_state == SEMI){
				multiline_comment_closing_state = IDLE;
				comment = OUT;
				comment_type = UNDEFINED;
			}
			else multiline_comment_closing_state = IDLE;
		}
		else if (comment_type == UNDEFINED){
			if (c == '/')
				comment_type = SINGLE;
			else if ( c == '*')
				comment_type = MULTIPLE;
			else{
				comment = OUT;
				comment_type = UNDEFINED;
				return 1;
			}
		}
	}
	return 0;
}
