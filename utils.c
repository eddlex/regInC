#include "libft.h"

int		ft_strlen(char *arr)
{
	int i = 0;
	while (arr[i] != '\0')
		i++;
	i--;
	return i;
}
int		xTrueY(char *x, char *y)
{
	int i = 0;
	if(ft_strlen(x) == ft_strlen(y))
		while(x[i] != '\0')
		{
			if(x[i] != y[i])
				return 0;
			i++;
		}
	else
		return 0;
	return 1;
}
int		ft_strcpy(char *arr, char *flag)
{
	char string[40];
	char *nw;
	printf("%s", flag);
	if (xTrueY(flag , "city: ") )
	{
		nw = cityTrue("database/cityEn.txt");
		if (xTrueY(nw, "NULL"))
		{
			printf("City error!\n");
			return 0;
		}
		else
		{
			int i = 0;
			while (nw[i] != '\0')
			{
				string[i] = nw[i];
				i++;
			}
			string[i] = '\0';
		}
		free(nw);
	}
	if (xTrueY(flag , "village: ") )
	{
		nw = cityTrue("database/villageEn.txt");
		if (xTrueY(nw, "NULL"))
		{
			printf("\nvillage error!\n");
			return 0;
		}
		else
		{
			int i = 0;
			while (nw[i] != '\0')
			{
				string[i] = nw[i];
				i++;
			}
			string[i] = '\0';
			free(nw);
		}
	}
	if(xTrueY(flag , "village: ") == 0 && xTrueY(flag , "city: ") == 0  && xTrueY(flag , "name: ") == 0 && xTrueY(flag , "surname: ") == 0 && xTrueY(flag , "fatherName: ") == 0 )
	{
		int i = 0;
		scanf("%c", &string[i]);
		i++;
		int sum = 1;
		while (i < 40)
		{
			scanf("%c", &string[i]);
			if (string[i] >= 'A' && string[i] <= 'Z' ||  string[i] >= 'a' && string[i] <= 'z' ||  string[i] >= '0' && string[i] <= '9'  )
				sum++;
			if (string[i] == '\n'  && sum > 0)
				break;
			i++;
		}
		string[i] = '\0';
		strChange(string);
	}
	if(xTrueY(flag , "name: ") == 1  || xTrueY(flag , "surname: ") == 1 || xTrueY(flag , "fatherName: ") == 1 )
	{
		int p = 0;
		int sum = 0;
		while(p < 20)
		{
			scanf("%c", &string[p]);
			if(string[p] == '\n' && sum >= 3)
				break;
			if(string[p] >= 'A' && string[p] <= 'Z' ||  string[p] >= 'a' && string[p] <= 'z' )
				sum++;
			p++;
		}
		string[p] = '\0';
		strChange(string);
		p = 0;
		while (string[p] != '\0')
		{
			if(string[p] == ' ')
			{
				string[p] = '\0';
				break;
			}
			p++;
		}
		if(string[1] >= 'A' && string[1] <= 'Z')
			string[1] +=32;

		p = 0;
		while (string[p] != '\0')
		{
			if(string[p] >= 'A' && string[p] <= 'Z' ||  string[p] >= 'a' && string[p] <= 'z' ){}
			else
			{
				printf("Error %s\n", flag);
				return 0;
			}
			p++;
		}
	}
	int i  = 0;
	while (string[i] != '\0')
	{
		arr[i] = string[i];
		i++;
	}
	arr[i] = '\0';
	return 1;
}
void	nameInfoPush(char *name, char *surname, char *fatherName)
{
	int x;
x:
	x = ft_strcpy(name, "name: ");
	if(x == 0) goto x;
y:
	x= ft_strcpy(surname, "surname: ");
	if(x == 0) goto y;
z:
	 x = ft_strcpy(fatherName, "fatherName: ");
	if(x == 0) goto z;
}
void	strChange(char *arr)
{
	int i = 0;
	char buf[50];
	int len = 0;
	while (arr[i] != '\0')
	{
		int count = 0;
		if( arr[i] == ' ' )
		{
			while (arr[i] != '\0' && arr[i] == ' ' )
			{
				count++;
				i++;
			}
			if(count >= 1 )
			{
				buf[len] = ' ';
				len++;
			}
		}
		if(arr[i] != ' '  &&  arr[i] != '\n')
		{
			buf[len] = arr[i];
			len++;
		}
		i++;
	}
	buf[len] = '\0';
	i = 1;
	int b = 0;
	while (buf[i-1] != '\0')
	{
		if(buf[i] == ' '  && buf[i+1] >= 'a' &&   buf[i+1] <= 'z')
			buf[i+1] -=32;
		if(buf[i] != ' '  && buf[i+1] >= 'A' &&   buf[i+1] <= 'Z')
			buf[i+1] +=32;
		i++;
	}
	buf[i] = '\0';
	i = 0;
	int l  = ft_strlen(buf) + 1;
	if( buf[0] == ' ')
		i = 1;
	if (buf[ft_strlen(buf)] == ' ')
		l -= 1;
	while (i <  l)
	{
		arr[b] = buf[i];
		b++;
		i++;
	}
	if(arr[0] >= 'a' && arr[0] <= 'z')
		arr[0] -=32;
	arr[b] = '\0';
}
char 	*cityTrue(char *arr)
{
	char *city = (char *) malloc(40 * sizeof(char));
	int i = 0;
	int sum = 1;
	scanf("%c", &city[i]);
	i++;
	while(i < 40)
	{
		scanf("%c", &city[i]);
		if(city[i] >= 'A' && city[i] <= 'Z' ||  city[i] >= 'a' && city[i] <= 'z' )
			sum++;
		if(city[i] == '\n' && sum > 2)
			break;
		i++;
	}
	city[i] = '\0';
	strChange(city);
	city[ft_strlen(city) + 1] = '\0';
	if(city[1] >= 'A' && city[1] <= 'Z')
		city[1] += 32;
	char buf[40];
	int fd = open(arr, O_RDONLY);
	if (fd == -1)
	{
		printf("fd = -1 error\n");
		return ("NULL");
	}
	else
	{
		int c = 1;
		i = 0;
		char ch;
		while (c != 0)
		{
			c = read(fd, &ch, 1);
			buf[i] = ch;
			if (ch == '\n' || ch == '\t' || ch == '\f' || ch == '\v')
			{
				buf[i] = '\0';
				if (xTrueY(buf, city))
					return city;
				i = -1;
			}
			i++;
		}
	}
	close(fd);
	return "NULL";
}
int 	home(char *house, char *home)
{
	int c = OneOrZero();
	if (c == 1)
	{
			ft_strcpy(house, "house: ");
			return 1;
	}

	if (c == 0)
	{
			ft_strcpy(home, "home: ");
			return 1;
	}
	return 0;
}
int  	phone(char *tell, char *path)
{
	char *arr = (char*)malloc(20*sizeof(char));
	int j = 0;
	while (tell[j] != '\0' && tell[j] != ' '  && (tell[j] >= '0' && tell[j] <= '9'))
	{
		arr[j] = tell[j];
		j++;
	}
	arr[j] = '\0';
	if (ft_strlen(arr) == 7)
	{
		char buf[40];
		int fd = open(path, O_RDONLY);
		if (fd == -1)
		{
			printf("fd = -1 error\n");
			return 0;
		}
		else
		{
			int c = 1;
			int i = 0;
			char ch;
			while (c != 0)
			{
				c = read(fd, &ch, 1);
				buf[i] = ch;
				if (ch == '\n' || ch == '\t' || ch == '\f' || ch == '\v')
				{
					buf[i] = '\0';
					if(xTrueY(path, "database/phone.txt"))
					{
						if ((buf[0] == arr[0]) && (buf[1] == arr[1]) && ft_strlen(buf) > 0)
						{
							int k = 0;
							while (arr[k] != '\0')
							{
								tell[k] = arr[k];
								k++;
							}
							tell[k] = '\0';
							return 1;
						}

					}
					if(xTrueY(path, "database/homeTell.txt"))
					{

						if(homeTell(buf, arr) && ft_strlen(buf) > 0)
						{
							int k = 0;
							while (arr[k] != '\0')
							{
								tell[k] = arr[k];
								k++;
							}
							tell[k] = '\0';
							return 1;
						}
					}
					i = -1;
				}
				i++;
			}
		}
		close(fd);
	}
	printf("wrong tell!(try again)\n");
	return 0;
}
int 	homeTell(char *buf, char *tell)
{
	int i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != tell[i])
			return (0);
		i++;
	}
	return 1;
}

