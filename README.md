# Power Converter Simulator

使用C++来写一个简单的电力电子仿真器

主要目的是练手C++开发

顺便回顾一下电力电子建模的基础知识



# 系统整体框架示意图

```mathematica
┌──────────────────────────────────────────────────────────────┐
│                  Intelligent Power Converter Simulator        │
└──────────────────────────────────────────────────────────────┘
    │
    ├── 1. 核心仿真引擎 (Core Simulation Engine)
    │       ├── 电路数学模型子系统 (Circuit Mathematical Model)
    │       │       ├── 电感、电容、开关模型 (L, C, Switch)
    │       │       ├── PWM 开关等效模型 (Average Model / Piecewise)
    │       │       ├── 三电平NPC、LLC、Buck、Boost 等模型插件
    │       │
    │       ├── 微分方程求解器 (ODE Solver)
    │       │       ├── Euler / RK2 / RK4
    │       │       ├── 可选择步长 (Fixed / Variable)
    │       │
    │       └── 数值稳定性模块 (Numerical Stability)
    │
    ├── 2. 控制器模块 (Controller Module)
    │       ├── PID 控制器
    │       ├── MPPT 控制器
    │       ├── 电流/电压双环控制
    │       ├── 滞环控制 / 符号控制
    │       ├── 自适应/模型预测控制（可扩展）
    │       └── 控制算法接口 (Controller Interface)
    │
    ├── 3. 硬件抽象层 (Hardware Abstraction Layer, HAL)
    │       ├── 虚拟 ADC（采样间隔、量化误差、延迟建模）
    │       ├── 虚拟 PWM（对接控制算法输出）
    │       ├── 虚拟 GPIO/IO 事件
    │       └── 时钟与中断模块
    │
    ├── 4. 数据管理模块 (Data Manager)
    │       ├── 波形存储 (CSV, binary)
    │       ├── 系统状态快照
    │       ├── 运行日志（Log System）
    │       └── 配置文件解析（JSON / YAML）
    │
    ├── 5. 可视化界面 / 前端 (Frontend)
    │       ├── CLI 模式
    │       │      ├── 调参数指令
    │       │      ├── 显示波形摘要
    │       │      └── 批量运行脚本
    │       ├── 或 GUI 模式（Qt）
    │       │      ├── 实时波形（I/O、Vdc、Id、Iq、Duty 等）
    │       │      ├── 控制参数在线修改
    │       │      └── 启停仿真
    │
    ├── 6. 插件系统 (Plugin System)
    │       ├── 添加新的变换器拓扑插件
    │       ├── 添加新的控制器插件
    │       └── 添加新的数值求解器
    │
    └── 7. 系统核心基础设施
            ├── 线程调度（C++11 thread, mutex）
            ├── 事件系统（event loop）
            ├── 时间步同步器
            └── 单元测试框架（GoogleTest）

```

