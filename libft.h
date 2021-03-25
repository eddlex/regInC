#ifndef HOME_MAIN_LIBFT_H
# define HOME_MAIN_LIBFT_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <io.h>
#include <time.h>


typedef struct
{
	char name[20];
	char surname[20];
	char fatherName[20];
}nameInfo;

typedef union
{
	char city[20];
	char village[20];
}add;

typedef union
{
	char house[30];
	char home[30];
}livingRoom;

struct data
{
	nameInfo aah;
	char data[20];
	add city;
	char street[30];
	livingRoom livingPlace;
	char tell[20];
	char tellHome[20];
};

typedef struct
{
	int year;
	int month;
	int day;
}intOrString;

intOrString dmy;
typedef struct data Data;
int		ft_strlen(char *arr);
int 	xTrueY(char * x, char * y);
char	*cityTrue();
int		ft_strcpy(char *arr, char *flag);
void	strChange(char *arr);
char	*villageTrue(char *arr);
int 	home(char *house, char *home);
void 	nameInfoPush(char *name,char *surname, char *fatherName);
char 	*ft_gets();
int  	phone(char *tell, char *path);
int 	homeTell(char *buf, char *tell);
int		OneOrZero();

int 	theEnd (int day, int month, int year);
char 	*dataBirth (char * Data, int j);
#endif
