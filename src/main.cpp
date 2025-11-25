#include <iostream>
#include "simulation_engine.hpp"
#include "circuit_rl.hpp"
#include "circuit_c.hpp"

int main()
{
    double dt = 0.0001; //步长100us
    SimulationEngine engine(dt);

    CircuitRL rl(1.0, 0.5, 10); //R=1欧姆 L=0.5H Vin=10V
    CircuitC cap(0.001, 0.0);
    double current_source_output = 2.0; //恒定电流源输出2A电流

    engine.set_step_callback([&](double t){
        rl.update(dt);
        cap.update(current_source_output, dt);

        if(static_cast<int>(t*1000) % 1 == 0)
        {
            std::cout << "t= "<< t << "     i=" << rl.current() <<std::endl;
            std::cout << "t= "<< t << "     cap voltage=" << cap.voltage() <<std::endl;
        }
    });

    engine.run(0.01);


    return 0;
}
