import numpy as np
a = np.arange(9).reshape(3,3)
print("Enter array elements")
for i in range(0,3):
    for j in range(0,3):
        a[i][j]=input()
        
print(a)

b = np.arange(9).reshape(3,3)
print("Enter array elements")
for i in range(0,3):
    for j in range(0,3):
        b[i][j]=input()
        
print(b)

c = np.arange(9).reshape(3,3)
print("The addition is: ")
for i in range(0,3):
    for j in range(0,3):
        b[i][j]=a[i][j]+b[i][j]

       
print(c)

O/P:

Enter array elements
1
2
3
4
5
6
7
8
9
[[1 2 3]
 [4 5 6]
 [7 8 9]]
Enter array elements
9
8
7
6
5
4
3
2
1
[[9 8 7]
 [6 5 4]
 [3 2 1]]
The addition is: 
[[0 1 2]
 [3 4 5]
 [6 7 8]]