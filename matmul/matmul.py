#!/usr/bin/env python
import numpy as np
import time

def matmul(A,B) -> np.ndarray:
    rowsA = len(A[0])
    colsA = len(A)
    rowsB = len(B[0])
    colsB = len(B)

    C = np.zeros([colsA,rowsB])
    assert(colsA == rowsB),"Matrix dimensions are incompatible for matrix multiplication"
    for i in range(rowsA):
        for j in range(colsB):
            for k in range(rowsB):
                C[i][j] += B[i][k] * A[k][j]
    return C

def time_it(operation,args=None) -> float:
    t0 = time.monotonic();
    if args is not None:
        operation(*args)
    else:
        operation()
    tf = time.monotonic();
    elap = tf - t0
    return elap


def verify_matmul(A,B):
    my_res = matmul(A,B)
    np_res = np.matmul(A,B)
    for i in range(len(my_res)):
        for j in range(len(my_res[0])):    
            assert(my_res[i][j] == np_res[i][j]),f"Mismatch at {i,j}"

def main():
    DIMS = 128
    A = np.random.rand(DIMS,DIMS) 
    B = np.random.rand(DIMS,DIMS) 
    print(f"Multiplying a {DIMS} x {DIMS} Matrix")
    iter = 5
    i = 0
    times = []
    while i < iter:
        elap = time_it(matmul,args=[A,B]) 
        times.append(elap)
        print(f"Elapsed time = {elap:.4f} s")
        i += 1
    print(f"Mean = {np.mean(times):.4f} s")










if __name__ == "__main__":
    main()