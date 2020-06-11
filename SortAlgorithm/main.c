#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"data.h" // 引入数据

// 时间变量
clock_t start_t, end_t;
double total_t;

// 直接插入排序
void InsertSort(int data[], int n)
{
	int i, j;
	for (i = 2; i < n; i++)
	{
		data[0] = data[i];
		for (j = i - 1; data[0] < data[j]; j--)
		{
			data[j + 1] = data[j];
		}
		data[j + 1] = data[0];
	}
}

// 折半插入排序
void BInsertSort(int data[], int n)
{
	int i, j;
	int low, mid, high;
	for (i = 2; i < n; i++)
	{
		data[0] = data[i];

		low = 1; high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (data[mid] > data[0])
				high = mid - 1;
			else
				low = mid + 1;
		}

		for (j = i - 1; j >= high + 1; j--)
		{
			data[j + 1] = data[j];
		}
		data[high + 1] = data[0];
	}
}

// 希尔排序
void ShellSort(int data[], int n)
{
	for (int dk = n/2; dk >= 1; dk /= 2)
		for (int i = dk + 1; i <= n; i++)
			if (data[i] < data[i - dk])
			{
				data[0] = data[i];

				int j;
				for (j = i - dk; j > 0 && data[0] < data[j]; j -= dk)
					data[j + dk] = data[j];
				data[j + dk] = data[0];
			}
}

void main()
{
	int label;
	printf("1.直接插入排序\n");
	printf("2.折半插入排序\n");
	printf("3.希尔排序\n\n");

	printf("请输入排序算法的编号：");
	scanf_s("%d", &label, 2);
	switch (label)
	{
	case 1:
		start_t = clock();
		InsertSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("直接插入排序的总时间：%fs\n", total_t);
		break;
	case 2:
		start_t = clock();
		BInsertSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);
			
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("直接插入排序的总时间：%fs\n", total_t);
		break;
	case 3:
		start_t = clock();
		ShellSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("直接插入排序的总时间：%fs\n", total_t);
		break;
	default:
		break;
	}

	system("pause");
}