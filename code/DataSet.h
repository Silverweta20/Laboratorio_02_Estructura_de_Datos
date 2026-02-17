/*
 * DataSet.h
 * ----------------------
 * Definición de la clase plantilla DataSet.
 * Esta clase gestiona un conjunto de puntos de datos (DataPoint)
 * y modelos de regresión lineal asociados.
 */

#ifndef DATASET_H
#define DATASET_H

#include "LinearRegression.h"
#include "DataPoint.h"
#include <deque>
#include <list>

/*
 * Plantilla de clase DataSet
 * ----------------------------
 * Administra un conjunto de puntos de datos y modelos de regresión.
 * T es el tipo de dato de los puntos almacenados (por ejemplo: int, float, double).
 */
template <typename T>
class DataSet {
public:
    /*
     * Atributos de la clase:
     * ----------------------
     * dataPoints - Estructura lineal que almacena los puntos de datos.
     * models - Estructura lineal que almacena los modelos de regresión lineal asociados.
     */
    std::deque<DataPoint<T>> dataPoints;
    std::list<LinearRegression<T>> models;

    /*
     * Método para añadir un punto de datos al conjunto.
     * ----------------------------------------------
     * Parámetros:
     *  - T x: Valor de la coordenada X.
     *  - T y: Valor de la coordenada Y.
     */
    void addDataPoint(T x, T y);

    /*
     * Método para añadir un modelo de regresión lineal al conjunto.
     * ------------------------------------------------------------
     * Parámetros:
     *  - double slope: Pendiente del modelo.
     *  - double intercept: Ordenada al origen del modelo.
     */
    void addModel(double slope, double intercept);

    /*
     * Método para evaluar todos los modelos de regresión asociados.
     * ------------------------------------------------------------
     * Este método ejecuta la evaluación de cada modelo utilizando los datos almacenados.
     */
    void evaluateModels();

    /*
     * Método para encontrar el mejor modelo basado en la evaluación.
     * ------------------------------------------------------------
     * Parámetros:
     *  - string metric: Métrica sobre la cual se va a encontrar el mejor modelo.
     * Retorna:
     *  - Modelo de regresión lineal con el mejor ajuste.
     */
    LinearRegression<T> findBestModel(const std::string& metric);
};

#include "DataSet.hxx"

#endif // DATASET_H