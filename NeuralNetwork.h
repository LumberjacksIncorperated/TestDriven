
typedef double NeuralValue;
#define DEFAULT_NEURAL_VALUE 7
struct _NeuralNetwork {
    NeuralValue** networkWeights;
    int numberOfLayers;
    int neuronsPerLayer;
    int sizeOfInputVector;
};

typedef struct _NeuralNetwork * NeuralNetwork;