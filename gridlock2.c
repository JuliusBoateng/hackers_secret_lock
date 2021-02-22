/*
int stl(char*s){
	int c;
	for(c=0;s[c];c++);
	return c;
}
*/

int main(int argc, char **argv){
	/* 1 encrypts, -1 decrypts */
	int sign = 1;

	/* Check arguments */
	if (argc != 3) {
		printf("Usage: %s key text\n", argv[0]);
		return 1;
	}

	/* Get key and key length */
	/* TODO: make sure key is all uppercase letters? */
	char *key = argv[1];
	int keylen = 0;
	for (; key[keylen]; keylen++);

	/* Get and translate text */
	/* The text variable will be updated in-place */
	char *text = argv[2];

	int j = 0;
	char *chr = text;
	for(; *chr; chr++) {
		char chrcase;
		if (*chr >= 'A' && *chr <= 'Z') {
			chrcase = 'A';
		} else if (*chr >= 'a' && *chr <= 'z') {
			chrcase = 'a';
		} else {
			continue;
		}

		int key_j = key[j % keylen] - 'A';
		int text_i = *chr - chrcase;
		*chr = chrcase + (text_i + sign * key_j + 26) % 26;
		j++;
	}

	puts(text);
	return 0;
}
