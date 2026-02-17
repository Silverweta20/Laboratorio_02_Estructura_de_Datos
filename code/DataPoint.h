/*
 * DataPoint.h
 * ----------------------
 * Definición de la clase plantilla DataPoint.
 * Esta clase representa un punto de datos con dos coordenadas (x, y),
 * que pueden ser de cualquier tipo numérico especificado por el usuario.
 */

#ifndef DATAPOINT_H
#define DATAPOINT_H

/*
 * Plantilla de clase DataPoint
 * ----------------------------
 * Representa un punto de datos genérico con coordenadas x e y.
 * T es el tipo de dato para las coordenadas, por ejemplo: int, float, double.
 */
template <typename T>
class DataPoint {
public:
    /*
     * Atributos de la clase:
     * ----------------------
     * x - Coordenada en el eje X.
     * y - Coordenada en el eje Y.
     */
    T x;
    T y;

    /*
     * Constructor de la clase DataPoint
     * ----------------------------------
     * Inicializa un punto de datos con los valores proporcionados para x e y.
     * 
     * Parámetros:
     *  - T x: Valor para la coordenada X.
     *  - T y: Valor para la coordenada Y.
     */
    DataPoint(T x, T y) : x(x), y(y) {}
};

#endif // DATAPOINT_H