#ifndef HEADER_H
# define HEADER_H

struct s_player {
  int   score;
  char  *name;
};

void quickSort(struct s_player **players);

struct s_player **genRandomPlayers(int n);
struct s_player *createRandomPlayer(char *name);
void printPlayers(struct s_player **players);

#endif
