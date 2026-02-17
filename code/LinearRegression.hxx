/*
 * LinearRegression.hxx
 * ----------------------
 * Implementación de la clase plantilla LinearRegression.
 * Aquí se definen los métodos para calcular métricas y realizar predicciones.
 */

#ifndef LINEARREGRESSION_HXX
#define LINEARREGRESSION_HXX

#include "LinearRegression.h"
#include "DataSet.h"
#include <cmath>
#include <stdexcept>
#include <deque>

/*
 * Constructor por defecto
 * -----------------------
 * Inicializa los valores de la pendiente, la ordenada al origen y las métricas en cero.
 * También marca las métricas como no calculadas.
 */
template <typename T>
LinearRegression<T>::LinearRegression() : slope(0.0), intercept(0.0), MAE(0.0), MSE(0.0), RMSE(0.0),
                                          MAECalculated(false), MSECalculated(false), RMSECalculated(false) {}

/*
 * Constructor parametrizado
 * -------------------------
 * Inicializa la pendiente y la ordenada al origen con los valores proporcionados.
 * Las métricas se inicializan en cero y se marcan como no calculadas.
 */
template <typename T>
LinearRegression<T>::LinearRegression(double slope, double intercept) : slope(slope), intercept(intercept),
                                                                        MAE(0.0), MSE(0.0), RMSE(0.0),
                                                                        MAECalculated(false), MSECalculated(false), RMSECalculated(false) {}

/*
 * Implementación del método calculateMetrics
 * ------------------------------------------
 * Calcula todas las métricas (MAE, MSE, RMSE) para el conjunto de datos proporcionado.
 * Lanza una excepción si el conjunto de datos está vacío.
 */
template <typename T>
void LinearRegression<T>::calculateMetrics(DataSet<T> dataSet)
{
    if (dataSet.dataPoints.empty())
    {
        throw std::runtime_error("El conjunto de datos está vacío");
    }
    calculateMAE(dataSet);
    calculateMSE(dataSet);
    calculateRMSE(dataSet);
}

/*
 * Implementación del método calculateMAE
 * ---------------------------------------
 * Calcula el Error Absoluto Medio (MAE) del modelo en relación con el conjunto de datos.
 * Lanza una excepción si el conjunto de datos está vacío.
 */
template <typename T>
void LinearRegression<T>::calculateMAE(const DataSet<T> &dataSet)
{
    if (dataSet.dataPoints.empty())
    {
        throw std::runtime_error("El conjunto de datos está vacío");
    }
    // TODO #04: Implementar el cálculo de MAE.
}

/*
 * Implementación del método calculateMSE
 * ---------------------------------------
 * Calcula el Error Cuadrático Medio (MSE) del modelo en relación con el conjunto de datos.
 * Lanza una excepción si el conjunto de datos está vacío.
 */
template <typename T>
void LinearRegression<T>::calculateMSE(const DataSet<T> &dataSet)
{
    if (dataSet.dataPoints.empty())
    {
        throw std::runtime_error("El conjunto de datos está vacío");
    }
    // TODO #05: Implementar el cálculo de MSE.
}

/*
 * Implementación del método calculateRMSE
 * ----------------------------------------
 * Calcula la Raíz del Error Cuadrático Medio (RMSE) del modelo en relación con el conjunto de datos.
 * Lanza una excepción si el conjunto de datos está vacío.
 */
template <typename T>
void LinearRegression<T>::calculateRMSE(const DataSet<T> &dataSet)
{
    if (dataSet.dataPoints.empty())
    {
        throw std::runtime_error("El conjunto de datos está vacío");
    }
    // TODO #06: Implementar el cálculo de RMSE.
}

/*
 * Implementación del método predict
 * ----------------------------------
 * Predice el valor de salida basado en un punto de entrada utilizando la ecuación del modelo.
 */
template <typename T>
DataPoint<T> LinearRegression<T>::predict(const DataPoint<T> &inputPoint) const
{
    // TODO #03: Implementar la función predict.
}

/*
 * Implementación de los métodos getter
 * -------------------------------------
 * Devuelven los valores de la pendiente, la ordenada al origen y las métricas calculadas.
 * Lanza excepciones si las métricas no han sido calculadas.
 */
template <typename T>
double LinearRegression<T>::getSlope() const
{
    return slope;
}

template <typename T>
double LinearRegression<T>::getIntercept() const
{
    return intercept;
}

template <typename T>
double LinearRegression<T>::getMAE() const
{
    if (!MAECalculated)
        throw std::logic_error("MAE no ha sido calculado");
    return MAE;
}

template <typename T>
double LinearRegression<T>::getMSE() const
{
    if (!MSECalculated)
        throw std::logic_error("MSE no ha sido calculado");
    return MSE;
}

template <typename T>
double LinearRegression<T>::getRMSE() const
{
    if (!RMSECalculated)
        throw std::logic_error("RMSE no ha sido calculado");
    return RMSE;
}

/*
 * Implementación de los métodos para verificar las métricas
 * ----------------------------------------------------------
 * Devuelven si cada métrica ha sido calculada o si todas lo han sido.
 */
template <typename T>
bool LinearRegression<T>::isMAECalculated() const
{
    return MAECalculated;
}

template <typename T>
bool LinearRegression<T>::isMSECalculated() const
{
    return MSECalculated;
}

template <typename T>
bool LinearRegression<T>::isRMSECalculated() const
{
    return RMSECalculated;
}

template <typename T>
bool LinearRegression<T>::areMetricsCalculated() const
{
    return MAECalculated && MSECalculated && RMSECalculated;
}

#endif // LINEARREGRESSION_HXX
