#include<stdio.h>
#include<string.h>

int main()
{
	char S[101];
	int Out[26];

	memset(Out, -1, sizeof(Out));
	int comp = 0x61;		// a���� �� ����
	int count_pos = 0;		// �񱳴���� �ִ� ��ġ

	fgets(S, sizeof(S), stdin);
	
	int len = strlen(S);		// strlen(S)�Լ��� �ѹ��� ����ϰ� ������ ����
	if (S[len - 1] == '\n')		// fgets�Լ��� �������� ���๮�� ����
	{
		S[len - 1] = '\0';
		len--;
	}

	
	for (int i = 0; i < len; i++)	//���ڿ� ���̸�ŭ �ݺ�
	{
		for (int j = 0; j < 26; j++)	// ���ĺ� ������ŭ �ݺ�
		{
			if (comp == S[i] && Out[j] == -1)	// ���� ���ڿ� �� ����� ���ٸ�  
			{
				Out[j] = count_pos;	// ��� �迭�� ���°���� ����
				count_pos++;		// ���� ����
			}
			else if (comp == S[i])	count_pos++;		// �̹� �ߺ����� ��� ������ ����
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
//        -> else if�� ���� �߰��ؼ� �ذ�

// Ȩ���������� Ʋ������: �ִ� 100�� �Է��ε� �Է� �迭 Sũ�⸦ 100���� �ּ�
// �ð����⵵ ���� �ʿ