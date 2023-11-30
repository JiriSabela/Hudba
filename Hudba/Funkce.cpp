#include "Hudba.h"

struct t_album* prvni = NULL; // globalni ukazatel na prvni auto

void show() // tisk aut
{
	int rok;
	struct t_album* aktAlbum = prvni; // ukazatel na aktualni auto
	system("cls");
	//printf("Rok:");
	//scanf_s("%d",&rok);
	while (aktAlbum) // prochazeni seznamu
	{
		//if(aktAlbum->rok >= rok){
			printf("%s: %s %d\n", aktAlbum->interpret, aktAlbum->nazev, aktAlbum->rok); // tisk radku
		//}
			aktAlbum = aktAlbum->dalsi; // posun na dalsi auto
	}
}

void add(const char* interpret, const char* nazev, int rok) // pridani auta
{
	struct t_album* noveAlbum; // ukazatel pro nove vkladane auto
	struct t_album* aktAlbum; // ukazatel na aktualni auto
	noveAlbum = (struct t_album*)malloc(sizeof(struct t_album)); // alokace dynamicke promenne
	strcpy_s(noveAlbum->interpret, MAX, interpret); // naplneni struktury
	strcpy_s(noveAlbum->nazev, MAX, nazev); // naplneni struktury
	noveAlbum->rok = rok;
	noveAlbum->dalsi = NULL;
	if (prvni == NULL) // linearni seznam je prazdny
	{
		prvni = noveAlbum;
		return;
	}
	else if (strcmp(noveAlbum->interpret, prvni->interpret)<0) // vlozime na zacatek
	{
		noveAlbum->dalsi = prvni;
		prvni = noveAlbum;
		return;
	}
	aktAlbum = prvni; // ukazatel na aktualni auto
	while (aktAlbum) // prochazeni seznamu
	{
		if (aktAlbum->dalsi == NULL) // jsme na poslednim aute
		{
			aktAlbum->dalsi = noveAlbum; // pridavame na konec
			return;
		}
		else if (strcmp(noveAlbum->interpret, prvni->interpret) < 0)
		{
			noveAlbum->dalsi = aktAlbum->dalsi; // vlozime za aktAuto
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		aktAlbum = aktAlbum->dalsi; // posun na dalsi auto
	}
}