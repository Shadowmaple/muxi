#include <stdio.h>
#include <string.h>

int main()
{
	char st[100];
	scanf("%[^\n]", st);
	int count=0, minus=0;
	int n[100], m[100];
	for (int i=0, cycle=1, k=0; i<=strlen(st); i++) {
		if (st[i]=='-') {
			minus = 1;
			k++;
			continue;
		}
		if (st[i]==' ' || st[i]=='\0') {
			int num=0;
			for (int j=k; j<i; j++) {
				num = num*10 + (st[j]-'0');
			}
		
			if (cycle == 1) {
				n[count] = num;
				if (minus) {
					n[count] = -n[count];
					minus=0;
				}
				cycle = 2;
			} else {
				m[count] = num;
				if (minus) {
					m[count] = -m[count];
					minus = 0;
				}
				cycle = 1;
				n[count] *= m[count];
				m[count++]--;
			}
			k = i+1;

		}
	}
	int flag = 0;
	for (int i=0; i<count; i++) {
		if (n[i]) {
			if (flag) {
				printf(" %d %d", n[i], m[i]);
			} else {
				printf("%d %d", n[i], m[i]);
				flag = 1;
			}
		}
	}
	if (!flag)
		printf("0 0");

	putchar('\n');
	return 0;
}
