/* 
 * File:   IActivationFunction.h
 * Author: abel
 *
 * Created on 28 de Novembro de 2016, 18:08
 */

#ifndef IACTIVATIONFUNCTION_H
#define IACTIVATIONFUNCTION_H

class IActivationFunction {
public:
    virtual double run(double x) =0;
    virtual double derive(double x) =0;
private:
};

#endif /* IACTIVATIONFUNCTION_H */

