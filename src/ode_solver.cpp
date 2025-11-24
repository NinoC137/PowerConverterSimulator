#include "ode_solver.hpp"

double ODESolver::euler(double x, double t, double dt, DerivativeFunction f){
    return x + dt * f(x, t);
}

double ODESolver::RK4(double x, double t, double dt, DerivativeFunction f){
  double k1 = f(x, t);
  double k2 = f(x + dt*k1/2, t + dt/2);
  double k3 = f(x + dt*k2/2, t + dt/2);
  double k4 = f(x + dt*k3, t + dt);
  return x + dt * (k1 + 2*k2 + 2*k3 + k4) / 6.0;
}
