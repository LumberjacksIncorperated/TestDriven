#include <stdlib.h>
#include <stdio.h>
#include "NeuralNetwork.h"
#include "test_library.h"

NeuralNetwork createNeuralNetworkWithNueronsPerLayerNumberOfLayersAndInputVectorSize(int nueronsPerLayer, int numberOfLayers, int sizeOfInputVector);
NeuralValue** _createNetworkWeightsMatrixForNueronsPerLayerNumberOfLayersAndInputVectorSize(int nueronsPerLayer, int numberOfLayers, int sizeOfInputVector);
//void forwardPropogateNeuralInputVectorThroughNeuralNetwork(NeuralValue* inputVector, NeuralNetwork neuralNetwork);

int _test_createNetworkWeightsMatrixForNueronsPerLayerNumberOfLayersAndInputVectorSize(void);
int _test_createNeuralNetworkWithNueronsPerLayerNumberOfLayersAndInputVectorSize(void);

void _test_createAndRunTest(TEST_FUNCTION testFunction, char* testName, char* testDescription) {
    TEST_RUN testToRun = CREATE_TEST(testFunction, testName, testDescription);
    RUN_TEST(testToRun);
}

void test_module_neural_network() {
  _test_createAndRunTest(_test_createNetworkWeightsMatrixForNueronsPerLayerNumberOfLayersAndInputVectorSize,"_createNetworkWeightsMatrixForNueronsPerLayerNumberOfLayersAndInputVectorSize", "none");
  _test_createAndRunTest(_test_createNeuralNetworkWithNueronsPerLayerNumberOfLayersAndInputVectorSize, "createNeuralNetworkWithNueronsPerLayerNumberOfLayersAndInputVectorSize", "none");
}

int main(void) {
    test_module_neural_network();
	return 0;
}

NeuralNetwork createNeuralNetworkWithNueronsPerLayerNumberOfLayersAndInputVectorSize(int nueronsPerLayer, int numberOfLayers, int sizeOfInputVector) {
	NeuralNetwork newNeuralNetwork = malloc(sizeof(struct _NeuralNetwork));
	newNeuralNetwork->numberOfLayers = numberOfLayers;
	newNeuralNetwork->neuronsPerLayer = nueronsPerLayer;
	newNeuralNetwork->sizeOfInputVector = sizeOfInputVector;
	newNeuralNetwork->networkWeights = _createNetworkWeightsMatrixForNueronsPerLayerNumberOfLayersAndInputVectorSize(nueronsPerLayer, numberOfLayers, sizeOfInputVector);
	return newNeuralNetwork;
}

NeuralValue** _createNetworkWeightsMatrixForNueronsPerLayerNumberOfLayersAndInputVectorSize(int nueronsPerLayer, int numberOfLayers, int sizeOfInputVector) {
	NeuralValue** newNeuralWeightMatrix = malloc(sizeof(NeuralValue*)*(numberOfLayers+1));
	if(newNeuralWeightMatrix != NULL) {
		for(int layerIndex = 0; layerIndex < (numberOfLayers+1); layerIndex++) {
			if(layerIndex == 0) {
				newNeuralWeightMatrix[layerIndex] = malloc(sizeof(NeuralValue)*sizeOfInputVector*nueronsPerLayer);
				for(int neuronIndex = 0; neuronIndex < sizeOfInputVector*nueronsPerLayer; neuronIndex++) {
					newNeuralWeightMatrix[layerIndex][neuronIndex] = DEFAULT_NEURAL_VALUE;
				}
			} else if(layerIndex == numberOfLayers) {
				newNeuralWeightMatrix[layerIndex] = malloc(sizeof(NeuralValue)*nueronsPerLayer);
				for(int neuronIndex = 0; neuronIndex < nueronsPerLayer; neuronIndex++) {
					newNeuralWeightMatrix[layerIndex][neuronIndex] = DEFAULT_NEURAL_VALUE;
				}
			} else {
				newNeuralWeightMatrix[layerIndex] = malloc(sizeof(NeuralValue)*nueronsPerLayer*nueronsPerLayer);
				for(int neuronIndex = 0; neuronIndex < nueronsPerLayer*nueronsPerLayer; neuronIndex++) {
					newNeuralWeightMatrix[layerIndex][neuronIndex] = DEFAULT_NEURAL_VALUE;
				}
			}
		}
	}
	return newNeuralWeightMatrix;
}

