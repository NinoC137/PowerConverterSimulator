#ifndef CIRCUIT_RL_H
#define CIRCUIT_RL_H

class CircuitRL {
  public:
    CircuitRL(double R, double L, double Vin);

    //仿真更新一次
    void update(double dt);

    //获取当前电流
    double current() const { return i_; }

  private:
    double R_;
    double L_;
    double Vin_;
    double i_;  //电感电流
};

#endif