#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"data.h" // ��������

// ʱ�����
clock_t start_t, end_t;
double total_t;

// ֱ�Ӳ�������
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

// �۰��������
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

// ϣ������
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

// ð������
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

// ������������㷨
int QuickSort_Partition(int data[], int low, int high)
{
	// ѡ������
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

// ��������
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
	printf("1.ֱ�Ӳ�������(��������)\n");
	printf("2.�۰��������(��������)\n");
	printf("3.ϣ������(��������)\n");
	printf("4.ð������(��������)\n"); 
	printf("5.��������(��������)\n");
	printf("6.�۰��ѡ������(ѡ������)\n");
	printf("7.������(ѡ������)\n");
	printf("8.�鲢����\n");
	printf("9.��������\n\n");

	printf("�����������㷨�ı�ţ�");
	scanf_s("%d", &label, 2);
	switch (label)
	{
	case 1:
		start_t = clock();
		InsertSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("ֱ�Ӳ����������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 2:
		start_t = clock();
		BInsertSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);
			
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("�۰�����������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 3:
		start_t = clock();
		ShellSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("ϣ���������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 4:
		start_t = clock();
		BubbleSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("ð���������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 5:
		start_t = clock();
		QuickSort(int_data, 1, DATA_NUM - 1);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("�����������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 6:
		start_t = clock();
		BInsertSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("��ѡ���������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 7:
		start_t = clock();
		ShellSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("���������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 8:
		start_t = clock();
		BubbleSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("�鲢�������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 9:
		start_t = clock();
		BubbleSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("�����������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	default:
		break;
	}

	system("pause");
}