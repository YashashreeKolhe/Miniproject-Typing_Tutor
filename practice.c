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

void choiceq(WINDOW *subwin, WINDOW *incwin, char *str, int choice2){
	int ch;
	wclear(incwin);
	wrefresh(incwin);
	wclear(subwin);
	wrefresh(subwin);
	prac_lesson(subwin, str, choice2);
	mvwprintw(subwin, 0, 0, "Press ESC to go back to previous menu or Press 'E' to Exit from the tutor......");
	wattroff(subwin, COLOR_PAIR(1) | A_BOLD);
	wrefresh(subwin);
	while(1){
		ch = wgetch(subwin);
		if(ch == 27){
			wclear(subwin);
			wrefresh(subwin);
			practice(subwin);
		}
		else if(ch == 69){
			endwin();
			exit(1);
		}
	}
}

void practice(WINDOW *subwin){
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	char **a = (char **)malloc(sizeof(char *));
	*a = (char *)malloc(sizeof(char)*10);
	strcpy(*a, "./project"); 
	WINDOW *incwin;
	int choice = 0, choicex = 0;
	int ch, choice2;
	int MAX_PATH_LENGTH = 80, i;
	char path[MAX_PATH_LENGTH];
	getcwd(path, MAX_PATH_LENGTH);
	char str[128];
	strcpy(str, path);
	char *choices[] = {"Practice 1", "Practice 2", "Practice 3", "Practice 4", "Practice 5"};
	char *choicestr[2] = {"Type Without Correcting","Type After Correcting"};
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
	pointers(files, files2, files3, path);
	subwin = newwin(height, width, 0, 0);
	strcat(str, "/data/practice_instructions.txt");
	read_from_file(subwin, str);
	wrefresh(subwin);
	while(1){
		ch = wgetch(subwin);
		if(ch == 32){
			wclear(subwin);
			wrefresh(subwin);
			break;
		}
		else if(ch == 113){
			wclear(subwin);
			wrefresh(subwin);
			main(1, a);
		}
	}
	subwin = newwin(40, 138, 0, 0);
	wresize(subwin, height, width);
	wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	mvwprintw(subwin, 0, 0, "Use 'up' and 'down' arrow keys to run through the options, Press <enter> to select from the choices:");
	wrefresh(subwin);
	choicex = difficulty_level(subwin);
	wclear(subwin);
	wrefresh(subwin);
	
	subwin = newwin(40, 138, 0, 0);
	wresize(subwin, height, width);
	wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	mvwprintw(subwin, 0, 0, "Use 'up' and 'down' arrow keys to run through the options, Press <enter> to select from the choices:");
	mvwprintw(subwin,1, 0, "Press 'ESC' to go to main menu:");
	wrefresh(subwin);
	incwin = newwin(9, 20, (60-30)/2, 40);
	mvwin(incwin, ((height/2)-4), (width/2)-10);
	box(incwin, 0, 0);
	keypad(incwin, TRUE);
	choice = menu(subwin, incwin, choices, 5);
	wclear(subwin);
	wclear(incwin);
	wrefresh(incwin);
	wrefresh(subwin);
	
	subwin = newwin(40, 138, 0, 0);
	wresize(subwin, height, width);
	wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	mvwprintw(subwin, 0, 0, "Use 'up' and 'down' arrow keys to run through the options, Press <enter> to select from the choices:");
	mvwprintw(subwin,1, 0, "Press 'ESC' to go to main menu:");
	wattroff(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	wrefresh(subwin);
	
	incwin = newwin(6, 27, (60-30)/2, 40);
	mvwin(incwin, ((height/2)-3), (width/2)-13);
	box(incwin, 0, 0);
	keypad(incwin, TRUE);
	choice2 = menu(subwin, incwin, choicestr, 2);
	wclear(subwin);
	wclear(incwin);
	wrefresh(incwin);
	wrefresh(subwin);
	if(choicex == 1) {
		if(choice == 1){
			choiceq(subwin, incwin, files[0], choice2);
		}
		if(choice == 2){
			choiceq(subwin, incwin, files[1], choice2);
		}
		if(choice == 3){
			choiceq(subwin, incwin, files[2], choice2);
		}
		if(choice == 4){
			choiceq(subwin, incwin, files[3], choice2);
		}
		if(choice == 5){
			choiceq(subwin, incwin, files[4], choice2);
		}
	}
	if(choicex == 2) {
		if(choice == 1){
			choiceq(subwin, incwin, files2[0], choice2);
		}
		if(choice == 2){
			choiceq(subwin, incwin, files2[1], choice2);
		}
		if(choice == 3){
			choiceq(subwin, incwin, files2[2], choice2);
		}
		if(choice == 4){
			choiceq(subwin, incwin, files2[3], choice2);
		}
		if(choice == 5){
			choiceq(subwin, incwin, files2[4], choice2);
		}
	}
	if(choicex == 3) {
		if(choice == 1){
			choiceq(subwin, incwin, files3[0], choice2);
		}
		if(choice == 2){
			choiceq(subwin, incwin, files3[1], choice2);
		}
		if(choice == 3){
			choiceq(subwin, incwin, files3[2], choice2);
		}
		if(choice == 4){
			choiceq(subwin, incwin, files3[3], choice2);
		}
		if(choice == 5){
			choiceq(subwin, incwin, files3[4], choice2);
		}
	}
}

