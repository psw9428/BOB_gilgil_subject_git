#include "add-nbo.h"


uint16_t my_ntohs(uint16_t n) {
	return (n >> 8) | ((n & 0xff) << 8);
}

uint32_t my_ntohl(uint32_t n) {
	return 
		((n & 0xff000000) >> 8*3) |
		((n & 0xff0000) >> 8) |
		((n & 0xff00) << 8) |
		((n & 0xff) << 8*3);
}

void error_print(char *s) {
	fprintf(stderr, "[*] %s\n", s);
	exit(1);
}

void add_nbo(char *path1, char *path2) {
	FILE *fp1, *fp2;
	char s1[5], s2[5];
	uint32_t n1, n2, sum;

	fp1 = fopen(path1, "r");
	if (!fp1) error_print(FILE_OPEN_ERROR_STRING);

	fp2 = fopen(path2, "r");
	if (!fp2) error_print(FILE_OPEN_ERROR_STRING);

	if (fread(s1, sizeof(char), 4, fp1) != sizeof(uint32_t))
		error_print(FILE_IS_NOT_4BYTE);

	if (fread(s2, sizeof(char), 4, fp2) != sizeof(uint32_t))
		error_print(FILE_IS_NOT_4BYTE);

	memcpy(&n1, s1, sizeof(uint32_t));
	memcpy(&n2, s2, sizeof(uint32_t));
	
	n1 = my_ntohl(n1);
	n2 = my_ntohl(n2);
	sum = n1 + n2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum);

	fclose(fp1);
	fclose(fp2);

	return;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
		printf(USAGE_STRING);
		return (0);
    }
	add_nbo(argv[1], argv[2]);
	return (0);
}
