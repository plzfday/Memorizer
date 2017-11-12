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
	char name[20]/*그룹이름*/;
	char card[101]/*카드번호*/[1001]/*글자수*/;
};

struct group front[101]/*그룹번호*/;
struct group back[101];/*그룹번호*/;

int main(void)
{
	char c;

	printf("press  m / o / a \n");
	printf("m = 그룹생성 o =  그룹열기 a = 추가");
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
	int i = 0; // 11월12일 11:46 AM 바꿈 int i; 에서 int i = 0으로.
	system("cls");
	printf("그룹을 생성하겠습니까? (Y/N)\n");
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
	printf("생성할 그룹 번호 : ");
	scanf_s("%d", &num);
	printf("생성할 그룹 이름 : ");
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
	printf("그룹번호		그룹이름\n");
	showgroup();
	printf("\n\n");
	printf("선택할 그룹의 번호");
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
		printf("선택하신 그룹은 존재하지 않습니다.\n");
		printf("메인화면으로 돌아갑니다.");
		Sleep(2400);
		main();
	}
	printf("%d번 그룹 | %s", num, front[num].name);
	printf("카드번호	 front	back");
	for (i = 1; front[num].card[i][0] != NULL; i++)
	{
		printf("%2d번: %s %s", i, front[num].card[i], back[num].card[i]);
	}
	printf("\n\n");
	printf("------------------------------------------------------");
	printf("main창으로 돌아가기 (m)");
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
	printf("카드를 추가할 그룹번호 : ");
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
		printf("카드를 더 추가 하겠습니까?(Y/N)");
		YN = getchar();
	}
	main();
}

void showgroup(void)
{
	int i;
	printf("그룹번호		그룹이름\n");
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
