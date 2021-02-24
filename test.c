#include <string.h>

/* Macros are flexible with whitespace */
   #define   a'a'
   #define b\
'b'

/* C is flexible with newlines */
main
(
int
argc
,
char
*
*
argv
)
{
	putchar(a);
	putchar(b);

	/* Use other bases instead of decimal */
	putchar(0x63); /* c */
	putchar(0144); /* d */

	/* Use numbers instead of chars */
	putchar(10);

	/* Ideas for removable locking part */
	int lock;
	lock =
		!!!
		!!!
		!!!
1;
	puts(lock ? "lock\n" : "unlock\n");

	int DEL = 0;
	lock =
		DEL&
		DEL&
		DEL&
1;
	puts(lock ? "lock\n" : "unlock\n");

	DEL = -1;
	int ETE = -1, ME = 0;
	lock =
		DEL|
		ETE|
		~ME|
1;

	printf("%d\n", lock);

	/* Strings next to each other are concatenated */
	puts("a"
"b");

	/* Use char arithmetic to obfuscate strings */
	/* Prints "Hello!\n" */
	char *s = "Mionp!\t";
	s = "Rk~$pwtt\x1f`b\x1cg_ml\\hh";
	s = "55lvlfmobi\x1dg`s\x19l\\ni";
	int i = -7;
	for(; *s; s++) {
		putchar(i+++*s);
	}

	s = "Key must be letters\n";
	s = "./gridlock key text\n";
	char *st = s;
	i = -7;
	for(; *st; st++) {
		printf("%c - %d = %c (%d)\n", *st, i, *st - i, *st - i);
		i++;
	}


#define F(i)for(;*z;z++)putchar(i+*z);
	/* i is now 2, and can be used elsewhere */

}
