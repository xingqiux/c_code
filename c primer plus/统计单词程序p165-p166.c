#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '0'  //结束符号

//这个程序是输入一段英文 ，然后识别其中的字符，单词，行数

int main(vodi)
{
	int wordNum=0;  //单词数
	int strNum=0;   //字符数
	int lineNum=0;  // 行数
	char ch;         //处理的字符
	bool inword = false;  //这是一个标志符号，表示在一个单词中
	while ((ch = getchar()) != STOP)  
	{
		strNum++;
		if (ch == '\n')
			lineNum++;
		if (!isspace(ch) && !inword)    //如果不是空格并且在一个单词里，单词数就加一
		{
			inword = true;
			wordNum++;
		}
		if (isspace(ch) && inword)  //当是空格时，就转换为不是在这个单词里  inworld =false 
			inword = false;
	}
	printf("字符有 %d 个，单词有 %d 个，行有 %d 个", strNum, wordNum, lineNum);
	return 0;
}
