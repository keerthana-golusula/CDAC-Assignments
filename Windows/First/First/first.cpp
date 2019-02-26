#include<stdio.h>
#include<windows.h>
int main() {
	CHAR arr[]="keerthana";
	//scanf_s("%s", arr);
	CHAR *c;
	WCHAR wch[] = L"tejaswini";
	WCHAR *wa;
	BOOL res, res2;
	int ret2;
	printf("MultiByte Character string arr is %s:\n", arr);
	printf("WideChar string wch is %S\n", wch);
	res = IsTextUnicode(arr, sizeof(arr), NULL);//testing whther arr is unicode or not
	if (0 != res) {
		printf("arr is unicode\n");
	}
	else {
		printf("arr is not a unicode\n");
	}
	res2 = IsTextUnicode(wch, sizeof(wch), NULL);//testing whether wch is unicode or not
	//printf("%d\n", res2);
	if (0 != res2) {   //res2 is non zerovalue as it is unicode
		printf("wch is unicode\n");
	}
	else
		printf("wch is not unicode\n");
	int ret = MultiByteToWideChar(CP_UTF8, 0, arr, -1, NULL, 0);//returns the no of bytes required;
	if (0 == ret) {
		printf("MultiByte to WideChar Failed:%d", GetLastError());
	}
	else {
	
	wa = new WCHAR[ret];//allocating ret size of memory
	ret2=MultiByteToWideChar(CP_UTF8, 0, arr, -1, wa, ret);
	if(0==ret2)
	printf("conversion failed:%d\n", GetLastError());
	else {
		printf("After conversion to wideChar:%S\n", wa);//printing wchar type of arr
	}
}
	ret = WideCharToMultiByte(CP_UTF8, 0, wch, -1, NULL, 0, NULL, NULL);
	if (0 == ret)
		printf("wide char to multibyte failed:%d", GetLastError());
	else {
		
		c = new CHAR[ret];
		ret2=WideCharToMultiByte(CP_UTF8, 0, wch, -1, c, ret, NULL, NULL);
		if(ret2==0)
		printf("converting Failed:%d", GetLastError());
		else
		printf("After converting to MultiByte: %s", c);
	}
	delete c;
	delete wa;
	system("pause");
}