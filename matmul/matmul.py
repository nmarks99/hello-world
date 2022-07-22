import numpy as np
import time

DIMS = 256
A = np.zeros([DIMS,DIMS])
B = np.zeros([DIMS,DIMS])
C = np.zeros([DIMS,DIMS])

rowsA = len(A)
colsA = len(A[0])
rowsB = len(B)
colsB = len(B[0])

def matmul():
    assert(colsA == rowsB),"Matrix dimensions are incompatible for matrix multiplication"
    for i in range(rowsA):
        for j in range(colsB):
            for k in range(rowsB):
                C[i][j] += B[k][j] * A[j][k]

def time_it(operation,args=None) -> float:
    t0 = time.monotonic();
    if args is not None:
        operation(*args)
    else:
        operation()
    tf = time.monotonic();
    elap = tf - t0
    return elap





def main():
    pass





if __name__ == "__main__":
    main()