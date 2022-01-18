#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	// Прямоугольник 130×150 с диагоналями
	float x;
	HDC hDC = GetDC(GetConsoleWindow());
	Rectangle(hDC, 0, 0, 130, 150);
	LineTo(hDC, 130, 150);
	MoveToEx(hDC, 130, 0, NULL);
	LineTo(hDC, 0, 150);
	Sleep(100000);
	system("pause");
}



