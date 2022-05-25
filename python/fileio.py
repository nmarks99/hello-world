import os

def gen_default_filename(default_name,extension, directory):

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


directory = "./"
default_name = "out"
extension = ".txt"
outfile = gen_default_filename(default_name, extension, directory)
print(outfile)

