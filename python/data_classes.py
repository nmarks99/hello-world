from dataclasses import dataclass


@dataclass
class acc:
    x:list 
    y:list 
    z:list
    mag: list
    t:list


p = acc([1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5])

print(p.x)  # Point(x=1.5, y=2.5, z=0.0)

