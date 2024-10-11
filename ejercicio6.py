def fibonacci(n):

    fibo = [0, 1]

    for i in range(2, n):
        siguiente = fibo[i - 1] + fibo[i - 2]
        fibo.append(siguiente)

    return fibo[:n]

n = int(input("Digite cantidad de digitos de la serie fibo: "))
resultado = fibonacci(n)
print(resultado)
