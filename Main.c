#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define CLEAN system("cls")

struct group
{
	int valid;
	int cnt; // 카드 개수
	char name[20]/*그룹이름*/;
	char front_card[101]/*카드번호*/[1001]/*글자수*/;
	char back_card[101]/*카드번호*/[1001]/*글자수*/;
};

struct group Group[101]/*그룹번호*/;

void menu();
void groupmaking(void);
void opengroup(int num);
void showgroup(int open);
void add(void);

// 전역 변수
int Total_group_NUM = 1;

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

	printf("press  m / o / a \n");
	printf("m = 그룹생성 o =  그룹열기 a = 추가\n\n");
	printf("입력해주세요 : ");
	scanf("%1c", &Menu_input);
	int open_num;
	switch (Menu_input)
	{
	case 'm':
	case 'M': 
		groupmaking();
		break;

	case 'o':
	case 'O': 
		printf("몇 번을 여시겠습니까?");
		scanf("%d", &open_num);
		opengroup(open_num);
		break;

	case 'a':
	case 'A': 
		add();
		break;
	default:
		menu();
		break;
	}
}

void groupmaking(void)
{
	CLEAN;
	char YN;
	char Name[20];
	printf("그룹을 생성하겠습니까? (Y/N) : ");
	
	getchar();
	scanf("%1c", &YN);

	if (YN == 'y' || YN == 'Y')
	{
		printf("생성할 그룹 이름 : ");
		scanf("%s", Name);

		strcpy(Group[Total_group_NUM].name, Name);
		Group[Total_group_NUM].valid = 1;
		printf("그룹 번호는 %d입니다.\n", Total_group_NUM);
		Sleep(1000);
		Total_group_NUM++;
		menu();
	}
	else if (YN == 'n' || YN == 'N')
		menu();
}

void showgroup(int open)
{
	printf("\n");
	for (int i = 1; i <= Group[open].cnt; i++) {
		printf("%d. 앞면 : %s    뒷면 : %s\n",
			i, Group[open].front_card[i], Group[open].back_card[i]);
	}
	char chk;
	printf("되돌아 가시겠습니까? (Y) ");
	getchar();
	chk = getchar();
	if (chk == 'y' || chk == 'Y')
		menu();
	else
		menu(); // y가 아니여도 그냥 돌아가라!!!
}

void add(void)
{
	char YN; // yes or no
	int num;
	printf("카드를 추가할 그룹번호 : ");
	scanf("%d", &num);
	if (num > 100) {
		printf("그룹 번호 최대는 100입니다.\n도움말을 참고하세요.\n");
		Sleep(1000);
		menu();
	}
	if (!Group[num].valid) {
		printf("어... 해당 그룹번호는 존재하지 않습니다!\n");
		Sleep(1000);
		menu();
	}

	printf("\n\n");

	while (Group[num].cnt <= 100)
	{
		Group[num].cnt++;
		printf("앞면 : ");
		gets(Group[num].front_card[Group[num].cnt]);
		printf("뒷면 : ");
		gets(Group[num].back_card[Group[num].cnt]);
		getchar();
		printf("-------------------------------\n");
	error:
		printf("카드를 더 추가 하겠습니까?(Y/N)");
		scanf("%c", &YN);

		if (YN == 'N' || YN == 'n')
			break;
		else if (YN == 'Y' || YN == 'y')
			continue;
		else
			goto error;
	}
	if (Group[num].cnt > 100) {
		printf("한 그룹 당 최대 100개의 카드만 저장 가능합니다!\n");
		Sleep(1000);
	}
	menu();
}

void opengroup(int num)
{
	CLEAN;
	if (num > 100)
		menu();
	if (Group[num].cnt == 0) {
		printf("흠... 아무것도 없네요?\n");
		Sleep(1000);
		menu();
	}
	printf("그룹 %s(%d)\n", Group[num].name, num);
	showgroup(num);
}