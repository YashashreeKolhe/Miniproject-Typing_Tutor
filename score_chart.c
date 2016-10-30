/*****************************************************************************
 * Copyright (C) Yashashree V.K. yashashreekolhe@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include"dummy.h"

typedef struct data{
	char arr[16];
	double gross;
	double net;
	double accuracy;
	char mon[4];
	char day[4];
	int  date;
	char time[20];
	int year;
}data;

void sort(data *d[], int size){
	data temp;
	int i = 0, j = 0;
	for(i = 0;i<size;i++){
		for(j = 0; j<i; j++){
			if(((d[i]->gross)*1000000) < ((d[j]->gross)*1000000)){
				temp = *d[i];
				*d[i] = *d[j];
				*d[j] = temp;
			}
		}
	}	
} 

void score_chart(WINDOW *subwin){
	FILE *fp;
	char ch;
	data *d[50];
	char arr[20];
	int i, j, k;
	initscr();
	raw();
	noecho();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	mvwprintw(subwin, 0, 0, "Press 'q' to go back to to main menu..");
	fp = fopen("score_record.txt", "r");
	wmove(subwin, 5, 0);
	i = 0;
	while(!feof(fp)){
		d[i] = (data *)malloc(sizeof(data));
		fscanf(fp, "%s", arr);
		strcpy(d[i]->arr, arr);
		fscanf(fp, "%c", &ch);
		fscanf(fp, "%s", arr);
		d[i]->gross = atof(arr);
		fscanf(fp, "%c", &ch);
		fscanf(fp, "%s", arr);
		d[i]->net = atof(arr);
		fscanf(fp, "%c", &ch);
		fscanf(fp, "%s", arr);
		d[i]->accuracy = atof(arr);
		fscanf(fp, "%c", &ch);
		fscanf(fp, "%s", arr);
		strcpy(d[i]->mon, arr);
		fscanf(fp, "%c", &ch);
		fscanf(fp, "%s", arr);
		strcpy(d[i]->day, arr);
		fscanf(fp, "%c", &ch);
		fscanf(fp, "%s", arr);
		d[i]->date = atoi(arr);
		fscanf(fp, "%c", &ch);
		fscanf(fp, "%s", arr);
		strcpy(d[i]->time, arr);
		fscanf(fp, "%c", &ch);
		fscanf(fp, "%s", arr);
		d[i]->year = atoi(arr);
		i++;
	}	
	fclose(fp);
	sort(d, i);
	mvwprintw(subwin,3, 0,  "Name	       Gross Speed      Net Speed    Accuracy  Month  Day  Date   Time    Year\n");
	wattroff(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	wmove(subwin, 5, 0);
	for(j = 0; j<(i-1);j++){
		wprintw(subwin, "%s", d[j]->arr);
		for(k = 0; k<(16-strlen(d[j]->arr));k++)
			wprintw(subwin, " ");
		if(d[j]->date >= 10) {
			if((int)d[j]->gross >= 10) {
				if((int)d[j]->accuracy == 100)
					wprintw(subwin, "| %lf | %lf | %lf | %s | %s | %d | %s | %d\n", d[j]->gross, d[j]->net, d[j]->accuracy, d[j]->mon, d[j]->day, d[j]->date, d[j]->time, d[j]->year);
				else
					wprintw(subwin, "| %lf | %lf | %lf  | %s | %s | %d | %s | %d\n", d[j]->gross, d[j]->net, d[j]->accuracy, d[j]->mon, d[j]->day, d[j]->date, d[j]->time, d[j]->year);
			}
			if((int)d[j]->gross < 10) {
				if((int)d[j]->accuracy == 100)
					wprintw(subwin, "| %lf  | %lf  | %lf | %s | %s | %d | %s | %d\n", d[j]->gross, d[j]->net, d[j]->accuracy, d[j]->mon, d[j]->day, d[j]->date, d[j]->time, d[j]->year);	
				else
					wprintw(subwin, "| %lf  | %lf  | %lf  | %s | %s | %d | %s | %d\n", d[j]->gross, d[j]->net, d[j]->accuracy, d[j]->mon, d[j]->day, d[j]->date, d[j]->time, d[j]->year);
			}	
		}
		else {
			if((int)d[j]->gross >= 10) {
				if((int)d[j]->accuracy == 100)
					wprintw(subwin, "| %lf | %lf | %lf | %s | %s | %d  | %s | %d\n", d[j]->gross, d[j]->net, d[j]->accuracy, d[j]->mon, d[j]->day, d[j]->date, d[j]->time, d[j]->year);	
				else
					wprintw(subwin, "| %lf | %lf | %lf  | %s | %s | %d  | %s | %d\n", d[j]->gross, d[j]->net, d[j]->accuracy, d[j]->mon, d[j]->day, d[j]->date, d[j]->time, d[j]->year);
			}
			if((int)d[j]->gross < 10) {
				if((int)d[j]->accuracy == 100)
					wprintw(subwin, "| %lf  | %lf  | %lf | %s | %s | %d  | %s | %d\n", d[j]->gross, d[j]->net, d[j]->accuracy, d[j]->mon, d[j]->day, d[j]->date, d[j]->time, d[j]->year);
				else
					wprintw(subwin, "| %lf  | %lf  | %lf  | %s | %s | %d  | %s | %d\n", d[j]->gross, d[j]->net, d[j]->accuracy, d[j]->mon, d[j]->day, d[j]->date, d[j]->time, d[j]->year);
			}
		}	
	}			
}
