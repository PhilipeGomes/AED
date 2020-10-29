#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
 
int main() {
	char str[1000];
	int chaves = 0, cochetes = 0, paranteses = 0;
	int i = 0;
	printf("informe o texto: ");
	gets(str);
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '{') {
			chaves++;
		}
		if(str[i] == '}') {
			chaves--;
		}
		if (str[i] == '[') {
			cochetes++;
		}
		if (str[i] == ']') {
			cochetes--;
		}
		if (str[i] == '(') {
			paranteses++;
		}
		if (str[i] == ')') {
			paranteses--;
		}
		if (chaves < 0 || cochetes < 0 || paranteses < 0) {
			break;
		}
	}
	if (chaves == 0 && cochetes == 0 && paranteses == 0) {
		printf("bem formada\n");
	}
	else {
		printf("malformada\n");
	}
	return 0;
}