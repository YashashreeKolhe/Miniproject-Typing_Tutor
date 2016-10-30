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
#include "stack.h"
/* The above #include brings the stack type and all prototypes into this file. 
 * This helps the compiler compile this file. 
 */
void push(stack *s, char num) {
	s->a[s->i]= num;
	(s->i)++;
}
/* the caller should check that the stack is not empty before calling pop() 
 */
char pop(stack *s) {
	int t = s->a[s->i - 1];
	(s->i)--;
	return t;
}
int empty(stack *s) {
	return s->i == 0;
}
int full(stack *s) {
	return s->i == MAX;
}
/* It is mandatory to call init() on a stack before calling push, pop or any other function on the stack 
 */
void sinit(stack *s) {
	s->i = 0;
}


