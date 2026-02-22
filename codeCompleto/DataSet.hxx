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

/*
 * Implementación del método addDataPoint
 * ---------------------------------------
 * Añade un nuevo punto de datos a la estructura lineal de puntos de datos de manera ordenada.
 */
template <typename T>
void DataSet<T>::addDataPoint(T x, T y)
{
    // TODO #01: Implementar la inserción ordenada de puntos de datos en la estructura lineal.
    DataPoint<T> dp(x,y);
    
    if(this->dataPoints.empty()){
        this->dataPoints.push_back(dp);
    } else {

        if(dp.x >= this->dataPoints.back().x){
            this->dataPoints.push_back(dp);
        } else if(dp.x < this->dataPoints.front().x){
            this->dataPoints.push_front(dp);
        } else {
            typename std::deque<DataPoint<T>>::iterator it;

            for(it=this->dataPoints.begin(); it != this->dataPoints.end(); it++){
                if(dp.x < it->x){
                    this->dataPoints.insert(it,dp); //insert recibe un iterador, mas no un indice
                    break;
                }  
            }
        }
    }

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
    LinearRegression<T> lr(slope, intercept);
    this->models.push_back(lr);

}

/*
 * Implementación del método evaluateModels
 * -----------------------------------------
 * Evalúa todos los modelos de regresión almacenados utilizando los datos actuales.
 */
template <typename T>
void DataSet<T>::evaluateModels()
{
    //se valida q si existan modelos
    if (this->models.empty())
    {
        throw std::runtime_error("El conjunto de modelos está vacío");
    }

    // TODO #7: Implementar la función evaluateModels.

    typename std::list<LinearRegression<T>>::iterator it=this->models.begin();

    for(; it != this->models.end(); it++){

        it->calculateMetrics(*this);

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

    LinearRegression<T> bestModel=this->models.front();

    typename std::list<LinearRegression<T>>::iterator it= this->models.begin();
    ++it;

    if(metric == "MAE"){
        for(; it != this->models.end(); it++){
            if(it->getMAE() < bestModel.getMAE()){
                bestModel=*it;
            }
        }
    } else if(metric == "MSE"){
        for(; it != this->models.end(); it++){
            if(it->getMSE() < bestModel.getMSE()){
                bestModel=*it;
            }
        }
    } else if(metric == "RMSE"){
        for(; it != this->models.end(); it++){
            if(it->getRMSE() < bestModel.getRMSE()){
                bestModel=*it;
            }
        }
    } else {
        throw std::invalid_argument("Métrica no reconocida: " + metric);
    }

    return bestModel;
}

#endif // DATASET_HXX
