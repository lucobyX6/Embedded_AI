# Librairies
import serial
import serial.tools.list_ports
import numpy as np

# Class for UART communication with STM32 Cube AI
class UART_AI:
    def __init__(self, port, baud_rate):
            self.serial_port = port
            self.baud_rate = baud_rate


    def synchronise_UART(self):
        """
        Synchronizes the UART communication by sending a byte and waiting for a response.

        Args:
            serial_port (serial.Serial): The serial port object to use for communication.

        Returns:
            None
        """
        self.serial_port = serial.Serial(self.port, self.baud_rate, timeout=1)
        while (1):
            self.serial_port.write(b"\xAB")
            ret = self.serial_port.read(1)
            if (ret == b"\xCD"):
                self.serial_port.read(1)
                break


    def send_inputs_to_STM32(self, inputs):
        """
        Sends a numpy array of inputs to the STM32 microcontroller via a serial port.

        Args:
            inputs (numpy.ndarray): The inputs to send to the STM32.
            serial_port (serial.Serial): The serial port to use for communication.

        Returns:
            None
        """
        inputs = inputs.astype(np.float32)
        buffer = b""
        for x in inputs:
            buffer += x.tobytes()
        self.serial_port.write(buffer)


    def read_output_from_STM32(self):
        """
        Reads 10 bytes from the given serial port and returns a list of float values obtained by dividing each byte by 255.

        Args:
        serial_port: A serial port object.

        Returns:
        A list of float values obtained by dividing each byte by 255.
        """
        output = serial_port.read(10)

        float_values = [int(out)/255 for out in output]
        return float_values


    def evaluate_model_on_STM32(self, iterations):
        """
        Evaluates the accuracy of a machine learning model on an STM32 device.

        Args:
            iterations (int): The number of iterations to run the evaluation for.
            serial_port (Serial): The serial port object used to communicate with the STM32 device.

        Returns:
            float: The accuracy of the model, as a percentage.
        """
        accuracy = 0
        for i in range(iterations):
            print(f"----- Iteration {i+1} -----")
            send_inputs_to_STM32(X_test[i])
            output = read_output_from_STM32()
            print(output)
            if (np.argmax(output) == np.argmax(Y_test[i])):
                accuracy += 1 / iterations
            print(f"   Expected output: {Y_test[i]}")
            print(f"   Received output: {output}")
            print(f"----------------------- Accuracy: {accuracy:.2f}\n")
        return accuracy
