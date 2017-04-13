#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/core/Edge.o \
	${OBJECTDIR}/core/ObjectID.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/neuralnet/Layer.o \
	${OBJECTDIR}/neuralnet/MultiLayerPerceptron.o \
	${OBJECTDIR}/neuralnet/algorithms/BackPropagationLearning.o \
	${OBJECTDIR}/neuralnet/functions/FuncRectifier.o \
	${OBJECTDIR}/neuralnet/functions/FuncSigmoid.o \
	${OBJECTDIR}/neuralnet/functions/FuncTanH.o \
	${OBJECTDIR}/neuralnet/neuron/AbstractNeuron.o \
	${OBJECTDIR}/neuralnet/neuron/BiasNeuron.o \
	${OBJECTDIR}/neuralnet/neuron/Neuron.o \
	${OBJECTDIR}/problem/WeightMatrix.o \
	${OBJECTDIR}/utils/IdGenerator.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f5

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/neuralnet/BackPropagationTest.o \
	${TESTDIR}/tests/neuralnet/BiasNeuronTest.o \
	${TESTDIR}/tests/neuralnet/Layer_Test.o \
	${TESTDIR}/tests/neuralnet/MultiLayerPerceptron_Test.o \
	${TESTDIR}/tests/neuralnet/NetworkPotential_Test.o \
	${TESTDIR}/tests/neuralnet/layer_runner.o \
	${TESTDIR}/tests/neuralnet/learning_test.o \
	${TESTDIR}/tests/neuralnet/multilayerperceptron-runner.o \
	${TESTDIR}/tests/neuralnet/networkPotential_runner.o \
	${TESTDIR}/tests/neuralnet/neuronrunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acai-lib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acai-lib: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acai-lib ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/core/Edge.o: core/Edge.cpp
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/Edge.o core/Edge.cpp

${OBJECTDIR}/core/ObjectID.o: core/ObjectID.cpp
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/ObjectID.o core/ObjectID.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/neuralnet/Layer.o: neuralnet/Layer.cpp
	${MKDIR} -p ${OBJECTDIR}/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/Layer.o neuralnet/Layer.cpp

${OBJECTDIR}/neuralnet/MultiLayerPerceptron.o: neuralnet/MultiLayerPerceptron.cpp
	${MKDIR} -p ${OBJECTDIR}/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/MultiLayerPerceptron.o neuralnet/MultiLayerPerceptron.cpp

${OBJECTDIR}/neuralnet/algorithms/BackPropagationLearning.o: neuralnet/algorithms/BackPropagationLearning.cpp
	${MKDIR} -p ${OBJECTDIR}/neuralnet/algorithms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/algorithms/BackPropagationLearning.o neuralnet/algorithms/BackPropagationLearning.cpp

${OBJECTDIR}/neuralnet/functions/FuncRectifier.o: neuralnet/functions/FuncRectifier.cpp
	${MKDIR} -p ${OBJECTDIR}/neuralnet/functions
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/functions/FuncRectifier.o neuralnet/functions/FuncRectifier.cpp

${OBJECTDIR}/neuralnet/functions/FuncSigmoid.o: neuralnet/functions/FuncSigmoid.cpp
	${MKDIR} -p ${OBJECTDIR}/neuralnet/functions
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/functions/FuncSigmoid.o neuralnet/functions/FuncSigmoid.cpp

${OBJECTDIR}/neuralnet/functions/FuncTanH.o: neuralnet/functions/FuncTanH.cpp
	${MKDIR} -p ${OBJECTDIR}/neuralnet/functions
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/functions/FuncTanH.o neuralnet/functions/FuncTanH.cpp

${OBJECTDIR}/neuralnet/neuron/AbstractNeuron.o: neuralnet/neuron/AbstractNeuron.cpp
	${MKDIR} -p ${OBJECTDIR}/neuralnet/neuron
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/neuron/AbstractNeuron.o neuralnet/neuron/AbstractNeuron.cpp

${OBJECTDIR}/neuralnet/neuron/BiasNeuron.o: neuralnet/neuron/BiasNeuron.cpp
	${MKDIR} -p ${OBJECTDIR}/neuralnet/neuron
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/neuron/BiasNeuron.o neuralnet/neuron/BiasNeuron.cpp

${OBJECTDIR}/neuralnet/neuron/Neuron.o: neuralnet/neuron/Neuron.cpp
	${MKDIR} -p ${OBJECTDIR}/neuralnet/neuron
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/neuron/Neuron.o neuralnet/neuron/Neuron.cpp

${OBJECTDIR}/problem/WeightMatrix.o: problem/WeightMatrix.cpp
	${MKDIR} -p ${OBJECTDIR}/problem
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/problem/WeightMatrix.o problem/WeightMatrix.cpp

