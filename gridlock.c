#include <stdio.h> 
#include <string.h>
char* lowercase(char* mixedCase) { 
	int i; /* this is necessary because c89 does not allow declaration of control variables in for loop */  
	for(i=0; i<strlen(mixedCase); i++) { /* I decided to do it this way instead of with tolower because it seemed more "hacker like" and easier to obfuscate */ 
		if(mixedCase[i]>=65&&mixedCase[i]<91){  
			mixedCase[i] += 32; 
		} 	 

	}	
	return mixedCase; 
}
char polysub(char t, char k) {
       	char start = 'a'; 
	char end = 'z'; 
	int offset = t - start; 
	char new_val = (k + offset) % (end + 1); 
	if(new_val < start) { 
		new_val = start + new_val; 
	} 	
	return new_val; 
}
int encrypting(char* text, char* key){ 
	text = lowercase(text);
       	key = lowercase(key); 	
	char result[BUFSIZ] = ""; /* we should try to find a way to use the exact size */  
	int i; 
	for(i=0; i<strlen(text); i++) { 
		char polysub_l = polysub(text[i], key[i % strlen(key)]); 
		strcat(result, &polysub_l);
	} 	
	printf("Encrypted Result: \'%s\'\n", result); 	
	return 0; 
} 


int main(int argc, char **argv){
	/* Set default key and text*/ 
	char* key = "APPLE";
       	char* text = "EDUCBA"; 	
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
	return encrypting(text, key); 
}
