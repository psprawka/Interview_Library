import numpy as np

A  = [
[0,1,0,0,0,1],  
[4,0,0,3,2,0],  
[0,0,0,0,0,0],  
[0,0,0,0,0,0], 
[0,0,0,0,0,0],
[0,0,0,0,0,0]
]

A = np.array(A)

A = np.linalg.matrix_power(A, 20)

print(A)