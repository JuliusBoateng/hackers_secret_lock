#include <stdio.h>  /*needed by printf and BUFSIZ*/ 
#include <stdlib.h> /*needed by exit()*/
int stl(char* str) { 
	int c = 0; 
	while(str[c] != '\0') { 
		c++; 
	}
	return c; 
}
char* my_strncat(char *dest, const char *src, size_t n){
    size_t dest_len = stl(dest);
    size_t i;
   for (i = 0 ; i < n && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

   return dest;
}
char* lowercase(char* mixedCase, char start, char end) {
	int i; /* this is necessary because c89 does not allow declaration of control variables in for loop */  
	for(i=0; i<stl(mixedCase); i++) { /* I decided to do it this way instead of with tolower because it seemed more "hacker like" and easier to obfuscate */
		char prev_char = mixedCase[i];
		if(mixedCase[i]>64&&mixedCase[i]<91){ 
			mixedCase[i] += 32;
		}
		if(mixedCase[i]<start || mixedCase[i]>end) { 
			printf("INVALID CHARACTER: \'%c\'! All characters must be between \'%c\' and \'%c\' in ASCII Table \n", prev_char, start, end);
		       	exit(1); 	
		}	
	}
	return mixedCase; 
}
char polysub(char t, char k, char start, char end) {
	int offset = t - start; 
	char new_val = (k + offset) % (end + 1); 
	if(new_val < start) { 
		new_val = start + new_val; 
	} 	
	return new_val; 
}
int encrypting(char* text, char* key, char start, char end){ 
	text = lowercase(text, start, end);
       	key = lowercase(key, start, end); 	
	char result[BUFSIZ] = ""; /* we should try to find a way to use the exact size */  
	int i; 
	for(i=0; i<stl(text); i++) { 
		char polysub_l = polysub(text[i], key[i % stl(key)], start, end); 
		my_strncat(result, &polysub_l, 1);
	} 	
	printf("Encrypted Result: \'%s\'\n", result); 	
	return 0; 
} 


int main(int argc, char **argv){
	/* Set default key and text*/ 
	char* key = "apple"; /*segfaults if this is uppercase in lowercase when mixedCase[i] += 32...*/
       	char* text = "educba"; 	
	char start = 'a'; 
	char end = 'z'; 
	/* Parse arguments */ 
	if (argc < 2) {
		printf("Usage: %s [key] text\n", argv[0]);  
		return 1;
	}
	else if (argc == 2) { 		/* optional key not given */ 
		text = argv[1]; 
	} 
	else { 
		key = argv[1]; 
		text = argv[2]; 
	} 
	printf("Encoding \'%s\'...\n", text); 
	return encrypting(text, key, start, end); 
}
