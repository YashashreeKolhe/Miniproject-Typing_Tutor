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

void choicew(WINDOW *subwin, WINDOW *incwin, int boolean, char *str) {
	int ch;
	wclear(incwin);
	wrefresh(incwin);
	wclear(subwin);
	wrefresh(subwin);
	speed_test(subwin, str, boolean);
	mvwprintw(subwin, 0, 0, "Press ESC to go back to previous menu or Press 'E' to Exit from the tutor......");
	wrefresh(subwin);
	while(1){
		ch = wgetch(subwin);
		if(ch == 27){
			wclear(subwin);
			wrefresh(subwin);
			speed(subwin);
		}
		else if(ch == 69){
			endwin();
			exit(1);
		}
	}	
}
void speed(WINDOW *subwin){
	WINDOW *incwin, *inswin, *regwin;
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	int ch, boolean = 0;
	int choice = 0,choicexy, i;
	char **a = (char **)malloc(sizeof(char *));
	*a = (char *)malloc(sizeof(char)*10);
	strcpy(*a, "./project"); 
	char *choices[] = {"Speed Test 1", "Speed Test 2", "Speed Test 3", "Speed Test 4", "Speed Test 5"};
	char *choicesx[] = {"Easy", "Medium", "Difficult"};
	int MAX_PATH_LENGTH = 80;
	char path[MAX_PATH_LENGTH];
	getcwd(path, MAX_PATH_LENGTH);
	char **files, **files2, **files3;
	files = (char **)malloc(sizeof(char *)*5);
	files2 = (char **)malloc(sizeof(char *)*5);
	files3 = (char **)malloc(sizeof(char *)*5);
	for(i = 0; i< 5; i++)
		files[i] = (char *)malloc(strlen(path) + 25);
	for(i = 0; i< 5; i++)
		files2[i] = (char *)malloc(strlen(path) + 25);
	for(i = 0; i< 5; i++)
		files3[i] = (char *)malloc(strlen(path) + 25);
	pointers2(files, files2, files3, path);
	int starty = 0;
	int startx = 0;
	char str[128];
	strcpy(str, path);
	strcat(str, "/data/rules_for_race");
	inswin = newwin(40, 138, 0, 0);
	wresize(inswin, height, width);
	wattron(inswin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	mvwprintw(inswin, 1, 0, "Press the 'SPACE BAR' to continue");
	wattroff(inswin,COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	wrefresh(inswin);
	read_from_file(inswin, str);
	while(1){
		ch = wgetch(inswin);
		if(ch == 113){
			wclear(inswin);
			wrefresh(inswin);
			main(1, a);
		}
		else if(ch == ' '){
			wclear(inswin);
			wrefresh(inswin);
			subwin = newwin(40, 138, starty, startx);
			wresize(subwin, height, width);
			wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
			mvwprintw(subwin, 0, 50, "REGISTRATION WINDOW");
			mvwprintw(subwin, 2, 30, "Press 'SPACE' to login or 'ESC' to continue without registering..");
			while(1){
				ch = wgetch(subwin);
				if(ch == ' '){
					boolean = 1;
					regwin = newwin(6, 50, 18, 30);
					mvwin(regwin, ((height/2)-3), (width/2)-25);
					reg_window(regwin, boolean);
					mvwprintw(subwin, 3, 30, "Again press 'ENTER' to register and move on to the race...");
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
			subwin = newwin(40, 138, starty, startx);
			wresize(subwin, height, width);
			wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);			
			mvwprintw(subwin, 0, 0, "Use 'up' and 'down' arrow keys to run through the options, Press <enter> to select from the choices:");
			mvwprintw(subwin,1, 0, "Press 'ESC' to go to main menu:");
			wrefresh(subwin);
			incwin = newwin(7, 20, (60-30)/2, 40);
			mvwin(incwin, ((height/2)-3), (width/2)-10);
			box(incwin, 0 , 0);
			keypad(incwin, TRUE);
			choicexy = menu(subwin, incwin, choicesx, 3);
			wclear(subwin);
			wclear(incwin);
			wrefresh(subwin);
			wrefresh(incwin);
			subwin = newwin(40, 138, starty, startx);
			wresize(subwin, height, width);			
			wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
			mvwprintw(subwin, 0, 0, "Use 'up' and 'down' arrow keys to run through the options, Press <enter> to select from the choices:");
			mvwprintw(subwin,1, 0, "Press 'ESC' to go to main menu:");
			wrefresh(subwin);
			incwin = newwin(9, 20, (60-30)/2, 40);
			mvwin(incwin, ((height/2)-4), (width/2)-10);
			box(incwin, 0 , 0);
			keypad(incwin, TRUE);
			choice = menu(subwin, incwin, choices, 5);
			wclear(subwin);
			wrefresh(subwin);
			wclear(incwin);
		 	wrefresh(incwin);
		 	if(choicexy == 1) {
				if(choice == 1){
					choicew(subwin, incwin, boolean, files[0]);
				}
				if(choice == 2){
					choicew(subwin, incwin, boolean, files[1]);
				}
				if(choice == 3){
					choicew(subwin, incwin, boolean, files[2]);	
				}
				if(choice == 4){
					choicew(subwin, incwin, boolean, files[3]);
				}
				if(choice == 5){
					choicew(subwin, incwin, boolean, files[4]);
				}
			}
			else if(choicexy == 2) {
				if(choice == 1){
					choicew(subwin, incwin, boolean, files2[0]);
				}
				if(choice == 2){
					choicew(subwin, incwin, boolean, files2[1]);
				}
				if(choice == 3){
					choicew(subwin, incwin, boolean, files2[2]);	
				}
				if(choice == 4){
					choicew(subwin, incwin, boolean, files2[3]);
				}
				if(choice == 5){
					choicew(subwin, incwin, boolean, files2[4]);
				}
			}
			else{
				if(choice == 1){
					choicew(subwin, incwin, boolean, files3[0]);
				}
				if(choice == 2){
					choicew(subwin, incwin, boolean, files3[1]);
				}
				if(choice == 3){
					choicew(subwin, incwin, boolean, files3[2]);	
				}
				if(choice == 4){
					choicew(subwin, incwin, boolean, files3[3]);
				}
				if(choice == 5){
					choicew(subwin, incwin, boolean, files3[4]);
				}
			}
		}
	}	
}
