#include <stdio.h>  /*needed for printf and BUFSIZ*/ 
#include <stdlib.h> /*needed for exit()*/
#include <stdbool.h> /*needed for encrypt bool*/  
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
		if(mixedCase[i]>64&&mixedCase[i]<91){ 
			mixedCase[i] += 32;
		}
		if(mixedCase[i]<start || mixedCase[i]>end) { 
			printf("INVALID CHARACTER! All characters must be between \'%c\' and \'%c\' in ASCII Table \n", start, end);
		       	exit(1); 	
		}	
	}
	return mixedCase; 
}
char polysub(char t, char k, char start, char end) {
	int offset = k - start; 
	char new_val = (t + offset) % (end + 1); 
	if(new_val < start) { 
		new_val = start + new_val; 
	} 	
	return new_val; 
} 
char rpolysub(char t, char k, char start, char end) {
    char diff = (t-k) % ((end - start) + 1);
    if(diff < 0) { /* must check because % is remainder in stead of modulo */  
        diff = diff + ((end-start)+1); 
    } 
    return (start + diff); 
} 
int crypt(char* text, char* key, char start, char end, bool encrypt){ 
	text = lowercase(text, start, end);
    key = lowercase(key, start, end); 	
	char result[BUFSIZ] = ""; /* we should try to find a way to use the exact size */  
	int i; 
	for(i=0; i<stl(text); i++) { 
        if(encrypt) { 
		    char polysub_l = polysub(text[i], key[i % stl(key)], start, end); 
		    my_strncat(result, &polysub_l, 1);
        } 
        else { 
            char rpolysub_l = rpolysub(text[i], key[i % stl(key)], start, end); 
		    my_strncat(result, &rpolysub_l, 1);
        } 
	} 	
	printf("Result: \'%s\'\n", result); 	
	return 0; 
} 


int main(int argc, char **argv){
	/* Set default key and text*/ 
	char* key = "apple"; /*segfaults if this is uppercase in lowercase() when mixedCase[i] += 32 because char* not modifiable*/  
    char* text = "educba"; 	
	char start = 'a'; 
	char end = 'z'; 
    bool encrypt = false; 
	/* Parse arguments */ 
	if (argc < 3) {
		printf("Usage: %s [key] text -e|-d\n", argv[0]);  
        printf("-e for encrypt -d for decrypt\n"); 
		return 1;
	}
	else if (argc == 3) { 		/* optional key not given */  
		text = argv[1];   
	} 
	else { 
		key = argv[1]; 
		text = argv[2]; 
	}
    
    if(argv[argc-1][1]=='e') { 
        printf("Encoding \'%s\'...\n", text); 
        encrypt = true; 
    }
    else if (argv[argc-1][1]=='d') {  
        printf("Decoding \'%s\'...\n", text); 
    }  
    else { /* has key and text but not -e or -d */  
        printf("Usage: %s [key] text -e|-d\n", argv[0]);  
        printf("-e for encrypt -d for decrypt\n"); 
		return 1;
    }  
    printf("key: %s, text: %s, encrypt? %d\n", key, text, encrypt); 
	return crypt(text, key, start, end, encrypt); 

}
