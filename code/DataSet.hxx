/*
 * DataSet.hxx
 * ----------------------
 * Implementación de la clase plantilla DataSet.
 * Aquí se definen los métodos para manipular los puntos de datos
 * y gestionar los modelos de regresión lineal.
 */

#ifndef DATASET_HXX
#define DATASET_HXX

#include "DataSet.h"
#include "LinearRegression.h"

/*
 * Implementación del método addDataPoint
 * ---------------------------------------
 * Añade un nuevo punto de datos a la estructura lineal de puntos de datos de manera ordenada.
 */
template <typename T>
void DataSet<T>::addDataPoint(T x, T y)
{
    // TODO #01: Implementar la inserción ordenada de puntos de datos en la estructura lineal.
    int inicio = 0;
    int fin = dataPoints.size(); // Usamos el tamaño total como límite superior

    // Algoritmo de Búsqueda Binaria
    while (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (dataPoints[medio].x < x) {
            inicio = medio + 1; // El lugar está en la mitad derecha
        } else {
            fin = medio;
        }
    }

    // Al terminar el ciclo, 'inicio' es el índice exacto donde debe ir el nuevo elemento
    dataPoints.insert(dataPoints.begin() + inicio, DataPoint<T>(x, y));
}

/*
 * Implementación del método addModel
 * -----------------------------------
 * Crea un nuevo modelo de regresión lineal con la pendiente y ordenada especificadas
 * y lo añade a la lista de modelos.
 */
template <typename T>
void DataSet<T>::addModel(double slope, double intercept)
{
    // TODO #02: Implementar la inserción de modelos de regresión en la lista.
    models.push_back(LinearRegression<T>(slope, intercept));
}

/*
 * Implementación del método evaluateModels
 * -----------------------------------------
 * Evalúa todos los modelos de regresión almacenados utilizando los datos actuales.
 */
template <typename T>
void DataSet<T>::evaluateModels()
{
    // TODO #7: Implementar la función evaluateModels.
    if (!models.empty()) {
        models.begin()->calculateMetrics(*this);
    }
}

/*
 * Implementación del método findBestModel
 * ----------------------------------------
 * Encuentra el modelo de regresión con el mejor ajuste basado en la métrica dada como parámetro.
 */
template <typename T>
LinearRegression<T> DataSet<T>::findBestModel(const std::string &metric)
{
    if (models.empty())
        throw std::runtime_error("No hay modelos disponibles para evaluar.");
    // TODO #8: Implementar la función findBestModel.
    LinearRegression<T> bestModel;

    return bestModel;
}

#endif // DATASET_HXX
