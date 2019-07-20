#include<stdio.h>
#include<string.h>

int day_of_month[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

int year_lun(int a)   //判断年份是不是闰年
{
	int x;
	if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0))
	{
		x = 0;
	}else{
		x = 1;
	}
	return x;
}

int max(int n,int month, int day)
{
	int sum,leap;
	switch(month)/*先计算某月以前月份的总天数*/
	{
	case 1 :sum=0  ;break;
	case 2 :sum=31 ;break;
	case 3 :sum=59 ;break;
	case 4 :sum=90 ;break;
	case 5 :sum=120;break;
	case 6 :sum=151;break;
	case 7 :sum=181;break;
	case 8 :sum=212;break;
	case 9 :sum=243;break;
	case 10:sum=273;break;
	case 11:sum=304;break;
	case 12:sum=334;break;
	default:printf("data error");break;
	}
	sum=sum+day; /*再加上某天的天数*/
	if(n == 0)/*判断是不是闰年*/
		leap = 1;
	else
		leap = 0;
	if(leap == 1 && month > 2)/*如果是闰年且月份大于2,总天数应该加一天*/
		sum++;
	return sum;

}

int weeks(int y, int m, int d)
{
	int x,w;
	if (m <= 2)
	{
		y = y - 1;
		m = m + 12;
	}
	x = (d + 2*m + 3*(m+1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
	return x; 
}

void print_year_month (int y,int m,int d,int n)
{
	int x ,first_week;
	if (n == 0)
	{
		day_of_month[1] = 29;
	}
	else day_of_month[1] = 28;
	day_of_month[0] = 31;
	day_of_month[2] = 31;
	day_of_month[3] = 30;
	day_of_month[4] = 31;
	day_of_month[5] = 30;
	day_of_month[6] = 31;
	day_of_month[7] = 31;
	day_of_month[8] = 30;
	day_of_month[9] = 31;
	day_of_month[10] = 30;
	day_of_month[11] = 31;
	first_week = weeks(y,m,1);
	printf ("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	for (x = 1;x <= first_week;x++)
	{
		printf("\t");
		if (x % 7 == 0) printf ("\n");
	}
	for (d = 1;d <= day_of_month[m-1];d++)
	{
		printf("%d\t",d);
		if (x % 7 == 0) printf ("\n");
		x++;
	}
	printf("\n");
}
int main(int argc, const char *argv[])
{
	int year, month, day;
	year = month = day = 0;
	printf("please input year month and day:");
	scanf("%d%d%d",&year,&month,&day);
	int n = year_lun(year);//用n接收返回值判断year是不是闰年

	if(n == 0)
	{
		printf("%d年%d月%d日是闰年\n",year,month,day);
	}else if(n == 1){
		printf("%d年%d月%d日不是闰年\n",year,month,day);
	}

	int days = max(n,month,day); // 用days表示day是year的第几天
	printf("%d年%d月%d日是%d年的第%d天\n",year,month,day,year,days);

	int week = weeks(year,month,day);
	printf("%d月%d日星期%d\n",month,day,week);

	print_year_month (year,month,day,n);   //调用展示月日历函数

	getchar();
	return 0;   
}
