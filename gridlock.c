int main(int argc, char **argv){
	if (argc != 3) {
		printf("Usage: %s key text\n", argv[0]);
		return 1;
	}

	puts(argv[2]);
}
