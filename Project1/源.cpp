/*****************ѧ���ɼ�����ϵͳv1.1.10*****************
******************ע�⣺ϵͳ��������Ϊ100*****************
****�������ݸ�ʽΪ��ѧ����� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ�\n��****/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����ѧ���ṹ��
 typedef struct studenttype
{
	int num = 0;//ѧ�����
	int ch = 0;//���ĳɼ�
	int ma = 0;	//��ѧ�ɼ�
	int eng = 0;//Ӣ��ɼ�
	int sum = 0;//�ܳɼ�
	float ave = (float)sum / 3;	//��������ƽ����
}student;

//����Ҫʹ�õĺ�������
void fun1(student stu[100], int stunum, int failnum);
void fun2(student stu[100], int stunum, int aboveave, float classave);
void fun3(student stu[100], int n);
void fun4(student stu[100], int n);
void fun5(student stu[100], int n, FILE *fp);
void fun6(student stu[100], int n);

//������
int main()
{
	//�򿪴���ɼ���Ϣ���ļ�
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp,"/*TestDataĿ¼*/","a+");
	if (fp == NULL)
	{
		printf("No data");
		return -1;
	}

	//����ѧ���ɼ�
	int i = 0;
	student stu[100];
	while(!feof(fp))
	{
		fscanf_s(fp, "%d%d%d%d", &stu[i].num, &stu[i].ch, &stu[i].ma, &stu[i].eng);
		stu[i].sum = (stu[i].ch + stu[i].ma + stu[i].eng);//��������ܷ�
		stu[i].ave = (float)stu[i].sum / 3;//�������ƽ����
		i++;
	}
	int stunum = i;

	//����༶ƽ���֡�����Ͳ����񡢳ɼ���ƽ����֮�ϵ�����
	float classave=0;
	int pass = 0, failnum = 0, aboveave = 0;
	for (int i = 0; i < stunum; i++)
	{
		classave += stu[i].ave;
	}
	classave = classave / stunum;
	for (int i = 0; i < stunum; i++)
	{
		if (stu[i].sum < 180)
		{
			failnum++;
		}
		if (stu[i].ave > classave)
		{
			aboveave++;
		}
	}

reStart://�ٴ�ʹ��ϵͳ�����

	//��ӡ�����б�ѡ��Ҫʹ�õĹ���
	printf("\t  ***�����б�***\n");
	printf("\t1 ��ӡ�ܳɼ��������ѧ��ѧ�Ų�ͳ������\n");
	printf("\t2 ͳ�Ƴɼ���ȫ��ƽ����֮�ϵ�ѧ��������ӡ����\n");
	printf("\t3 ͳ�Ƹ������ε�ѧ�������Ͱٷֱ� \n"); 
	printf("\t4 ���ֳܷɼ��Ӹߵ�������\n");
	printf("\t5 ��ӡ�����α�\n");
	printf("\t6 ����ѧ���ɼ�������\n");
	printf("\t  ������Ҫʹ�õĹ�����ţ�");
	int f;
	scanf_s("%d", &f);

	//ѡ��Ҫʹ�õĺ���
	switch (f)
	{
	case 1:fun1(stu, stunum, failnum);
		break;
	case 2:fun2(stu, stunum, aboveave, classave);
		break;
	case 3:fun3(stu, stunum);
		break;
	case 4:fun4(stu, stunum);
		break;
	case 5:fun5(stu, stunum, fp);
		break;
	case 6:fun6(stu, stunum);
		break;
	default:printf("����");
	}

reScan://�ٴ�ѯ���Ƿ������������

	//ѯ���Ƿ����ʹ��
	printf("�Ƿ�Ҫ��������\n�����밴0������ʹ���밴1\n");
	int x;
	scanf_s("%d", &x);
	if (x == 0) { goto end; }
	else if (x == 1) { goto reStart; }
	else { printf("����"); goto reScan; }

