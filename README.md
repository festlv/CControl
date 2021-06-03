# CControl

CControl is a library written in C only. 
The purpose with this library is to fit advanced tools for really small embedded systems. So these tools are very slim and
I have removed the most time consuming parts of the theory. Here you can use basic linear algebra to create everything from
system identification to control engineering. 

Many examples can be found in the scr folder.

- Artificial Intelligence
  - Astar algorithm for quick path finding
  
- Control Engineering
  - Kalman filter update
  - Linear Quadratic Integral regulator
  - Model predictive Control
  - Model Reference Adaptive Control
  - Transfer function to state space
  - Stability check
  - Continuous to discrete
  - Comming soon: Nonlinear Model Predictive Control

- Filtering
  - Comming soon: Unscented Kalman Filter
  - Comming soon: Particle filter
  - Filtfilt 

- Dynamics
  - Comming soon: Euler Method
  
- Linear Algebra
  - Balance matrix
  - Cholesky decomposition
  - Determinant
  - Discrete Lyapunov solver
  - Eigenvalues symmetric + Eigenvectors
  - Random real eigenvalues and random imaginary eigenvalues
  - Hankel matrix
  - Inverse
  - Linear solver
  - LUP factorization
  - Multiplication
  - Pseudo inverse
  - QR-factorization
  - Singular Value Decomposition Golup Reinsch
  - Singular Value Decomposition Jacobi One Sided
  - Tikanov regularization
  - Transpose
  - Upper triangular
  - Matrix sum
  - Norm
  - Matrix exponential

- Miscellaneous
  - Cut matrix
  - Insert sub matrix into matrix
  - Print matrix or vector
  - Saturation
  - Sign
  
- Optimization
  - Linear programming maximization
  - Linear programming minimization
  - Nonlinear mimimization
  - Nonlinear maximization

- System Identification
  - Observer Kalman Filter identification
  - Eigensystem Realization Algorithm
  - Recursive Least Square with forgetting factor and kalman filter identification

### How the project is structured

This project is structured as
```
 * No malloc, calloc or free - No dynamic memory allocation in other words
 * Use pointers as much as you can
 * Use "valgrind --tool=exp-sgcheck ./CControl" to check if your output in Debug folder is correct
 * I'm focusing on real practical controllers or methods that are cost effective and don't require "a lot of tuning"
 * Main focusing on: Control engineering, linear algebra, optimization, AI algorithms, system identification and classification
```

### What I recommend

- MPC for slow temperature/water lever systems
- LQI for fast mechanical systems
- MRAC for replacing PI controllers. MRAC is actually a PI controller, with integration on P
- RLS for identification due to it's low memory use. For MIMO, please use MataveID if you going to do off-line identification


# Fan Controller with Linear Quadratic Integral Control

I have created a controller for a fan. The controller works as it read the temperature sensor and it compare the temperature sensor with the potentiometer, which is the reference set point. If the error is large between the temperature sensor and the potentiometer, then the fan is going to turn on high, or low, depending on if the error is negative or positive. 

The goal with this system is that I'm going to implement this on a heat source. The fan is going to blow warm air onto a object and the object is holding the temperature sensor. If the fan is blowing to much warm air, then the controller is going to turn down the speed of the fan so the temperature of the object meets the reference

![a](https://raw.githubusercontent.com/DanielMartensson/CControl/master/Projects/Fan%20Controller/System.jpg)

I have been using Matavecontrol and Mataveid to estimate and creating the kalman gain matrix and the LQR control law with integral action. I'm the author of both Matavecontrol and Mataveid.

Identification process. Here I have using the Observer Kalman Filter Identification and Eigen System Realization methods.

![a](https://raw.githubusercontent.com/DanielMartensson/CControl/master/Projects/Fan%20Controller/Identification%20and%20simulation/Identification.png)

Simulation process:

![a](https://raw.githubusercontent.com/DanielMartensson/CControl/master/Projects/Fan%20Controller/Identification%20and%20simulation/Simulation.png)


# Model Predictive Integral Temperature Controller

This is a Model Predictive Controller, with integral action. It uses linear programming instead of quadratic programming for the optimization. This controller works well.

This predictive controller have a wiring diagram if you want to build the same controller for your temperature project.

![a](https://raw.githubusercontent.com/DanielMartensson/CControl/master/Projects/Temperature%20Controller/IMPC.jpg)

![a](https://raw.githubusercontent.com/DanielMartensson/CControl/master/Projects/Temperature%20Controller/IMPC2.jpg)

Step answer of first order model.

![a](https://raw.githubusercontent.com/DanielMartensson/CControl/master/Projects/Temperature%20Controller/Step%20answer%20-%20First%20order.png)

# Model Reference Adaptive CAN-bus controller

This is a MRAC project, Model Reference Adaptive Controller. This controls the a Sonceboz stepper motor with CAN-bus J1939-21 protocol. The purpose is to control a big wheel with two multivariable hydraulical valves.

See the movie in the project folder. 

![a](https://raw.githubusercontent.com/DanielMartensson/CControl/master/Projects/Stepper%20Motor%20Controller/Picture%20CAN-bus.jpg)

