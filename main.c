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
#include <sys/ioctl.h>
#include <signal.h>
#define HEIGHT  10
#define WIDTH 40
int startx;
int starty;
int boolean = 0;

void GetTermSize(int * rows, int * cols) {
	struct winsize ws;
   	if ( ioctl(0, TIOCGWINSZ, &ws) < 0 ) {
       		perror("couldn't get window size");
       		exit(EXIT_FAILURE);
       	}
	*rows = ws.ws_row;
	*cols = ws.ws_col;
}		

int main(int argc, char *argv[]){
	FILE *fp;
	char n;
	int MAX_PATH_LENGTH = 80, i;
	char path[MAX_PATH_LENGTH];
	getcwd(path, MAX_PATH_LENGTH);
	char str[128];
	
	if(argc == 2 && !strcmp(argv[1], "-h")){
		strcpy(str, path);
		strcat(str, "/data/help1.txt");
		fp = fopen(str, "r");
		while(fread(&n, 1, 1, fp)){
				printf("%c", n);
		}
		fclose(fp);
		exit(1);
	}
	if(argc == 2 && !strcmp(argv[1], "-sc")){
		fp = fopen("score_record.txt", "r");
		while(fscanf(fp, "%c", &n) != (-1)){
			printf("%c", n);
		}
		fclose(fp);
		return 0;
	}
	if(argc == 3 && !strcmp(argv[1], "-sc")){
		char s[500];
		int size_word, size_string, i, j, k, flag=0, max;
		size_word = strlen(argv[2]);
	
		fp = fopen("score_record.txt", "r");
		while(fgets(s, 1024, fp) != NULL) {
			size_string = strlen(s);
			max = size_string - size_word + 1;
			for(i = 0; i < max; i++) {
				for(j = i,k=0; j < (i + size_word); j++,k++) {		
					if(s[j] == argv[2][k])
						flag++;
					else 
						flag = 0;
					if(flag == size_word && s[j+1] == ' ' && (s[j-(size_word)-1] == ' ' || (j == size_word-1))) {
						puts(s);
					}
				}
			}
		       
		 }
		 fclose(fp);
		 return 0;
	}
	int choice = 0, ch;
	WINDOW *subwin, *new;
	GetTermSize(&height, &width);
 	wresize(stdscr, height, width);
 	strcpy(str, path);	
	char **learn_alp = (char **)malloc(sizeof(char *)*5);
	for(i = 0; i<5; i++) {
		learn_alp[i] = (char *)malloc(strlen(path) + 30);
		strcpy(learn_alp[i], path);
		if(i == 0)
			strcat(learn_alp[i], "/data/learn_alp");
		if(i == 1)
			strcat(learn_alp[i], "/data/learn_alp_1");
		if(i == 2)
			strcat(learn_alp[i], "/data/learn_alp_3");
		if(i == 3)
			strcat(learn_alp[i], "/data/learn_alp_4");
		if(i == 4)
			strcat(learn_alp[i], "/data/learn_alp_5");
	}		
	char **a = (char **)malloc(sizeof(char *));
	*a = (char *)malloc(sizeof(char)*10);
	strcpy(*a, "./project"); 
	initscr();
	raw();
	noecho();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	starty = (70 - WIDTH)/2;
	startx = (100 - HEIGHT)/2;
	new = newwin(14, 40, starty, startx);
	mvwin(new, ((height/2)-7), (width/2)-20);
	keypad(new, TRUE);
	if(argc == 2) {
		if(!strcmp(argv[1], "-p")){
			choice = 3;
		}
		else if(!strcmp(argv[1], "-sp"))
			choice = 4;
		else if(!strcmp(argv[1], "-n"))
			choice = 5;
		else if(!strcmp(argv[1], "-al"))
			choice = 1;
		else if(!strcmp(argv[1], "-al"))
			choice = 2;
		else if((!strcmp(argv[1], "-s")) || (!strcmp(argv[1], "-q"))){
			beeps = 1;
			subwin = newwin(40, 138, 0, 0);
			wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
			mvwprintw(subwin, 0, 0, "Use 'up' and 'down' arrow keys to run through the options, Press <enter> to select from the choices:");
			wattroff(subwin, COLOR_PAIR(1) | A_BOLD| A_ITALIC);
			wrefresh(subwin);
			choice = main_menu(new);
		}
		else if(!strcmp(argv[1], "-t")){
			timer = 1;
			subwin = newwin(40, 138, 0, 0);
			wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
			mvwprintw(subwin, 0, 0, "Use 'up' and 'down' arrow keys to run through the options, Press <enter> to select from the choices:");
			wattroff(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
			wrefresh(subwin);
			choice = main_menu(new);
		}
	}
	else if(argc == 1) {
		subwin = newwin(40, 138, 0, 0);
		wresize(subwin, height, width);
		wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
		mvwprintw(subwin, 0, 0, "Use 'up' and 'down' arrow keys to run through the options, Press <enter> to select from the choices:");
		wattroff(subwin, COLOR_PAIR(1) | A_BOLD |A_ITALIC);
		wrefresh(subwin);
		choice = main_menu(new);
	}
	
	if(choice == 1){
		for(i = 0; i<5; i++) {
			subwin= newwin(40, 138, 0, 0);
			wresize(subwin, height, width);
			read_from_file(subwin, learn_alp[i]);
			while(1){
				ch = wgetch(subwin);
				if(ch == 'q'){
					wclear(subwin);
					wrefresh(subwin);
					main(1, a);
				}
				if(ch == ' '){
					wclear(subwin);
					wrefresh(subwin);
					break;
				}
			}
		}
		main(1, a);			
	}
	if(choice == 2){
		wrefresh(subwin);
		subwin= newwin(40, 138, 0, 0);
		wresize(subwin, height, width);
		strcpy(str, path);
		strcat(str, "/data/learn_num");
		read_from_file(subwin, str);
		while(1){
			ch = wgetch(subwin);
			if(ch == 'q'){
				wclear(subwin);
				wrefresh(subwin);
				main(1, a);
				break;
			}	
		}
	}
	if(choice == 3){
		practice(subwin);
		while(1){
			ch = wgetch(subwin);
			wrefresh(subwin);
			if(ch == 'q'){
				wclear(subwin);
				wrefresh(subwin);
				main(1, a);
				break;
			}
		}
	}
	if(choice == 4){
		speed(subwin);
		while(1){
			ch = wgetch(subwin);
			wrefresh(subwin);
			if(ch == 'q'){
				wclear(subwin);
				wrefresh(subwin);
				main(1, a);
			}
		}
	
	}
	if(choice == 5){
		num_drill(subwin);
		while(1){
			ch = wgetch(subwin);
			wrefresh(subwin);
			if(ch == 'q'){
				wclear(subwin);
				wrefresh(subwin);
				main(1, a);
			}
		}
	
	}
	if(choice == 6){
		subwin = newwin(40, 138, 0, 0);
		wresize(subwin, height, width);
		score_chart(subwin);
		while(1){
			ch = wgetch(subwin);
			wrefresh(subwin);
			if(ch == 'q'){
				wclear(subwin);
				wrefresh(subwin);
				main(1, a);
			}
		}
		
	}
	if(choice == 7){
		subwin= newwin(40, 138, 0, 0);
		wresize(subwin, height, width);
		strcat(str, "/data/about");
		read_from_file(subwin, str);
		while(1){
			ch = wgetch(subwin);
			if(ch == 'q'){
				wclear(subwin);
				wrefresh(subwin);
				main(1, a);
				break;
			}
		}
	}
	
	if(choice == 8){
		subwin = newwin(40, 138, 0, 0);
		wresize(subwin, height, width);
		strcat(str, "/data/help");
		read_from_file(subwin, str);
		while(1){
			ch = wgetch(subwin);
			if(ch == 'q'){
				wclear(subwin);
				wrefresh(subwin);
				main(1, a);
				break;
			}
			if(ch == ' '){
				wclear(subwin);
				wrefresh(subwin);
				strcpy(str, path);
				strcat(str, "/data/help2");
				read_from_file(subwin, str);
				while(1){
			 		ch = wgetch(subwin);
					if(ch == 'q'){
						wclear(subwin);
						wrefresh(subwin);
						main(1, a);
						break;
					}
				}
			}
		}
	}
	if(choice == 9){
		subwin = newwin(40, 138, 0, 0);
		wresize(subwin, height, width);
		wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
		mvwprintw(subwin, 0, 0, "Are you sure you want to exit (y/n):");
		wrefresh(subwin);
		ch = wgetch(subwin);
		if(ch == 'y'){
			wprintw(subwin, "%c", ch);
			wattroff(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
			wrefresh(subwin);
		        endwin();
			exit(1);
		}
		else{
			wprintw(subwin, "%c", ch);
			wattroff(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
			wrefresh(subwin);
			wclear(subwin);
			wrefresh(subwin);
			main(1, a);
		}
	}
		
	return 0;
}
void printmenu(WINDOW *menu_win,int n, int highlight, char *choices[])
{
	int x, y, i;	

	x = 2;
	y = 2;
	if(n==9)
		box(menu_win, 0, 0);
	for(i = 0; i < n; ++i)
	{	if(highlight == i + 1)
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

void read_from_file(WINDOW *subwin, char *s){
		FILE *fp;
		char ch1;
		wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
		mvwprintw(subwin,0, 0, "Press 'q' to go to main menu or press 'SPACE' to go to next page:");
		wattroff(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
		wrefresh(subwin);
		fp = fopen(s, "r");
		wmove(subwin, 3, 0);
		while(!feof(fp)){
			fscanf(fp, "%c", &ch1);
			wprintw(subwin,"%c", ch1);
		}
		wrefresh(subwin);
		fclose(fp);
}

int main_menu(WINDOW *new){
	int highlight = 1, r = 0;
	int ch;
	char *choices[] = {"learn alphabets typing","learn numeric typing", "Practice Typing", "Go for a speed test", "Go for a numeric drill", "Score Chart", "About", "Help...", "Exit"};
	
	printmenu(new, 9, highlight, choices);
	while(1){
		ch = wgetch(new);
		switch(ch){
			case KEY_UP:
				if(highlight == 1)
					highlight = 9;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == 9)
					highlight = 1;
				else
				  	++highlight;
				 break;
			case 10:
				r = highlight;
				break;
			default:
				//mvprintw(28, 0, "Use only 'up' and 'down' arrow keys to access the options: ");
				wrefresh(new);
			break;
		}
		printmenu(new, 9, highlight, choices);
		if(r != 0)
			break;
	}
	wclear(new);
	wrefresh(new);
	return r;
}
void pointers(char **files, char **files2, char **files3, char *path) {
	int i;
	for(i = 0; i<5; i++){
		strcpy(files[i], path);
		if(i == 0)
			strcat(files[i], "/data/easy_text1");
		if(i == 1)
			strcat(files[i], "/data/easy_text2");
		if(i == 2)
			strcat(files[i], "/data/easy_text3");
		if(i == 3)
			strcat(files[i], "/data/easy_text4");
		if(i == 4)
			strcat(files[i], "/data/easy_text5");
	}
	for(i = 0; i<5; i++){
		strcpy(files2[i], path);
		if(i == 0)
			strcat(files2[i], "/data/medium_text1");
		if(i == 1)
			strcat(files2[i], "/data/medium_text2");
		if(i == 2)
			strcat(files2[i], "/data/medium_text3");
		if(i == 3)
			strcat(files2[i], "/data/medium_text4");
		if(i == 4)
			strcat(files2[i], "/data/medium_text5");
	}
	for(i = 0; i<5; i++){
		strcpy(files3[i], path);
		if(i == 0)
			strcat(files3[i], "/data/difficult_text1");
		if(i == 1)
			strcat(files3[i], "/data/difficult_text2");
		if(i == 2)
			strcat(files3[i], "/data/difficult_text3");
		if(i == 3)
			strcat(files3[i], "/data/difficult_text4");
		if(i == 4)
			strcat(files3[i], "/data/difficult_text5");
	}
}

void pointers2(char **files, char **files2, char **files3, char *path) {
	int i;
	for(i = 0; i<5; i++){
		strcpy(files[i], path);
		if(i == 0)
			strcat(files[i], "/data/easy_speed1");
		if(i == 1)
			strcat(files[i], "/data/easy_speed2");
		if(i == 2)
			strcat(files[i], "/data/easy_speed3");
		if(i == 3)
			strcat(files[i], "/data/easy_speed4");
		if(i == 4)
			strcat(files[i], "/data/easy_speed5");
	}
	for(i = 0; i<5; i++){
		strcpy(files2[i], path);
		if(i == 0)
			strcat(files2[i], "/data/medium_speed1");
		if(i == 1)
			strcat(files2[i], "/data/medium_speed2");
		if(i == 2)
			strcat(files2[i], "/data/medium_speed3");
		if(i == 3)
			strcat(files2[i], "/data/medium_speed4");
		if(i == 4)
			strcat(files2[i], "/data/medium_speed5");
	}
	for(i = 0; i<5; i++){
		strcpy(files3[i], path);
		if(i == 0)
			strcat(files3[i], "/data/difficult_speed1");
		if(i == 1)
			strcat(files3[i], "/data/difficult_speed2");
		if(i == 2)
			strcat(files3[i], "/data/difficult_speed3");
		if(i == 3)
			strcat(files3[i], "/data/difficult_speed4");
		if(i == 4)
			strcat(files3[i], "/data/difficult_speed5");
	}
}

