#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void groupmaking(void);
void chgroup(void);
void opengroup(int);
void add(void);
void making(int, char);
void showgroup(void);
void showcard(int);


struct group
{
	char name[20]/*�׷��̸�*/;
	char card[101]/*ī���ȣ*/[1001]/*���ڼ�*/;
};

struct group front[101]/*�׷��ȣ*/;
struct group back[101];/*�׷��ȣ*/;

int main(void)
{
	char c;

	printf("press  m / o / a \n");
	printf("m = �׷���� o =  �׷쿭�� a = �߰�");
	c = getchar();
	switch (c)
	{
	case 'm':
	case 'M': groupmaking(); break;

	case 'o':
	case 'O': chgroup(); break;

	case 'a':
	case 'A': add(); break;
	}
}

void groupmaking(void)
{
	int num;
	char n[20];
	char YN;
	int i = 0; // 11��12�� 11:46 AM �ٲ� int i; ���� int i = 0����.
	system("cls");
	printf("�׷��� �����ϰڽ��ϱ�? (Y/N)\n");
	YN = getchar();
	system("cls");

	if (YN == 'y' || YN == 'Y')
	{
		showgroup();
	}

	if (YN == 'n' || YN == 'N')
	{
		main();
	}

	printf("\n\n");
	printf("������ �׷� ��ȣ : ");
	scanf_s("%d", &num);
	printf("������ �׷� �̸� : ");
	gets_s(n, sizeof(n));
	making(num, *n);
}

void making(int num, char name[])
{
	strcpy_s(front[num].name, sizeof(name), name);
	groupmaking();
}

void chgroup(void)
{
	int i;
	char a;
	printf("�׷��ȣ		�׷��̸�\n");
	showgroup();
	printf("\n\n");
	printf("������ �׷��� ��ȣ");
	scanf_s("%c", &a, sizeof(a));
	opengroup(a);
}

void opengroup(int num)
{
	system("cls");
	int i;
	char a;
	if (front[num].name == NULL)
	{
		printf("�����Ͻ� �׷��� �������� �ʽ��ϴ�.\n");
		printf("����ȭ������ ���ư��ϴ�.");
		Sleep(2400);
		main();
	}
	printf("%d�� �׷� | %s", num, front[num].name);
	printf("ī���ȣ	 front	back");
	for (i = 1; front[num].card[i][0] != NULL; i++)
	{
		printf("%2d��: %s %s", i, front[num].card[i], back[num].card[i]);
	}
	printf("\n\n");
	printf("------------------------------------------------------");
	printf("mainâ���� ���ư��� (m)");
	while (1)
	{
		a = getchar();
		if (a == 'm')
			main();
	}
}

void add(void)
{
	int num;
	int a;
	char YN = 'y';
	system("cls");
	showgroup();
	printf("\n\n");
	printf("ī�带 �߰��� �׷��ȣ : ");
	scanf_s("%d", &num);
	system("cls");
	showcard(num);
	printf("\n\n");

	for (a = 1; YN == 'y'; a++)
	{
		printf("front : ");
		gets_s(front[num].card[a], sizeof(front[num].card[a]));
		printf("back : ");
		gets_s(back[num].card[a], sizeof(back[num].card[a]));
		printf("-------------------------------\n");
		printf("ī�带 �� �߰� �ϰڽ��ϱ�?(Y/N)");
		YN = getchar();
	}
	main();
}

void showgroup(void)
{
	int i;
	printf("�׷��ȣ		�׷��̸�\n");
	for (i = 1; i <= 100; i++)
	{
		if (front[i].name == 0)
			printf("%d		%s\n", i, front[i].name);
	}
}

void showcard(int num)
{
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (front[i].name == 0)
			printf("%d. fornt :	%s   back : %s\n", i, front[num].card[i], back[num].card[i]);
	}

}
