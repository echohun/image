from Tkinter import *
tk= Tk()
import sys
import os
import pytesseract
from PIL import Image
img = Image.open("s.png")
print(img)
print(pytesseract.image_to_string(img))
#�Ͼ����ʹ��apt-get install tesseract-ocr
