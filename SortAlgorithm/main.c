#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"data.h" // ��������

// ʱ�����
clock_t start_t, end_t;
double total_t;

// ֱ�Ӳ�������(��������)
void InsertSort(ElemType data[], int n)
{
	int i, j;
	for (i = 2; i < n; i++)
	{
		// data[0]���ڱ�
		data[0] = data[i];
		for (j = i - 1; data[0] < data[j]; j--)
		{
			data[j + 1] = data[j];
		}
		data[j + 1] = data[0];
	}
}

// �۰��������(��������)
void BInsertSort(ElemType data[], int n)
{
	int i, j;
	int low, mid, high;
	for (i = 2; i < n; i++)
	{
		// data[0]���ڱ�
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

// ϣ������(��������)
void ShellSort(ElemType data[], int n)
{
	for (int dk = n/2; dk >= 1; dk /= 2)
		for (int i = dk + 1; i <= n; i++)
			if (data[i] < data[i - dk])
			{
				// data[0]���ڱ�
				data[0] = data[i];

				int j;
				for (j = i - dk; j > 0 && data[0] < data[j]; j -= dk)
					data[j + dk] = data[j];
				data[j + dk] = data[0];
			}
}

// ð������(��������)
void BubbleSort(ElemType data[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		bool flag = false;
		for (int j = n - 1; j > i; j--)
		{
			if (data[j - 1] > data[j])
			{
				ElemType t = data[j];
				data[j] = data[j - 1];
				data[j - 1] = t;
				flag = true;
			}
		}
	}
}

// ������������㷨
int QuickSort_Partition(ElemType data[], int low, int high)
{
	// ѡ������
	ElemType pivot = data[low];
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

// ��������(��������)
void QuickSort(int data[], int low, int high)
{
	if (low < high)
	{
		int pivotpos = QuickSort_Partition(data, low, high);
		QuickSort(data, low, pivotpos - 1);
		QuickSort(data, pivotpos + 1, high);
	}
}

// ֱ��ѡ������ʱ�临�Ӷȣ�O(n^2),��ʱ�临�Ӷ����ʼ�����޹�(��һ��)
void SelectSort(ElemType data[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (data[j] < data[min])
				min = j;
		if (min != i)
		{
			ElemType t = data[i];
			data[i] = data[min];
			data[min] = t;
		}
	}
}

// ��������µ���
void MaxHeap_AdjustDown(ElemType data[], int k, int len)
{
	// lenΪ���ݳ���
	// data[0]���ڱ�
	data[0] = data[k];
	for (int i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && data[i] < data[i + 1])
			i++;
		if (data[0] >= data[i])
			break;
		else
		{
			data[k] = data[i];
			k = i;
		}
	}
	data[k] = data[0];
}
// ��������ϵ���
void MaxHeap_AdjustUp(ElemType data[], int len)
{
	data[0] = data[len];
	int k = len;
	int i = k / 2;
	while (i > 0 && data[i] < data[0])
	{
		data[k] = data[i];
		k = i;
		i = k / 2;
	}
	data[k] = data[0];
}

// С�������µ���
void MinHeap_AdjustDown(ElemType data[], int k, int len)
{
	// lenΪ���ݳ���
	// data[0]���ڱ�
	data[0] = data[k];
	for (int i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && data[i] > data[i + 1])
			i++;
		if (data[0] <= data[i])
			break;
		else
		{
			data[k] = data[i];
			k = i;
		}
	}
	data[k] = data[0];
}
// С�������ϵ���
void MinHeap_AdjustUp(ElemType data[], int len)
{
	data[0] = data[len];
	int k = len;
	int i = k / 2;
	while (i > 0 && data[i] > data[0])
	{
		data[k] = data[i];
		k = i;
		i = k / 2;
	}
	data[k] = data[0];
}

// ����ѳ�ʼ��
void BuildMaxHeap(ElemType data[], int len)
{
	for (int i = len / 2; i > 0; i--)
		MaxHeap_AdjustDown(data, i, len);
}

// С���ѳ�ʼ��
void BuildMinHeap(ElemType data[], int len)
{
	for (int i = len / 2; i > 0; i--)
		MinHeap_AdjustDown(data, i, len);
}

// ���������(ѡ������)
void MaxHeapSort(ElemType data[], int len)
{
	BuildMaxHeap(data, len);
	for (int i = len; i > 0; i--)
	{
		data[0] = data[i];
		data[i] = data[1];
		data[1] = data[0];
		MaxHeap_AdjustDown(data, 1, i - 1);
	}
}

// С��������(ѡ������)
void MinHeapSort(ElemType data[], int len)
{
	BuildMinHeap(data, len);
	for (int i = len; i > 0; i--)
	{
		data[0] = data[i];
		data[i] = data[1];
		data[1] = data[0];
		MinHeap_AdjustDown(data, 1, i - 1);
	}
}

// �鲢�����У��ϲ������������Ա�
void Merge(ElemType data[], ElemType assistant[], int low, int mid, int high)
{
	int i, j, k;
	for (k = low; k <= high; k++)
		assistant[k] = data[k];
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		if (assistant[i] < assistant[j])
			data[k] = assistant[i++];
		else
			data[k] = assistant[j++];
	}
	while (i <= mid)
		data[k++] = assistant[i++];
	while (j <= high)
		data[k++] = assistant[j++];
}

// ��·�鲢����
void MergeSort(ElemType data[], ElemType assistant[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(data, assistant, low, mid);
		MergeSort(data, assistant, mid + 1, high);
		Merge(data, assistant, low, mid, high);
	}
}

void main()
{
	ElemType* assistant; // ��������
	int label;
	printf("1.ֱ�Ӳ�������(��������)\n");
	printf("2.�۰��������(��������)\n");
	printf("3.ϣ������(��������)\n");
	printf("4.ð������(��������)\n"); 
	printf("5.��������(��������)\n");
	printf("6.�۰��ѡ������(ѡ������)\n");
	printf("7.������(ѡ������)\n");
	printf("8.�鲢����\n");

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

		// for (int i = 0; i < DATA_NUM; i++) printf("%d ", int_data[i]);

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
		SelectSort(int_data, DATA_NUM);
		end_t = clock();

		// for (int i = 0; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("ֱ��ѡ���������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 7:
		start_t = clock();
		MaxHeapSort(int_data, DATA_NUM - 1);
		end_t = clock();

		// for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("���������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	case 8:
		assistant = (ElemType*)malloc(DATA_NUM * sizeof(ElemType));
		start_t = clock();
		MergeSort(int_data, assistant, 1, DATA_NUM - 1);
		end_t = clock();

		for (int i = 1; i < DATA_NUM; i++) printf("%d ", int_data[i]);

		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("�鲢�������ʱ�䣺%fs\n", total_t);
		printf("ʱ��������Ϊ��%d\n", end_t - start_t);
		break;
	default:
		break;
	}

	system("pause");
}