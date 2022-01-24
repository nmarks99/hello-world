#!/usr/bin/env python3
import cv2
import sys

assert(len(sys.argv) == 2),'No input given. Please input path to image'
img_path = str(sys.argv[1])

# Load the cascade
face_cascade = cv2.CascadeClassifier('face_detector.xml')

# Read the image
img = cv2.imread(img_path)

print('Running...')

# Detect faces
faces = face_cascade.detectMultiScale(img, 1.1, 4)

# Draw rectangles around faces
for (x,y,w,h) in faces:
    cv2.rectangle(img,(x,y), (x+w,y+h), (0,0,255), 2)

# Save the result 
cv2.imwrite('out.png',img)
print('\nDone. Result saved to out.png')

