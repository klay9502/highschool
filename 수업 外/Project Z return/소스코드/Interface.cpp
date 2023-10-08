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
	ScreenPrint(0, 0, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	ScreenPrint(0, 1, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 2, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 3, "¦¢                                ! Warning !                                 ¦¢");
	ScreenPrint(0, 4, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 5, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 6, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 7, "¦¢             º» °ÔÀÓ¿¡¼­ µîÀåÇÏ´Â ÀÎ¹°, Àå¼Ò´Â ¸ðµÎ ÇÈ¼ÇÀÔ´Ï´Ù.             ¦¢");
	ScreenPrint(0, 8, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 9, "¦¢                                                                            ¦¢");
	ScreenPrint(0,10, "¦¢        º» °ÔÀÓÀº »çÈ¸»ýÈ°¿¡ ´Ù¼Ò ºÎÁ¤ÀûÀÎ ¿µÇâÀ» ¹ÌÄ¥ ¼ö ÀÖ½À´Ï´Ù.         ¦¢");
	ScreenPrint(0,11, "¦¢                                                                            ¦¢");
	ScreenPrint(0,12, "¦¢                                                                            ¦¢");
	ScreenPrint(0,13, "¦¢      º» °ÔÀÓÀ¸·Î ÀÌÇØ ¹ß»ýÇÏ´Â ÇÇÇØ¿¡ ´ëÇØ ÀÏÃ¼ Ã¥ÀÓÀ» ÁöÁö ¾Ê½À´Ï´Ù.      ¦¢");
	ScreenPrint(0,14, "¦¢                                                                            ¦¢");
	ScreenPrint(0,15, "¦¢                                                                            ¦¢");
	ScreenPrint(0,16, "¦¢         º» °ÔÀÓÀÇ ÀúÀÛ±ÇÀº ¸ðµÎ °ÔÀÓ°ú '±èÁ¾¹Î' ÇÐ»ý¿¡°Ô ÀÖ½À´Ï´Ù.         ¦¢");
	ScreenPrint(0,17, "¦¢                                                                            ¦¢");
	ScreenPrint(0,18, "¦¢                                                                            ¦¢");
	ScreenPrint(0,19, "¦¢           Copyright (c) 2015 Jong-min Kim. All rights reserved.            ¦¢");
	ScreenPrint(0,20, "¦¢                                                                            ¦¢");
	ScreenPrint(0,21, "¦¢                              Press Space Key                               ¦¢");
	ScreenPrint(0,22, "¦¢                                                                            ¦¢");
	ScreenPrint(0,23, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	ScreenPrint(0,24, "ClaySoft                                                               1.00 ver");
	return 0;
}

int Interface(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	ScreenPrint(0, 1, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 2, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 3, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 4, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 5, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 6, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 7, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 8, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 9, "¦¢                                                                            ¦¢");
	ScreenPrint(0,10, "¦¢                                                                            ¦¢");
	ScreenPrint(0,11, "¦¢                                                                            ¦¢");
	ScreenPrint(0,12, "¦¢                                                                            ¦¢");
	ScreenPrint(0,13, "¦¢                                                                            ¦¢");
	ScreenPrint(0,14, "¦¢                                                                            ¦¢");
	ScreenPrint(0,15, "¦¢                                                                            ¦¢");
	ScreenPrint(0,16, "¦¢                                                                            ¦¢");
	ScreenPrint(0,17, "¦¢                                                                            ¦¢");
	ScreenPrint(0,18, "¦¢                                                                            ¦¢");
	ScreenPrint(0,19, "¦¢                                                                            ¦¢");
	ScreenPrint(0,20, "¦¢                                                                            ¦¢");
	ScreenPrint(0,21, "¦¢                                                                            ¦¢");
	ScreenPrint(0,22, "¦¢                                                                            ¦¢");
	ScreenPrint(0,23, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceMain(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	ScreenPrint(0, 1, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 2, "¦¢    ¡á¡á¡á¡á                                                    TM          ¦¢");
	ScreenPrint(0, 3, "¦¢    ¡á      ¡á                    ¡á                        ¡á              ¦¢");
	ScreenPrint(0, 4, "¦¢    ¡á¡á¡á¡á    ¡á  ¡á    ¡á¡á          ¡á¡á      ¡á¡á      ¡á              ¦¢");
	ScreenPrint(0, 5, "¦¢    ¡á          ¡á¡á    ¡á    ¡á  ¡á  ¡á    ¡á  ¡á    ¡á  ¡á¡á¡á            ¦¢");
	ScreenPrint(0, 6, "¦¢    ¡á          ¡á      ¡á    ¡á  ¡á  ¡á¡á¡á¡á  ¡á          ¡á              ¦¢");
	ScreenPrint(0, 7, "¦¢    ¡á          ¡á        ¡á¡á    ¡á  ¡á        ¡á    ¡á    ¡á              ¦¢");
	ScreenPrint(0, 8, "¦¢           Return ver             ¡á    ¡á¡á¡á    ¡á¡á      ¡á¡á            ¦¢");
	ScreenPrint(0, 9, "¦¢                                ¡á                                          ¦¢");
	ScreenPrint(0,10, "¦¢     ¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â    ¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â                   ¦¢");
	ScreenPrint(0,11, "¦¢           ¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â                         ¦¢");
	ScreenPrint(0,12, "¦¢                         ¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â                               ¦¢");
	ScreenPrint(0,13, "¦¢                             ¢Â¢Â¢Â¢Â¢Â¢Â            ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¤       ¦¢");
	ScreenPrint(0,14, "¦¢                         ¢Â¢Â¢Â¢Â¢Â¢Â                ¦¢            ¦¢       ¦¢");
	ScreenPrint(0,15, "¦¢                       ¢Â¢Â¢Â¢Â¢Â                    ¦§¦¡¦¡¦¡¦¡¦¡¦¡¦©       ¦¢");
	ScreenPrint(0,16, "¦¢                     ¢Â¢Â¢Â¢Â                        ¦¢            ¦¢       ¦¢");
	ScreenPrint(0,17, "¦¢                 ¢Â¢Â¢Â¢Â¢Â                          ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¥       ¦¢");
	ScreenPrint(0,18, "¦¢               ¢Â¢Â¢Â¢Â                                                     ¦¢");
	ScreenPrint(0,19, "¦¢            ¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â                                          ¦¢");
	ScreenPrint(0,20, "¦¢        ¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â         ¢Â               ¦¢");
	ScreenPrint(0,21, "¦¢ ¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â¢Â               ¦¢");
	ScreenPrint(0,22, "¦¢                                                                            ¦¢");
	ScreenPrint(0,23, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int  InterfaceTutorial(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	ScreenPrint(0, 1, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 2, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 3, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 4, "¦¢  * °ÔÀÓ¹æ¹ý                                                                ¦¢");
	ScreenPrint(0, 5, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 6, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 7, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 8, "¦¢  ÁÖ È÷·ÎÀÎÀÎ '¹ÚÁöÇõ' ±º°ú °ü°èµµ°¡ +100 ÀÌ»óÀÌ µÇ¸é µË´Ï´Ù.               ¦¢");
	ScreenPrint(0, 9, "¦¢                                                                            ¦¢");
	ScreenPrint(0,10, "¦¢                                                                            ¦¢");
	ScreenPrint(0,11, "¦¢  ´ëÈ­ ¹× ¹Ì´Ï°ÔÀÓ, ¾ÆÀÌÅÛ µîÀ¸·Î °ü°èµµ¸¦ Çâ»ó ¹× ÇÏÇâ ½ÃÅ³ ¼ö ÀÖ½À´Ï´Ù.   ¦¢");
	ScreenPrint(0,12, "¦¢                                                                            ¦¢");
	ScreenPrint(0,13, "¦¢                                                                            ¦¢");
	ScreenPrint(0,14, "¦¢  °ü°èµµ°¡ -100, ¶Ç´Â ±× ÀÌÇÏ°¡ µÉ ½Ã °ÔÀÓ¿À¹öÀÔ´Ï´Ù.                       ¦¢");
	ScreenPrint(0,15, "¦¢                                                                            ¦¢");
	ScreenPrint(0,16, "¦¢                                                                            ¦¢");
	ScreenPrint(0,17, "¦¢  ±×·³ Çà¿îÀ» º÷´Ï´Ù!                                                       ¦¢");
	ScreenPrint(0,18, "¦¢                                                                            ¦¢");
	ScreenPrint(0,19, "¦¢                                                                            ¦¢");
	ScreenPrint(0,20, "¦¢                                                                            ¦¢");
	ScreenPrint(0,21, "¦¢  Press Space Key                                                           ¦¢");
	ScreenPrint(0,22, "¦¢                                                                            ¦¢");
	ScreenPrint(0,23, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceIngame(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	ScreenPrint(0, 1, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 2, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 3, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 4, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 5, "¦¢           ¹«¾ùÀ» ÇÏ½Ã°Ú½À´Ï±î?                  ¡ß  ¡ß  ¡ß  ¡ß  ¡ß  ¡ß     ¦¢");
	ScreenPrint(0, 6, "¦¢                                                 ¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß     ¦¢");
	ScreenPrint(0, 7, "¦¢     ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤            ¡ß¡ß¡ß¡ß      ¡ß¡ß¡ß¡ß     ¦¢");
	ScreenPrint(0, 8, "¦¢     ¦¢                            ¦¢            ¡ß                  ¡ß     ¦¢");
	ScreenPrint(0, 9, "¦¢     ¦¢          ´ëÈ­ÇÏ±â          ¦¢            ¡ß ¡á¡á¡á    ¡á¡á¡á ¡ß     ¦¢");
	ScreenPrint(0,10, "¦¢     ¦¢                            ¦¢            ¡ß ¡á  ¡á¡á¡á¡á  ¡á ¡ß     ¦¢");
	ScreenPrint(0,11, "¦¢     ¦¢            ¸ÅÁ¡            ¦¢             ¡ß  ¡á   ¡á   ¡á  ¡ß      ¦¢");
	ScreenPrint(0,12, "¦¢     ¦¢                            ¦¢              ¡ß              ¡ß       ¦¢");
	ScreenPrint(0,13, "¦¢     ¦¢          ÀÎº¥Åä¸®          ¦¢               ¡ß            ¡ß        ¦¢");
	ScreenPrint(0,14, "¦¢     ¦¢                            ¦¢                 ¡ß¡ß     ¡ß¡ß         ¦¢");
	ScreenPrint(0,15, "¦¢     ¦¢          ¾Ë¹ÙÇÏ±â          ¦¢                ¡Þ    ¡ß     ¡Þ        ¦¢");
	ScreenPrint(0,16, "¦¢     ¦¢                            ¦¢              ¡Þ              ¡Þ       ¦¢");
	ScreenPrint(0,17, "¦¢     ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥             ¡Þ                ¡Þ      ¦¢");
	ScreenPrint(0,18, "¦¢                                                 ¡Þ                  ¡Þ     ¦¢");
	ScreenPrint(0,19, "¦¢                                                 ¡Þ                  ¡Þ     ¦¢");
	ScreenPrint(0,20, "¦¢                                                 ¡Þ                  ¡Þ     ¦¢");
	ScreenPrint(0,21, "¦¢                                                ¡Þ                    ¡Þ    ¦¢");
	ScreenPrint(0,22, "¦¢                                                ¡Þ                    ¡Þ    ¦¢");
	ScreenPrint(0,23, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceInven(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	ScreenPrint(0, 1, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 2, "¦¢                                                 ¡ß  ¡ß  ¡ß  ¡ß  ¡ß  ¡ß     ¦¢");
	ScreenPrint(0, 3, "¦¢        ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤         ¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß     ¦¢");
	ScreenPrint(0, 4, "¦¢        ¦¢                            ¦¢         ¡ß¡ß¡ß¡ß      ¡ß¡ß¡ß¡ß     ¦¢");
	ScreenPrint(0, 5, "¦¢        ¦¢   Æ÷Ä¿Ä¨                   ¦¢         ¡ß                  ¡ß     ¦¢");
	ScreenPrint(0, 6, "¦¢        ¦¢                            ¦¢         ¡ß ¡á¡á¡á    ¡á¡á¡á ¡ß     ¦¢");
	ScreenPrint(0, 7, "¦¢        ¦¢   ÇÇ±×´Ð                   ¦¢         ¡ß ¡á  ¡á¡á¡á¡á  ¡á ¡ß     ¦¢");
	ScreenPrint(0, 8, "¦¢        ¦¢                            ¦¢          ¡ß  ¡á   ¡á   ¡á  ¡ß      ¦¢");
	ScreenPrint(0, 9, "¦¢        ¦¢   »¶»¶ÇÑ ³ªÃÝÄ¨            ¦¢           ¡ß              ¡ß       ¦¢");
	ScreenPrint(0,10, "¦¢        ¦¢                            ¦¢            ¡ß            ¡ß        ¦¢");
	ScreenPrint(0,11, "¦¢        ¦¢   ÃÊÄÚ ´Ù¾ÆÀç              ¦¢              ¡ß¡ß     ¡ß¡ß         ¦¢");
	ScreenPrint(0,12, "¦¢        ¦¢                            ¦¢             ¡Þ    ¡ß     ¡Þ        ¦¢");
	ScreenPrint(0,13, "¦¢        ¦¢   °ÔÀÌÆ®¿þÀÌ               ¦¢           ¡Þ              ¡Þ       ¦¢");
	ScreenPrint(0,14, "¦¢        ¦¢                            ¦¢          ¡Þ                ¡Þ      ¦¢");
	ScreenPrint(0,15, "¦¢        ¦¢   ³ª°¡±â                   ¦¢         ¡Þ                  ¡Þ     ¦¢");
	ScreenPrint(0,16, "¦¢        ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥         ¡Þ                  ¡Þ     ¦¢");
	ScreenPrint(0,17, "¦¢¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¢");
	ScreenPrint(0,18, "¦¢                                                                            ¦¢");
	ScreenPrint(0,19, "¦¢                                                                            ¦¢");
	ScreenPrint(0,20, "¦¢                                                                            ¦¢");
	ScreenPrint(0,21, "¦¢                                                                            ¦¢");
	ScreenPrint(0,22, "¦¢                                                                            ¦¢");
	ScreenPrint(0,23, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");
	
	return 0;
}

int InterfaceShop(void)
{
	ScreenPrint(0, 0, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	ScreenPrint(0, 1, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 2, "¦¢                                                     ¡á¡á¡á¡á¡á¡á¡á         ¦¢");
	ScreenPrint(0, 3, "¦¢        ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤         ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á     ¦¢");
	ScreenPrint(0, 4, "¦¢        ¦¢                            ¦¢       ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á   ¦¢");
	ScreenPrint(0, 5, "¦¢        ¦¢           Æ÷Ä¿Ä¨           ¦¢       ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á   ¦¢");
	ScreenPrint(0, 6, "¦¢        ¦¢                            ¦¢         ¡á                  ¡á     ¦¢");
	ScreenPrint(0, 7, "¦¢        ¦¢           ÇÇ±×´Ð           ¦¢         ¡á   ¡á        ¡á   ¡á     ¦¢");
	ScreenPrint(0, 8, "¦¢        ¦¢                            ¦¢         ¡ß                  ¡ß     ¦¢");
	ScreenPrint(0, 9, "¦¢        ¦¢        »¶»¶ÇÑ ³ªÃÝÄ¨       ¦¢         ¡ß                  ¡ß     ¦¢");
	ScreenPrint(0,10, "¦¢        ¦¢                            ¦¢           ¡ß              ¡ß       ¦¢");
	ScreenPrint(0,11, "¦¢        ¦¢         ÃÊÄÚ ´Ù¾ÆÀç        ¦¢             ¡ß¡ß¡ß¡ß¡ß¡ß¡ß         ¦¢");
	ScreenPrint(0,12, "¦¢        ¦¢                            ¦¢           ¡Þ              ¡Þ       ¦¢");
	ScreenPrint(0,13, "¦¢        ¦¢         °ÔÀÌÆ®¿þÀÌ         ¦¢        ¡Þ                    ¡Þ    ¦¢");
	ScreenPrint(0,14, "¦¢        ¦¢                            ¦¢      ¡Þ                        ¡Þ  ¦¢");
	ScreenPrint(0,15, "¦¢        ¦¢           ³ª°¡±â           ¦¢      ¡Þ                        ¡Þ  ¦¢");
	ScreenPrint(0,16, "¦¢        ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥      ¡Þ                        ¡Þ  ¦¢");
	ScreenPrint(0,17, "¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
	ScreenPrint(0,18, "¦¢                                                                            ¦¢");
	ScreenPrint(0,19, "¦¢                                                                            ¦¢");
	ScreenPrint(0,20, "¦¢                                                                            ¦¢");
	ScreenPrint(0,21, "¦¢                                                                            ¦¢");
	ScreenPrint(0,22, "¦¢                                                                            ¦¢");
	ScreenPrint(0,23, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceWork(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	ScreenPrint(0, 1, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 2, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 3, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 4, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 5, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 6, "¦¢                                                    ¦¢                      ¦¢");
	ScreenPrint(0, 7, "¦¢                                                         /                  ¦¢");
	ScreenPrint(0, 8, "¦¢                                                    £À                      ¦¢");
	ScreenPrint(0, 9, "¦¢                                                  £À   £À   ¦¡              ¦¢");
	ScreenPrint(0,10, "¦¢                                                £À   £À                     ¦¢");
	ScreenPrint(0,11, "¦¢                               Working...     £À   £À ¡ß                    ¦¢");
	ScreenPrint(0,12, "¦¢                                                 £À     ¡ß                  ¦¢");
	ScreenPrint(0,13, "¦¢                                                          ¡ß                ¦¢");
	ScreenPrint(0,14, "¦¢                                                            ¡ß              ¦¢");
	ScreenPrint(0,15, "¦¢                                                                            ¦¢");
	ScreenPrint(0,16, "¦¢                                                                            ¦¢");
	ScreenPrint(0,17, "¦¢                                                                            ¦¢");
	ScreenPrint(0,18, "¦¢                                                                            ¦¢");
	ScreenPrint(0,19, "¦¢                                                                            ¦¢");
	ScreenPrint(0,20, "¦¢                                                                            ¦¢");
	ScreenPrint(0,21, "¦¢                                                                            ¦¢");
	ScreenPrint(0,22, "¦¢                                                                            ¦¢");
	ScreenPrint(0,23, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}

int InterfaceTalk(void)
{
	SetColor(7);
	ScreenPrint(0, 0, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	ScreenPrint(0, 1, "¦¢                                                                            ¦¢");
	ScreenPrint(0, 2, "¦¢                             ¡ß  ¡ß  ¡ß  ¡ß  ¡ß  ¡ß                         ¦¢");
	ScreenPrint(0, 3, "¦¢                             ¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß                         ¦¢");
	ScreenPrint(0, 4, "¦¢                             ¡ß¡ß¡ß¡ß      ¡ß¡ß¡ß¡ß                         ¦¢");
	ScreenPrint(0, 5, "¦¢                             ¡ß                  ¡ß                         ¦¢");
	ScreenPrint(0, 6, "¦¢                             ¡ß ¡á¡á¡á    ¡á¡á¡á ¡ß                         ¦¢");
	ScreenPrint(0, 7, "¦¢                             ¡ß ¡á  ¡á¡á¡á¡á  ¡á ¡ß                         ¦¢");
	ScreenPrint(0, 8, "¦¢                              ¡ß  ¡á   ¡á   ¡á  ¡ß                          ¦¢");
	ScreenPrint(0, 9, "¦¢                               ¡ß              ¡ß                           ¦¢");
	ScreenPrint(0,10, "¦¢                                ¡ß            ¡ß                            ¦¢");
	ScreenPrint(0,11, "¦¢                                  ¡ß¡ß     ¡ß¡ß                             ¦¢");
	ScreenPrint(0,12, "¦¢                                 ¡Þ    ¡ß     ¡Þ                            ¦¢");
	ScreenPrint(0,13, "¦¢                               ¡Þ              ¡Þ                           ¦¢");
	ScreenPrint(0,14, "¦¢                              ¡Þ                ¡Þ                          ¦¢");
	ScreenPrint(0,15, "¦¢                             ¡Þ                  ¡Þ                         ¦¢");
	ScreenPrint(0,16, "¦¢                             ¡Þ                  ¡Þ                         ¦¢");
	ScreenPrint(0,17, "¦¢¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¢");
	ScreenPrint(0,18, "¦¢                                                                            ¦¢");
	ScreenPrint(0,19, "¦¢                                                                            ¦¢");
	ScreenPrint(0,20, "¦¢                                                                            ¦¢");
	ScreenPrint(0,21, "¦¢                                                                            ¦¢");
	ScreenPrint(0,22, "¦¢                                                                            ¦¢");
	ScreenPrint(0,23, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	ScreenPrint(0, 24, "ClaySoft                                                               1.00 ver");

	return 0;
}