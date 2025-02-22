#ifndef _EI_CLASSIFIER_MODEL_VARIABLES_H_
#define _EI_CLASSIFIER_MODEL_VARIABLES_H_

/**
 * @file
 *  
 *  
 *  This file should only be included in ei_run_classifier.h file.
 */

#include <stdint.h>
#include "model_metadata.h"

#include "tflite-model/tflite_learn_5_compiled.h"
#include "ai-sdk/classifier/ei_model_types.h"
#include "ai-sdk/classifier/inferencing_engines/engines.h"

const char* ei_classifier_inferencing_categories[] = { "parcel" };

uint8_t ei_dsp_config_3_axes[] = { 0 };
const uint32_t ei_dsp_config_3_axes_size = 1;
ei_dsp_config_image_t ei_dsp_config_3 = {
    3, // uint32_t blockId
    1, // int implementationVersion
    1, // int length of axes
    NULL, // named axes
    0, // size of the named axes array
    "Grayscale" // select channels
};

const uint8_t ei_dsp_blocks_size = 1;
ei_model_dsp_t ei_dsp_blocks[ei_dsp_blocks_size] = {
    { // DSP block 3
        3,
        9216, // output size
        &extract_image_features, // DSP function pointer
        (void*)&ei_dsp_config_3, // pointer to config struct
        ei_dsp_config_3_axes, // array of offsets into the input stream, one for each axis
        ei_dsp_config_3_axes_size, // number of axes
        1, // version
        nullptr, // factory function
    }
};
const ei_config_tflite_eon_graph_t ei_config_tflite_graph_5 = {
    .implementation_version = 1,
    .model_init = &tflite_learn_5_init,
    .model_invoke = &tflite_learn_5_invoke,
    .model_reset = &tflite_learn_5_reset,
    .model_input = &tflite_learn_5_input,
    .model_output = &tflite_learn_5_output,
};

const ei_learning_block_config_tflite_graph_t ei_learning_block_config_5 = {
    .implementation_version = 1,
    .classification_mode = EI_CLASSIFIER_CLASSIFICATION_MODE_OBJECT_DETECTION,
    .block_id = 5,
    .object_detection = 1,
    .object_detection_last_layer = EI_CLASSIFIER_LAST_LAYER_FOMO,
    .output_data_tensor = 0,
    .output_labels_tensor = 1,
    .output_score_tensor = 2,
    .threshold = 0.9,
    .quantized = 1,
    .compiled = 1,
    .graph_config = (void*)&ei_config_tflite_graph_5
};

const uint8_t ei_learning_blocks_size = 1;
const uint32_t ei_learning_block_5_inputs[1] = { 3 };
const uint8_t ei_learning_block_5_inputs_size = 1;
const ei_learning_block_t ei_learning_blocks[ei_learning_blocks_size] = {
    {
        5,
        false,
        &run_nn_inference,
        (void*)&ei_learning_block_config_5,
        EI_CLASSIFIER_IMAGE_SCALING_NONE,
        ei_learning_block_5_inputs,
        ei_learning_block_5_inputs_size,
        288
    },
};


const ei_object_detection_nms_config_t ei_object_detection_nms = {
    0.0f, /* NMS confidence threshold */
    0.2f  /* NMS IOU threshold */
};

const ei_impulse_t impulse_607229_0 = {
    .project_id = 607229,
    .project_owner = "Vedanshi",
    .project_name = "Parcel Detection ",
    .impulse_id = 1,
    .impulse_name = "Image data, Image, Object Detection (Images)",
    .deploy_version = 31,

    .nn_input_frame_size = 9216,
    .raw_sample_count = 9216,
    .raw_samples_per_frame = 1,
    .dsp_input_frame_size = 9216 * 1,
    .input_width = 96,
    .input_height = 96,
    .input_frames = 1,
    .interval_ms = 1,
    .frequency = 0,
    .dsp_blocks_size = ei_dsp_blocks_size,
    .dsp_blocks = ei_dsp_blocks,
    
    .object_detection_count = 10,
    .fomo_output_size = 12,
    
    
    .visual_ad_grid_size_x = int((96 / 8) / 2 - 1),
    .visual_ad_grid_size_y = int((96 / 8) / 2 - 1),
    
    .tflite_output_features_count = 288,
    .learning_blocks_size = ei_learning_blocks_size,
    .learning_blocks = ei_learning_blocks,

    .postprocessing_blocks_size = 0,
    .postprocessing_blocks = nullptr,

    .inferencing_engine = EI_CLASSIFIER_TFLITE,

    .sensor = EI_CLASSIFIER_SENSOR_CAMERA,
    .fusion_string = "image",
    .slice_size = (9216/4),
    .slices_per_model_window = 4,

    .has_anomaly = EI_ANOMALY_TYPE_UNKNOWN,
    .label_count = 1,
    .categories = ei_classifier_inferencing_categories,
    .object_detection_nms = ei_object_detection_nms
};

ei_impulse_handle_t impulse_handle_607229_0 = ei_impulse_handle_t( &impulse_607229_0 );
ei_impulse_handle_t& ei_default_impulse = impulse_handle_607229_0;

#endif // _EI_CLASSIFIER_MODEL_VARIABLES_H_
