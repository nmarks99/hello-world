#!/usr/bin/env python

# You must install pandoc 
# You must also install pdflatex (probably with MiKTeX)

import os
import sys

# Get arguments
x = sys.argv
inmd = x[1] # Get name of markdown file
outpdf = x[2] # Get name of output pdf

pandoc_cmd = ('pandoc --number-sections ' 
'-V geometry:paperwidth=8.5in '
'-V geometry:paperheight=11in '
'-V geometry:margin=1in ' 
'-V colorlinks ' 
'-V urlcolor=blue '
'--pdf-engine=pdflatex')

pandoc_cmd = "".join([pandoc_cmd,' -o {outpdf} {inmd}'.format(outpdf=outpdf,inmd=inmd)])
os.system("clear|cls")
print('Generating PDF...')
os.system(pandoc_cmd)
print('Done')
