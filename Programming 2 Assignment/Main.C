
#include "stdio.h"
#include "stdlib.h"
/*
Proragmming 2 C assignment:
You are required to write a program in C that reads in a text file words.txt containing words separated
by whitespace characters and punctuation. The program detects any palindromic words, i.e. words
that contain a sequence of letters (not including numeric digits) that is the same read backwards as it is
forwards, such as noon, kayak or radar. The program outputs a list of all of the palindromes that occur in
the text file, along with the number of times each palindrome occurs in the text. Hints: start by writing
function to determine whether a string is palindromic, then write a program that reads text from a file and
prints the palindromic words as the occur in the text. Then write a program that counts the occurrences of
each palindrome, the Linked List in C example (given in the C++ lectures on BlackBoard) may be useful
for this (when adapted). The text file contains the word ”civic” five times. Include a printout of the ouptut
of your program in the submission.
*/
struct node {
	char* val;
	int count;
	struct node * next;
};

main()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->val = "Words";
	head->count = 0;

	struct node* next =  (struct node*)malloc(sizeof(struct node));
	head->next = next;
	next->val = "derp2";
	next->count = 0;
	
	char  *f = "text.txt"; 
	char word[256];
	FILE * fp = fopen(f, "r");
	while (fscanf(fp, "%s", word) != EOF)
	{
		int t= 0, t2 = 0;
		size_t len = strlen(word);
		for (int i = 0; i < len; i++) {
			if (word[i] != word[len - i - 1]) {
					t = 1;
			}
		}
		if (t == 0 && len > 2 && ((word[0] >= 'a' && word[0] <= 'z') || (word[0] >= 'A' && word[0] <= 'Z'))) {

			char *str2 = malloc(len + 1 + 1); /* one for extra char, one for trailing zero */
			strcpy(str2, word);
			char compare[256];
			next->next = NULL;
			struct node* print = head;
			while (print->next != NULL) {
				strcpy(compare, print->val);
				if (strcmp(word, compare) == 0) {
					print->count++;
					t2 = 1;
				}
				print = print->next;
			}

			if (t2 == 0) {
				struct node* next2 = (struct node*)malloc(sizeof(struct node));
				next->next = next2;
				next2->val = str2;
				next2->count = 1;
				next = next2;
			}
		}
	}
	fclose(fp);
	next->next = NULL;
	
	struct node* print = head;
	while (print->next != NULL) {
		printf("%d:%s\n",print->count, print->val);
		print = print->next;
	}
	
	char stringOne[100] = "Changing Strings from lower to UPPERCASE without additional libaries";
	printf("The string in upper case without changing orginal:\nOriginal: %s\nNew String: %s\n", stringOne, upper_stringNoChange(stringOne));
	upper_stringChange(stringOne);
	printf("The string in upper case by changing original: %s\n", stringOne);
	
	
	
	int i;
	i = getchar();
	return 1;
	
}

