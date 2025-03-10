/* USER CODE BEGIN includes */

extern UART_HandleTypeDef huart2;

#define BYTES_IN_FLOATS 28*28*4

#define TIMEOUT 1000

#define SYNCHRONISATION 0xAB

#define ACKNOWLEDGE 0xCD

#define CLASS_NUMBER 10

 void synchronize_UART(void);

/* USER CODE END includes */

void synchronize_UART(void)

{

    bool is_synced = 0;

    unsigned char rx[2] = {0};

    unsigned char tx[2] = {ACKNOWLEDGE, 0};

    while (!is_synced)

    {

      HAL_UART_Receive(&huart2, (uint8_t *)rx, sizeof(rx), TIMEOUT);

      if (rx[0] == SYNCHRONISATION)

      {

        HAL_UART_Transmit(&huart2, (uint8_t *)tx, sizeof(tx), TIMEOUT);

        is_synced = 1;

      }

    }

    return;

}

void MX_X_CUBE_AI_Process(void)

{

    /* USER CODE BEGIN 6 */

  int res = -1;

  uint8_t *in_data = ai_input[0].data;

  uint8_t *out_data = ai_output[0].data;

  synchronize_UART();

  if (mnist) {

    do {

      /* 1 - acquire and pre-process input data */

      res = acquire_and_process_data(in_data);

      /* 2 - process the data - call inference engine */

      if (res == 0)

        res = ai_run();

      /* 3- post-process the predictions */

      if (res == 0)

        res = post_process(out_data);

    } while (res==0);

  }

  if (res) {

    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};

    ai_log_err(err, "Process has FAILED");

  }

    /* USER CODE END 6 */

}
