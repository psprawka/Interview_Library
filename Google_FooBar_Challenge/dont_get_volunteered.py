# -------------------------
# | 0| 1| 2| 3| 4| 5| 6| 7|
# -------------------------
# | 8| 9|10|11|12|13|14|15|
# -------------------------
# |16|17|18|19|20|21|22|23|
# -------------------------
# |24|25|26|27|28|29|30|31|
# -------------------------
# |32|33|34|35|36|37|38|39|
# -------------------------
# |40|41|42|43|44|45|46|47|
# -------------------------
# |48|49|50|51|52|53|54|55|
# -------------------------
# |56|57|58|59|60|61|62|63|
# -------------------------

# from queue import *

def answer(src, dest):

	if src < 0 or src > 63 or dest < 0 or dest > 63:
		return -1
	if src == dest:
		return 0

	mov_x = [-2, -1, 1, 2, 2, 1, -1, -2]
	mov_y = [-1, -2, -2, -1, 1, 2, 2, 1]
	knight = [src % 8, src / 8, 0]									# knight[x][y][nb_moves]
	dest_y = dest / 8 ; dest_x = dest % 8
	myList = knight

	board = [[0 for x in range(8)] for y in range(8)]
	board[knight[0]][knight[1]] = 1									# initial position of a knight

	while len(myList):
		knight = [myList.pop(0), myList.pop(0), myList.pop(0)]
		for i in range(8):
			new_x = knight[0] + mov_x[i]
			new_y = knight[1] + mov_y[i]
			if new_x < 0 or new_x > 7 or new_y < 0 or new_y > 7:
				continue
			if new_x == dest_x and new_y == dest_y:
				return knight[2] + 1 
			
			board[new_x][new_y] = 1										# mark cell as visited
			myList.append(new_x)
			myList.append(new_y)
			myList.append(knight[2] + 1)

# print answer(19,36)
# print answer(0,1)
# print answer(0,0)
# answer(15,1)
# answer(32,1)
# answer(22,1)
# answer(58,1)