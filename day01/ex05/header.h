#ifndef HEADER_H
# define HEADER_H

struct s_elem {
    int energy;
    struct s_elem *next;
};

struct s_stack {
    struct s_elem *elem;
    int sum;
};

struct s_tank {
    struct s_stack **stacks;
    int n;
};

struct s_tank *initTank(void);
void    tankPush(struct s_tank *tank, int energy);
int     tankPop(struct s_tank *tank);
void	printStacks(struct s_tank *tank);

#endif
