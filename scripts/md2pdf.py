#!/usr/bin/env python
import os
import sys

# Get arguments
x = sys.argv
inmd = x[1] # Get name of markdown file
outpdf = x[2] # Get name of output pdf

# pandoc command
cmd = ('pandoc --number-sections ' 
'-V geometry:paperwidth=8.5in '
'-V geometry:paperheight=11in '
'-V geometry:margin=1in ' 
'-V colorlinks ' 
'-V urlcolor=blue ')

cmd = cmd + ' -o {outpdf} {inmd}'.format(outpdf=outpdf,inmd=inmd)
os.system('clear||cls')
print('Generating PDF...')
os.system(cmd)
os.system('clear||cls')
print('Done')
