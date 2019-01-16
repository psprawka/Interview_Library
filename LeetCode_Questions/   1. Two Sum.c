/*
**  1. Two Sum
**  Given an array of integers, return indices of the two numbers
**  such that they add up to a specific target.
**  You may assume that each input would have exactly one solution,
**  and you may not use the same element twice.
*/

/*
**  To solve this exercise I use external uthash library. I iterate
**  through an array adding the values to a hash table. Before each
**  addition I check if desired value already exist in ht and if i
**  does, I delete ht and return the indexes. O(n) time, O(n) space.
*/

typedef struct  s_item
{
  int               value;  //an index number
  int               key;    //an integer held under this number
  UT_hash_handle    hh;
}               t_item;


void    delete_ht(t_item **ht)
{
    t_item  *item, *tmp;
    
    HASH_ITER(hh, *ht, item, tmp)
    {   
        HASH_DEL(*ht, item);
        free(item);
    }
}

/*
**  A key has to be unique in uthash!!
*/
int    add_item(t_item **hash_table, int integer, int index)
{
    t_item  *item;

    if (!(item = (t_item *)calloc(1, sizeof(t_item))))
        return (EXIT_FAILURE);
    item->key = integer;
    item->value = index;
    HASH_ADD_INT(*hash_table, key, item);
    return (EXIT_SUCCESS);
}

int     *twoSum(int *nums, int numsSize, int target)
{
    t_item  *hash_table = NULL, *item;
    int     *res;
    int     number;
    
    if (!nums || !(res = (int *)calloc(2, sizeof(int))))
        return (NULL);
    
    for (int i = 0; i < numsSize; i++)
    {
        number = target - nums[i];
        HASH_FIND_INT(hash_table, &number, item);
        if (item)
        {
            res[0] = item->value;
            res[1] = i;
            break;
        }
        HASH_FIND_INT(hash_table, &nums[i], item);
        if (!item)
            add_item(&hash_table, nums[i], i);
    }
    delete_ht(&hash_table);
    return (res);
}