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
#include<ncurses.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

void choicen(WINDOW *subwin, char *str, WINDOW *incwin, int boolean) {
	int ch;
	wclear(incwin);
	wrefresh(incwin);
	wclear(subwin);
	wrefresh(subwin);	
	num_test(subwin, str, boolean);
	mvwprintw(subwin, 0, 0, "Press ESC to go back to previous menu or Press 'E' to Exit from the tutor......");
	wrefresh(subwin);
	while(1){
		ch = wgetch(subwin);
		if(ch == 27){
			wclear(subwin);
			wrefresh(subwin);
			num_drill(subwin);
		}
		else if(ch == 69){
			endwin();
			exit(1);
		}
	}	
}
void num_drill(WINDOW *subwin){
	WINDOW *incwin, *regwin;
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	int choice = 0;
	int ch;
	int boolean = 0;
	int MAX_PATH_LENGTH = 80, i;
	char path[MAX_PATH_LENGTH];
	getcwd(path, MAX_PATH_LENGTH);
	char **files = (char **)malloc(sizeof(char *)*5);
	for(i = 0; i<5; i++){
		files[i] = (char *)malloc(strlen(path)+25);
		strcpy(files[i], path);
		if(i == 0)
			strcat(files[i], "/data/num_1");
		if(i == 1)
			strcat(files[i], "/data/num_2");
		if(i == 2)
			strcat(files[i], "/data/num_3");
		if(i == 3)
			strcat(files[i], "/data/num_4");
		if(i == 4)
			strcat(files[i], "/data/num_5");
	}
	char **a = (char **)malloc(sizeof(char *));
	*a = (char *)malloc(sizeof(char)*10);
	strcpy(*a, "./project"); 
	char *choices[] = {"Numeric Drill 1", "Numeric Drill 2", "Numeric Drill 3", "Numeric Drill 4", "Numeric Drill 5"};
	wclear(subwin);
	wrefresh(subwin);
	subwin = newwin(80, 138, 0, 0);
	wresize(subwin, height, width);
	wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	mvwprintw(subwin, 0, 15, "REGISTRATION WINDOW");
	mvwprintw(subwin, 2, 0, "If you don't want to login, Press 'SPACE' to login or 'ESC' to continue without registering..");
	while(1){
		ch = wgetch(subwin);
		if(ch == ' '){
			boolean = 1;
			regwin = newwin(6, 50, (80-30)/2, (138-60)/2);
			mvwin(regwin, ((height/2)-3), (width/2)-25);
			reg_window(regwin, boolean);
			mvwprintw(subwin, 3, 0, "Again press 'ENTER' to register and move on to the race...");
			wattroff(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
			wrefresh(subwin);
			while(1){
				ch = wgetch(regwin);
				if(ch == 10){
					wclear(regwin);
					wrefresh(regwin);
					wclear(subwin);
					wrefresh(subwin);
					break;
				}
			}
			break;
		}
		else if(ch == 27){
			wclear(subwin);
			wrefresh(subwin);
			break;
		}
	}
	subwin = newwin(40, 138, 0, 0);
	wresize(subwin, height, width);
	wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	mvwprintw(subwin, 0, 0, "Use 'up' and 'down' arrow keys to run through the options, Press <enter> to select from the choices:");
	mvwprintw(subwin,1, 0, "Press 'ESC' to go to main menu:");
	wrefresh(subwin);
	incwin = newwin(9, 20, (60-30)/2, 40);
	mvwin(incwin, ((height/2)-4), (width/2)-10);
	box(incwin, 0 , 0);
	keypad(incwin, TRUE);
	choice = menu(subwin, incwin,choices, 5);
	wrefresh(incwin);
	if(choice == 1){
		choicen(subwin, files[0], incwin, boolean);
	}
	if(choice == 2){
		choicen(subwin, files[1], incwin, boolean);
	}
	if(choice == 3){
		choicen(subwin, files[2], incwin, boolean);
	}
	if(choice == 4){
		choicen(subwin, files[3], incwin, boolean);
	}
	if(choice == 5){
		choicen(subwin, files[4], incwin, boolean);
	}	
}
