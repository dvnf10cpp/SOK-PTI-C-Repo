#include <stdio.h>
#include <string.h>

int main()
{
	int n, AT[100], b[100], i, j, tmp, WT[100], TAT[100], time[100];
	int TotWT=0,TotTA=0;
	float AvWT,AvTA;
	char name[20][20], tmpName[20];
	
	printf("\t Algoritma CPU Scheduling FCFS \n");
	puts("");
	printf("Jumlah proses\t= "); scanf("%d", &n);
	puts("");
	
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("Nama Proses\t= ");scanf("%s", name[i]);
		printf("Arrival Time\t= ");scanf("%d", &AT[i]);
		printf("Burst Time\t= ");scanf("%d", &b[i]);
		puts("");
	}
	
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(AT[i]>AT[j])
			{
				strcpy(tmpName, name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],tmpName);
				
				tmp=AT[i];
				AT[i]=AT[j];
				AT[j]=tmp;
				
				tmp=b[i];
				b[i]=b[j];
				b[j]=tmp;
			}
		}
	}
	
	time[0]=AT[0];
	
	puts("\n\t Tabel Proses ");
	puts("===========================================");
	printf("| No | Proses\t | time arrival\t | burst |\n");
	puts("-------------------------------------------");
	
	for(i=0;i<n;i++)
	{
		printf("| %2d | %s\t | \t%d\t | %d\t |\n", i+1, name[i], AT[i], b[i]);
		time [i+1]=time[i]+b[i];
		WT[i]=time[i]-AT[i];
		TAT[i]=time[i+1]-AT[i];
		TotWT+=WT[i];
		TotTA+=TAT[i];
	}
	
	puts("===========================================");
	printf("\tTotal Waiting Time\t= %d \n", TotWT);
	printf("\tTurn Around Time\t= %d \n", TotTA);
	puts("\n\t Tabel Waktu Proses ");
	puts("===========================================");
	printf("| No | Proses\t | Waiting Time\t | Turn Around\t |\n");
	puts("-------------------------------------------");
	
	for(i=0;i<n;i++)
	{
		printf("| %2d | %s\t | \t%d\t | \t%d\t |\n", i+1, name[i], WT[i], TAT[i]);
	}
	
	puts("===========================================");
	
	puts("\n");
	puts("\t Gant-Chart \n");
	for(i=0; i<n; i++)
	{
		printf(" %s\t ", name[i]);
	}
	
	puts("\n");
	for(i=0; i<n; i++)
	{
		printf("=========");
	}
	
	puts("\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t ", time[i]);
	}
	
	printf("//diperoleh dari penjumlahan Burst");
	puts("\n");
	AvWT=(float)TotWT/n;
	AvTA=(float)TotTA/n;
	printf("\tAverage Waiting Time : %f\n", AvWT);
	printf("\tAverage Turn Around Time : %f\n", AvTA);

}