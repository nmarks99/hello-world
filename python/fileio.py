import os

def gen_unique_filename(default_name,extension, directory="./"):
    '''
    Generates a string "default_name.extension" if a file 
    of that name does not already exist in the directory "directory". If a file of that 
    name already exists, the generated string will be "default_name_1.extension". If that 
    already exists, the string will be "default_name_2.extension" and so on.
    '''
    contents = os.listdir(directory)
    nums = []
    f = False
    for name in contents:
        if default_name in name:
            f = True
            for ch in name:
                if ch.isdigit():
                    nums.append(int(ch))
            nums.sort()

    if not f:
        outfile = "".join([default_name,extension])
    else:
        if len(nums) >= 1:
            n = nums[-1]
            outfile = "".join([default_name,"_{}".format(n+1),extension])
        else:
            outfile = "".join([default_name,"_1",extension])

    return outfile