end://��������ĳ���

	fclose(fp);
	return 0;
}

//����1����ӡ�ܳɼ��������ѧ��ѧ�Ų�ͳ����������
void fun1(student stu[100], int stunum, int failnum)
{
	printf("ѧ��Ϊ��");
	for (int i = 0; i < stunum; i++)
	{
		if (stu[i].sum < 180)
		{
			printf("%d�� ", stu[i].num);
		}
	}
	printf("\n������Ϊ��%d\n", failnum);
}

//����2��ͳ�Ƴɼ���ȫ��ƽ����֮�ϵ�ѧ��������ӡ����
void fun2(student stu[100], int stunum, int aboveave , float classave)
{
	printf("�ɼ���ƽ����֮�ϵ��У�");
	for (int i = 0; i < stunum; i++)
	{
		if (stu[i].ave > classave)
		{
			printf("%d�� ", stu[i].num);
		}
	}
	printf("\n������Ϊ��%d\n", aboveave);
}

//����3��ͳ�Ƹ������������ͰٷֱȲ����
void fun3(student stu[100], int n)
{
	int num50 = 0, num60 = 0, num70 = 0, num80 = 0, num90 = 0;
	float per50, per60, per70, per80, per90;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].sum < 180) { num50++; }
		else if (stu[i].sum < 210) { num60++; }
		else if (stu[i].sum < 240) { num70++; }
		else if (stu[i].sum < 270) { num80++; }
		else { num90++; }
	}
	per50 = (float)num50 / n;
	per60 = (float)num60 / n;
	per70 = (float)num70 / n;
	per80 = (float)num80 / n;
	per90 = (float)num90 / n;
	printf("60���£�%d �ٷֱȣ�%f\n", num50, per50);
	printf("60~70��%d �ٷֱȣ�%f\n", num60, per60);
	printf("70~80��%d �ٷֱȣ�%f\n", num70, per70);
	printf("80~90��%d �ٷֱȣ�%f\n", num80, per80);
	printf("90���ϣ�%d �ٷֱȣ�%f\n", num90, per90);
}

//����4�����ֳܷɼ��Ӹߵ�������
void fun4(student stu[100], int n)
{
	student tool;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stu[j].sum < stu[i].sum)
			{
				tool = stu[j];
				stu[j] = stu[i];
				stu[i] = tool;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		printf("��%d����ѧ�ţ�%d,���ģ�%d����ѧ��%d��Ӣ�%d���ܷ֣�%d\n", n - i,stu[i].num, stu[i].ch, stu[i].ma, stu[i].eng, stu[i].sum);
	}
}

//����5����ӡ���α�
void fun5(student stu[100], int n, FILE *fp)
{
	student tool;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stu[j].sum < stu[i].sum)
			{
				tool = stu[j];
				stu[j] = stu[i];
				stu[i] = tool;
			}
		}
	}
	fprintf(fp, "\n����  ѧ��  ����  ��ѧ  Ӣ��  �ܷ�\n");
	for (int i = n - 1; i >= 0; i--)
	{
		fprintf(fp, " %d    %d    %d    %d    %d    %d\n", n - i, stu[i].num, stu[i].ch, stu[i].ma, stu[i].eng, stu[i].sum);
	}
}

//����6������ѧ���ɼ�������
void fun6(student stu[100],int n)
{
	student tool;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stu[j].sum < stu[i].sum)
			{
				tool = stu[j];
				stu[j] = stu[i];
				stu[i] = tool;
			}
		}
	}
	int num, i = 0;
	printf("���������ѧ�ţ�");
	scanf_s("%d", &num);
	while (stu[i].num != num&&i<n)
	{
		i++;
	}
	if(i<n)
	printf("����������%d,���ģ�%d,��ѧ��%d,Ӣ�%d,�ܷ֣�%d", n - i, stu[i].ch, stu[i].ma, stu[i].eng, stu[i].sum);
}