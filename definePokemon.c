#include "game_structs.h"
#include <string.h>
#include <stdio.h>
pokemon* definePokemon(attack* allAttacks){
	static pokemon allPokemon[NUMPOKEMON];

	pokemon charmander;
	strcpy(charmander.name, "CHARMANDER");
	static attack moveSet0[4];
	moveSet0[0] = allAttacks[0];
	moveSet0[1] = allAttacks[1];
	moveSet0[2] = allAttacks[2];
	moveSet0[3] = allAttacks[3];
	charmander.attacks = moveSet0;
	charmander.health = 39;
	charmander.def = 65;
	charmander.PP = 10;
	charmander.numValue = 0;
	allPokemon[charmander.numValue] = charmander;

	pokemon squirtle;
	strcpy(squirtle.name, "SQUIRTLE");
	static attack moveSet1[4];
	moveSet1[0] = allAttacks[0];
	moveSet1[1] = allAttacks[1];
	moveSet1[2] = allAttacks[2];
	moveSet1[3] = allAttacks[3];
	squirtle.attacks = moveSet1;
	squirtle.health = 44;
	squirtle.def = 48;
	squirtle.PP = 10;
	squirtle.numValue = 1;
	allPokemon[squirtle.numValue] = squirtle;

	pokemon bulbasaur;
	strcpy(bulbasaur.name, "BULBASAUR");
	static attack moveSet2[4];
	moveSet2[0] = allAttacks[0];
	moveSet2[1] = allAttacks[1];
	moveSet2[2] = allAttacks[2];
	moveSet2[3] = allAttacks[3];
	bulbasaur.attacks = moveSet2;
	bulbasaur.health = 45;
	bulbasaur.def = 49;
	bulbasaur.PP = 10;
	bulbasaur.numValue = 2;
	allPokemon[bulbasaur.numValue] = bulbasaur;

	pokemon pikachu;
	strcpy(pikachu.name, "PIKACHU");
	static attack moveSet3[4];
	moveSet3[0] = allAttacks[0];
	moveSet3[1] = allAttacks[1];
	moveSet3[2] = allAttacks[2];
	moveSet3[3] = allAttacks[3];
	pikachu.attacks = moveSet3;
	pikachu.health = 35;
	pikachu.def = 40;
	pikachu.PP = 10;
	pikachu.numValue = 3;
	allPokemon[pikachu.numValue] = pikachu;	

	pokemon eevee;
	strcpy(eevee.name, "EEVEE");
	static attack moveSet4[4];
	moveSet4[0] = allAttacks[0];
	moveSet4[1] = allAttacks[1];
	moveSet4[2] = allAttacks[2];
	moveSet4[3] = allAttacks[3];
	eevee.attacks = moveSet4;
	eevee.health = 55;
	eevee.def = 50;
	eevee.PP = 10;
	eevee.numValue = 4;
	allPokemon[eevee.numValue] = eevee;

	pokemon chikorita;
	strcpy(chikorita.name, "CHIKORITA");
	static attack moveSet5[4];
	moveSet5[0] = allAttacks[0];
	moveSet5[1] = allAttacks[1];
	moveSet5[2] = allAttacks[2];
	moveSet5[3] = allAttacks[3];
	chikorita.attacks = moveSet5;
	chikorita.health = 45;
	chikorita.def = 65;
	chikorita.PP = 10;
	chikorita.numValue = 5;
	allPokemon[chikorita.numValue] = chikorita;

	pokemon cyndaquil;
	strcpy(cyndaquil.name, "CYNDAQUIL");
	static attack moveSet6[4];
	moveSet6[0] = allAttacks[0];
	moveSet6[1] = allAttacks[1];
	moveSet6[2] = allAttacks[2];
	moveSet6[3] = allAttacks[3];
	cyndaquil.attacks = moveSet6;
	cyndaquil.health = 39;
	cyndaquil.def = 43;
	cyndaquil.PP = 10;
	cyndaquil.numValue = 5;
	allPokemon[cyndaquil.numValue] = cyndaquil;


	pokemon totodile;
	strcpy(totodile.name, "CYNDAQUIL");
	static attack moveSet7[4];
	moveSet7[0] = allAttacks[0];
	moveSet7[1] = allAttacks[1];
	moveSet7[2] = allAttacks[2];
	moveSet7[3] = allAttacks[3];
	totodile.attacks = moveSet7;
	totodile.health = 50;
	totodile.def = 64;
	totodile.PP = 10;
	totodile.numValue = 6;
	allPokemon[totodile.numValue] = totodile;









	return allPokemon;
}