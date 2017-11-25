#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>	

#define CLEAN system("cls")

struct group
{
	int valid;	// ??? 
	int cnt;	// 카드 개수
	char name[20];	//그룹 이름
	char front_card[101][1001];	// 카드 개수, 글자 수
	char back_card[101][1001];	// 카드 번호, 글자 수
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

struct group Group[101];	// 그룹 이름
struct again Again[101];	// 다시 반복할 그룹만 따로 만듦 (매번 초기화 해줘야 함)
struct copy Copy[101];

void menu();
void groupmaking(void);

void opengroup(int num);
void showgroup(int open);
void add(void);
void description(void);

// 전역 변수
int Total_group_NUM = 0;

int main()
{
	CLEAN;
	system("mode con lines=25 cols=65");
	SetConsoleTitle(TEXT("성훈이 버스 부르릉~!"));
	memset(&Group, 0, sizeof(struct group));
	memset(&Again, 0, sizeof(struct again));
	memset(&Copy, 0, sizeof(struct copy));
	menu();


	return 0;
}


// 메뉴----------------------- 게임 시작
void menu(void)
{
	CLEAN;
	char Menu_input;

	printf("press  m / o / a\n\n");
	printf("m = 그룹생성 \n\no =  그룹열기(공부하기) \n\na = 카드추가 \n\nh = 도움말\n\n나머지 = 종료\n\n");
	printf("입력해주세요 : ");
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
		printf("몇 번을 여시겠습니까?");
		scanf("%d", &open_num);
		opengroup(open_num);	// 그룹 번호 검사 함수 실행
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
// 메뉴 끝 



// 그룹 만들기--------------------------------
void groupmaking(void)
{
	CLEAN;
	char YN;
	char Name[20];
	printf("그룹을 생성하겠습니까? (Y/N) \n나머지 : 뒤로\n\n입력 : ");
	YN = getchar();
	while (getchar() != '\n');
	if (YN == 'y' || YN == 'Y')
	{
		printf("그룹 이름을 정해주세요.\n");
		gets(Group[Total_group_NUM].name);

		Group[Total_group_NUM].valid = 1;
		printf("그룹 번호는 %d입니다.\n", Total_group_NUM);
		while (getchar() != '\n');
		Total_group_NUM++;
		menu();
	}
	else {
		menu();
	}
}
// 그룹 만들기 끝




// 그룹 보여주기----------------------------- 공부 시작
void showgroup(int open)
{
	int NM;
	int j = 0;
	int i, h;

	getchar();
	printf("\n");
	for (i = 0; i < Group[open].cnt; i++) {
		printf("%d. 앞면 : %s\n", i + 1, Group[open].front_card[i]);
		getchar();
		while (getchar() != '\n');
		printf("%d. 뒷면 : %s\n", i + 1, Group[open].back_card[i]);
		printf("기억남 = n / 기억안남 = m\n입력 : ");
		NM = getchar();
		CLEAN;
		if (NM == 'n' || NM == 'N') {

		}
		else if (NM == 'm' || NM == 'M') {
			strcpy(Again[open].front_card[j], Group[open].front_card[i]);	// 기억이 나지 않는 카드만 Again 에 저장
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
			printf("%d. 앞면 : %s\n", i + 1, Again[open].front_card[i]);
			getchar();
			while (getchar() != '\n');
			printf("%d. 뒷면 : %s\n", i + 1, Again[open].back_card[i]);
			printf("기억남 = n / 기억안남 = m\n입력 : ");
			NM = getchar();
			CLEAN;
			if (NM == 'n' || NM == 'N') {
				Again[open].cnt--;
			}
			else if (NM == 'm' || NM == 'M') {
				strcpy(Copy[open].front_card[j], Again[open].front_card[i]);	// 기억이 나지 않는 카드만 copy 에 저장
				strcpy(Copy[open].back_card[j], Again[open].back_card[i]);
				Copy[open].cnt++;
				j++;
			}
		}

		for (i = 0; i < Copy[open].cnt; i++) {
			printf("%d. 앞면 : %s\n", i + 1, Copy[open].front_card[i]);
			getchar();
			while (getchar() != '\n');
			printf("%d. 뒷면 : %s\n", i + 1, Copy[open].back_card[i]);
			printf("기억남 = n / 기억안남 = m\n입력 : ");
			NM = getchar();
			CLEAN;
			if (NM == 'n' || NM == 'N') {
				Copy[open].cnt--;
			}
			else if (NM == 'm' || NM == 'M') {
				strcpy(Again[open].front_card[j], Copy[open].front_card[i]);	// 기억이 나지 않는 카드만 copy 에 저장
				strcpy(Again[open].back_card[j], Copy[open].back_card[i]);
				Again[open].cnt++;
				j++;
			}
		}
	}


	char chk = NULL;
	printf("되돌아 가시겠습니까? (Press any) ");
	scanf("%c", &chk);
	while (getchar() != '\n');
	if (chk != NULL)
		menu();
}
// 그룹 보여주기 끝




// 카드 추가----------------------------- 카드 생성 시작
void add(void)
{
	char YN; // yes or no
	int num;
	printf("카드를 추가할 그룹번호 : ");
	scanf("%d%*c", &num);
	if (num > 100 || num < 0) {
		printf("그룹 번호 0에서 100까지 입니다.\n도움말을 참고하세요.\n");
		while (getchar() != '\n');
		menu();
	}
	if (!Group[num].valid) {
		printf("해당 그룹번호는 존재하지 않습니다!\n");
		while (getchar() != '\n');
		menu();
	}

	printf("\n\n");
	Group[num].cnt;
	while (Group[num].cnt <= 100)
	{
		printf("앞면 : ");
		gets(Group[num].front_card[Group[num].cnt]);

		printf("뒷면 : ");
		gets(Group[num].back_card[Group[num].cnt]);

		fflush(stdin);
		printf("-------------------------------\n");
		printf("카드를 더 추가 하겠습니까?(Y/N)");


		scanf("%c", &YN);
		while (getchar() != '\n');

		/*printf("[debug]YN : %c\n", YN);*/

		Group[num].cnt++;
		if (YN == 'Y' || YN == 'y')
		{
			if (Group[num].cnt > 100) {
				printf("한 그룹 당 최대 100개의 카드만 저장 가능합니다!\n");
				while (getchar() != '\n');
				menu();
			}
		}
		else {
			menu();
		}
	}
}
// 카드 추가 끝



// 오픈그룹-------------------	그룹 번호 검사함 (번호가 이상하거나 존재하지 않으면 오류 발생시켜줌)
void opengroup(int num)
{
	CLEAN;
	if (num > 100 || num < 0)
		menu();
	if (Group[num].cnt == 0) {
		printf("흠... 아무것도 없네요?\n");
		Sleep(1000);
		menu();
	}
	printf("그룹 : %s(%d)\n", Group[num].name, num);
	showgroup(num);
}
// 오픈그룹 끝


// 메뉴얼
void description(void)
{
	CLEAN;
	fputs("안녕하세요! 성훈이 버스 부르릉입니다.\n", stdout);
	Sleep(1000);
	fputs("간단하게 설명해드리겠습니다.\n\n", stdout);
	Sleep(1000);
	fputs("m(그룹생성):그룹을 생성합니다.\na(카드추가):그룹에 카드를 추가합니다.\no(그룹열기):생성된 그룹을 열 수 있으며 공부를 시작하게 됩니다.\nh(도움말):도움말입니다.\n\n", stdout);
	char ch = NULL;
	printf("Continue (Press any) ");
	scanf("%c", &ch);
	while (getchar() != '\n');
	fputs("1. 우선 그룹을 생성하세요. 그룹 번호가 주어집니다.\n2. a를 눌러 해당 그룹에 카드를 추가합니다.(최대 100개)\n3. 공부를 하시려면 o(그룹열기)를 눌러 공부를 시작하시면 됩니다!\n\n감사합니다.\nCopyright(c)2017 성훈이 버스 부르릉 All rights reserved.\n", stdout);

	char chk = NULL;
	printf("\n\n되돌아 가시겠습니까? (Press any) ");
	scanf("%c", &chk);
	while (getchar() != '\n');
	if (chk != NULL)
		menu();
}
// 메뉴얼 끝