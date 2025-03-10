int acquire_and_process_data(ai_i8 *data[])

{

    //

    // 1. Variables for data acquisition

    //

    unsigned char tmp[BYTES_IN_FLOATS] = {0};

    int num_elements = sizeof(tmp) / sizeof(tmp[0]);

    int num_floats = num_elements / 4;

    //

    // 2. Receive data from UART

    //

    HAL_StatusTypeDef status = HAL_UART_Receive(&huart2, (uint8_t *)tmp, sizeof(tmp), TIMEOUT);

    // Check the return status of HAL_UART_Receive

    if (status != HAL_OK)

    {

      printf("Failed to receive data from UART. Error code: %d\n", status);

      return (1);

    }

    //

    // 3. Reconstruct floats from bytes

    //

    if (num_elements % 4 != 0)

    {

      printf("The array length is not a multiple of 4 bytes. Cannot reconstruct floats.\n");

      return (1);

    }

    for (size_t i = 0; i < num_floats; i++)

    {

      unsigned char bytes[4] = {0};

      // Reconstruction of the bytes

      for (size_t j = 0; j < 4; j++)

      {

        bytes[j] = tmp[i * 4 + j];

      }

      // Store the bytes in 'data'

      for (size_t k = 0; k < 4; k++)

      {

        ((uint8_t *)data)[(i * 4 + k)] = bytes[k];

      }

    }

    return (0);

}