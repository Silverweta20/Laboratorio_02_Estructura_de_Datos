/*
 * EvaluationSystem.h
 * ----------------------
 * Definición de la clase plantilla EvaluationSystem.
 * Esta clase permite gestionar un único conjunto de datos (DataSet)
 * y realizar evaluaciones de modelos de regresión lineal.
 */

#ifndef EVALUATIONSYSTEM_H
#define EVALUATIONSYSTEM_H

#include "DataSet.h"
#include <vector>

/*
 * Plantilla de clase EvaluationSystem
 * ----------------------------
 * Administra un único conjunto de datos y ofrece funcionalidades para:
 * - Añadir puntos de datos.
 * - Agregar modelos de regresión lineal.
 * - Ejecutar la evaluación de los modelos.
 * - Imprimir los resultados de las evaluaciones y el mejor modelo.
 * 
 * T es el tipo de dato de los puntos almacenados (por ejemplo: int, float, double).
 */
template <typename T>
class EvaluationSystem {
public:
    DataSet<T> dataSet;  // Conjunto de datos gestionado por el sistema

    /*
     * Método para añadir un punto de datos al conjunto.
     * ----------------------------------------------
     * Parámetros:
     *  - T x: Coordenada en el eje X.
     *  - T y: Coordenada en el eje Y.
     */
    void addDataPoint(T x, T y);

    /*
     * Método para añadir un modelo de regresión lineal al conjunto.
     * ------------------------------------------------------------
     * Parámetros:
     *  - double slope: Pendiente del modelo de regresión.
     *  - double intercept: Ordenada al origen del modelo.
     */
    void addModel(double slope, double intercept);

    /*
     * Método para ejecutar la evaluación de los modelos de regresión.
     * ------------------------------------------------------------
     * Calcula las métricas de error para cada modelo almacenado en el conjunto de datos.
     */
    void runEvaluation();

    /*
     * Método para imprimir los resultados de la evaluación.
     * -----------------------------------------------------
     * Muestra las métricas de error calculadas para cada modelo en el conjunto.
     */
    void printResults();

    /*
     * Método para imprimir los mejores modelos basados en las métricas de error.
     * --------------------------------------------------------------------
     * Identifica y muestra los modelos con el mejor desempeño según las métricas evaluadas.
     */
    void printBestModels();
};

#include "EvaluationSystem.hxx"

#endif // EVALUATIONSYSTEM_H