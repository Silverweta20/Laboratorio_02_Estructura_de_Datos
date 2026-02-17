/*
 * LinearRegression.h
 * ----------------------
 * Definición de la clase plantilla LinearRegression.
 * Esta clase permite almacenar los coeficientes de una regresión lineal
 * y calcular métricas de evaluación como MAE, MSE y RMSE.
 */

#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

template <typename T>
class DataSet;

#include "DataSet.h"
#include "DataPoint.h"

/*
 * Plantilla de clase LinearRegression
 * ----------------------------
 * Almacena la pendiente y la ordenada al origen de la regresión lineal.
 * Proporciona métodos para calcular métricas de error.
 * T es el tipo de dato de los puntos almacenados (por ejemplo: int, float, double).
 */
template <typename T>
class LinearRegression
{
private:
    double slope = 0.0;     // Pendiente de la recta
    double intercept = 0.0; // Ordenada al origen

    double MAE;  // Error absoluto medio
    double MSE;  // Error cuadrático medio
    double RMSE; // Raíz del error cuadrático medio

    bool MAECalculated = false;  // Bandera para verificar si MAE ha sido calculado
    bool MSECalculated = false;  // Bandera para verificar si MAE ha sido calculado
    bool RMSECalculated = false; // Bandera para verificar si MAE ha sido calculado

public:
    // Constructor por defecto
    LinearRegression();

    // Constructor parametrizado
    LinearRegression(double slope, double intercept);

    // Método para calcular métricas de error basadas en un conjunto de datos
    void calculateMetrics(DataSet<T> dataSet);

    // Método para calcular la métrica MAE basada en un conjunto de datos
    void calculateMAE(const DataSet<T> &dataSet);

    // Método para calcular la métrica MSE basada en un conjunto de datos
    void calculateMSE(const DataSet<T> &dataSet);

    // Método para calcular la métrica RMSE basada en un conjunto de datos
    void calculateRMSE(const DataSet<T> &dataSet);

    // Método para predecir un valor basado en un DataPoint
    DataPoint<T> predict(const DataPoint<T> &inputPoint) const;

    // Métodos getter para acceder a los coeficientes y métricas
    double getSlope() const;
    double getIntercept() const;
    double getMAE() const;
    double getMSE() const;
    double getRMSE() const;

    // Métodos para verificar si cada métrica está calculada
    bool isMAECalculated() const;
    bool isMSECalculated() const;
    bool isRMSECalculated() const;

    // Método para verificar si las métricas están calculadas
    bool areMetricsCalculated() const;
};

#include "LinearRegression.hxx"

#endif // LINEARREGRESSION_H
