/**
  ******************************************************************************
  * @file    mlp_predict_failure.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-03-16T12:00:54+0100
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "mlp_predict_failure.h"
#include "mlp_predict_failure_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_mlp_predict_failure
 
#undef AI_MLP_PREDICT_FAILURE_MODEL_SIGNATURE
#define AI_MLP_PREDICT_FAILURE_MODEL_SIGNATURE     "0xd2061c6a80a34814029135c7afd30ba5"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "2025-03-16T12:00:54+0100"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_MLP_PREDICT_FAILURE_N_BATCHES
#define AI_MLP_PREDICT_FAILURE_N_BATCHES         (1)

static ai_ptr g_mlp_predict_failure_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_mlp_predict_failure_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_4_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 5, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  dense_11_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  dense_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  dense_12_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  dense_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  dense_13_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  dense_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  dense_14_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  dense_14_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 5, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  dense_11_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 160, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  dense_11_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  dense_12_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  dense_12_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  dense_13_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  dense_13_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  dense_14_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 640, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  dense_14_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  dense_11_dense_bias, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &dense_11_dense_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  dense_11_dense_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &dense_11_dense_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  dense_11_dense_weights, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 5, 32, 1, 1), AI_STRIDE_INIT(4, 4, 20, 640, 640),
  1, &dense_11_dense_weights_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  dense_11_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &dense_11_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  dense_12_dense_bias, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_12_dense_bias_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  dense_12_dense_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_12_dense_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  dense_12_dense_weights, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 32, 64, 1, 1), AI_STRIDE_INIT(4, 4, 128, 8192, 8192),
  1, &dense_12_dense_weights_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  dense_12_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_12_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  dense_13_dense_bias, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_13_dense_bias_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  dense_13_dense_output, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_13_dense_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  dense_13_dense_weights, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 64, 128, 1, 1), AI_STRIDE_INIT(4, 4, 256, 32768, 32768),
  1, &dense_13_dense_weights_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  dense_13_output, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_13_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  dense_14_dense_bias, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &dense_14_dense_bias_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  dense_14_dense_output, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &dense_14_dense_output_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  dense_14_dense_weights, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 128, 5, 1, 1), AI_STRIDE_INIT(4, 4, 512, 2560, 2560),
  1, &dense_14_dense_weights_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  dense_14_output, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &dense_14_output_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  input_4_output, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &input_4_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_14_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_14_layer, 6,
  SM_TYPE, 0x0, NULL,
  sm, forward_sm,
  &dense_14_chain,
  NULL, &dense_14_layer, AI_STATIC, 
  .nl_params = NULL, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_14_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_14_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_14_dense_weights, &dense_14_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_14_dense_layer, 6,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_14_dense_chain,
  NULL, &dense_14_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_13_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_13_layer, 4,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_13_chain,
  NULL, &dense_14_dense_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_13_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_13_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_13_dense_weights, &dense_13_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_13_dense_layer, 4,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_13_dense_chain,
  NULL, &dense_13_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_12_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_12_layer, 3,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_12_chain,
  NULL, &dense_13_dense_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_12_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_12_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_12_dense_weights, &dense_12_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_12_dense_layer, 3,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_12_dense_chain,
  NULL, &dense_12_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_11_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_11_layer, 2,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_11_chain,
  NULL, &dense_12_dense_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_11_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_11_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_11_dense_weights, &dense_11_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_11_dense_layer, 2,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_11_dense_chain,
  NULL, &dense_11_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 45076, 1, 1),
    45076, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 768, 1, 1),
    768, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_MLP_PREDICT_FAILURE_IN_NUM, &input_4_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_MLP_PREDICT_FAILURE_OUT_NUM, &dense_14_output),
  &dense_11_dense_layer, 0x8bf88126, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 45076, 1, 1),
      45076, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 768, 1, 1),
      768, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_MLP_PREDICT_FAILURE_IN_NUM, &input_4_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_MLP_PREDICT_FAILURE_OUT_NUM, &dense_14_output),
  &dense_11_dense_layer, 0x8bf88126, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool mlp_predict_failure_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_mlp_predict_failure_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_4_output_array.data = AI_PTR(g_mlp_predict_failure_activations_map[0] + 236);
    input_4_output_array.data_start = AI_PTR(g_mlp_predict_failure_activations_map[0] + 236);
    dense_11_dense_output_array.data = AI_PTR(g_mlp_predict_failure_activations_map[0] + 256);
    dense_11_dense_output_array.data_start = AI_PTR(g_mlp_predict_failure_activations_map[0] + 256);
    dense_11_output_array.data = AI_PTR(g_mlp_predict_failure_activations_map[0] + 256);
    dense_11_output_array.data_start = AI_PTR(g_mlp_predict_failure_activations_map[0] + 256);
    dense_12_dense_output_array.data = AI_PTR(g_mlp_predict_failure_activations_map[0] + 0);
    dense_12_dense_output_array.data_start = AI_PTR(g_mlp_predict_failure_activations_map[0] + 0);
    dense_12_output_array.data = AI_PTR(g_mlp_predict_failure_activations_map[0] + 0);
    dense_12_output_array.data_start = AI_PTR(g_mlp_predict_failure_activations_map[0] + 0);
    dense_13_dense_output_array.data = AI_PTR(g_mlp_predict_failure_activations_map[0] + 256);
    dense_13_dense_output_array.data_start = AI_PTR(g_mlp_predict_failure_activations_map[0] + 256);
    dense_13_output_array.data = AI_PTR(g_mlp_predict_failure_activations_map[0] + 256);
    dense_13_output_array.data_start = AI_PTR(g_mlp_predict_failure_activations_map[0] + 256);
    dense_14_dense_output_array.data = AI_PTR(g_mlp_predict_failure_activations_map[0] + 0);
    dense_14_dense_output_array.data_start = AI_PTR(g_mlp_predict_failure_activations_map[0] + 0);
    dense_14_output_array.data = AI_PTR(g_mlp_predict_failure_activations_map[0] + 20);
    dense_14_output_array.data_start = AI_PTR(g_mlp_predict_failure_activations_map[0] + 20);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool mlp_predict_failure_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_mlp_predict_failure_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    dense_11_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_11_dense_weights_array.data = AI_PTR(g_mlp_predict_failure_weights_map[0] + 0);
    dense_11_dense_weights_array.data_start = AI_PTR(g_mlp_predict_failure_weights_map[0] + 0);
    dense_11_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_11_dense_bias_array.data = AI_PTR(g_mlp_predict_failure_weights_map[0] + 640);
    dense_11_dense_bias_array.data_start = AI_PTR(g_mlp_predict_failure_weights_map[0] + 640);
    dense_12_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_12_dense_weights_array.data = AI_PTR(g_mlp_predict_failure_weights_map[0] + 768);
    dense_12_dense_weights_array.data_start = AI_PTR(g_mlp_predict_failure_weights_map[0] + 768);
    dense_12_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_12_dense_bias_array.data = AI_PTR(g_mlp_predict_failure_weights_map[0] + 8960);
    dense_12_dense_bias_array.data_start = AI_PTR(g_mlp_predict_failure_weights_map[0] + 8960);
    dense_13_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_13_dense_weights_array.data = AI_PTR(g_mlp_predict_failure_weights_map[0] + 9216);
    dense_13_dense_weights_array.data_start = AI_PTR(g_mlp_predict_failure_weights_map[0] + 9216);
    dense_13_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_13_dense_bias_array.data = AI_PTR(g_mlp_predict_failure_weights_map[0] + 41984);
    dense_13_dense_bias_array.data_start = AI_PTR(g_mlp_predict_failure_weights_map[0] + 41984);
    dense_14_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_14_dense_weights_array.data = AI_PTR(g_mlp_predict_failure_weights_map[0] + 42496);
    dense_14_dense_weights_array.data_start = AI_PTR(g_mlp_predict_failure_weights_map[0] + 42496);
    dense_14_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_14_dense_bias_array.data = AI_PTR(g_mlp_predict_failure_weights_map[0] + 45056);
    dense_14_dense_bias_array.data_start = AI_PTR(g_mlp_predict_failure_weights_map[0] + 45056);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_mlp_predict_failure_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_MLP_PREDICT_FAILURE_MODEL_NAME,
      .model_signature   = AI_MLP_PREDICT_FAILURE_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 11568,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x8bf88126,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_mlp_predict_failure_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_MLP_PREDICT_FAILURE_MODEL_NAME,
      .model_signature   = AI_MLP_PREDICT_FAILURE_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 11568,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x8bf88126,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_mlp_predict_failure_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_mlp_predict_failure_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_mlp_predict_failure_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_mlp_predict_failure_create(network, AI_MLP_PREDICT_FAILURE_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_mlp_predict_failure_data_params_get(&params) != true) {
    err = ai_mlp_predict_failure_get_error(*network);
    return err;
  }
#if defined(AI_MLP_PREDICT_FAILURE_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_MLP_PREDICT_FAILURE_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_mlp_predict_failure_init(*network, &params) != true) {
    err = ai_mlp_predict_failure_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_mlp_predict_failure_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_mlp_predict_failure_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_mlp_predict_failure_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_mlp_predict_failure_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= mlp_predict_failure_configure_weights(net_ctx, params);
  ok &= mlp_predict_failure_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_mlp_predict_failure_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_mlp_predict_failure_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_MLP_PREDICT_FAILURE_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

