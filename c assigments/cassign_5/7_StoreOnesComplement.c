#include<stdio.h>
int main(int argc, char *argv[]) {
	//char *file = argv[1];
	int ich, size = 0, i = 0;;
	char ch;
	char *storecmpl, *actual;
	FILE *fp = NULL;
	if (argc != 2) {
		printf("pass arguments currectly");
		return -1;
	}
	fopen_s(&fp, argv[1], "r+");
	if (fp != NULL) {
		printf("file open successfully");
		while ((ch = fgetc(fp)) != EOF) {
			size++;
		}
		printf("%d\n", size);
		storecmpl = (char *)malloc((size+1) * sizeof(char));
		actual = (char *)malloc((size+1) * sizeof(char));
		
		rewind(fp);
		while ((ch = fgetc(fp))!=EOF) {
		//	printf("%d", i);
			
			actual[i] = ch;
			ich = (int)ch;
			storecmpl[i] = (char)(~ich);
			i++;
		}
		actual[i] = '\0';
		storecmpl[i] = '\0';
		printf("%d", i);
		//return 0;
		printf("Actual content is: %s\n", actual);
		printf("After one's complement: %s", storecmpl);
		// to strore into file after ones complement is done.
	/*rewind(fp);
		i = 0;
		while ((ch = fgetc(fp)) != EOF) {
		fputc(storecmpl[i],fp);
		i++;
		}
		printf("%d\n", i);
		rewind(fp);
		while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
		}*/
		free(actual);
		free(storecmpl);
		fclose(fp);
	}
	else {
		printf("file open failed");
		return -1;
	}
}