#include<stdio.h>
#include<stdlib.h>
void countchars();
void removeComments();
void replaceTabs();
void rotateAndReplace();

// main starts here
int main() {
	int op;
	while (1) {
		// choosing an option for different tasks;
		printf("select the option\n");
		printf("1. count the no.of alphabets,digits,spaces and special characters in a file\n");
		printf("2.Remove all comments from the file\n");
		printf("3.Find a matching word in the file and rotate and replace it in the same file\n");
		printf("4.Replace all the tabs present in file content with \t\n");
		printf("5.exit\n");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			// functionality for counting number of alphabets,digits, spaces,and special characters
			countchars();
			break;
		case 2:
			removeComments();
			break;
		case 3:
			rotateAndReplace();
			break;
		case 4:
			replaceTabs();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("choose a valid option\n");
			break;

		}

	}

	system("pause");
}



