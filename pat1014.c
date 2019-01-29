#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[4][61];
	for (int i=0; i<4; i++) {
		scanf("%s", str[i]);
	}
	char day[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char a[2];
	int count=0;
	for (int i=0; i<strlen(str[0]); i++) {
		char c = str[0][i];
		if (count==2) break;
		if (!count) {
			if (isupper(c) && strchr(str[1], c) != NULL) {
				a[count++] = c;
			}
		} else {
			if ((isupper(c) || isdigit(c)) && strchr(str[1], c) != NULL) {
				a[count++] = c;
			}
		}
	}

	int index;
	for (int i=0; i<strlen(str[2]); i++) {
		char c = str[0][i];
		char *x = strchr(str[3], c);
		if (isalpha(c) && x!= NULL) {
			index = (index > i) ? index : i;
		}
	}
	
	int week = a[0]-'A'+1;
	int hour;
	if (isdigit(a[1]))
		hour = a[1]-'0'+1;
	else
		hour = a[1]-'A'+10;

	printf("%s %02d:%02d\n", day[week-1], hour, index);

	return 0;
}
