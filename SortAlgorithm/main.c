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

// 冒泡排序
void BubbleSort(int data[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		bool flag = false;
		for (int j = n - 1; j > i; j--)
		{
			if (data[j - 1] > data[j])
			{
				int t = data[j];
				data[j] = data[j - 1];
				data[j - 1] = t;
				flag = true;
			}
		}
	}
}

// 快速排序分组算法
int QuickSort_Partition(int data[], int low, int high)
{
	// 选择枢轴
	int pivot = data[low];
	while (low < high)
	{
		while (low < high && data[high] >= pivot)
			high --;
		data[low] = data[high];
		while (low < high && data[low] <= pivot)
			low ++;
		data[high] = data[low];
	}
	data[low] = pivot;
	return low;
}

// 快速排序
void QuickSort(int data[], int low, int high)
{
	if (low < high)
	{
		int pivotpos = QuickSort_Partition(data, low, high);
		QuickSort(data, low, pivotpos - 1);
		QuickSort(data, pivotpos + 1, high);
	}
}

void main()
{
	int label;
	printf("1.直接插入排序(插入排序)\n");
	printf("2.折半插入排序(插入排序)\n");
	printf("3.希尔排序(插入排序)\n");
	printf("4.冒泡排序(交换排序)\n"); 
	printf("5.快速排序(交换排序)\n");
	printf("6.折半简单选择排序(选择排序)\n");
	printf("7.堆排序(选择排序)\n");
	printf("8.归并排序\n");
	printf("9.基数排序\n\n");

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
		printf("时钟周期数为：%d\n", end_t - start_t);
		break;
	case 2:
		start_t = clock();
		BInsertSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);
			
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("折半插入排序的总时间：%fs\n", total_t);
		printf("时钟周期数为：%d\n", end_t - start_t);
		break;
	case 3:
		start_t = clock();
		ShellSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("希尔排序的总时间：%fs\n", total_t);
		printf("时钟周期数为：%d\n", end_t - start_t);
		break;
	case 4:
		start_t = clock();
		BubbleSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("冒泡排序的总时间：%fs\n", total_t);
		printf("时钟周期数为：%d\n", end_t - start_t);
		break;
	case 5:
		start_t = clock();
		QuickSort(int_data, 1, DATA_NUM - 1);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("快速排序的总时间：%fs\n", total_t);
		printf("时钟周期数为：%d\n", end_t - start_t);
		break;
	case 6:
		start_t = clock();
		BInsertSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("简单选择排序的总时间：%fs\n", total_t);
		printf("时钟周期数为：%d\n", end_t - start_t);
		break;
	case 7:
		start_t = clock();
		ShellSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("堆排序的总时间：%fs\n", total_t);
		printf("时钟周期数为：%d\n", end_t - start_t);
		break;
	case 8:
		start_t = clock();
		BubbleSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("归并排序的总时间：%fs\n", total_t);
		printf("时钟周期数为：%d\n", end_t - start_t);
		break;
	case 9:
		start_t = clock();
		BubbleSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("基数排序的总时间：%fs\n", total_t);
		printf("时钟周期数为：%d\n", end_t - start_t);
		break;
	default:
		break;
	}

	system("pause");
}