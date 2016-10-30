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
 #ifndef __DUMMY_H
 #define __DUMMY_H
#include<ncurses.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<time.h>
#include"tree.h"
#include"stack.h"
int beeps; /*used to indicate command line beep stopping demand*/
int timer; /*used to indicate command line timer stopping demand*/
int height, width; /*used to store the y and x coordintes of the size of screen*/
int main();
/*Prints the drop down menu which contains the options and the highlight to show the movement of the arrow keys*/		    
void printmenu(WINDOW *menu_win,int n, int highlight, char *choices[]);
/*It reads the file with filename given as arguement and displays it on the window sent as another arguement to the function*/
void read_from_file(WINDOW *, char *);
/*It is the function which looks after when the practice option from the main window is selected.
 *It first displays the difficulty level selection window.
 *It then shows the menu of the practice session samples.
 *It then shows the menu for selecting the typing mode(after correcting or without correcting).
 */
void practice(WINDOW *);
/*It prints the menu of the main window*/
int main_menu(WINDOW *);
/*It is the call from the practice window.
 *It sends appropriate data to the character_check() or no_correction() depending upon which typing mode has been selected by the learner
 */
void prac_lesson(WINDOW *, char *s, int);
/*It is the function which looks after when the speed test option from the main window is selected.
 *It first displays the difficulty level selection window.
 *It then shows the menu of the test samples.
 */
void speed(WINDOW *);
/*It is the call from the speed test window.
 *It sends appropriate data to the character_check() function.
 */
void speed_test(WINDOW *, char *, int);
/*It is the function which looks after when the numeric drill option from the main window is selected.
 *It then shows the menu of the test samples available.
 */
void num_drill(WINDOW *);
/*It is the call from the numeric drill window.
 *It sends appropriate data to the character_check() function.
 */
void num_test(WINDOW *, char *, int);
/*It takes the time taken by the user to type the text, and number of characters typed(total, correct, incorrect) , calculates the net
 *speed, gross speed, accuracy, number of incorrect entries, number of corrected entries, and total characters typed.
 */
void time_taken(WINDOW *, int, int, int, int, int, int);
/*It takes the username the player wants to give in order to save the score of the test he is taking.
 *It writes the username in the file created to store the entries.
 */
void reg_window(WINDOW *, int);
/*It writes the other statistics of the test like the scores, etc and the date and time at which the test was taken.
 *It displays the sorted list of the scores that are stored in the file until then.
 */
void score_chart(WINDOW *);
void ring_bell();
/*It is the function which displays the replica of the qwerty keyboard on the practice window*/
void box1(WINDOW *);
/*It is called to print any menu accessed by the arrow keys and the desired entry is selected by pressing enter
 *The arguement to this funtion is the strings that are the options of the menu and the number of options in the menu to be printed.
 *It returns the choice from the option that is selected by the user.
 */
int menu(WINDOW *, WINDOW *, char **, int );
/*It reads the the text (to be typed by the user) from the 'data' directory and displays it on the window.
 *It then checks every character typed with the character which is to be typed from the provided text.
 *It shows finger and hand to be used to type the next character from teh text.
 *If the character is incorrectly typed, it prints a highlighted '^'.
 *It also provides the data for the time_taken funtion().
 */
void character_check(WINDOW *, char *, int , int);
/*It creates a tree which stores the structures in a binary tree form.
 *Each structures contains a unique alphabet as its value , then the finger to be used to type that character on the keyboard, the hand
  to be used to type the key, and the x and y coordinates of that key on the keyboard displayed on the practice window.
 */
void datat(tree *st);
/*It searches the trees and returns the data of the tree which has the character value matching with the character passed as the arguement*/
datas* traverse(tree st, char);
void practice_box(WINDOW *);
int difficulty_level(WINDOW *);
void no_correction(WINDOW *, char *, int , int);
void hand(WINDOW *subwin);
void pointers(char **, char **, char **, char *);
void pointers2(char **, char **, char **, char *);
#endif
