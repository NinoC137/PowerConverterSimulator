#ifndef CIRCUIT_C_H
#define CIRCUIT_C_H

// i = C * dv/dt -> dv/dt = i / C
class CircuitC {
  public:
    CircuitC(double C, double V_init = 0.0);

    void update(double current, double dt);

    double voltage() const { return v_; };

  private:
    double C_;
    double v_;
};

#endif