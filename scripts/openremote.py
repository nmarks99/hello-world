#!/usr/bin/env python
import os
import subprocess


def isRepo():
    c = 'git rev-parse --is-inside-work-tree'
    try:
        subprocess.check_output(c, shell=True).decode("utf8")
        return True
    except:
        return False

if isRepo():

    cmd1 = "git config --get remote.origin.url"
    result = subprocess.check_output(cmd1, shell=True)
    result = result.decode('utf8').replace(".git","")

    cmd2 = "explorer " + result
    os.system(cmd2)
