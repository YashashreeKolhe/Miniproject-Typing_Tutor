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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#define LEFT 1
#define RIGHT 2
void init(tree *t) {
	*t = NULL;
}
void insert(tree *t, datas m) {
	int direction;
	node *tmp, *p, *q;
	tmp = (node *)malloc(sizeof(node));
	tmp->d = m;
	tmp->left = tmp->right = NULL;
	if(*t == NULL) {
		*t = tmp;
		return;
	}
	p = *t;
	while(p) {
		q = p;
		if(p->d.str > m.str) {
			p = p->left;
			direction = LEFT;
		}
		else {
			p = p->right;
			direction = RIGHT;
		}
	}
	if(direction == RIGHT)
		q->right = tmp;
	else
		q->left = tmp;
		
}
void inorder(tree t) { /* LNR */
	if(t == NULL)
		return;
	inorder(t->left);
	printf("%c ", t->d.str);
	inorder(t->right);	
}

