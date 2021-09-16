#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct note{
	char text[60];
	int year;
	int month;
	int day;
	int hour;
	int minute;
};
int main() {
	FILE *fa=fopen("note.txt","a+");
	struct note n[100],m;
	int i,j,a,count=0,check;
	int year,month,day,hour,minute;
	char text[60];
	while(!eof(fa)){
		fscanf(fa,"%d%d%d%d%d",&n[count].year,&n[count].month,&n[count].day,&n[count].hour,&n[count].minute);
		fscanf(fa,"%s",n[count].text);
		count++;
	}
	fclose(fa);
	while(1){
		printf("1.add  2.edit  3.delete  4.sort  5.report  6.exit\n");
		scanf("%d",&a);
		if(a==1){
			printf("time: ");
			scanf("%d:%d",&hour,&minute);
			printf("date: ");
			scanf("%d/%d/%d",&year,&month,&day);
			printf("text: ");
			scanf("%s",text);
			for(i=0;i<count;i++){
				if(year<n[i].year){
					break;
				}
				if(year==n[i].year){
					if(month<n[i].month){
						break;
					}
					if(month==n[i].month){
						if(day<n[i].day){
							break;
						}
						if(day==n[i].day){
							if(hour<n[i].hour){
								break;
							}
							if(hour==n[i].hour){
								if(minute<n[i].minute){
									break;
								}
							}
						}
					}
				}
			}
			for(j=count;j>i;j--){
				n[j]=n[j-1];
			}
			n[i].year=year;
			n[i].month=month;
			n[i].day=day;
			n[i].hour=hour;
			n[i].minute=minute;
			strcpy(n[i].text,text);
			count++;
		}
		if(a==2){
			printf("time: ");
			scanf("%d:%d",&hour,&minute);
			printf("date: ");
			scanf("%d/%d/%d",&year,&month,&day);
			check=0;
			for(i=0;i<count;i++){
				if(n[i].year==year && n[i].month==month && n[i].day==day && n[i].hour==hour && n[i].minute==minute){
					check=1;
					break;
				}
			}
			if(!check){
				printf("there is no note in this time\n");
			}
			else{
				printf("%s\nnew text: ");
				scanf("%s",n[i].text);
			}
		}
		if(a==3){
			printf("time: ");
			scanf("%d:%d",&hour,&minute);
			printf("date: ");
			scanf("%d/%d/%d",&year,&month,&day);
			check=0;
			for(i=0;i<count;i++){
				if(n[i].year==year && n[i].month==month && n[i].day==day && n[i].hour==hour && n[i].minute==minute){
					check=1;
					break;
				}
			}
			if(!check){
				printf("there is no note in this time\n");
			}
			else{
				for(j=i;j<count;j++){
					n[j]=n[j+1];
				}
				count--;
				n[count].year=n[count].month=n[count].day=n[count].hour=n[count].minute=0;
				n[count].text[0]='\0';
			}
		}
		if(a==4){
			int s;
		    for(j=0;j<count;j++){
		    	s=0;
		    	for(i=0;i<count;i++){
					if(n[i+1].year<n[i].year){
						break;
					}
					if(n[i+1].year==n[i].year){
						if(n[i+1].month<n[i].month){
							s=1;
							break;
						}
						if(n[i+1].month==n[i].month){
							if(n[i+1].day<n[i].day){
								s=1;
								break;
							}
							if(n[i+1].day==n[i].day){
								if(n[i+1].hour<n[i].hour){
									s=1;
									break;
								}
								if(n[i+1].hour==n[i].hour){
									if(n[i+1].minute<n[i].minute){
										s=1;
										break;
									}
								}
							}
						}
					}
				}
				if(s){
					m=n[i]; n[i]=n[i+1]; n[i+1]=m;
				}
			}	
		}
		if(a==5){
			for(i=0;i<count;i++){
				printf("%d/%2d/%2d  %.2d:%.2d  %s\n",n[i].year,n[i].month,n[i].day,n[i].hour,n[i].minute,n[i].text);
			}
		}
		if(a==6){
			break;
		}
		fa=fopen("note.txt","w");
		for(i=0;i<count;i++){
			fprintf(fa,"%d %d %d %d %d\n%s\n",n[i].year,n[i].month,n[i].day,n[i].hour,n[i].minute,n[i].text);
		}
		fclose(fa);
	}
	return 0;
}
