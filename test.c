/* Macros are flexible with whitespace */
   #define   a'a'
   #define b\
'b'

/* C is flexible with newlines */
int
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

	/* Strings next to each other are concatenated */
	puts("a"
"b");

	/* Use char arithmetic to obfuscate strings */
	/* Prints "Hello!\n" */
	char *s = "Mionp!\t";
	int i = -5;
	for(; *s; s++) {
		putchar(i+++*s);
	}
	/* i is now 2, and can be used elsewhere */

	return 0;
}
