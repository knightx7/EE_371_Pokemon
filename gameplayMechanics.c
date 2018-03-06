#include "auxillary_functions.h"

int getCommand(player* opponent, player* whoAmI) {
  player oppo = *opponent;
  player me = *whoAmI;

  char* oppoPokemonName = oppo.pokemonParty[oppo.whichPokemon].name;
  char* mePokemonName = me.pokemonParty[me.whichPokemon].name;
  int oppoPokemonHP = oppo.whichHP;
  int mePokemonHP = me.whichHP;
  char* attack1 = me.pokemonParty[me.whichPokemon].attacks[0].name;
  char* attack2 = me.pokemonParty[me.whichPokemon].attacks[1].name;
  char* attack3 = me.pokemonParty[me.whichPokemon].attacks[2].name;
  char* attack4 = me.pokemonParty[me.whichPokemon].attacks[3].name;

  bool validAnswer;
  validAnswer = false;

  while (!validAnswer) {
    printf("Opponent Pokemon: %s, HP: %d\n", oppoPokemonName, oppoPokemonHP); // Will print entire string or just one char?
    printf("Own Pokemon: %s, HP: %d\n", mePokemonName, mePokemonHP); // Will print entire string or just one char?
    printf("Switch: (0)\n");
    printf("Attack: \n %s (1) %s (2) \n %s (3) %s (4)\n", attack1, attack2, attack3, attack4);

    int command = getchar() - '0';

    if (command < 0 || command > 4) {
      printf("Please enter a valid command!\n");
      continue;
    }

    if (me.whichPokemon == 0 && me.pokemonParty[1].hp <= 0 || me.whichPokemon == 1 && me.pokemonParty[0].hp <= 0) {
      printf("%s already fainted. Unable to battle!\n", me.pokemonParty[me.whichPokemon].name);
      continue;
    }

    return command;
  }
}

int processCommand(player* opponent, player* whoAmI, int usrCommand) {
  if (usrCommand == 0) {
    switchPokemon(whoAmI);
    return 0;
  } else {
    int damage = calculateDamage(opponent, whoAmI, usrCommand);
    updateHP(opponent, damage);
    return damage;
  }
}

void switchPokemon(player* whoAmI) {
  player thePlayer = *whoAmI;
  int pokemon = thePlayer.whichPokemon;
  if (pokemon == 0) {
    thePlayer.whichPokemon = 1;
    thePlayer.whichHP = thePlayer.pokemon1HP;
  } else {
    thePlayer.whichPokemon = 0;
    thePlayer.whichHP = thePlayer.pokemon2HP;
  }
}

int calculateDamage(player* opponent, player* whoAmI, int usrCommand) {
  player oppo = *opponent;
  player me = *whoAmI;
  int atkIndex = usrCommand - 1;
  int atkStat = me.pokemonParty[me.whichPokemon].attacks[atkIndex].power;
  int defStat = oppo.pokemonParty[oppo.whichPokemon].def;
  int damage;
  damage = (int) ((atkStat - defStat) / 2);
  return damage;
}

void updateHP(player* whoAmI, int opponentInformation) {
  whoAmI->whichHP -= opponentInformation;
  if (whoAmI->whichHP < 0) {
    whoAmI->whichHP = 0;
  }
}

void processInformation(player* opponent, player* whoAmI, int opponentInformation) {
  if (opponentInformation == 0) {
    switchPokemon(opponent);
  } else {
    updateHP(whoAmI, opponentInformation);
  }
}

bool checkGameOver(player* whoAmI) {
  player thePlayer = *whoAmI;
  int pokemon1HP = thePlayer.pokemon1HP;
  int pokemon2HP = thePlayer.pokemon2HP;
  int total = pokemon1HP + pokemon2HP;
  if (total <= 0) {
    return true;
  } else {
    return false;
  }
}

void handleGameOver(bool gameOverForOpponent, bool gameOverForMe) {
  // int sramAddressWins = 0;
  // int sramAddressLosses = 1;
  // int wins = readSRAM(sramAddressWins);
  // int losses = readSRAM(sramAddressLosses);
  //
  // if (gameOverForOpponent) {
  //   wins += 1;
  //   writeSRAM(sramAddressWins, wins);
  // } else {
  //   losses += 1;
  //   writeSRAM(sramAddressLosses, losses);
  // }
  //
  // printf("Wins: %d\n", wins);
  // printf("Losses: %d\n", losses);
  if (gameOverForOpponent) {
    printf("Player won.");
  } else {
    printf("Opponent won.");
  }
}

/* Will vary among groups depending on SRAM is connected.
int readSRAM(int sramAddress) {
  *ramControls = 2;
  *address = sramAddress;
  int sramData = *dataOut;
  *ramControls = 1;
  return sramData;
}

// Will vary among groups depending on SRAM is connected.
void writeSRAM(int sramAddress, int sramData) {
  *ramControls = 4;
  *dataIn = sramData;
  *ramControls = 1;
} */
