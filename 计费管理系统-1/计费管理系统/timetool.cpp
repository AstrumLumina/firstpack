#define   _CRT_SECURE_NO_WARNINGS  1

#include"timetool.h"

//格式化时间
void timetostr(time_t *t, char* savetime)
{
	struct tm *timetochange = localtime(t);
	strftime(savetime, 18,"%F %R", timetochange);
}
//读取时间
//time_t strtotime(char* stime) {
//	;
//}




//一下为一些时间函数的介绍

//
//struct tm* localtime(const time_t* timer);
//struct tm* gmtime(const time_t* timer);
//获得年、月、日、时、分、秒等信息。
//函数原型：
//struct tm* gmtime(const time_t* timer);
//	将日历时间转化为世界标准时间（即格林尼治时间），并返回一个tm 结构体来保存这个时间
//	struct tm* localtime(const time_t* timer);
//	localtime()函数是将日历时间转化为本地时间。
//
//#ifndef _TM_DEFINED
//	struct tm {
//	int tm_sec; /* 秒 – 取值区间为[0,59] */
//		int tm_min; /* 分 取值区间为[0,59] */
//		int tm_hour; /* 时 取值区间为[0,23] */
//		int tm_mday; /* 一个月中的日期 取值区间为[1,31] */
//		int tm_mon; /* 月份（从一月开始，0代表一月） 区间为[0,11] */
//		int tm_year; /* 年份，其值等于实际年份减去1900 */
//		int tm_wday; /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，类推 */
//		int tm_yday; /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，类推*/
//		int tm_isdst; /* 夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。*/
//};
//#define _TM_DEFINED
//#endif

//使用strftime（）函数将时间格式化为想要的格式
//size_t strftime(char* strDest, size_t maxsize,
//	const char* format, 
//	const struct tm* timeptr);
//根据format指向字符串中格式命令把timeptr中保存的时间信息放在strDest指向的字符串中，
//最多向strDest中存放maxsize个字符。该函数返回向strDest指向的字符串中放置的字符数。
//函数strftime()的操作类似sprintf()：识别以百分号(%)开始的格式命令集合，格式化输出
//结果放在一个字符串中。格式化命令说明串strDest中各种日期和时间信息的确切表示方法。格式串中的其他字符原样放进串中。格式命令如下，它们是区分大小写的。
//% a 星期几的简写
//% A 星期几的全称
//% b 月分的简写
//% B 月份的全称
//% c 标准的日期的时间串
//% C 年份的后两位数字
//% d 十进制表示的每月的第几天
//% D 月 / 天 / 年
//% e 在两字符域中，十进制表示的每月的第几天
//% F 年 - 月 - 日
//% g 年份的后两位数字，使用基于周的年
//% G 年分，使用基于周的年
//% h 简写的月份名
//% H 24小时制的小时
//% I 12小时制的小时
//% j 十进制表示的每年的第几天
//% m 十进制表示的月份
//% M 十时制表示的分钟数
//% n 新行符
//% p 本地的AM或PM的等价显示
//% r 12小时的时间
//% R 显示小时和分钟：hh : mm
//% S 十进制的秒数
//% t 水平制表符
//% T 显示时分秒：hh : mm:ss
//% u 每周的第几天，星期一为第一天 （值从0到6，星期一为0）
//% U 第年的第几周，把星期日做为第一天（值从0到53）
//% V 每年的第几周，使用基于周的年
//% w 十进制表示的星期几（值从0到6，星期天为0）
//% W 每年的第几周，把星期一做为第一天（值从0到53）
//% x 标准的日期串
//% X 标准的时间串
//% y 不带世纪的十进制年份（值从0到99）
//% Y 带世纪部分的十制年份
//% z， % Z 时区名称，如果不能得到时区名称则返回空字符。
//% %百分号
// strftime(pBuf, 20, "%Y-%m-%d %H:%M",timeinfo);
// 
// 
//sscanf(pTime, "%d-%d-%d %d:%d",&tm1.tm_year, &tm1.tm_mon, 
//& tm1.tm_mday, & tm1.tm_hour, & tm1.tm_min);
//sscanf() - 从一个字符串中读进与指定格式相符的数据
//int sscanf(string str, string fmt, mixed var1, mixed var2 ...)
//int scanf(const char* format[, argument]...)
//sscanf与scanf类似，都是用于输入，只是后者以标准输
//入(stdin)为输入源，前者以固定字符串为输入源。

//time_t stringToTime(char* pTime)
//{
//	struct tm tm1;
//	time_t time1;
//	sscanf(pTime, "%d-%d-%d %d:%d", &tm1.tm_year, &tm1.tm_mon,
//		&tm1.tm_mday, &tm1.tm_hour, &tm1.tm_min);
//	tm1.tm_year -= 1900;  // 年份为从1900年开始
//	tm1.tm_mon -= 1;      // 月份为0~11
//	tm1.tm_sec = 0;
//	tm1.tm_isdst = -1;
//	time1 = mktime(&tm1);
//	return time1;
//}