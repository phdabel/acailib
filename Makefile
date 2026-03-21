CXX      = g++
CXXFLAGS = -std=c++11 -g -Wall

TARGET = acailib

SRCS = main.cpp \
       core/Edge.cpp \
       core/ObjectID.cpp \
       neuralnet/Layer.cpp \
       neuralnet/MultiLayerPerceptron.cpp \
       neuralnet/algorithms/BackPropagationLearning.cpp \
       neuralnet/functions/FuncRectifier.cpp \
       neuralnet/functions/FuncSigmoid.cpp \
       neuralnet/functions/FuncTanH.cpp \
       neuralnet/neuron/AbstractNeuron.cpp \
       neuralnet/neuron/BiasNeuron.cpp \
       neuralnet/neuron/Neuron.cpp \
       problem/WeightMatrix.cpp \
       utils/IdGenerator.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
