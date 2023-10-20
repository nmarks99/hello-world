import os
from enum import Enum

ANSI_PREFIX = "\x1B["
ANSI_SUFFIX = "m"
ANSI_RESET = "\x1B[0m"

class Color(Enum):
    RED = 31
    GREEN = 32
    YELLOW = 33
    BLUE = 34
    MAGENTA = 35
    CYAN = 36
    WHITE = 37

class Style(Enum):
    BOLD = 1
    ITALIC = 3
    UNDERLINE = 4
    STRIKETHROUGH = 9


def hline(length):
    '''
    Draws a horizontal line on the screen of the requested length
    '''
    for _ in range(length):
        print("\u2500",end="")
    else:
        print("\n")

def style_print(text: str, color: Color, style=None):
   
    if style is None:
        ansi_escape_code = "".join([ANSI_PREFIX, str(color.value), ANSI_SUFFIX])
    else:
        ansi_escape_code = "".join([ANSI_PREFIX, str(color.value), ";", str(style.value), ANSI_SUFFIX])
        
    print(repr(ansi_escape_code))

    out_string = "".join([ansi_escape_code, text, ANSI_RESET])
    print(out_string)


style_print("Hello World!", Color.RED, Style.ITALIC)
print("done")



