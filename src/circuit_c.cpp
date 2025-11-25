#include "circuit_c.hpp"
#include "ode_solver.hpp"

CircuitC::CircuitC(double C, double V_init)
    : C_(C), v_(V_init) {}

// i = C * dv/dt -> dv/dt = i / C
void CircuitC::update(double current, double dt) {
    auto diff = [&](double v, double t){
      return current / C_;
    };

    v_ = ODESolver::RK4(v_, 0, dt, diff);
}