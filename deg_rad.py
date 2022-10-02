import math

def deg_to_rad(x):
    return (math.radians(x))


x = int(input("Degree -> "))

px = math.sin(deg_to_rad(x) * 5) * 5
py = math.cos(deg_to_rad(x) * 5) * 5

i = 1
for i in range(10):
    print (f"Px {px * 5 * i } \nPy {px * 5 * i}\n")

