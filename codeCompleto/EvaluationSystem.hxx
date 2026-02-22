/*
 * EvaluationSystem.hxx
 * ----------------------
 * Implementación de la clase plantilla EvaluationSystem.
 * Aquí se definen los métodos para gestionar un conjunto de datos
 * y realizar evaluaciones de modelos de regresión lineal.
 */

#ifndef EVALUATIONSYSTEM_HXX
#define EVALUATIONSYSTEM_HXX

#include "EvaluationSystem.h"
#include <iostream>

// Método para añadir un punto de datos al conjunto
template <typename T>
void EvaluationSystem<T>::addDataPoint(T x, T y) {
    this->dataSet.addDataPoint(x, y);
}

// Método para añadir un modelo de regresión lineal al conjunto
template <typename T>
void EvaluationSystem<T>::addModel(double slope, double intercept) {
    this->dataSet.addModel(slope, intercept);
}

// Método para ejecutar la evaluación de los modelos de regresión
template <typename T>
void EvaluationSystem<T>::runEvaluation() {
    this->dataSet.evaluateModels();
}

// Método para imprimir los resultados de la evaluación
template <typename T>
void EvaluationSystem<T>::printResults() {
    const std::list<LinearRegression<T>>& models = dataSet.models;
    if (models.empty()) {
        std::cout << "No hay modelos para evaluar." << std::endl;
        return;
    }

    int index = 1;
    for (typename std::list<LinearRegression<T>>::const_iterator it = dataSet.models.begin(); it != dataSet.models.end(); ++it) {
        std::cout << "Modelo " << index++ << ":\n";
        std::cout << "  Ecuación del modelo: y = " << it->getSlope() << " x + " << it->getIntercept() << "\n";
        
        if (it->isMAECalculated()) {
            std::cout << " -> MAE: " << it->getMAE() << "\n";
        }
        if (it->isMSECalculated()) {
            std::cout << " -> MSE: " << it->getMSE() << "\n";
        }
        if (it->isRMSECalculated()) {
            std::cout << " -> RMSE: " << it->getRMSE() << "\n";
        }
    }
}

// Método para imprimir el mejor modelo basado en las métricas de error
template <typename T>
void EvaluationSystem<T>::printBestModels() {
    try {
        LinearRegression<T> bestModelMAE = this->dataSet.findBestModel("MAE");
        std::cout << "Mejor modelo basado en MAE:\n";
        std::cout << "  Ecuación del modelo: y = " << bestModelMAE.getSlope() << " x + " << bestModelMAE.getIntercept() << "\n";
        std::cout << "  MAE: " << bestModelMAE.getMAE() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error al buscar el mejor modelo basado en MAE: " << e.what() << std::endl;
    }

    try {
        LinearRegression<T> bestModelMSE = this->dataSet.findBestModel("MSE");
        std::cout << "Mejor modelo basado en MSE:\n";
        std::cout << "  Ecuación del modelo: y = " << bestModelMSE.getSlope() << " x + " << bestModelMSE.getIntercept() << "\n";
        std::cout << "  MSE: " << bestModelMSE.getMSE() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error al buscar el mejor modelo basado en MSE: " << e.what() << std::endl;
    }

    try {
        LinearRegression<T> bestModelRMSE = this->dataSet.findBestModel("RMSE");
        std::cout << "Mejor modelo basado en RMSE:\n";
        std::cout << "  Ecuación del modelo: y = " << bestModelRMSE.getSlope() << " x + " << bestModelRMSE.getIntercept() << "\n";
        std::cout << "  RMSE: " << bestModelRMSE.getRMSE() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error al buscar el mejor modelo basado en RMSE: " << e.what() << std::endl;
    }
}


#endif // EVALUATIONSYSTEM_HXX
