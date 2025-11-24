#include "circuit_rl.hpp"
#include "ode_solver.hpp"

CircuitRL::CircuitRL(double R, double L, double Vin)
    : R_(R), L_(L), Vin_(Vin) {}

// di/dt = (Vin - R*i)/ L
void CircuitRL::update(double dt) {
    auto diff = [&](double i, double t) {
        return (Vin_ - R_ * i) / L_;
    };

    i_ = ODESolver::RK4(i_, 0, dt, diff);
}