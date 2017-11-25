#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>	

#define CLEAN system("cls")

struct group
{
	int valid;	// ??? 
	int cnt;	// ī�� ����
	char name[20];	//�׷� �̸�
	char front_card[101][1001];	// ī�� ����, ���� ��
	char back_card[101][1001];	// ī�� ��ȣ, ���� ��
};

struct again
{
	int valid;
	int cnt;
	char name[20];
	char front_card[101][1001];
	char back_card[101][1001];
};

struct copy
{
	int valid;
	int cnt;
	char name[20];
	char front_card[101][1001];
	char back_card[101][1001];
};

struct group Group[101];	// �׷� �̸�
struct again Again[101];	// �ٽ� �ݺ��� �׷츸 ���� ���� (�Ź� �ʱ�ȭ ����� ��)
struct copy Copy[101];

void menu();
void groupmaking(void);

void opengroup(int num);
void showgroup(int open);
void add(void);
void description(void);

// ���� ����
int Total_group_NUM = 0;

int main()
{
	CLEAN;
	system("mode con lines=25 cols=65");
	SetConsoleTitle(TEXT("������ ���� �θ���~!"));
	memset(&Group, 0, sizeof(struct group));
	memset(&Again, 0, sizeof(struct again));
	memset(&Copy, 0, sizeof(struct copy));
	menu();


	return 0;
}


// �޴�----------------------- ���� ����
void menu(void)
{
	CLEAN;
	char Menu_input;

	printf("press  m / o / a\n\n");
	printf("m = �׷���� \n\no =  �׷쿭��(�����ϱ�) \n\na = ī���߰� \n\nh = ����\n\n������ = ����\n\n");
	printf("�Է����ּ��� : ");
	Menu_input = getchar();
	while (getchar() != '\n');
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
		opengroup(open_num);	// �׷� ��ȣ �˻� �Լ� ����
		break;

	case 'a':
	case 'A':
		add();
		break;
	case 'h':
	case 'H':
		description();
		break;
	default:
		exit(1);
		break;
	}
}
// �޴� �� 



// �׷� �����--------------------------------
void groupmaking(void)
{
	CLEAN;
	char YN;
	char Name[20];
	printf("�׷��� �����ϰڽ��ϱ�? (Y/N) \n������ : �ڷ�\n\n�Է� : ");
	YN = getchar();
	while (getchar() != '\n');
	if (YN == 'y' || YN == 'Y')
	{
		printf("�׷� �̸��� �����ּ���.\n");
		gets(Group[Total_group_NUM].name);

		Group[Total_group_NUM].valid = 1;
		printf("�׷� ��ȣ�� %d�Դϴ�.\n", Total_group_NUM);
		while (getchar() != '\n');
		Total_group_NUM++;
		menu();
	}
	else {
		menu();
	}
}
// �׷� ����� ��




