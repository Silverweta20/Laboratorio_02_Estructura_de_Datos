/*
 * main.cpp
 * ----------------------
 * Programa principal para evaluar modelos de regresión lineal.
 * Lee datos desde un archivo de entrada y realiza evaluaciones.
 */

#include "EvaluationSystem.h"
#include <iostream>
#include <fstream>
#include <string>

void readDataPoints(std::ifstream &inputFile, EvaluationSystem<double> &system, int N)
{
    for (int i = 0; i < N; ++i)
    {
        double x, y;
        inputFile >> x >> y;
        system.addDataPoint(x, y);
    }
}

void ReadModels (std::ifstream &inputFile, EvaluationSystem<double> &system, int P) {
    for (int i = 0; i < P; ++i)
    {
        double M, B;
        inputFile >> M >> B;
        system.addModel(M, B);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Uso: " << argv[0] << " <nombre_del_archivo>" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << fileName << std::endl;
        return 1;
    }

    EvaluationSystem<double> system;

    try
    {

        int N;
        inputFile >> N;

        if (N <= 0)
        {
            throw std::runtime_error("El número de puntos debe ser mayor que cero.");
        }

        readDataPoints(inputFile, system, N);

        int P;
        inputFile >> P;

        if (P <= 0)
        {
            throw std::runtime_error("El número de modelos debe ser mayor que cero.");
        }

        ReadModels(inputFile, system, P);

        inputFile.close();

        system.runEvaluation();
        system.printResults();
        system.printBestModels();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

void readModels(std::ifstream &inputFile, EvaluationSystem<double> &system, int P)
{
    for (int i = 0; i < P; ++i)
    {
        double m, b;
        inputFile >> m >> b;
        system.addModel(m, b);
    }
}