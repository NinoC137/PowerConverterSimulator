#include "simulation_engine.hpp"
#include <iostream>

SimulationEngine::SimulationEngine(double dt)
    : dt_(dt) {}

void SimulationEngine::set_step_callback(std::function<void(double)> step_callback) {
  step_func_ = step_callback;
}

void SimulationEngine::run(double duration) {
  if(!step_func_) {
      std::cout << "ERROR: step callback not set!" << std::endl;
      return;
  }

  double t= 0.0;
  while(t < duration) {
    step_func_(t);
    t+=dt_;
  }
}