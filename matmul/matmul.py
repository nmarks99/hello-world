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
                C[i][j] += B[k][j] * A[j][k]
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


def verify_matmul():
    DIMS = 3
    A = np.random.rand(DIMS,DIMS)
    B = np.random.rand(DIMS,DIMS)
    my_res = matmul(A,B)
    np_res = np.matmul(A,B)
    # for i in range(len(my_res)):
    #     for j in range(len(my_res[0])):    
    #         pass
    #         # assert(my_res[i][j] == np_res[i][j]),f"Mismatch at ({i},{j})"
    print(my_res)
    print("\n")
    print(np_res)
    return True

def main():
    
    A = [[0.012513,5.635853,1.933042],[8.087405,5.850093,4.798730],[3.502915,8.959624,8.228400]]
    B = [[7.466048,1.741081,8.589435],[7.105014,5.135350,3.039949],[0.149846,0.914029,3.644520]]
    matmul(A,B)

if __name__ == "__main__":
    main()