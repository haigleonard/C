
#include "stdio.h"
#include "stdlib.h"
/*
Comment briefly on any limitations which might apply to your code.
	The string is restricted to 100 characters in memory
If you wanted to obtain an uppercased version of the original string without changing the original, how might you handle this ?
	To keep the original char array the same, a copy must be made in the function, and returned
*/
const char * upper_stringNoChange(char s[]) {
	int c = 0;
	static char string[100]="";
	strcpy(string, s);
	while (string[c] != '\0') {
		if (string[c] >= 'a' && string[c] <= 'z') {
			string[c] = string[c] - 32;
		}
		c++;
	}
	return string;
}
void upper_stringChange(char s[]) {
	for (int c = 0; c < strlen(s); c++) {
		if (s[c] >= 'a' && s[c] <= 'z') {
			s[c] = s[c] - 32;
		}
	}
}
main()
{
	char stringOne[100] = "Changing Strings from lower to UPPERCASE without additional libaries";
	printf("The string in upper case without changing orginal:\nOriginal: %s\nNew String: %s\n", stringOne, upper_stringNoChange(stringOne));
	upper_stringChange(stringOne);
	printf("The string in upper case by changing original: %s\n", stringOne);
	int i;
	i = getchar();
	return 1;
	
}

