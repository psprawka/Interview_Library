#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_player {
  char  *timeStamp;
  int   score;
  char  *name;
};

struct s_player **mergeSort(struct s_player **players);


struct s_player **genRandomPlayers(int n);
struct s_player *createRandomPlayer(char *name, char *timeStamp);
void printPlayers(struct s_player **players);

#endif
