from PIL import Image
import numpy as np
from datetime import datetime
import cv2
from scipy import *
from math import sqrt, ceil  # scalar calls are faster
from scipy.special import erfc
import matplotlib.pyplot as plt



print('Reading image programm is starting...')

print('cv2 veriosn: ', cv2.__version__)
input_img = 'spring.jpg' #Input image
img=cv2.imread(input_img)

#cv2.imshow(input_img,img)
cv2.imshow('Image',input_img)