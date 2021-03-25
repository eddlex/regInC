#include "libft.h"

void 	search(struct data Data, char *city, char *searchTell, int age)
{
	int i = 6;
	int p = 0;
	char *arr = Data.data;
	char year[10];
	while (arr[i] != '\0')
	{
		year[p] = arr[i];
		p++;
		i++;
	}
	year[p] = '\0';
	char day[3]  = {arr[0],arr[1]};
	day[2] = '\0';
	char month[3] = {arr[3],arr[4]};
	month[2] = '\0';
	int yearInt = atoi(year);
	int monthInt = atoi(month);
	int dayInt = atoi(day);
	int k = 0;
	if(dmy.month - monthInt < 0)
		k = 1;
	if(dmy.month - monthInt == 0)
		if(dmy.day - dayInt < 0)
			k = 1;
	k = dmy.year - yearInt - k;
	char *tell = Data.tell;
	p = 0;
	while (searchTell[p] != '\0')
	{
		if(searchTell[p] != tell[p])
			break;
		p++;
	}
	p = -1;
	if(xTrueY(Data.city.city, city) && p < 0  &&  k == age  )
     	printf("%s\n", Data.aah.name);
}

void userAdd()
{
	int n ;

	printf("please give me your pc data:)\n");
	printf("Write (1) : Auto (0)\n");
	while (1)
	{
		n = OneOrZero();
		if(n == 1 || n == 0)
			break;
	}
	if(n == 0)
	{
		time_t tme;
		time(&tme);
		struct tm *mytime = localtime(&tme);

		dmy.year= mytime->tm_year + 1900;
		dmy.month = mytime->tm_mon+1;
		dmy.day = mytime->tm_mday;
	}
	else
	{
		char *ptr;
		printf("data(dd.mm.yy): ");
		while (1)
		{
			ptr = ft_gets();
			strChange(ptr);
			ptr = dataBirth(ptr, 0);
			if(xTrueY(ptr, "NULL") != 1)
			{

				printf("%s---ptr\n", ptr);
				char day[3] = {ptr[0], ptr[1]};
				day[2] = '\0';
				char month[3] = {ptr[3], ptr[4]};
				month[2] = '\0';
				char year[10];
				int i = 6;
				int j = 0;
				while (ptr[i] != '\0')
				{
					year[j] = ptr[i];
					j++;
					i++;
				}
				year[j] = '\0';
				free(ptr);
				dmy.year = atoi(year);
				dmy.month = atoi(month);
				dmy.day = atoi(day);
				break;
			}
		}
	}

	printf("*****Your Data in Pc*****\n");
	printf("*******%d/%d/%d*******\n",dmy.day,dmy.month,dmy.year);
	printf("How many user add?: ");
	n = 0;
	while (n <= 0)
	{
		n = atoi(ft_gets());
		if(n > 0)
			break;
		printf("wrong number(try again): ");
	}
	Data man[n];
	int d = 0;

	for(int i = 0 ; i < n ; ++i)
	{
		printf("////////User%d////////\n", ++d);

		///////nameInfo///////
		nameInfoPush(man[i].aah.name, man[i].aah.surname, man[i].aah.fatherName);

		////////////dataBirth////////
		char *y;
		printf("data(format dd.mm.yy): ");
		while (1)
		{
			ft_strcpy(man[i].data, "");
			y = dataBirth(man[i].data, 1);
			if(xTrueY(y, "NULL") != 1)
			{
				strcpy(man[i].data, y);
				free(y);
				break;
			}
		}


		///////////City&&Village/////////
		printf("City(1) or Village(0): ");
		int k;
		while (1)
		{
			k = OneOrZero();
			if(k == 1 || k == 0)
				break;
		}
		if(k)
		{
			int x = 0;
			while(x != 1)
				x = ft_strcpy(man[i].city.city, "city: ");
		}
		else
		{
			int x = 0;
			while (x != 1)
				x = ft_strcpy(man[i].city.village, "village: ");
		}

		/////////////street////////////////
	   ft_strcpy(man[i].street, "street: ");


		//////////house&&home///////////////
		printf("House(1) or Home(0): ");
		while ( home(man[i].livingPlace.house, man[i].livingPlace.home) != 1){}

		///////////phoneTell//////////////
		int x = 0;
		while (x != 1)
		{
			ft_strcpy(man[i].tell, "tell: +374");
			x = phone(man[i].tell, "database/phone.txt");
		}

		/////////homeTell///////////////
		x = 0;
		while (x != 1)
		{
			ft_strcpy(man[i].tellHome, "homeTell: +374");
			x = phone(man[i].tellHome, "database/homeTell.txt");
		}
		search(man[i], "Yerevan", "95" , 20);
	 }

}

int main (void)
{
	userAdd();
	return (0);
}