#!usr/bin/python
import keras
from keras.models import Sequential
from keras.utils import np_utils
from keras.preprocessing.image import ImageDataGenerator
from keras.layers import Dense, Activation, Flatten, Dropout, BatchNormalization
from keras.layers import Conv2D, MaxPooling2D
from keras.datasets import cifar10
from keras import regularizers
from keras.callbacks import LearningRateScheduler


def model2(num_classes):


        print('---------------------------------------------- Initialize the model ----------------------------------------------')
        #initialize a sequencial model
        model = keras.models.Sequential()
        
        
        #-----------------------> Use convolution layers to extract features from the image
        
        
        #add a 2D concolution network, with 3x3 filters, and resulting image an image with the same dimensions as the input (padding), also using regularization term the maxnorm with an upper bound of 3
        model.add(keras.layers.convolutional.Conv2D(32, (3,3), input_shape=(3,32,32), padding='same', kernel_constraint=keras.constraints.maxnorm(3)))
         
        
        model.add(keras.layers.convolutional.Conv2D(64, (3,3), padding='same', kernel_constraint=keras.constraints.maxnorm(3)))
        
        
        model.add(Activation('relu'))

        
        
        model.add(MaxPooling2D(pool_size=(2,2)))

        
        #flatten the output
        model.add(keras.layers.Flatten())
        
        #fully contected layer, before the classification
        #model.add(keras.layers.Dense(512, activation='relu', kernel_constraint=keras.constraints.maxnorm(3)))
        
        model.add(keras.layers.Dense(num_classes, activation='softmax'))
        
        
        
        keras.utils.vis_utils.plot_model(model, show_shapes=True, show_layer_names=True, to_file='model2.png')
        
        
        
        return model
