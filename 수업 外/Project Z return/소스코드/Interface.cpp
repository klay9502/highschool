//
// Interface.cpp
// project_return_Z
// Remaking 'Project Z'
//
// Created by Jong-min Kim on 2015. 1. 26
// Copyright (c) 2015 Jong-min Kim. All rights reserved.
//

#include <Windows.h>
#include "Screen.h"

int InterfaceWarning(void)
{
	SetColor(79);
	ScreenPrint(0, 0, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 1, "��                                                                            ��");
	ScreenPrint(0, 2, "��                                                                            ��");
	ScreenPrint(0, 3, "��                                ! Warning !                                 ��");
	ScreenPrint(0, 4, "��                                                                            ��");
	ScreenPrint(0, 5, "��                                                                            ��");
	ScreenPrint(0, 6, "��                                                                            ��");
	ScreenPrint(0, 7, "��             �� ���ӿ��� �����ϴ� �ι�, ��Ҵ� ��� �ȼ��Դϴ�.             ��");
	ScreenPrint(0, 8, "��                                                                            ��");
	ScreenPrint(0, 9, "��                                                                            ��");
	ScreenPrint(0,10, "��        �� ������ ��ȸ��Ȱ�� �ټ� �������� ������ ��ĥ �� �ֽ��ϴ�.         ��");
	ScreenPrint(0,11, "��                                                                            ��");
	ScreenPrint(0,12, "��                                                                            ��");
	ScreenPrint(0,13, "��      �� �������� ���� �߻��ϴ� ���ؿ� ���� ��ü å���� ���� �ʽ��ϴ�.      ��");
	ScreenPrint(0,14, "��                                                                            ��");
	ScreenPrint(0,15, "��                                                                            ��");
	ScreenPrint(0,16, "��         �� ������ ���۱��� ��� ���Ӱ� '������' �л����� �ֽ��ϴ�.         ��");
	ScreenPrint(0,17, "��                                                                            ��");
	ScreenPrint(0,18, "��                                                                            ��");
	ScreenPrint(0,19, "��           Copyright (c) 2015 Jong-min Kim. All rights reserved.            ��");
	ScreenPrint(0,20, "��                                                                            ��");
	ScreenPrint(0,21, "��                              Press Space Key                               ��");
	ScreenPrint(0,22, "��                                                                            ��");
	ScreenPrint(0,23, "��������������������������������������������������������������������������������");
	ScreenPrint(0,24, "ClaySoft                                                               1.00 ver");
	return 0;
}

