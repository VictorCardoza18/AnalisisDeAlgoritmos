import numpy as np


def DAC_Max(a, index, l):
    max = -1
    if (l - 1 == 0):
        return a[index]
    if (index >= l - 2):
        if (a[index] > a[index + 1]):
            return a[index]
        else:
            return a[index + 1]

    max = DAC_Max(a, index + 1, l)

    if (a[index] > max):
        return a[index]
    else:
        return max


def DAC_Min(a, index, l):
    min = 0
    if (l - 1 == 0):
        return a[index]
    if (index >= l - 2):
        if (a[index] < a[index + 1]):
            return a[index]
        else:
            return a[index + 1]

    min = DAC_Min(a, index + 1, l)

    if (a[index] < min):
        return a[index]
    else:
        return min


# Driver Code
if __name__ == '__main__':

    min, max = 0, -1

    n = 10000000000
    rango_minimo = 0
    rango_maximo = 10000000
    a = np.random.randint(rango_minimo, rango_maximo, size=n)

    max = DAC_Max(a, 0, 7)

    min = DAC_Min(a, 0, 7)
    print("The minimum number in a given array is : ", min)
    print("The maximum number in a given array is : ", max)
