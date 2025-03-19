# Embedded_AI
*Abstract :* Development of a predictive AI and implementation on a STM32 Discovery Kit. 

Introduction
----------------------

**Goal :** Train a failure predictibe AI model and implement it on a STM32 Discovery Kit, to develop embedded AI for microelectronics. 

**Hardware :** Discovery kit with STM32L4R9AI MCU

![STM32L4R9IDISCOVERY](./pictures/STM32.jpg "STM32L4R9IDISCOVERY")

**Tools :** 
- Google Collab (https://colab.research.google.com/)
- STM32 CubeIDE (https://www.st.com/en/development-tools/stm32cubeide.html)
- CubeAI (https://stm32ai.st.com/stm32-cube-ai/)

Repository structure
----------------------
- Embedded_AI 
    - 0_Data -> *Csv, numpy files and model file for the AI training and implementation*
    - 1_CubeIDE -> *STM32 project in C++ with CubeAI*
    - 2_Jupyter -> *Jupyter python files for UART communication and AI training

Project
----------------------

#### Artificial Intelligence training

**Data :**\
The dataset contains of 10,000 machines with failure or not. For each machine, there is the operating condition of a machine and labels. Labels are the machine failure indicator and the failure type : 

*   **TWF**: Tool Wear Failure
*   **HDF**: Heat Dissipation Failure
*   **PWF**: Power Failure
*   **OSF**: Overstrain Failure
*   **RNF**: Random Failure

With a plot of this dataset, we observe that the dataset is not clean correctly. For example, some machines without failure have a RNF failure (something impossible by definition) and machine with failure can have RNF failure or no specific failure. This failure types aren't predictible, so this will descrease model accurrancy.

Moreover, our dataset has bias, because the ratio between machine_failure = 1 and machine_failure = 0 is very small 3.39%. This is bad for our model training and will creates overfitting.

To correct this problem, we have use SMOTE. It creates new datas based on current minority data. With an extensive dataset and less bias our model accurancy will be better without overfitting.

| Before SMOTE | After SMOTE |
| ------------- | ------------- |
|Shape X_train : (6981, 5) | Shape X_train : (33861, 5) |
|Shape X_test : (2992, 5) | Shape X_test : (14512, 5) |
|Shape Y_train : (6981, 5) | Shape Y_train : (33861, 5) |
|Shape Y_test : (2992, 5) | Shape Y_test : (14512, 5) |

After training and test, we get a good light model of 11,269 parameters, with an accurancy of 92%. We export the model to .h5 file, to implement on the board.

#### Implementation with CubeAI

> CubeAI
> Code explain (not long)

### UART communication 

> Developpement of code
> Result on UART Communication