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

int difficulty_level(WINDOW *subwin) {
	WINDOW *incwin;
	int choice = 0;
	char **a = (char **)malloc(sizeof(char *));
	*a = (char *)malloc(sizeof(char)*10);
	strcpy(*a, "./project"); 
	char *choices[] = {"Easy    ", "Medium ", "Hard    "};
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	wattron(subwin, COLOR_PAIR(1));
	mvwprintw(subwin,1, 0, "Press 'ESC' to go to main menu:");
	wrefresh(subwin);
	incwin = newwin(7, 16, (60-30)/2, 40);
	mvwin(incwin, ((height/2)-3), (width/2)-8);
	box(incwin, 0, 0);
	keypad(incwin, TRUE);
	choice = menu(subwin, incwin, choices, 3);
	wclear(subwin);
	wclear(incwin);
	wrefresh(subwin);
	wrefresh(incwin);
	if(choice == 1){
		return 1;
	}
	if(choice == 2){
		return 2;
	}
	if(choice == 3){
 		return 3;
	}
	return 0;
}