${OBJECTDIR}/utils/IdGenerator.o: utils/IdGenerator.cpp
	${MKDIR} -p ${OBJECTDIR}/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/IdGenerator.o utils/IdGenerator.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/neuralnet/BackPropagationTest.o ${TESTDIR}/tests/neuralnet/learning_test.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/neuralnet/BiasNeuronTest.o ${TESTDIR}/tests/neuralnet/neuronrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/neuralnet/Layer_Test.o ${TESTDIR}/tests/neuralnet/layer_runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/neuralnet/MultiLayerPerceptron_Test.o ${TESTDIR}/tests/neuralnet/multilayerperceptron-runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/neuralnet/NetworkPotential_Test.o ${TESTDIR}/tests/neuralnet/networkPotential_runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   


${TESTDIR}/tests/neuralnet/BackPropagationTest.o: tests/neuralnet/BackPropagationTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/BackPropagationTest.o tests/neuralnet/BackPropagationTest.cpp


${TESTDIR}/tests/neuralnet/learning_test.o: tests/neuralnet/learning_test.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/learning_test.o tests/neuralnet/learning_test.cpp


${TESTDIR}/tests/neuralnet/BiasNeuronTest.o: tests/neuralnet/BiasNeuronTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/BiasNeuronTest.o tests/neuralnet/BiasNeuronTest.cpp


${TESTDIR}/tests/neuralnet/neuronrunner.o: tests/neuralnet/neuronrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/neuronrunner.o tests/neuralnet/neuronrunner.cpp


${TESTDIR}/tests/neuralnet/Layer_Test.o: tests/neuralnet/Layer_Test.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/Layer_Test.o tests/neuralnet/Layer_Test.cpp


${TESTDIR}/tests/neuralnet/layer_runner.o: tests/neuralnet/layer_runner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/layer_runner.o tests/neuralnet/layer_runner.cpp


${TESTDIR}/tests/neuralnet/MultiLayerPerceptron_Test.o: tests/neuralnet/MultiLayerPerceptron_Test.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/MultiLayerPerceptron_Test.o tests/neuralnet/MultiLayerPerceptron_Test.cpp


${TESTDIR}/tests/neuralnet/multilayerperceptron-runner.o: tests/neuralnet/multilayerperceptron-runner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/multilayerperceptron-runner.o tests/neuralnet/multilayerperceptron-runner.cpp


${TESTDIR}/tests/neuralnet/NetworkPotential_Test.o: tests/neuralnet/NetworkPotential_Test.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/NetworkPotential_Test.o tests/neuralnet/NetworkPotential_Test.cpp


${TESTDIR}/tests/neuralnet/networkPotential_runner.o: tests/neuralnet/networkPotential_runner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/neuralnet
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neuralnet/networkPotential_runner.o tests/neuralnet/networkPotential_runner.cpp


${OBJECTDIR}/core/Edge_nomain.o: ${OBJECTDIR}/core/Edge.o core/Edge.cpp 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/Edge.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/Edge_nomain.o core/Edge.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/core/Edge.o ${OBJECTDIR}/core/Edge_nomain.o;\
	fi

${OBJECTDIR}/core/ObjectID_nomain.o: ${OBJECTDIR}/core/ObjectID.o core/ObjectID.cpp 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/ObjectID.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/ObjectID_nomain.o core/ObjectID.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/core/ObjectID.o ${OBJECTDIR}/core/ObjectID_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/neuralnet/Layer_nomain.o: ${OBJECTDIR}/neuralnet/Layer.o neuralnet/Layer.cpp 
	${MKDIR} -p ${OBJECTDIR}/neuralnet
	@NMOUTPUT=`${NM} ${OBJECTDIR}/neuralnet/Layer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/Layer_nomain.o neuralnet/Layer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/neuralnet/Layer.o ${OBJECTDIR}/neuralnet/Layer_nomain.o;\
	fi

${OBJECTDIR}/neuralnet/MultiLayerPerceptron_nomain.o: ${OBJECTDIR}/neuralnet/MultiLayerPerceptron.o neuralnet/MultiLayerPerceptron.cpp 
	${MKDIR} -p ${OBJECTDIR}/neuralnet
	@NMOUTPUT=`${NM} ${OBJECTDIR}/neuralnet/MultiLayerPerceptron.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/MultiLayerPerceptron_nomain.o neuralnet/MultiLayerPerceptron.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/neuralnet/MultiLayerPerceptron.o ${OBJECTDIR}/neuralnet/MultiLayerPerceptron_nomain.o;\
	fi

