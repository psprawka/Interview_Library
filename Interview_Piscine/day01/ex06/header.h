#ifndef HEADER_H
# define HEADER_H

struct s_city {
	char *name;
	struct s_city *next;
};


char  *NthLastCity(struct s_city *city, int n);
struct s_city *getCities(void);


#endif
