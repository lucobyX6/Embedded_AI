int post_process(ai_i8 *data[])

{

    //

    // Get the output data

    //

    if (data == NULL)

    {

      printf("The output data is NULL.\n");

      return (1);

    }

    uint8_t *output = data;

    // An array to store the float outputs

    float outs[CLASS_NUMBER] = {0.0};

    uint8_t outs_uint8[CLASS_NUMBER] = {0};

    /* Convert the probability to float */

    for (size_t i = 0; i < CLASS_NUMBER; i++)

    {

      uint8_t temp[4] = {0};

      // Extract 4 bytes to reconstruct a float

      for (size_t j = 0; j < 4; j++)

      {

        temp[j] = output[i * 4 + j];

      }

      // Reconstruct the float from the bytes

      outs[i] = *(float *)&temp;

      // Convert the float to uint8_t for UART transmission

      outs_uint8[i] = (char)(outs[i] * 255);

    }

    //

// Transmit the output data

//

HAL_StatusTypeDef status = HAL_UART_Transmit(&huart2, (uint8_t *)outs_uint8, sizeof(outs_uint8), TIMEOUT);

// Check the return status of HAL_UART_Transmit

if (status != HAL_OK)

{

printf("Failed to transmit data to UART. Error code: %d\n", status);

return (1);

}

return 0;

}
