#ifndef __ODE_SOLVER_H__
#define __ODE_SOLVER_H__

#include <functional>

class ODESolver {
  public:
    //f(x,t) -> dx/dt
    using DerivativeFunction = std::function<double(double, double)>;

    //简单的Euler方法
    static double euler(double x, double t, double dt, DerivativeFunction f);

    //常用的RK4方法
    static double RK4(double x, double t, double dt, DerivativeFunction f);
};

#endif