int Interface(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 1, "��                                                                            ��");
	ScreenPrint(0, 2, "��                                                                            ��");
	ScreenPrint(0, 3, "��                                                                            ��");
	ScreenPrint(0, 4, "��                                                                            ��");
	ScreenPrint(0, 5, "��                                                                            ��");
	ScreenPrint(0, 6, "��                                                                            ��");
	ScreenPrint(0, 7, "��                                                                            ��");
	ScreenPrint(0, 8, "��                                                                            ��");
	ScreenPrint(0, 9, "��                                                                            ��");
	ScreenPrint(0,10, "��                                                                            ��");
	ScreenPrint(0,11, "��                                                                            ��");
	ScreenPrint(0,12, "��                                                                            ��");
	ScreenPrint(0,13, "��                                                                            ��");
	ScreenPrint(0,14, "��                                                                            ��");
	ScreenPrint(0,15, "��                                                                            ��");
	ScreenPrint(0,16, "��                                                                            ��");
	ScreenPrint(0,17, "��                                                                            ��");
	ScreenPrint(0,18, "��                                                                            ��");
	ScreenPrint(0,19, "��                                                                            ��");
	ScreenPrint(0,20, "��                                                                            ��");
	ScreenPrint(0,21, "��                                                                            ��");
	ScreenPrint(0,22, "��                                                                            ��");
	ScreenPrint(0,23, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceMain(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 1, "��                                                                            ��");
	ScreenPrint(0, 2, "��    �����                                                    TM          ��");
	ScreenPrint(0, 3, "��    ��      ��                    ��                        ��              ��");
	ScreenPrint(0, 4, "��    �����    ��  ��    ���          ���      ���      ��              ��");
	ScreenPrint(0, 5, "��    ��          ���    ��    ��  ��  ��    ��  ��    ��  ����            ��");
	ScreenPrint(0, 6, "��    ��          ��      ��    ��  ��  �����  ��          ��              ��");
	ScreenPrint(0, 7, "��    ��          ��        ���    ��  ��        ��    ��    ��              ��");
	ScreenPrint(0, 8, "��           Return ver             ��    ����    ���      ���            ��");
	ScreenPrint(0, 9, "��                                ��                                          ��");
	ScreenPrint(0,10, "��     �¢¢¢¢¢¢¢¢¢¢¢¢�    �¢¢¢¢¢¢¢¢¢¢�                   ��");
	ScreenPrint(0,11, "��           �¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢�                         ��");
	ScreenPrint(0,12, "��                         �¢¢¢¢¢¢¢¢¢�                               ��");
	ScreenPrint(0,13, "��                             �¢¢¢¢¢�            ����������������       ��");
	ScreenPrint(0,14, "��                         �¢¢¢¢¢�                ��            ��       ��");
	ScreenPrint(0,15, "��                       �¢¢¢¢�                    ����������������       ��");
	ScreenPrint(0,16, "��                     �¢¢¢�                        ��            ��       ��");
	ScreenPrint(0,17, "��                 �¢¢¢¢�                          ����������������       ��");
	ScreenPrint(0,18, "��               �¢¢¢�                                                     ��");
	ScreenPrint(0,19, "��            �¢¢¢¢¢¢¢¢¢¢�                                          ��");
	ScreenPrint(0,20, "��        �¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢�         ��               ��");
	ScreenPrint(0,21, "�� �¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢�               ��");
	ScreenPrint(0,22, "��                                                                            ��");
	ScreenPrint(0,23, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int  InterfaceTutorial(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 1, "��                                                                            ��");
	ScreenPrint(0, 2, "��                                                                            ��");
	ScreenPrint(0, 3, "��                                                                            ��");
	ScreenPrint(0, 4, "��  * ���ӹ��                                                                ��");
	ScreenPrint(0, 5, "��                                                                            ��");
	ScreenPrint(0, 6, "��                                                                            ��");
	ScreenPrint(0, 7, "��                                                                            ��");
	ScreenPrint(0, 8, "��  �� �������� '������' ���� ���赵�� +100 �̻��� �Ǹ� �˴ϴ�.               ��");
	ScreenPrint(0, 9, "��                                                                            ��");
	ScreenPrint(0,10, "��                                                                            ��");
	ScreenPrint(0,11, "��  ��ȭ �� �̴ϰ���, ������ ������ ���赵�� ��� �� ���� ��ų �� �ֽ��ϴ�.   ��");
	ScreenPrint(0,12, "��                                                                            ��");
	ScreenPrint(0,13, "��                                                                            ��");
	ScreenPrint(0,14, "��  ���赵�� -100, �Ǵ� �� ���ϰ� �� �� ���ӿ����Դϴ�.                       ��");
	ScreenPrint(0,15, "��                                                                            ��");
	ScreenPrint(0,16, "��                                                                            ��");
	ScreenPrint(0,17, "��  �׷� ����� ���ϴ�!                                                       ��");
	ScreenPrint(0,18, "��                                                                            ��");
	ScreenPrint(0,19, "��                                                                            ��");
	ScreenPrint(0,20, "��                                                                            ��");
	ScreenPrint(0,21, "��  Press Space Key                                                           ��");
	ScreenPrint(0,22, "��                                                                            ��");
	ScreenPrint(0,23, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceIngame(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 1, "��                                                                            ��");
	ScreenPrint(0, 2, "��                                                                            ��");
	ScreenPrint(0, 3, "��                                                                            ��");
	ScreenPrint(0, 4, "��                                                                            ��");
	ScreenPrint(0, 5, "��           ������ �Ͻðڽ��ϱ�?                  ��  ��  ��  ��  ��  ��     ��");
	ScreenPrint(0, 6, "��                                                 �ߡߡߡߡߡߡߡߡߡߡ�     ��");
	ScreenPrint(0, 7, "��     ��������������������������������            �ߡߡߡ�      �ߡߡߡ�     ��");
	ScreenPrint(0, 8, "��     ��                            ��            ��                  ��     ��");
	ScreenPrint(0, 9, "��     ��          ��ȭ�ϱ�          ��            �� ����    ���� ��     ��");
	ScreenPrint(0,10, "��     ��                            ��            �� ��  �����  �� ��     ��");
	ScreenPrint(0,11, "��     ��            ����            ��             ��  ��   ��   ��  ��      ��");
	ScreenPrint(0,12, "��     ��                            ��              ��              ��       ��");
	ScreenPrint(0,13, "��     ��          �κ��丮          ��               ��            ��        ��");
	ScreenPrint(0,14, "��     ��                            ��                 �ߡ�     �ߡ�         ��");
	ScreenPrint(0,15, "��     ��          �˹��ϱ�          ��                ��    ��     ��        ��");
	ScreenPrint(0,16, "��     ��                            ��              ��              ��       ��");
	ScreenPrint(0,17, "��     ��������������������������������             ��                ��      ��");
	ScreenPrint(0,18, "��                                                 ��                  ��     ��");
	ScreenPrint(0,19, "��                                                 ��                  ��     ��");
	ScreenPrint(0,20, "��                                                 ��                  ��     ��");
	ScreenPrint(0,21, "��                                                ��                    ��    ��");
	ScreenPrint(0,22, "��                                                ��                    ��    ��");
	ScreenPrint(0,23, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceInven(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 1, "��                                                                            ��");
	ScreenPrint(0, 2, "��                                                 ��  ��  ��  ��  ��  ��     ��");
	ScreenPrint(0, 3, "��        ��������������������������������         �ߡߡߡߡߡߡߡߡߡߡ�     ��");
	ScreenPrint(0, 4, "��        ��                            ��         �ߡߡߡ�      �ߡߡߡ�     ��");
	ScreenPrint(0, 5, "��        ��   ��ĿĨ                   ��         ��                  ��     ��");
	ScreenPrint(0, 6, "��        ��                            ��         �� ����    ���� ��     ��");
	ScreenPrint(0, 7, "��        ��   �Ǳ״�                   ��         �� ��  �����  �� ��     ��");
	ScreenPrint(0, 8, "��        ��                            ��          ��  ��   ��   ��  ��      ��");
	ScreenPrint(0, 9, "��        ��   ������ ����Ĩ            ��           ��              ��       ��");
	ScreenPrint(0,10, "��        ��                            ��            ��            ��        ��");
	ScreenPrint(0,11, "��        ��   ���� �پ���              ��              �ߡ�     �ߡ�         ��");
	ScreenPrint(0,12, "��        ��                            ��             ��    ��     ��        ��");
	ScreenPrint(0,13, "��        ��   ����Ʈ����               ��           ��              ��       ��");
	ScreenPrint(0,14, "��        ��                            ��          ��                ��      ��");
	ScreenPrint(0,15, "��        ��   ������                   ��         ��                  ��     ��");
	ScreenPrint(0,16, "��        ��������������������������������         ��                  ��     ��");
	ScreenPrint(0,17, "��������������������������������������������������������������������������������");
	ScreenPrint(0,18, "��                                                                            ��");
	ScreenPrint(0,19, "��                                                                            ��");
	ScreenPrint(0,20, "��                                                                            ��");
	ScreenPrint(0,21, "��                                                                            ��");
	ScreenPrint(0,22, "��                                                                            ��");
	ScreenPrint(0,23, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");
	
	return 0;
}

int InterfaceShop(void)
{
	ScreenPrint(0, 0, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 1, "��                                                                            ��");
	ScreenPrint(0, 2, "��                                                     ��������         ��");
	ScreenPrint(0, 3, "��        ��������������������������������         ������������     ��");
	ScreenPrint(0, 4, "��        ��                            ��       ��������������   ��");
	ScreenPrint(0, 5, "��        ��           ��ĿĨ           ��       ��������������   ��");
	ScreenPrint(0, 6, "��        ��                            ��         ��                  ��     ��");
	ScreenPrint(0, 7, "��        ��           �Ǳ״�           ��         ��   ��        ��   ��     ��");
	ScreenPrint(0, 8, "��        ��                            ��         ��                  ��     ��");
	ScreenPrint(0, 9, "��        ��        ������ ����Ĩ       ��         ��                  ��     ��");
	ScreenPrint(0,10, "��        ��                            ��           ��              ��       ��");
	ScreenPrint(0,11, "��        ��         ���� �پ���        ��             �ߡߡߡߡߡߡ�         ��");
	ScreenPrint(0,12, "��        ��                            ��           ��              ��       ��");
	ScreenPrint(0,13, "��        ��         ����Ʈ����         ��        ��                    ��    ��");
	ScreenPrint(0,14, "��        ��                            ��      ��                        ��  ��");
	ScreenPrint(0,15, "��        ��           ������           ��      ��                        ��  ��");
	ScreenPrint(0,16, "��        ��������������������������������      ��                        ��  ��");
	ScreenPrint(0,17, "��������������������������������������������������������������������������������");
	ScreenPrint(0,18, "��                                                                            ��");
	ScreenPrint(0,19, "��                                                                            ��");
	ScreenPrint(0,20, "��                                                                            ��");
	ScreenPrint(0,21, "��                                                                            ��");
	ScreenPrint(0,22, "��                                                                            ��");
	ScreenPrint(0,23, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceWork(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 1, "��                                                                            ��");
	ScreenPrint(0, 2, "��                                                                            ��");
	ScreenPrint(0, 3, "��                                                                            ��");
	ScreenPrint(0, 4, "��                                                                            ��");
	ScreenPrint(0, 5, "��                                                                            ��");
	ScreenPrint(0, 6, "��                                                    ��                      ��");
	ScreenPrint(0, 7, "��                                                         /                  ��");
	ScreenPrint(0, 8, "��                                                    ��                      ��");
	ScreenPrint(0, 9, "��                                                  ��   ��   ��              ��");
	ScreenPrint(0,10, "��                                                ��   ��                     ��");
	ScreenPrint(0,11, "��                               Working...     ��   �� ��                    ��");
	ScreenPrint(0,12, "��                                                 ��     ��                  ��");
	ScreenPrint(0,13, "��                                                          ��                ��");
	ScreenPrint(0,14, "��                                                            ��              ��");
	ScreenPrint(0,15, "��                                                                            ��");
	ScreenPrint(0,16, "��                                                                            ��");
	ScreenPrint(0,17, "��                                                                            ��");
	ScreenPrint(0,18, "��                                                                            ��");
	ScreenPrint(0,19, "��                                                                            ��");
	ScreenPrint(0,20, "��                                                                            ��");
	ScreenPrint(0,21, "��                                                                            ��");
	ScreenPrint(0,22, "��                                                                            ��");
	ScreenPrint(0,23, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceTalk(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 1, "��                                                                            ��");
	ScreenPrint(0, 2, "��                             ��  ��  ��  ��  ��  ��                         ��");
	ScreenPrint(0, 3, "��                             �ߡߡߡߡߡߡߡߡߡߡ�                         ��");
	ScreenPrint(0, 4, "��                             �ߡߡߡ�      �ߡߡߡ�                         ��");
	ScreenPrint(0, 5, "��                             ��                  ��                         ��");
	ScreenPrint(0, 6, "��                             �� ����    ���� ��                         ��");
	ScreenPrint(0, 7, "��                             �� ��  �����  �� ��                         ��");
	ScreenPrint(0, 8, "��                              ��  ��   ��   ��  ��                          ��");
	ScreenPrint(0, 9, "��                               ��              ��                           ��");
	ScreenPrint(0,10, "��                                ��            ��                            ��");
	ScreenPrint(0,11, "��                                  �ߡ�     �ߡ�                             ��");
	ScreenPrint(0,12, "��                                 ��    ��     ��                            ��");
	ScreenPrint(0,13, "��                               ��              ��                           ��");
	ScreenPrint(0,14, "��                              ��                ��                          ��");
	ScreenPrint(0,15, "��                             ��                  ��                         ��");
	ScreenPrint(0,16, "��                             ��                  ��                         ��");
	ScreenPrint(0,17, "��������������������������������������������������������������������������������");
	ScreenPrint(0,18, "��                                                                            ��");
	ScreenPrint(0,19, "��                                                                            ��");
	ScreenPrint(0,20, "��                                                                            ��");
	ScreenPrint(0,21, "��                                                                            ��");
	ScreenPrint(0,22, "��                                                                            ��");
	ScreenPrint(0,23, "��������������������������������������������������������������������������������");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}