def swap(i, j, A):
    A[i], A[j] = A[j], A[i]

def perm(t, A, n):
    if t >= n:
        print(A)
    else:
        for i in range(t, n):
            swap(i, t, A)
            perm(t + 1, A, n)
            swap(i, t, A)

if __name__ == "__main__":
    n = 3
    A = list(range(1, n + 1))
    perm(0, A, n)