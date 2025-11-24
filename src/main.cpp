#include <iostream>
#include "simulation_engine.hpp"
#include "circuit_rl.hpp"

int main()
{
    double dt = 0.0001; //步长100us
    SimulationEngine engine(dt);

    CircuitRL rl(1.0, 0.5, 10); //R=1欧姆 L=0.5H Vin=10V

    engine.set_step_callback([&](double t)
    {
        rl.update(t);

        if(static_cast<int>(t*1000) % 1 == 0)
        {
            std::cout << "t= "<< t << "     i=" << rl.current() <<std::endl;
        }
    });

    engine.run(0.1);

    return 0;
}
