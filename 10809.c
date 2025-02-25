#include<stdio.h>
#include<string.h>

int main()
{
	char S[100];
	int Out[30];
	memset(Out, -1, sizeof(Out));
	int comp = 0x61; // a부터 비교 시작
	int count_pos = 0;	// 비교대상이 있는 위치

	fgets(S, sizeof(S), stdin);

	 /*문자열 출력 확인
	S[strlen(S)-1] = '\0';
	printf("%s", S);*/
	for (int i = 0; i < strlen(S); i++)	//문자열 길이만큼 반복
	{
		for (int j = 0; j < 26; j++)	// 알파벳 개수만큼 반복
		{
			if (comp == S[i] && Out[j] == -1)	// 만약 문자와 비교 대상이 같다면  
			{
				Out[j] = count_pos;	// 출력 배열에 몇번째인지 저장
				count_pos++;		// 순서 증가
			}
			comp++;	// 알파벳 하나씩 증가
		}
		comp = 0x61;
	}

	for (int k = 0; k < 26; k++)
	{
		printf("%d ", Out[k]);
	}
	return 0;
}

// 문제점: 중복 문자가 나올경우 첫문자의 순서가 아닌 마지막 숫자의 순서가 출력됨