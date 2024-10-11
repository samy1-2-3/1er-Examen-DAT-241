import multiprocessing
import random

def terminos(numPuntos):
    cont = 0
    for i in range(numPuntos):
        x = random.uniform(0, 1)
        y = random.uniform(0, 1)
        if x**2 + y**2 <= 1:
            cont += 1
    return cont

def calculoPi(numPuntos, numProcesadores):
    puntosXpro = numPuntos // numProcesadores
    with multiprocessing.Pool(processes=numProcesadores) as pool:
        results = pool.map(terminos, [puntosXpro] * numProcesadores)

    calcPi = sum(results)
    return (calcPi / numPuntos) * 4

if __name__ == '__main__':
    numPuntos = 1000000  
    numProcesadores = 3      

    pi = calculoPi(numPuntos, numProcesadores)
    print(f"Calculo estimado de pi: {pi}")
