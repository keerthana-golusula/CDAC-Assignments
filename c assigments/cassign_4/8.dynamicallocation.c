#include<stdio.h>
#include<string.h>
int main() {
	int i=0, len,n;
	char msg[50];
	char **str=NULL;
	printf("enter number of strings you want to enter");
	scanf("%d", &n);
	str = (char **)malloc(n * sizeof(char *));
	while (i<n) {
		//char msg[50];
		printf("enter string %d\n", i);
		scanf("%s", msg);
		len = strlen(msg);
		str[i] = (char *)malloc((len + 1) * sizeof(char));
		if (str[i] == NULL) {
			return -1;
		}
		else {
			strcpy(str[i], msg);
		}

		i++;
	}
	for (i = 0; i < n; i++) {
		
		printf("%s", str[i]);

	}
	while (n--) {
		free(str[n]);
}
	free(str);
	return 0;

}