#include <stdio.h>

int main()
{
	int Q, N;
	while (1) {
		scanf("%d%d", &Q, &N);

		if (N == 0) break;
		double price[N][50], sum[N];
		int n[N];
		//发票的物品数
		char type[N][50];

		//输入数据并计算总额
		for (int i=0; i < N; i++)  {
			sum[i] = 0;
			scanf("%d", &n[i]);
			for (int j=0; j < n[i]; j++) {
				getchar();
				scanf("%c:%lf", &type[i][j], &price[i][j]);
				sum[i] += price[i][j];
			}
			printf("-%f-\n", sum[i]);
		}

		int mean[N];//是否可以报销

		for (int i =0; i < N; i++) {
			int count =0;
			mean[i] = 1;
			//总价值vs限额
			if (sum[i] > Q) {
				mean[i] = 0;
				continue;
			}

			//单项物品是否超过600
			int sum_A=0,sum_B=0,sum_C=0;
			for (int j=0; j < n[i]; j++) {
				switch(type[i][j] == 'A') {
					case 'A': sum_A += price[i][j];break;
					case 'B': sum_B += price[i][j];break;
					case 'C': sum_C += price[i][j];break;
				}
			}
			if (sum_A>600 || sum_B>600 || sum_C>600) {
				mean[i] =0;
				continue;
			}

			//不符合要求的物品类型
			while (count < n[i]) {
				if (type[i][count]!='A' && type[i][count]!='B' && type[i][count]!='C')
				{
					mean[i] = 0;
					break;
				}
				count++;
			}
		}

		double max = 0, sum_ = 0;
		double sort[N];
		for (int j=0; j < N; j++) {
			if (!mean[j]) continue;
			sort[] = 
			sum_ += sum[j];
//			max = (max > sum[j]) ? max:sum[j];
		}
		
		for (int i=0; i < N; i++){
			for (int j=i; j < N; j++) {
				
			
			}	
		
		}

		while (sum_ > Q) {
		
		
		}
		printf("%.2f\n", max);
	}
}
