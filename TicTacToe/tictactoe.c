#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void BoardPrint(int(*board)[3], int(*playerX)[3], int(*playerO)[3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 1 && playerX[i][j] == 1)
			{
				printf("| %c ", 'X');
				continue;
			}

			if (board[i][j] == 1 && playerO[i][j] == 1)
			{
				printf("| %c ", 'O');
				continue;
			}
			printf("| %c  ", '\0');

		}
		printf("|\n");
	}


	//printf("| %c | %c | %c |\n", '\0', '\0', '\0');
	//printf("| - | - | - |\n");
	//printf("| %c | %c | %c |\n", '\0', '\0', '\0');
	//printf("| - | - | - |\n");
	//printf("| %c | %c | %c |\n", '\0', '\0', '\0');

}
int CheckCount(int(*player)[3])
{
	int count[3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		if (player[0][i] == 1)
			count[0]++;
		if (player[1][i] == 1)
			count[1]++;
		if (player[2][i] == 1)
			count[2]++;
		if (count[0] == 3)
			return count[0];
		else if (count[1] == 3)
			return count[1];
		else if (count[2] == 3)
			return count[2];
	}

	for (int i = 0; i < 3; i++)
		count[i] = 0;

	for (int i = 0; i < 3; i++)
	{
		if (player[i][0] == 1)
			count[0]++;
		if (player[i][1] == 1)
			count[1]++;
		if (player[i][2] == 1)
			count[2]++;
		if (count[0] == 3)
			return count[0];
		else if (count[1] == 3)
			return count[1];
		else if (count[2] == 3)
			return count[2];
	}

	for (int i = 0; i < 3; i++)
		count[i] = 0;

	for (int i = 0, j=0; i < 3; i++, j++)
	{
		if (player[i][j] == 1)
			count[0]++;
		if (count[0] == 3)
			return count[0];
	}
		count[0] = 0;

	for (int i = 2; i >= 0; i--)
	{
		if (player[2 - i][i])
			count[1]++;
		if (count[1] == 3)
			return count[1];
	}
	count[1] = 0;
	return 0;
}

int main()
{
	int playerXrow = 0;
	int playerXcol = 0;
	int playerX[3][3] = { 0 };

	int playerOrow = 0;
	int playerOcol = 0;
	int playerO[3][3] = { 0 };

	int board[3][3] = { 0 };
	int count = 0;
	int playerTurn = 0;
	int emptyCount = 9;

	while (count < 3 && emptyCount >0)
	{
		playerTurn = 0;
		if (playerTurn == 0)	// X ����
		{
			printf("Player X, �������� �Է��ϼ���(��[0 - 2]�� ��[0 - 2]) : ");
			scanf("%d %d", &playerXrow, &playerXcol);
		}

		//������ ä��� �ߺ� �˻� , �߸��� �Է�
		if (board[playerXrow][playerXcol] == 1 || playerXrow > 2 || playerXcol > 2 || playerXrow < 0 || playerXcol < 0)
		{
			printf("�߸��� ������! �ٽ� �õ����ּ���.\n");
			continue;
		}

		// ������ ä���
		board[playerXrow][playerXcol] = 1;
		playerX[playerXrow][playerXcol] = 1;

		// ��ĭ
		emptyCount--;

		// ������ ���
		BoardPrint(board, playerX, playerO);

		count = CheckCount(playerX);
		if (count == 3)
		{
			printf("�÷��̾� X �¸�\n");
			break;
		}


		//�ϳѱ�
		playerTurn++;
		while (count < 3 && playerTurn == 1 && emptyCount >0)
		{
			if (playerTurn == 1)	// O ����
			{
				printf("Player O, �������� �Է��ϼ���(��[0 - 2]�� ��[0 - 2]) : ");
				scanf("%d %d", &playerOrow, &playerOcol);
			}

			//������ ä��� �ߺ� �˻� , �߸��� �Է�
			if (board[playerOrow][playerOcol] == 1 || playerOrow > 2 || playerOcol > 2 || playerOrow < 0 || playerOcol < 0)
			{
				printf("�߸��� ������! �ٽ� �õ����ּ���.\n");
				continue;
			}

			// ������ ä���
			board[playerOrow][playerOcol] = 1;
			playerO[playerOrow][playerOcol] = 1;


			// ��ĭ
			emptyCount--;

			// ������ ���
			BoardPrint(board, playerX, playerO);
			count = CheckCount(playerO);
			if (count == 3)
			{
				printf("�÷��̾� O �¸�\n");
				break;
			}

			// �� ����
			playerTurn = 0;
		}



		//���


	}
	printf("���� ����");
	return 0;
}