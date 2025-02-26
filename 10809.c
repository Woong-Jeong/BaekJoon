#include<stdio.h>
#include<string.h>

int main()
{
	char S[101];
	int Out[26];

	memset(Out, -1, sizeof(Out));
	int comp = 0x61;		// a부터 비교 시작
	int count_pos = 0;		// 비교대상이 있는 위치

	fgets(S, sizeof(S), stdin);
	
	int len = strlen(S);		// strlen(S)함수를 한번만 계산하게 변수에 저장
	if (S[len - 1] == '\n')		// fgets함수에 딸려오는 개행문자 제거
	{
		S[len - 1] = '\0';
		len--;
	}

	
	for (int i = 0; i < len; i++)	//문자열 길이만큼 반복
	{
		for (int j = 0; j < 26; j++)	// 알파벳 개수만큼 반복
		{
			if (comp == S[i] && Out[j] == -1)	// 만약 문자와 비교 대상이 같다면  
			{
				Out[j] = count_pos;	// 출력 배열에 몇번째인지 저장
				count_pos++;		// 순서 증가
			}
			else if (comp == S[i])	count_pos++;		// 이미 중복됐을 경우 순서만 증가
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
//        -> else if문 조건 추가해서 해결

// 홈페이지에서 틀린이유: 최대 100자 입력인데 입력 배열 S크기를 100으로 둬서
// 시간복잡도 개선 필요