char 	*ft_gets()
{

	char *c = (char*)malloc(20 * sizeof(char));
	int p = 0;
	scanf("%c", &c[p]);
	p++;
	while(p < 20)
	{
		scanf("%c", &c[p]);
		if(c[p] == '\n')
			break;
		p++;
	}
	c[p] = '\0';
	return c;
}
int 	OneOrZero()
{

	char arr[20];
	int i = 0;
	while (arr[i] != '\n')
	{
		read(0, &arr[i],1);
		if(arr[i] == '\n')
			break;
		i++;
	}
	arr[i] = '\0';

//	printf("%s-->arr\n", arr);
//	printf("%c-->arr[0]\n", arr[0]);
//	printf("%c-->arr[1]\n", arr[1]);

	if((arr[0] == '1' || arr[0] == '0') && i == 1)
		return atoi(&arr[0]);
	printf("wrong number!(try again): ");
	return 2;
}
int 	theEnd (int day, int month, int year)
{
	switch (month)
	{
		/////////////31///////////
		case 1:
			if(day <= 31)
				return (1); //1,3,5,7,8,10,12
			break;   //32
		case 3:
			if (day <= 31)
				return (1);
			break;
		case 5:
			if (day <= 31)
				return (1);;
			break;
		case 7:
			if (day <= 31)
				return (1);;
			break;
		case 8:
			if (day <= 31)
				return (1);;
			break;
		case 10:
			if (day <= 31)
				return (1);;
			break;
		case 12:
			if (day <= 31)
				return (1);;
			break;

			/////////30/////////
		case 4:
			if(day <= 30)
				return (1);    //4 ,6,9,11
			break;
		case 6:
			if(day <= 30)
				return (1);
			break;
		case 9:
			if(day <= 30)
				return (1);
			break;

		case 11:
			if(day <= 30)
				return (1);
			break;
		case 2:
			if (year >= 400 && year % 400 == 0 && day <= 29  )
				return (1);
			if (year >= 100 && year % 100 == 0)
			{
				if(day == 29)
				{
					printf("wrong format!(day)\n");
					return (0);
				}
				return (1);
			}
			else if (year % 4 == 0  && day <= 29)
				return (1);
			else if(day <= 28)
				return (1);
			break;

	}

	printf("wrong format!(day): ");
	return  0;
}
char 	*dataBirth (char * Data, int j)
{
	char *arr = (char*)malloc(50 * sizeof(char));
	int i = 0;
	while ( Data[i] != '\0' || Data[i] != ' ' )
	{
		if(Data[i] == '.'  || (Data[i] >= '0' && Data[i] <= '9') )
		{
			arr[i] = Data[i];
			i++;
		}
		else
			break;
	}
	arr[i] = '\0';

	i = 0;

	if(ft_strlen(arr) < 6 )
	{
		printf("wrong format!(data): ");
		return ("NULL");
	}
	while (arr[i] != '\0' &&  i < 6)
	{

		if(arr[i] >= '0' && arr[i] <= '9'  &&  arr[i+1] > '0' && arr[i+1] <= '9' && arr[i+2] == '.' )
		{
			if(arr[3] < '0' || arr[3] > '1')
			{
				printf("wrong format!(mon): ");
				return ("NULL");
			}

			if(arr[3] == '1' && arr[4] != '1' && arr[4] != '2')
			{
				printf("wrong format!(mon): ");
				return ("NULL");
			}

			if(arr[0] < '0' || arr[0] > '3')
			{
				printf("wrong format!(day): ");
				return ("NULL");
			}
			else
			{
				if(arr[0] == '3' && arr[1] > '1')
				{
					printf("wrong format(day) :");
					return ("NULL");
				}
			}
		}
		else
		{
			printf("wrong format(data): ");
			return ("NULL");
		}

		i+=3;
	}

	i++;
	while (arr[i] != '\0')
	{
		if(arr[i] == '.')
		{
			printf("wrong format!(year): ");
			return ("NULL");
		}
		if(arr[6] == '0' && arr[i] == '0')
		{
			printf("wrong format!(year): ");
			return ("NULL");
		}
		i++;
	}
	i = 6;
	int p = 0;
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

	if(theEnd(dayInt, monthInt, yearInt) == 0)
		return ("NULL");

	if(j)
	{
		if (yearInt > dmy.year)
		{
			printf("false year: ");
			return ("NULL");
		}

		if (yearInt == dmy.year)
		{
			if (monthInt > dmy.month)
			{
				printf("false month: ");
				return ("NULL");
			}
			if (monthInt == dmy.month)
			{
				if (dayInt > dmy.day)
				{
					printf("false day: ");
					return ("NULL");
				}

			}
		}
	}
	return  arr;
}

