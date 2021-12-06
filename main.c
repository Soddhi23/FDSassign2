#include <stdio.h>
#include <string.h>
int n;
struct sc
{
	char name[100];
	int age;
	char country[100];
	char category[100];
	int odi;
	int t20;
	float avg_bat;
	int wickets;
};


void sortplayers(struct sc ar[]);
void n_country(struct sc ar[]);
void h_avg(struct sc ar[]);
void bowl_country(struct sc ar[]);
void maxwickets(struct sc ar[]);

int main(void) 
{
	printf("Enter no of players to take data of: \n");
	scanf("%d", &n);
	struct sc ar[n];
	for (int i = 0; i < n; i++) 
  {
		printf("Enter Name of Player %d: \n", i + 1);
		scanf("%s", ar[i].name);
		printf("Enter  age: \n");
		scanf("%d", &ar[i].age);
		printf("Enter  country: \n");
		scanf("%s", ar[i].country);
		printf("Enter  style of play, 'batsman','bowler','wk','all rounder\n");
		scanf("%s", ar[i].category);
		printf("Enter no of odis played: \n");
		scanf("%d", &ar[i].odi);
		printf("Enter no of T20Is played: \n");
		scanf("%d", &ar[i].t20);
		printf("Enter batting average: \n");
		scanf("%f", &ar[i].avg_bat);
		printf("Enter no of wickets taken: \n");
		scanf("%d", &ar[i].wickets);
	}
   printf("\n\n");
	int c = 0;
	for (;;) 
  {
		printf("1.Find players from a particular country\n");
		printf("2.Find player with highest batting avg\n");
		printf("3.Find Bowlers from a particular country\n");
		printf("4.Find player with Maximum Wickets\n");
    printf("5.To sort the batsman acc to their batting avg\n");
		printf("6.To close the software\n");
		printf("Enter your choice\n");
		scanf("%d", &c);

		switch (c) 

    {
		case 1:
			n_country(ar);
			break;
		case 2:
			h_avg(ar);
			break;
		case 3:
			bowl_country(ar);
			break;
		case 4:
			maxwickets(ar);
			break;
      case 5:
      sortplayers(ar);
      break;
		case 6:
			goto label;
			break;
		default:
			printf("Invalid input try again\n");
		}
	}

label:
	return 0;
}
void n_country(struct sc ar[]) 
{
	char ch[100];
	printf("Enter the country to display its players\n");
	scanf("%s", ch);
	printf("Players playing for %s country are\n", ch);
	for (int i = 0; i < n; i++) 
  {
		if (strcmp(ch, ar[i].country) == 0)
			printf("%s\n", ar[i].name);
	}
}
void h_avg(struct sc ar[]) 
{
	float cont = ar[0].avg_bat;
	int c;
	for (int i = 0; i < n; i++) 
  {
		if (ar[i].avg_bat > cont) 
    {
			cont = ar[i].avg_bat;
			c = i;
		}
	}
	printf("Player with highest batting avg is %s with avg %.2f\n",ar[c].name, cont);
}
void bowl_country(struct sc arr[]) 
{
	char ch[100];
	printf("Enter Country\n");
	scanf("%s", ch);
	printf("Bowlers from %s are\n", ch);
	for (int i = 0; i < n; i++) 
  {
		if ((strcmp(ch, arr[i].country) == 0) &&
			strcmp(arr[i].category, "bowler") == 0)
			printf("%s\n", arr[i].name);
	}
}
void maxwickets(struct sc ar[]) 
{
	int cont = ar[0].wickets;
	int c = 0;
	for (int i = 0; i < n; i++) 
  {
		if (ar[i].wickets > cont)
     {
			cont = ar[i].wickets;
			c = i;
		}
	}
	printf("Players with most wickets is %s with wickets %d\n", ar[c].name, cont);
}


void sortplayers(struct sc ar[])
{
 int  min_idx;
 
   char temp[100];
   float tem=0;
    for (int i = 0; i < n-1; i++)
    {
     min_idx = i;
     for (int j = i+1; j < n; j++)
     if (ar[j].avg_bat > ar[min_idx].avg_bat)
     min_idx = j;


tem=ar[min_idx].avg_bat;
ar[min_idx].avg_bat=ar[i].avg_bat;
ar[i].avg_bat=tem;
  strcpy(temp, ar[min_idx].name);
  strcpy(ar[min_idx].name,ar[i].name);
  strcpy(ar[i].name,temp);
}
    printf("Name\tAvg\n");
    for(int i=0;i<n;i++)
    {
      printf("%s\t%.2f\n",ar[i].name,ar[i].avg_bat);
    }
}
 