//void forwardPropogateNeuralInputVectorThroughNeuralNetwork(NeuralValue* inputVector, NeuralNetwork neuralNetwork) {

//}

int _test_createNetworkWeightsMatrixForNueronsPerLayerNumberOfLayersAndInputVectorSize(void) {
	int test_result = 1;
	int nueronsPerLayer = 5;
	int sizeOfInputVector = 5;
	int numberOfLayers = 5;
	NeuralValue** networkWeights = _createNetworkWeightsMatrixForNueronsPerLayerNumberOfLayersAndInputVectorSize(nueronsPerLayer,numberOfLayers,sizeOfInputVector);
	if(networkWeights != NULL) {
		for(int layerIndex = 0; layerIndex < (numberOfLayers+1); layerIndex++) {
			if(layerIndex == 0) {
				for(int neuronIndex = 0; neuronIndex < sizeOfInputVector*nueronsPerLayer; neuronIndex++) {
					if(networkWeights[layerIndex] != NULL) {
						if(networkWeights[layerIndex][neuronIndex] != DEFAULT_NEURAL_VALUE) {
							test_result = 0;
						}
					} else {
						test_result = 0;
					}
				}
			} else if(layerIndex == numberOfLayers) {
				for(int neuronIndex = 0; neuronIndex < nueronsPerLayer; neuronIndex++) {
					if(networkWeights[layerIndex] != NULL) {
						if(networkWeights[layerIndex][neuronIndex] != DEFAULT_NEURAL_VALUE) {
							test_result = 0;
						}
					} else {
						test_result = 0;
					}
				}
			} else {
				for(int neuronIndex = 0; neuronIndex < nueronsPerLayer*nueronsPerLayer; neuronIndex++) {
					if(networkWeights[layerIndex] != NULL) {
						if(networkWeights[layerIndex][neuronIndex] != DEFAULT_NEURAL_VALUE) {
							test_result = 0;
						}
					} else {
						test_result = 0;
					}
				}
			}
		}
	}	
	return test_result;
}

int _test_createNeuralNetworkWithNueronsPerLayerNumberOfLayersAndInputVectorSize(void) {
	int test_result = 1;
	NeuralNetwork newNeuralNetwork = createNeuralNetworkWithNueronsPerLayerNumberOfLayersAndInputVectorSize(5, 5, 5);
	if (newNeuralNetwork != NULL) {
		if(newNeuralNetwork->networkWeights != NULL) {		
        	NeuralValue** networkWeights = newNeuralNetwork->networkWeights;
			for(int layerIndex = 0; layerIndex < (newNeuralNetwork->numberOfLayers+1); layerIndex++) {
				if(layerIndex == 0) {
					for(int neuronIndex = 0; neuronIndex < newNeuralNetwork->sizeOfInputVector*newNeuralNetwork->neuronsPerLayer; neuronIndex++) {
						if(networkWeights[layerIndex] != NULL) {
							if(networkWeights[layerIndex][neuronIndex] != DEFAULT_NEURAL_VALUE) {
								test_result = 0;
							}
						} else {
							test_result = 0;
						}
					}
				} else if(layerIndex == newNeuralNetwork->numberOfLayers) {
					for(int neuronIndex = 0; neuronIndex < newNeuralNetwork->neuronsPerLayer; neuronIndex++) {
						if(networkWeights[layerIndex] != NULL) {
							if(networkWeights[layerIndex][neuronIndex] != DEFAULT_NEURAL_VALUE) {
								test_result = 0;
							}
						} else {
							test_result = 0;
						}
					}
				} else {
					for(int neuronIndex = 0; neuronIndex < newNeuralNetwork->neuronsPerLayer*newNeuralNetwork->neuronsPerLayer; neuronIndex++) {
						if(networkWeights[layerIndex] != NULL) {
							if(networkWeights[layerIndex][neuronIndex] != DEFAULT_NEURAL_VALUE) {
								test_result = 0;
							}
						} else {
							test_result = 0;
						}
					}
				}
			}
		} else {
			test_result = 0;
		}
		if(newNeuralNetwork->numberOfLayers != 5) {
			test_result = 0;
		}
		if(newNeuralNetwork->neuronsPerLayer != 5) {
			test_result = 0;
		}
		if(newNeuralNetwork->sizeOfInputVector != 5) {
			test_result = 0;
		}
	} else {
		test_result = 0;
	}
	return test_result;
}