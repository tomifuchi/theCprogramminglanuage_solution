



#include <stdio.h>
#define MAXLINE		5000/*maximum input line size*/
//Comment state
#define IN 1
#define OUT 0
//Comment type
#define UNDEFINED 0
#define SINGLE 1
#define MULTIPLE 2

void getlines(void);

char line[MAXLINE]; //current input line
char nocomment_line[MAXLINE]; //No comment line

//Removing comments from a .c file.
//Try and paste the stream of input into this program.
int main()
{
	int len; //current length
	extern char nocomment_line[];

	getlines();
	printf("-----------------------\n");
	printf("REMOVING COMMENT LINE\n");
	printf("-----------------------\n");
	printf("\n<Start beyond this>\n");
	printf("%s", nocomment_line);

	return 0;
}

/* getlines: rea line into s, return length with detabbing filter*/
void getlines(void)
{
	int c,i,j;
	int comment = OUT;
	int comment_type = UNDEFINED;
	//0 for undefined, 1 for semi-close waiting for / to close
	int multiline_comment_closing_state;

	extern char line[];
	extern char nocomment_line[];

	for (i = 0,j = 0; i < MAXLINE - 1 \
			&& j < MAXLINE - 1 \
			&& (c=getchar())!=EOF \
			; ++i){
		line[i] = c;
		if (comment == OUT){
			if (c == '/')
			  comment = IN;

			nocomment_line[j] = c;
			++j;
		}
		else if (comment == IN){
			if (comment_type == SINGLE){
				if (c == '\n'){
			  	  nocomment_line[j] = '\n';
			  	  ++j;
				  comment = OUT;
				  comment_type = UNDEFINED;
				}
			}
			else if (comment_type == MULTIPLE){
				if (c == '*' && multiline_comment_closing_state == 0)
					multiline_comment_closing_state = 1;
				else if (c == '/' && multiline_comment_closing_state == 1){
					comment = OUT;
					comment_type = UNDEFINED;
				}
				else multiline_comment_closing_state = 0;
			}
			else if (comment_type == UNDEFINED){
				if (c == '/')
				  comment_type = SINGLE;
				else if ( c == '*')
				  comment_type = MULTIPLE;

				if (comment_type == SINGLE || comment_type == MULTIPLE)
				  j = j - 1;
				else{
				  nocomment_line[j] = c;
				  ++j;
				  comment = OUT;
			          comment_type = UNDEFINED;
				}
			}
		}
	}

	line[i] = '\0';
	nocomment_line[j] = '\0';
}