// �׷� �����ֱ�----------------------------- ���� ����
void showgroup(int open)
{
	int NM;
	int j = 0;
	int i, h;

	getchar();
	printf("\n");
	for (i = 0; i < Group[open].cnt; i++) {
		printf("%d. �ո� : %s\n", i + 1, Group[open].front_card[i]);
		getchar();
		while (getchar() != '\n');
		printf("%d. �޸� : %s\n", i + 1, Group[open].back_card[i]);
		printf("��ﳲ = n / ���ȳ� = m\n�Է� : ");
		NM = getchar();
		CLEAN;
		if (NM == 'n' || NM == 'N') {

		}
		else if (NM == 'm' || NM == 'M') {
			strcpy(Again[open].front_card[j], Group[open].front_card[i]);	// ����� ���� �ʴ� ī�常 Again �� ����
			strcpy(Again[open].back_card[j], Group[open].back_card[i]);
			Again[open].cnt++;
			j++;
		}
	}
	i = 0;
	j = 0;
	h = 0;
	while (Again[open].cnt > 0) {

		for (i = 0; i < Again[open].cnt; i++) {
			printf("%d. �ո� : %s\n", i + 1, Again[open].front_card[i]);
			getchar();
			while (getchar() != '\n');
			printf("%d. �޸� : %s\n", i + 1, Again[open].back_card[i]);
			printf("��ﳲ = n / ���ȳ� = m\n�Է� : ");
			NM = getchar();
			CLEAN;
			if (NM == 'n' || NM == 'N') {
				Again[open].cnt--;
			}
			else if (NM == 'm' || NM == 'M') {
				strcpy(Copy[open].front_card[j], Again[open].front_card[i]);	// ����� ���� �ʴ� ī�常 copy �� ����
				strcpy(Copy[open].back_card[j], Again[open].back_card[i]);
				Copy[open].cnt++;
				j++;
			}
		}

		for (i = 0; i < Copy[open].cnt; i++) {
			printf("%d. �ո� : %s\n", i + 1, Copy[open].front_card[i]);
			getchar();
			while (getchar() != '\n');
			printf("%d. �޸� : %s\n", i + 1, Copy[open].back_card[i]);
			printf("��ﳲ = n / ���ȳ� = m\n�Է� : ");
			NM = getchar();
			CLEAN;
			if (NM == 'n' || NM == 'N') {
				Copy[open].cnt--;
			}
			else if (NM == 'm' || NM == 'M') {
				strcpy(Again[open].front_card[j], Copy[open].front_card[i]);	// ����� ���� �ʴ� ī�常 copy �� ����
				strcpy(Again[open].back_card[j], Copy[open].back_card[i]);
				Again[open].cnt++;
				j++;
			}
		}
	}


	char chk = NULL;
	printf("�ǵ��� ���ðڽ��ϱ�? (Press any) ");
	scanf("%c", &chk);
	while (getchar() != '\n');
	if (chk != NULL)
		menu();
}
// �׷� �����ֱ� ��




// ī�� �߰�----------------------------- ī�� ���� ����
void add(void)
{
	char YN; // yes or no
	int num;
	printf("ī�带 �߰��� �׷��ȣ : ");
	scanf("%d%*c", &num);
	if (num > 100 || num < 0) {
		printf("�׷� ��ȣ 0���� 100���� �Դϴ�.\n������ �����ϼ���.\n");
		while (getchar() != '\n');
		menu();
	}
	if (!Group[num].valid) {
		printf("�ش� �׷��ȣ�� �������� �ʽ��ϴ�!\n");
		while (getchar() != '\n');
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
		while (getchar() != '\n');

		/*printf("[debug]YN : %c\n", YN);*/

		Group[num].cnt++;
		if (YN == 'Y' || YN == 'y')
		{
			if (Group[num].cnt > 100) {
				printf("�� �׷� �� �ִ� 100���� ī�常 ���� �����մϴ�!\n");
				while (getchar() != '\n');
				menu();
			}
		}
		else {
			menu();
		}
	}
}
// ī�� �߰� ��



// ���±׷�-------------------	�׷� ��ȣ �˻��� (��ȣ�� �̻��ϰų� �������� ������ ���� �߻�������)
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
// ���±׷� ��


// �޴���
void description(void)
{
	CLEAN;
	fputs("�ȳ��ϼ���! ������ ���� �θ����Դϴ�.\n", stdout);
	Sleep(1000);
	fputs("�����ϰ� �����ص帮�ڽ��ϴ�.\n\n", stdout);
	Sleep(1000);
	fputs("m(�׷����):�׷��� �����մϴ�.\na(ī���߰�):�׷쿡 ī�带 �߰��մϴ�.\no(�׷쿭��):������ �׷��� �� �� ������ ���θ� �����ϰ� �˴ϴ�.\nh(����):�����Դϴ�.\n\n", stdout);
	char ch = NULL;
	printf("Continue (Press any) ");
	scanf("%c", &ch);
	while (getchar() != '\n');
	fputs("1. �켱 �׷��� �����ϼ���. �׷� ��ȣ�� �־����ϴ�.\n2. a�� ���� �ش� �׷쿡 ī�带 �߰��մϴ�.(�ִ� 100��)\n3. ���θ� �Ͻ÷��� o(�׷쿭��)�� ���� ���θ� �����Ͻø� �˴ϴ�!\n\n�����մϴ�.\nCopyright(c)2017 ������ ���� �θ��� All rights reserved.\n", stdout);

	char chk = NULL;
	printf("\n\n�ǵ��� ���ðڽ��ϱ�? (Press any) ");
	scanf("%c", &chk);
	while (getchar() != '\n');
	if (chk != NULL)
		menu();
}
// �޴��� ��