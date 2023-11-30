// Hudba.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
struct t_album
{
	char interpret[MAX];
	char nazev[MAX];
	int rok;
	struct t_album* dalsi;
};


// TODO: Reference additional headers your program requires here.
void show();
void add(const char* interpret, const char* nazev, int rok);