#!usr/bin/python
import os
import tensorflow as tf
import keras
from keras.models import Sequential
from keras.utils import np_utils
from keras.preprocessing.image import ImageDataGenerator
from keras.layers import Dense, Activation, Flatten, Dropout, BatchNormalization
from keras.layers import Conv2D, MaxPooling2D
from keras.datasets import cifar10
from keras import regularizers
from keras.callbacks import LearningRateScheduler
import numpy as np
import sys
sys.path.insert(0, '/media/data/gionanide/shared_python_scripts')
import gpu_initializations as gpu_init
from keras.datasets import cifar10
import matplotlib.pyplot as plt
from scipy.misc import toimage
import numpy as np
import collections
import model2 as model2
from keras import models


#we fix the random number seed with a constant to ensure the results are reprducible, for example we maybe want the same random initializations of the weights to happen again
seed = 7
np.random.seed(seed)


# 'th' format means that the convolution kernels(filters) will have the shape (depth,input_depth, rows, columns)
keras.backend.set_image_dim_ordering('th')


#visualize a part of the dataset
def visualize(x_train):

        #create some samples in a very low quality just to visualize them
        for x in range(0,9):
        
                #define a 3x3 grid and after this the position 1-9 of every image
                plt.subplot(330 + 1 + x)
                #the first nine images
                plt.imshow(toimage(x_train[x]))
             
        #visualize
        plt.show()
        
        
        
#all the preprocessings procedures
def preprocessing():
        
        print(' ---------------------------------------------- Start preprocessing ----------------------------------------------')
        #load the dataset, images 23x23
        
        (sample_train, label_train), (sample_test, label_test) = cifar10.load_data()
  
        print('Classes 0-9')
        print('Number of train samples:',len(label_train))
        print('Number of test samples:',len(label_test))
        #visualize(x_train)
        
        
                
        #normalize the values from 0-255 to 0.0-1.0
        sample_train = sample_train.astype('float32')
        sample_test = sample_test.astype('float32')
        sample_train = sample_train / 255.0
        sample_test = sample_test / 255.0
        
        
        #we use the one hot encoding to transform the sets
        #for example label 9 becomes [0 0 0 0 0 0 0 0 0 1]
        label_train = keras.utils.to_categorical(label_train)
        label_test = keras.utils.to_categorical(label_test)
        
        #keep the number of classes        
        num_classes = label_test.shape[1]
        print('Number of classes:',num_classes)
        
        print('Image shape:',sample_train.shape)
        print('Label shape:',label_train.shape)
        
        
        return sample_train, label_train, sample_test, label_test, num_classes
        



        
      
#a seperate function to compile the model
def compile_model(model):

        print('---------------------------------------------- Compile the model ----------------------------------------------')
        
        #initialize the properties of the procedure
        epochs = 30
        learning_rate = 0.001
        #we use the decay method in order to adjust(decrease) our learning rate as the epochs are taking place, the concept behind that is that the more we are approaching the minimum we have to be more carefull and make smaller steps
        decay = learning_rate/epochs
        
        sgd = keras.optimizers.SGD(lr=learning_rate, momentum=0.9, decay=decay, nesterov=False)
        
        model.compile(loss='categorical_crossentropy',optimizer=sgd, metrics=['accuracy'])
        
        return model,epochs
        
        
        
def train_model(model, sample_train, label_train, sample_test, label_test,epochs):

        print('---------------------------------------------- Start training procedure ----------------------------------------------')
        history = model.fit(sample_train, label_train, validation_data=(sample_test,label_test), epochs=epochs, batch_size=32, verbose=1)

        training_scores = model.evaluate(sample_train, label_train, verbose=0)

        testing_scores = model.evaluate(sample_test, label_test, verbose=0)
        
        #check for overfitting
        train_accuracy = training_scores[1]*100
        testing_accuracy = testing_scores[1]*100

        print('Training accuracy:',train_accuracy,'%')
        print('Testing accuracy:',testing_accuracy,'%')
        
        #make the title
        title = 'Train accuracy: '+str(train_accuracy)+' %  ||  Testing accuracy: '+str(testing_accuracy)+' %'
        
        #plot the results
        plt.figure(1)
        plt.plot(history.history['loss'])
        plt.plot(history.history['val_loss'])
        plt.legend(['train loss','test loss'])
        plt.ylabel('softmax loss')
        plt.xlabel('epoch')
        plt.title(title)
        #plt.savefig('/media/data/gionanide/CNNs/plots/figure1.png')
        plt.show()
        
        return model
        
        
        
#main prcedure      
if __name__=='__main__':


        #initialize CUDA properties
        sess = gpu_init.CUDA_init(core='GPU',memory='dynamically')
        
        #preprocessing
        sample_train, label_train, sample_test, label_test, num_classes = preprocessing()
        
        #----------------------------------------------------------> Create model
        model = model2.model2(num_classes)
        
        print(model.summary())
        
        model,epochs =  compile_model(model)
        
        #-----------------------------------------------------------------------> Train and save model
        #model = train_model(model, sample_train, label_train, sample_test, label_test,epochs)
        
        #model.save_weights("model.h5")
        #print("Saved model to disk")
        
        
        #-------------------------------------------------------------------------------> Load model
        #load model 
        model.load_weights('model2_weights.h5')
        print('Load model')
        
        
        #training_scores = model.evaluate(sample_train, label_train, verbose=0)

        #testing_scores = model.evaluate(sample_test, label_test, verbose=0)
        
        print('\n\n')
        #print('Training score:',training_scores[1]*100)
        #print('Testing score:',testing_scores[1]*100)
        
        layer_outputs = [layer.output for layer in model.layers]
        activation_model = models.Model(inputs=model.input, outputs=layer_outputs)
        
        intermediate_activations_sample_input = sample_test[:2]
        
        plt.imshow(toimage(intermediate_activations_sample_input[1]))
        #visualize
        plt.show()
        
        
        print('ship:',label_test[1]) 
        
        print('input shape:',intermediate_activations_sample_input.shape)
        
        
        activations = activation_model.predict(intermediate_activations_sample_input)
        
        #take only the activations for the first input sample, 'ship'
        activation_ship = []
        layer_names = []
        
        for layer in model.layers:
        
                layer_names.append(layer.name)
        
        
        
        #cheking the outputs for each layer
        for layer, activation_output in enumerate(activations):
        
                print('layer: ',layer_names[layer],'output shape:',activation_output.shape)
                activation_ship.append(activation_output[0])
                
        print('\n')
        print('Ship')
        print('\n')
        #cheking the outputs for each layer
        for layer, activation in enumerate(activation_ship):
        
                print('layer: ',layer_names[layer],'output shape:',activation.shape)
                
                
                
        conv1 = activation_ship[0]
        conv2 = activation_ship[3]
        maxpool1 = activation_ship[6]
        
        conv3 = activation_ship[8]
        conv4 = activation_ship[11]
        maxpool2 = activation_ship[14]
        
        conv5 = activation_ship[16]
        conv6 = activation_ship[19]
        maxpool3 = activation_ship[22]
        
        
        
        #create some samples in a very low quality just to visualize them
        for x in range(0,9):
        
                #define a 3x3 grid and after this the position 1-9 of every image
                plt.subplot(330 + 1 + x)
                #the first nine images
                plt.imshow(toimage(conv6[x, :, :]))
             
        #visualize
        plt.show()
        
        
                
                
                
                
                
                
        
        
        
        
        
        
        
        
        
        

        


        
