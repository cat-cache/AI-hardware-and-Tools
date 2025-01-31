
#ifndef tflite_learn_5_GEN_H
#define tflite_learn_5_GEN_H

#include "ai-sdk/tensorflow/lite/c/common.h"

// Sets up the model with init and prepare steps.
TfLiteStatus tflite_learn_5_init( void*(*alloc_fnc)(size_t,size_t) );
// Returns the input tensor with the given index.
TfLiteStatus tflite_learn_5_input(int index, TfLiteTensor* tensor);
// Returns the output tensor with the given index.
TfLiteStatus tflite_learn_5_output(int index, TfLiteTensor* tensor);
// Runs inference for the model.
TfLiteStatus tflite_learn_5_invoke();
//Frees memory allocated
TfLiteStatus tflite_learn_5_reset( void (*free)(void* ptr) );


// Returns the number of input tensors.
inline size_t tflite_learn_5_inputs() {
  return 1;
}
// Returns the number of output tensors.
inline size_t tflite_learn_5_outputs() {
  return 1;
}

#endif
