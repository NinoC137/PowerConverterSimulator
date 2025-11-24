#ifndef SIMULATION_ENGINE_H
#define SIMULATION_ENGINE_H

#include <functional>

class SimulationEngine {
  public:
    SimulationEngine(double dt);

    //单步仿真回调函数
    void set_step_callback(std::function<void(double)> function);

    //运行仿真，duration=总时间
    void run(double duration);

  private:
    double dt_;
    std::function<void(double)> step_func_;
};

#endif