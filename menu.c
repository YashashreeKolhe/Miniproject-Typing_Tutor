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

int menu(WINDOW *subwin, WINDOW *incwin, char *choices[], int n){
	int ch;
	int highlight = 1;
	int choice = 0;
	char **a = (char **)malloc(sizeof(char *));
	*a = (char *)malloc(sizeof(char)*10);
	strcpy(*a, "./dummy2"); 
	printmenu(incwin, n, highlight, choices);
	while(1){
		ch = wgetch(incwin);
		switch(ch){
			case KEY_UP:
				if(highlight == 1)
					highlight = n;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n)
					highlight = 1;
				else
				  	++highlight;
				 break;
			case 10:
				choice = highlight;
				break;
			case 27:
				wclear(subwin);
				wclear(incwin);
				wrefresh(incwin);
				wrefresh(subwin);
				main(1, a);
				break;
			default:
				mvwprintw(subwin, 3, 0, "Use only 'up' and 'down' arrow keys to access the options: ");
				wrefresh(subwin);
			break;
		}
		printmenu(incwin, n, highlight, choices);
		if(choice != 0)
			break;
	}
	return choice;
}
