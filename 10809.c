#include<stdio.h>
#include<string.h>

int main()
{
	char S[100];
	int Out[30];
	memset(Out, -1, sizeof(Out));
	int comp = 0x61; // a���� �� ����
	int count_pos = 0;	// �񱳴���� �ִ� ��ġ

	fgets(S, sizeof(S), stdin);

	 /*���ڿ� ��� Ȯ��
	S[strlen(S)-1] = '\0';
	printf("%s", S);*/
	for (int i = 0; i < strlen(S); i++)	//���ڿ� ���̸�ŭ �ݺ�
	{
		for (int j = 0; j < 26; j++)	// ���ĺ� ������ŭ �ݺ�
		{
			if (comp == S[i] && Out[j] == -1)	// ���� ���ڿ� �� ����� ���ٸ�  
			{
				Out[j] = count_pos;	// ��� �迭�� ���°���� ����
				count_pos++;		// ���� ����
			}
			comp++;	// ���ĺ� �ϳ��� ����
		}
		comp = 0x61;
	}

	for (int k = 0; k < 26; k++)
	{
		printf("%d ", Out[k]);
	}
	return 0;
}

// ������: �ߺ� ���ڰ� ���ð�� ù������ ������ �ƴ� ������ ������ ������ ��µ