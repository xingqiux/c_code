#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '0'  //��������

//�������������һ��Ӣ�� ��Ȼ��ʶ�����е��ַ������ʣ�����

int main(vodi)
{
	int wordNum=0;  //������
	int strNum=0;   //�ַ���
	int lineNum=0;  // ����
	char ch;         //������ַ�
	bool inword = false;  //����һ����־���ţ���ʾ��һ��������
	while ((ch = getchar()) != STOP)  
	{
		strNum++;
		if (ch == '\n')
			lineNum++;
		if (!isspace(ch) && !inword)    //������ǿո�����һ��������������ͼ�һ
		{
			inword = true;
			wordNum++;
		}
		if (isspace(ch) && inword)  //���ǿո�ʱ����ת��Ϊ���������������  inworld =false 
			inword = false;
	}
	printf("�ַ��� %d ���������� %d �������� %d ��", strNum, wordNum, lineNum);
	return 0;
}