${OBJECTDIR}/neuralnet/algorithms/BackPropagationLearning_nomain.o: ${OBJECTDIR}/neuralnet/algorithms/BackPropagationLearning.o neuralnet/algorithms/BackPropagationLearning.cpp 
	${MKDIR} -p ${OBJECTDIR}/neuralnet/algorithms
	@NMOUTPUT=`${NM} ${OBJECTDIR}/neuralnet/algorithms/BackPropagationLearning.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/algorithms/BackPropagationLearning_nomain.o neuralnet/algorithms/BackPropagationLearning.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/neuralnet/algorithms/BackPropagationLearning.o ${OBJECTDIR}/neuralnet/algorithms/BackPropagationLearning_nomain.o;\
	fi

${OBJECTDIR}/neuralnet/functions/FuncRectifier_nomain.o: ${OBJECTDIR}/neuralnet/functions/FuncRectifier.o neuralnet/functions/FuncRectifier.cpp 
	${MKDIR} -p ${OBJECTDIR}/neuralnet/functions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/neuralnet/functions/FuncRectifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/functions/FuncRectifier_nomain.o neuralnet/functions/FuncRectifier.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/neuralnet/functions/FuncRectifier.o ${OBJECTDIR}/neuralnet/functions/FuncRectifier_nomain.o;\
	fi

${OBJECTDIR}/neuralnet/functions/FuncSigmoid_nomain.o: ${OBJECTDIR}/neuralnet/functions/FuncSigmoid.o neuralnet/functions/FuncSigmoid.cpp 
	${MKDIR} -p ${OBJECTDIR}/neuralnet/functions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/neuralnet/functions/FuncSigmoid.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/functions/FuncSigmoid_nomain.o neuralnet/functions/FuncSigmoid.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/neuralnet/functions/FuncSigmoid.o ${OBJECTDIR}/neuralnet/functions/FuncSigmoid_nomain.o;\
	fi

${OBJECTDIR}/neuralnet/functions/FuncTanH_nomain.o: ${OBJECTDIR}/neuralnet/functions/FuncTanH.o neuralnet/functions/FuncTanH.cpp 
	${MKDIR} -p ${OBJECTDIR}/neuralnet/functions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/neuralnet/functions/FuncTanH.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/functions/FuncTanH_nomain.o neuralnet/functions/FuncTanH.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/neuralnet/functions/FuncTanH.o ${OBJECTDIR}/neuralnet/functions/FuncTanH_nomain.o;\
	fi

${OBJECTDIR}/neuralnet/neuron/AbstractNeuron_nomain.o: ${OBJECTDIR}/neuralnet/neuron/AbstractNeuron.o neuralnet/neuron/AbstractNeuron.cpp 
	${MKDIR} -p ${OBJECTDIR}/neuralnet/neuron
	@NMOUTPUT=`${NM} ${OBJECTDIR}/neuralnet/neuron/AbstractNeuron.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/neuron/AbstractNeuron_nomain.o neuralnet/neuron/AbstractNeuron.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/neuralnet/neuron/AbstractNeuron.o ${OBJECTDIR}/neuralnet/neuron/AbstractNeuron_nomain.o;\
	fi

${OBJECTDIR}/neuralnet/neuron/BiasNeuron_nomain.o: ${OBJECTDIR}/neuralnet/neuron/BiasNeuron.o neuralnet/neuron/BiasNeuron.cpp 
	${MKDIR} -p ${OBJECTDIR}/neuralnet/neuron
	@NMOUTPUT=`${NM} ${OBJECTDIR}/neuralnet/neuron/BiasNeuron.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/neuron/BiasNeuron_nomain.o neuralnet/neuron/BiasNeuron.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/neuralnet/neuron/BiasNeuron.o ${OBJECTDIR}/neuralnet/neuron/BiasNeuron_nomain.o;\
	fi

${OBJECTDIR}/neuralnet/neuron/Neuron_nomain.o: ${OBJECTDIR}/neuralnet/neuron/Neuron.o neuralnet/neuron/Neuron.cpp 
	${MKDIR} -p ${OBJECTDIR}/neuralnet/neuron
	@NMOUTPUT=`${NM} ${OBJECTDIR}/neuralnet/neuron/Neuron.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/neuralnet/neuron/Neuron_nomain.o neuralnet/neuron/Neuron.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/neuralnet/neuron/Neuron.o ${OBJECTDIR}/neuralnet/neuron/Neuron_nomain.o;\
	fi

${OBJECTDIR}/problem/WeightMatrix_nomain.o: ${OBJECTDIR}/problem/WeightMatrix.o problem/WeightMatrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/problem
	@NMOUTPUT=`${NM} ${OBJECTDIR}/problem/WeightMatrix.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/problem/WeightMatrix_nomain.o problem/WeightMatrix.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/problem/WeightMatrix.o ${OBJECTDIR}/problem/WeightMatrix_nomain.o;\
	fi

${OBJECTDIR}/utils/IdGenerator_nomain.o: ${OBJECTDIR}/utils/IdGenerator.o utils/IdGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/utils
	@NMOUTPUT=`${NM} ${OBJECTDIR}/utils/IdGenerator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/IdGenerator_nomain.o utils/IdGenerator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/utils/IdGenerator.o ${OBJECTDIR}/utils/IdGenerator_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
