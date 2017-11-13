#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>

#define CLEAN system("cls")

struct group
{
	int valid;
	int cnt; // ī�� ����
	char name[20]/*�׷��̸�*/;
	char front_card[101]/*ī���ȣ*/[1001]/*���ڼ�*/;
	char back_card[101]/*ī���ȣ*/[1001]/*���ڼ�*/;
};

/*
	ToDoList
	0. ���� ���� �ý����� ������.
	1. ���� �ý��� - ������ �ý����� ������ : ���� �Ұ���.
*/

struct group Group[101]/*�׷��ȣ*/;

void menu();
void groupmaking(void);

void opengroup(int num);
void showgroup(int open);
void add(void);

// ���� ����
int Total_group_NUM = 0;

int main()
{
	CLEAN;
	memset(&Group, 0, sizeof(struct group));
	menu();

	return 0;
}

void menu(void)
{
	CLEAN;
	char Menu_input;

	printf("press  m / o / a\n");
	printf("m = �׷���� o =  �׷쿭�� a = �߰� / ������ = ����\n\n");
	printf("�Է����ּ��� : ");
	Menu_input = getchar();
	getchar();
	int open_num;
	switch (Menu_input)
	{
	case 'm':
	case 'M':
		groupmaking();
		break;

	case 'o':
	case 'O':
		printf("�� ���� ���ðڽ��ϱ�?");
		scanf("%d", &open_num);
		opengroup(open_num);
		break;

	case 'a':
	case 'A':
		add();
		break;
	default:
		exit(1);
		break;
	}
}

void groupmaking(void)
{
	CLEAN;
	char YN;
	char Name[20];
	printf("�׷��� �����ϰڽ��ϱ�? (Y/N) \n������ : ����\n\n�Է� : ");
	YN = getchar();
	getchar();
	if (YN == 'y' || YN == 'Y')
	{
		printf("�׷� �̸��� �����ּ���.\n");
		gets(Group[Total_group_NUM].name);

		Group[Total_group_NUM].valid = 1;
		printf("�׷� ��ȣ�� %d�Դϴ�.\n", Total_group_NUM);
		Sleep(1000);
		Total_group_NUM++;
		menu();
	}
	else if (YN == 'n' || YN == 'N')
		menu();
	else
		exit(1);
}

void showgroup(int open)
{
	printf("\n");
	for (int i = 0; i < Group[open].cnt; i++) {
		printf("%d. �ո� : %s    �޸� : %s\n",
			i + 1, Group[open].front_card[i], Group[open].back_card[i]);
	}
	char chk = NULL;
	printf("�ǵ��� ���ðڽ��ϱ�? (Press any) ");
	scanf("%c", &chk);
	getchar();
	if (chk != NULL)
		menu();
}

void add(void)
{
	char YN; // yes or no
	int num;
	printf("ī�带 �߰��� �׷��ȣ : ");
	scanf("%d%*c", &num);
	if (num > 100 || num < 0) {
		printf("�׷� ��ȣ �ִ�� 100�Դϴ�.\n������ �����ϼ���.\n");
		Sleep(1000);
		menu();
	}
	if (!Group[num].valid) {
		printf("��... �ش� �׷��ȣ�� �������� �ʽ��ϴ�!\n");
		Sleep(1000);
		menu();
	}

	printf("\n\n");
	Group[num].cnt;
	while (Group[num].cnt <= 100)
	{
		printf("�ո� : ");
		gets(Group[num].front_card[Group[num].cnt]);

		printf("�޸� : ");
		gets(Group[num].back_card[Group[num].cnt]);

		fflush(stdin);
		printf("-------------------------------\n");
		printf("ī�带 �� �߰� �ϰڽ��ϱ�?(Y/N)");

		
		scanf("%c", &YN);
		getchar();

		printf("[debug]YN : %c\n", YN);

		Group[num].cnt++;
		if (YN == 'Y' || YN == 'y')
		{
			if (Group[num].cnt > 100) {
				printf("�� �׷� �� �ִ� 100���� ī�常 ���� �����մϴ�!\n");
				Sleep(1000);
				menu();
			}
		}
		else {
			menu();
		}
	}
}

void opengroup(int num)
{
	CLEAN;
	if (num > 100 || num < 0)
		menu();
	if (Group[num].cnt == 0) {
		printf("��... �ƹ��͵� ���׿�?\n");
		Sleep(1000);
		menu();
	}
	printf("�׷� : %s(%d)\n", Group[num].name, num);
	showgroup(num);
}