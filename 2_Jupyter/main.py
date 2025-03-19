# Librairies
import UART_AI
import socket
import serial
import serial.tools.list_ports
import numpy as np


# Port detection
ports = serial.tools.list_ports.comports(include_links=False)

if ports:
    PORT = ports[0].device
    print(f"[INFO] STM32 Connected on {PORT}")
else:
    print("[CRITICAL WARNING] There is no communication port connected")
    quit()
    

# Main
if __name__ == '__main__' and ports:
    uart_ai = UART_AI(serial_port = PORT, baud_rate = 115200)

    X_test = np.load("../0_Data/Predict_machine_X.npy")
    Y_test = np.load("../0_Data/Predict_machine_Y.npy")

    print("Synchronising...")
    uart_ai.synchronise_UART()
    print("Synchronised")

    print("Evaluating model on STM32...")
    error = uart_ai.evaluate_model_on_STM32(100)